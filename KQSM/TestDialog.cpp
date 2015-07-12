// TestDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "KQSM.h"
#include "TestDialog.h"
#include "afxdialogex.h"
#include "KSMarketApiHandler.h"
#include "Global.h"

// TestDialog 对话框

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


// TestDialog 消息处理程序

void TestDialog::OnBnClickedWizfinish()
{
	// TODO:  在此添加控件通知处理程序代码
	for (int i = 0; i < 1; i++)
	{
		// 创建CThostFtdcMdApi实例
		pUserApi[i] = CThostFtdcMdApi::CreateFtdcMdApi("./log");
		// 创建事件处理实例
		pSpi[i] = new KSMarketApiHandler(pUserApi[i]);
		// 创建一个手工重置事件
		pSpi[i]->m_hEvent = event_create(true, false);
		// 设置SPI响应实例的【期货公司ID】、【用户ID】、【用户密码】
		strcpy(pSpi[i]->m_chBrokerID, "08CBBC2E");	// 期货周边测试系统(v6)
#ifdef WIN32
		_snprintf(pSpi[i]->m_chUserID, sizeof(pSpi[i]->m_chUserID) - 1, "56002229");
#else
		snprintf(pSpi[i]->m_chUserID, sizeof(pSpi[i]->m_chUserID), "56002229");
#endif
		strcpy(pSpi[i]->m_chPassword, "280890");
		// 注册事件处理实例
		pUserApi[i]->RegisterSpi(pSpi[i]);
		// 注册前置地址和端口号
		pUserApi[i]->RegisterFront("tcp://119.147.208.132:26993");
		// 初始化
		pUserApi[i]->Init();
	}

}


BOOL TestDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	// TODO: 列表   
	CRect rect;

	// 获取编程语言列表视图控件的位置和大小   
	m_SpiMessage.GetClientRect(&rect);

	// 为列表视图控件添加全行选中和栅格风格   
	m_SpiMessage.SetExtendedStyle(m_SpiMessage.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 为列表视图控件添加一列表头
	m_SpiMessage.InsertColumn(0, _T("信息显示区域"), LVCFMT_CENTER, rect.Width(), 0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void TestDialog::OnLvnItemchangedListTestMessage(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO:  在此添加控件通知处理程序代码
	*pResult = 0;
}


void TestDialog::OnBnClickedButtonLoginin()
{
	// TODO:  在此添加控件通知处理程序代码
}
