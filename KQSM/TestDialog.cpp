// TestDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "KQSM.h"
#include "TestDialog.h"
#include "afxdialogex.h"
#include "KSMarketApiHandler.h"
#include "Global.h"

// TestDialog �Ի���

IMPLEMENT_DYNAMIC(TestDialog, CDialogEx)

TestDialog::TestDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(TestDialog::IDD, pParent)
{

}

TestDialog::~TestDialog()
{
}

void TestDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_TEST_MESSAGE, m_SpiMessage);
}


BEGIN_MESSAGE_MAP(TestDialog, CDialogEx)
	ON_BN_CLICKED(ID_WIZFINISH, &TestDialog::OnBnClickedWizfinish)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_TEST_MESSAGE, &TestDialog::OnLvnItemchangedListTestMessage)
	ON_BN_CLICKED(IDC_BUTTON_LOGININ, &TestDialog::OnBnClickedButtonLoginin)
END_MESSAGE_MAP()


// TestDialog ��Ϣ�������

void TestDialog::OnBnClickedWizfinish()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	for (int i = 0; i < 1; i++)
	{
		// ����CThostFtdcMdApiʵ��
		pUserApi[i] = CThostFtdcMdApi::CreateFtdcMdApi("./log");
		// �����¼�����ʵ��
		pSpi[i] = new KSMarketApiHandler(pUserApi[i]);
		// ����һ���ֹ������¼�
		pSpi[i]->m_hEvent = event_create(true, false);
		// ����SPI��Ӧʵ���ġ��ڻ���˾ID�������û�ID�������û����롿
		strcpy(pSpi[i]->m_chBrokerID, "08CBBC2E");	// �ڻ��ܱ߲���ϵͳ(v6)
#ifdef WIN32
		_snprintf(pSpi[i]->m_chUserID, sizeof(pSpi[i]->m_chUserID) - 1, "56002229");
#else
		snprintf(pSpi[i]->m_chUserID, sizeof(pSpi[i]->m_chUserID), "56002229");
#endif
		strcpy(pSpi[i]->m_chPassword, "280890");
		// ע���¼�����ʵ��
		pUserApi[i]->RegisterSpi(pSpi[i]);
		// ע��ǰ�õ�ַ�Ͷ˿ں�
		pUserApi[i]->RegisterFront("tcp://119.147.208.132:26993");
		// ��ʼ��
		pUserApi[i]->Init();
	}

}


BOOL TestDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	// TODO: �б�   
	CRect rect;

	// ��ȡ��������б���ͼ�ؼ���λ�úʹ�С   
	m_SpiMessage.GetClientRect(&rect);

	// Ϊ�б���ͼ�ؼ����ȫ��ѡ�к�դ����   
	m_SpiMessage.SetExtendedStyle(m_SpiMessage.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// Ϊ�б���ͼ�ؼ����һ�б�ͷ
	m_SpiMessage.InsertColumn(0, _T("��Ϣ��ʾ����"), LVCFMT_CENTER, rect.Width(), 0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void TestDialog::OnLvnItemchangedListTestMessage(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void TestDialog::OnBnClickedButtonLoginin()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
