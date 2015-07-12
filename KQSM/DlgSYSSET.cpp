// DlgSYSSET.cpp : 实现文件
//

#include "stdafx.h"
#include "KQSM.h"
#include "DlgSYSSET.h"
#include "afxdialogex.h"


// CDlgSYSSET 对话框

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


// CDlgSYSSET 消息处理程序


void CDlgSYSSET::OnBnClickedButtonConnect()
{
	// TODO:  在此添加控件通知处理程序代码
	CString c_IP;
	CString c_PORT;
	CString c_BROKERID;
	CString c_USERNAME;
	CString c_PASSWORD;

	//获取IP地址
	BYTE IP0, IP1, IP2, IP3;
	m_IPADDRESS.GetAddress(IP0, IP1, IP2, IP3);
	c_IP.Format(_T("%d.%d.%d.%d"), IP0, IP1, IP2, IP3);
	MessageBox(c_IP);
	//获取端口号
	this->m_PORT.GetWindowTextW(c_PORT);
	//获取BrokerID
	this->m_BROKERID.GetWindowTextW(c_BROKERID);
	//获取用户名
	this->m_USERNAME.GetWindowTextW(c_USERNAME);
	//获取密码
	this->m_PASSWORD.GetWindowTextW(c_PASSWORD);
}


void CDlgSYSSET::OnBnClickedButtonShutdown()
{
	// TODO:  在此添加控件通知处理程序代码
	EndDialog(IDCANCEL);
}
