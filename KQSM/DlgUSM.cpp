// DlgUSM.cpp : 实现文件
//

#include "stdafx.h"
#include "KQSM.h"
#include "DlgUSM.h"
#include "afxdialogex.h"


// CDlgUSM 对话框

IMPLEMENT_DYNAMIC(CDlgUSM, CDialogEx)

CDlgUSM::CDlgUSM(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgUSM::IDD, pParent)
{
	//快捷键列表初始化
	m_hAccelTable = LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_ACCELERATOR_USM));
}

CDlgUSM::~CDlgUSM()
{
}

void CDlgUSM::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_REVOKESEC, m_REVOKESEC);
	DDX_Control(pDX, IDC_RADIO_REVOKE1, m_RADIO_REVOKE);
	DDX_Control(pDX, IDC_RADIO_SUB1, m_RADIO_REVOKESUB);
	DDX_Control(pDX, IDC_RADIO_SUB2_1, m_RADIO_REVOKESUB2);
	DDX_Control(pDX, IDC_EDIT_REVOKESUB_NEWPOINT, m_REVOKESUB_NEWPOINT);
	DDX_Control(pDX, IDC_EDIT_REVOKESUB_OLDPOINT, m_REVOKESUB_OLDPOINT);
}


BEGIN_MESSAGE_MAP(CDlgUSM, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_START, &CDlgUSM::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CDlgUSM::OnBnClickedButtonSave)
	ON_BN_CLICKED(IDC_RADIO_SUB2_1, &CDlgUSM::OnBnClickedRadioSub21)
	ON_BN_CLICKED(IDC_RADIO_SUB2_2, &CDlgUSM::OnBnClickedRadioSub22)
	ON_BN_CLICKED(IDC_RADIO_SUB2, &CDlgUSM::OnBnClickedRadioSub2)
	ON_BN_CLICKED(IDC_RADIO_SUB1, &CDlgUSM::OnBnClickedRadioSub1)
	ON_BN_CLICKED(IDC_RADIO_REVOKE2, &CDlgUSM::OnBnClickedRadioRevoke2)
	ON_BN_CLICKED(IDC_RADIO_REVOKE1, &CDlgUSM::OnBnClickedRadioRevoke1)
END_MESSAGE_MAP()


// CDlgUSM 消息处理程序

BOOL CDlgUSM::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_REVOKESEC.EnableWindow(FALSE);
	m_REVOKESUB_OLDPOINT.EnableWindow(FALSE);
	m_REVOKESUB_NEWPOINT.EnableWindow(FALSE);
	m_RADIO_REVOKE.SetCheck(TRUE);
	m_RADIO_REVOKESUB.SetCheck(TRUE);
	//m_RADIO_REVOKESUB2.SetCheck(TRUE);

	// TODO:  在此添加额外的初始化
	CButton *bn1 = (CButton *)this->GetDlgItem(IDC_RADIO_SUB2_1);
	bn1->EnableWindow(FALSE);
	CButton *bn2 = (CButton *)this->GetDlgItem(IDC_RADIO_SUB2_2);
	bn2->EnableWindow(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}

BOOL CDlgUSM::PreTranslateMessage(MSG* pMsg)
{
	// TODO:  在此添加专用代码和/或调用基类
	//快捷键消息处理
	if (m_hAccelTable)
	{
		if (::TranslateAccelerator(m_hWnd, m_hAccelTable, pMsg))
		{
			return(TRUE);
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

//启动监控
void CDlgUSM::OnBnClickedButtonStart()
{
	// TODO:  在此添加控件通知处理程序代码
	MessageBox(_T("R")); 
}

//保存设置
void CDlgUSM::OnBnClickedButtonSave()
{
	// TODO:  在此添加控件通知处理程序代码
	MessageBox(_T("S"));
}

//最新委托价格
void CDlgUSM::OnBnClickedRadioSub21()
{
	// TODO:  在此添加控件通知处理程序代码
	m_REVOKESUB_NEWPOINT.EnableWindow(TRUE);
	m_REVOKESUB_OLDPOINT.EnableWindow(FALSE);
}

//原委托价格
void CDlgUSM::OnBnClickedRadioSub22()
{
	// TODO:  在此添加控件通知处理程序代码
	m_REVOKESUB_NEWPOINT.EnableWindow(FALSE);
	m_REVOKESUB_OLDPOINT.EnableWindow(TRUE);
}

//重发委托
void CDlgUSM::OnBnClickedRadioSub2()
{
	// TODO:  在此添加控件通知处理程序代码
	CButton *bn1 = (CButton *)this->GetDlgItem(IDC_RADIO_SUB2_1);
	CButton *bn2 = (CButton *)this->GetDlgItem(IDC_RADIO_SUB2_2);
	bn1->EnableWindow(TRUE);
	bn2->EnableWindow(TRUE);
	if (bn1->GetCheck()){
		m_REVOKESUB_NEWPOINT.EnableWindow(TRUE);
		m_REVOKESUB_OLDPOINT.EnableWindow(FALSE);
	}
	else if (bn2->GetCheck()){
		m_REVOKESUB_NEWPOINT.EnableWindow(FALSE);
		m_REVOKESUB_OLDPOINT.EnableWindow(TRUE);
	}
	else{
		m_RADIO_REVOKESUB2.SetCheck(TRUE);
		m_REVOKESUB_NEWPOINT.EnableWindow(TRUE);
	}
	
}

//无操作
void CDlgUSM::OnBnClickedRadioSub1()
{
	// TODO:  在此添加控件通知处理程序代码
	m_REVOKESUB_NEWPOINT.EnableWindow(FALSE);
	m_REVOKESUB_OLDPOINT.EnableWindow(FALSE);

	CButton *bn1 = (CButton *)this->GetDlgItem(IDC_RADIO_SUB2_1);
	CButton *bn2 = (CButton *)this->GetDlgItem(IDC_RADIO_SUB2_2);
	bn1->EnableWindow(FALSE);
	bn2->EnableWindow(FALSE);
	m_RADIO_REVOKESUB2.SetCheck(FALSE);
}

//延时撤单
void CDlgUSM::OnBnClickedRadioRevoke2()
{
	// TODO:  在此添加控件通知处理程序代码
	m_REVOKESEC.EnableWindow(TRUE);
}

//不成交即撤单
void CDlgUSM::OnBnClickedRadioRevoke1()
{
	// TODO:  在此添加控件通知处理程序代码
	m_REVOKESEC.EnableWindow(FALSE);
}