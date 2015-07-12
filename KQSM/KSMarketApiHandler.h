#pragma once
#ifndef __TEST_KSMARKET_DATA_API_H__
#define __TEST_KSMARKET_DATA_API_H__

#ifndef WIN32

#define INVALID_HANDLE_VALUE   -1
#define _MAX_PATH       260 /* max. length of full pathname */
#define MAX_PATH        260
//#define TRUE                true
//#define FALSE               false
#define TRUE               1
#define FALSE              0
#define __stdcall
#define __declspec(x)
#define __cdecl
#define max(a,b)           (((a) > (b)) ? (a) : (b))
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#define INVALID_SOCKET  -1
#define  INFINITE      0xFFFFFFFF
#define  CALLBACK
#define  WINAPI
typedef void                *HINSTANCE;
typedef void                *HANDLE;
typedef void                *HMODULE;
typedef int                     BOOL;
typedef unsigned char       BYTE;
typedef float                     FLOAT;
typedef FLOAT                  *PFLOAT;
typedef char                      CHAR;
typedef unsigned char       UCHAR;
typedef unsigned char       *PUCHAR;
typedef short                    SHORT;
typedef unsigned short      USHORT;
typedef unsigned short      *PUSHORT;
typedef long                      LONG;
typedef unsigned short      WORD;
typedef unsigned int       DWORD;
typedef long long              LONGLONG;
typedef unsigned long long  ULONGLONG;
typedef ULONGLONG           *PULONGLONG;
typedef unsigned long       ULONG;
typedef int                 INT;
typedef unsigned int        UINT;
typedef unsigned int        *PUINT;
typedef void                VOID;
typedef char               *LPSTR;
typedef const char         *LPCSTR;
typedef wchar_t            WCHAR;
typedef WCHAR              *LPWSTR;
typedef const WCHAR        *LPCWSTR;
typedef DWORD              *LPDWORD;
typedef unsigned long      UINT_PTR;
typedef UINT_PTR           SIZE_T;
typedef LONGLONG           USN;
typedef BYTE               BOOLEAN;
typedef void                *PVOID;
typedef void                *LPVOID;
typedef char                *LPTSTR;

typedef unsigned char byte;
typedef struct _FILETIME {
	DWORD dwLowDateTime;
	DWORD dwHighDateTime;
}    FILETIME;
typedef union _ULARGE_INTEGER {
	struct {
		DWORD LowPart;
		DWORD HighPart;
	};
	struct {
		DWORD LowPart;
		DWORD HighPart;
	} u;
	ULONGLONG QuadPart;
} ULARGE_INTEGER,
*PULARGE_INTEGER;

#ifndef MAXPACKSIZE
#define MAXPACKSIZE             8192
#endif

#endif

#include "event.h"
#include "KSMarketDataAPI\KSMarketDataAPI.h"
using namespace KingstarAPI;

class KSMarketApiHandler : public CThostFtdcMdSpi
{
public:
	// �ڻ���˾ID
	TThostFtdcBrokerIDType m_chBrokerID;
	// �û�ID
	TThostFtdcUserIDType m_chUserID;
	// �û�����
	TThostFtdcPasswordType m_chPassword;
	// ��ͬ��
	char m_chContract[80];
	// request id
	int m_nRequestID;
	// finish event
	HANDLE m_hEvent;
public:
	KSMarketApiHandler(CThostFtdcMdApi *pUserApi);
	~KSMarketApiHandler();
	// CTP���������ӳɹ��󣬿ͻ��˷��͵�¼����
	virtual void OnFrontConnected();
	// ���ͻ�����CTP�������Ͽ�����ʱ�����淽������ִ��
	virtual void OnFrontDisconnected(int nReason);
	// ���յ��ͻ��˵ĵ�¼����֮��CTP��������������Ӧ��Ϣ��֪ͨ�ͻ����Ƿ��¼�ɹ�
	virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	// �����г����鶩�ĵ���Ӧ��Ϣ
	virtual void OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	// �����г������˶�����Ӧ��Ϣ
	virtual void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	// ��������г��������Ӧ��Ϣ
	virtual void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData);
	// �û��ǳ���Ӧ��Ϣ
	virtual void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
private:
	// CThostFtdcMduserApiʵ��ָ��
	CThostFtdcMdApi *m_pUserApi;
};

#endif



