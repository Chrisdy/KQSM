// DlgSYSSET.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "KQSM.h"
#include "DlgSYSSET.h"
#include "afxdialogex.h"


// CDlgSYSSET �Ի���

IMPLEMENT_DYNAMIC(CDlgSYSSET, CDialogEx)

CDlgSYSSET::CDlgSYSSET(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgSYSSET::IDD, pParent)
{

}

CDlgSYSSET::~CDlgSYSSET()
{
}

void CDlgSYSSET::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_PORT, m_PORT);
	DDX_Control(pDX, IDC_EDIT_BROKERID, m_BROKERID);
	DDX_Control(pDX, IDC_EDIT_USERNAME, m_USERNAME);
	DDX_Control(pDX, IDC_EDIT_PASSWORD, m_PASSWORD);
	DDX_Control(pDX, IDC_IPADDRESS_INPUT, m_IPADDRESS);
}


BEGIN_MESSAGE_MAP(CDlgSYSSET, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_CONNECT, &CDlgSYSSET::OnBnClickedButtonConnect)
	ON_BN_CLICKED(IDC_BUTTON_SHUTDOWN, &CDlgSYSSET::OnBnClickedButtonShutdown)
END_MESSAGE_MAP()


// CDlgSYSSET ��Ϣ�������


void CDlgSYSSET::OnBnClickedButtonConnect()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CString c_IP;
	CString c_PORT;
	CString c_BROKERID;
	CString c_USERNAME;
	CString c_PASSWORD;

	//��ȡIP��ַ
	BYTE IP0, IP1, IP2, IP3;
	m_IPADDRESS.GetAddress(IP0, IP1, IP2, IP3);
	c_IP.Format(_T("%d.%d.%d.%d"), IP0, IP1, IP2, IP3);
	MessageBox(c_IP);
	//��ȡ�˿ں�
	this->m_PORT.GetWindowTextW(c_PORT);
	//��ȡBrokerID
	this->m_BROKERID.GetWindowTextW(c_BROKERID);
	//��ȡ�û���
	this->m_USERNAME.GetWindowTextW(c_USERNAME);
	//��ȡ����
	this->m_PASSWORD.GetWindowTextW(c_PASSWORD);
}


void CDlgSYSSET::OnBnClickedButtonShutdown()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	EndDialog(IDCANCEL);
}
