#include "stdafx.h"
#include "KSMarketApiHandler.h"


KSMarketApiHandler::KSMarketApiHandler(CThostFtdcMdApi *pUserApi) : m_pUserApi(pUserApi)
{
}


KSMarketApiHandler::~KSMarketApiHandler()
{
}


// After making a succeed connection with the CTP server, the client should send the login request to the CTP server.
void KSMarketApiHandler::OnFrontConnected()
{
	printf("OnFrontConnected:\n");

	CThostFtdcReqUserLoginField reqUserLogin;
	memset(&reqUserLogin, 0, sizeof(reqUserLogin));
	// set BrokerID
	printf("BrokerID:%s\n", m_chBrokerID);
	strcpy(reqUserLogin.BrokerID, m_chBrokerID);

	// set user id
	printf("userid:%s\n", m_chUserID);
	strcpy(reqUserLogin.UserID, m_chUserID);

	// set password
	printf("password:%s\n", m_chPassword);
	strcpy(reqUserLogin.Password, m_chPassword);

	// send the login request
	m_pUserApi->ReqUserLogin(&reqUserLogin, m_nRequestID++);
}


//When the connection between client and the CTP server	disconnected,the follwing function will be called.
void KSMarketApiHandler::OnFrontDisconnected(int nReason)
{
	//  Inthis  case,  API  willreconnect��the  client  application can ignore this.
	printf("OnFrontDisconnected.\n");
}

// After receiving the login request from  the client��the CTP server will send the following response to notify the client whether the login success or not.
void KSMarketApiHandler::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	printf("OnRspUserLogin:");
	if (pRspUserLogin != NULL)
	{
		printf("%s|%s|%s|%s|%s|%s|%s|%s|%s|%d|%d|%s|",
			pRspUserLogin->BrokerID,					// ���͹�˾����
			pRspUserLogin->UserID,						// �û�����
			pRspUserLogin->TradingDay,					// ������
			pRspUserLogin->SystemName,					// ����ϵͳ����
			pRspUserLogin->LoginTime,					// ��½�ɹ�ʱ��
			pRspUserLogin->SHFETime,					// ������ʱ��
			pRspUserLogin->DCETime,						// ������ʱ��
			pRspUserLogin->CZCETime,					// ֣����ʱ��
			pRspUserLogin->FFEXTime,					// �н���ʱ��
			pRspUserLogin->FrontID,						// frond id
			pRspUserLogin->SessionID,					// session id
			pRspUserLogin->MaxOrderRef					// ��󱨵�����
			);
	}
	printf("\n");
	printf("ErrorCode=[%d], ErrorMsg=[%s]\n", pRspInfo->ErrorID, pRspInfo->ErrorMsg);
	printf("RequestID=[%d], Chain=[%d]\n", nRequestID, bIsLast);
	if (pRspInfo->ErrorID != 0)
	{
		// in case any login failure, the client should handle this error.
		printf("Failed to login, errorcode=%d errormsg=%s requestid=%d chain=%d", pRspInfo->ErrorID, pRspInfo->ErrorMsg, nRequestID, bIsLast);
		return;
	}

	// get trading day
	printf("��ȡ��ǰ������ = %s\n", m_pUserApi->GetTradingDay());

	// ���鶩���б�
	//char *ppInstrumentID[] = {"IF1203"};
	char *ppInstrumentID[1024];
	ppInstrumentID[0] = new char[31];
	strcpy(ppInstrumentID[0], m_chContract);
	// ���鶩�ĸ���
	int iInstrumentID = 1;
	// 	����
	m_pUserApi->SubscribeMarketData(ppInstrumentID, iInstrumentID);
	// �ͷ��ڴ�
	delete ppInstrumentID[0];
}

///RspSubMarketData return
void KSMarketApiHandler::OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	printf("OnRspSubMarketData:%s\n", pSpecificInstrument->InstrumentID);
	printf("ErrorCode=[%d], ErrorMsg=[%s]\n", pRspInfo->ErrorID, pRspInfo->ErrorMsg);
}


///OnRspUnSubMarketData return
void KSMarketApiHandler::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	printf("OnRspUnSubMarketData:\n");
	printf("ErrorCode=[%d], ErrorMsg=[%s]\n", pRspInfo->ErrorID, pRspInfo->ErrorMsg);
}

///OnRtnDepthMarketData
void KSMarketApiHandler::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData)
{
	printf("OnRtnDepthMarketData:");
	if (pDepthMarketData != NULL)
	{
		printf("%s|%s|%.04f|%.04f|%.04f|%.04f|%.04f|%d|%.04f|%.04f|%.04f|%d|%d|%.04f|%.04f|%.04f|%.04f|%.04f|%s|%d|%.04f|%d|%.04f|%d|%.04f|%d|%.04f|%d|%.04f|%d|%.04f|%d|%.04f|%d|%.04f|",
			pDepthMarketData->ExchangeID,					// ����������
			pDepthMarketData->InstrumentID,					// ��Լ����
			pDepthMarketData->PreClosePrice,				// ������
			pDepthMarketData->OpenPrice,					// ����
			pDepthMarketData->HighestPrice,					// ��߼�
			pDepthMarketData->LowestPrice,					// ��ͼ�
			pDepthMarketData->LastPrice,					// ���¼�
			pDepthMarketData->Volume,						// ����
			pDepthMarketData->Turnover,						// �ɽ����
			pDepthMarketData->BidPrice1,					// �����һ
			pDepthMarketData->AskPrice1,					// ������һ
			pDepthMarketData->BidVolume1,					// ������һ
			pDepthMarketData->AskVolume1,					// ������һ
			pDepthMarketData->UpperLimitPrice,				// ��ͣ���
			pDepthMarketData->LowerLimitPrice,				// ��ͣ���
			pDepthMarketData->PreSettlementPrice,			// �ϴν����
			pDepthMarketData->SettlementPrice,				// ���ν����
			pDepthMarketData->OpenInterest,					// �ֲ���
			pDepthMarketData->TradingDay,					// ������
			pDepthMarketData->BidVolume2,					// ��������
			pDepthMarketData->BidPrice2,					// ����۶�
			pDepthMarketData->BidVolume3,					// ��������
			pDepthMarketData->BidPrice3,					// �������
			pDepthMarketData->BidVolume4,					// ��������
			pDepthMarketData->BidPrice4,					// �������
			pDepthMarketData->BidVolume5,					// ��������
			pDepthMarketData->BidPrice5,					// �������
			pDepthMarketData->AskVolume2,					// ��������
			pDepthMarketData->AskPrice2,					// �����۶�
			pDepthMarketData->AskVolume3,					// ��������
			pDepthMarketData->AskPrice3,					// ��������
			pDepthMarketData->AskVolume4,					// ��������
			pDepthMarketData->AskPrice4,					// ��������
			pDepthMarketData->AskVolume5,					// ��������
			pDepthMarketData->AskPrice5						// ��������
			);
	}
	printf("\n");
}

// logout return
void KSMarketApiHandler::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	printf("OnRspUserLogout:");
	if (NULL != pUserLogout)
	{
		printf("%s", pUserLogout->UserID);
	}
	printf("\n");
	printf("ErrorCode=[%d], ErrorMsg=[%s]\n", pRspInfo->ErrorID, pRspInfo->ErrorMsg);
	printf("RequestID=[%d], Chain=[%d]\n", nRequestID, bIsLast);

	// inform the main thread order transaction is over 
	//SetEvent(m_hEvent); 
	event_set((event_handle)m_hEvent);

	return;
}
