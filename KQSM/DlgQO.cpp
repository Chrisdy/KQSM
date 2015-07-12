// DlgQO.cpp : 实现文件
//

#include "stdafx.h"
#include "KQSM.h"
#include "DlgQO.h"
#include "afxdialogex.h"


// CDlgQO 对话框

IMPLEMENT_DYNAMIC(CDlgQO, CDialogEx)

CDlgQO::CDlgQO(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgQO::IDD, pParent)
{
	//快捷键列表初始化
	m_hAccelTable = LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_ACCELERATOR_QO));
}

CDlgQO::~CDlgQO()
{
}

void CDlgQO::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgQO, CDialogEx)
	ON_WM_TIMER()
	ON_CBN_SELCHANGE(IDC_COMBO_CONTRACT, &CDlgQO::OnCbnSelchangeComboContract)
	ON_BN_CLICKED(IDC_BUTTON_VARIETY1, &CDlgQO::OnBnClickedButtonVariety1)
	ON_BN_CLICKED(IDC_BUTTON_VARIETY2, &CDlgQO::OnBnClickedButtonVariety2)
	ON_BN_CLICKED(IDC_BUTTON_VARIETY3, &CDlgQO::OnBnClickedButtonVariety3)
	ON_BN_CLICKED(IDC_BUTTON_SELL1, &CDlgQO::OnBnClickedButtonSell1)
	ON_BN_CLICKED(IDC_BUTTON_SELL2, &CDlgQO::OnBnClickedButtonSell2)
	ON_BN_CLICKED(IDC_BUTTON_SELL3, &CDlgQO::OnBnClickedButtonSell3)
	ON_BN_CLICKED(IDC_BUTTON_BUY1, &CDlgQO::OnBnClickedButtonBuy1)
	ON_BN_CLICKED(IDC_BUTTON_BUY2, &CDlgQO::OnBnClickedButtonBuy2)
	ON_BN_CLICKED(IDC_BUTTON_BUY3, &CDlgQO::OnBnClickedButtonBuy3)
	ON_BN_CLICKED(IDC_BUTTON_REGULARORDER, &CDlgQO::OnBnClickedButtonRegularorder)
	ON_BN_CLICKED(IDC_BUTTON_ANOMALYCONTROL, &CDlgQO::OnBnClickedButtonAnomalycontrol)
	ON_BN_CLICKED(IDC_BUTTON_SUBTRACT, &CDlgQO::OnBnClickedButtonSubtract)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CDlgQO::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_ENTER, &CDlgQO::OnBnClickedButtonEnter)
END_MESSAGE_MAP()


// CDlgQO 消息处理程序


void CDlgQO::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CDialogEx::OnTimer(nIDEvent);

	CEdit* cEditCapital;
	cEditCapital = (CEdit*)GetDlgItem(IDC_EDIT_CAPITAL);
	CString oldCapital;
	cEditCapital->GetWindowTextW(oldCapital);

	//CString to int
	int capital = _ttoi(oldCapital);
	//设置资金显示数据
	SetDlgItemInt(IDC_EDIT_CAPITAL, --capital);
	/*
	另一种设置显示数据的方式，给Edit Control增加一个变量m_Capital，修改其值来显示
	CString curCapital;
	curCapital.Format(_T("%d"), capital);
	m_Capital.SetWindowTextW(curCapital);
	*/

	//设置可开，d_kekai要实时获取
	double d_kekai = 101.0;
	CString temp_kekai;
	temp_kekai.Format(_T("%.2lf"), d_kekai);
	SetDlgItemTextW(IDC_EDIT_KEKAI, temp_kekai);

	//设置要开，d_yaokai要实时获取
	double d_yaokai = 201.0;
	CString temp_yaokai;
	temp_yaokai.Format(_T("%.2lf"), d_yaokai);
	SetDlgItemTextW(IDC_EDIT_YAOKAI, temp_yaokai);

	//设置买价，d_cost要实时获取
	double d_cost = 301.0;
	CString temp_cost;
	temp_cost.Format(_T("%.2lf"), d_cost);
	SetDlgItemTextW(IDC_EDIT_BUYPRICE, temp_cost);

	//设置卖价，d_price要实时获取
	double d_price = 401.0;
	CString temp_price;
	temp_price.Format(_T("%.2lf"), d_price);
	SetDlgItemTextW(IDC_EDIT_SELLPRICE, temp_price);
}


BOOL CDlgQO::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//设置资金的变量,外部提供数据
	int capital;
	//假设为1000
	capital = 1000;
	CString capitalStr;
	capitalStr.Format(_T("%d"), capital);
	SetDlgItemInt(IDC_EDIT_CAPITAL, capital);
	//m_Capital.SetWindowTextW(capitalStr);


	//设置可开数据，获取初始值
	double d_kekai = 100.0;
	CString temp_kekai;
	temp_kekai.Format(_T("%.2lf"), d_kekai);
	SetDlgItemTextW(IDC_EDIT_KEKAI, temp_kekai);

	//设置要开数据，获取初始值
	double d_yaokai = 200.0;
	CString temp_yaokai;
	temp_yaokai.Format(_T("%.2lf"), d_yaokai);
	SetDlgItemTextW(IDC_EDIT_YAOKAI, temp_yaokai);

	//设置买价数据，获取初始值
	double d_cost = 300.0;
	CString temp_cost;
	temp_cost.Format(_T("%.2lf"), d_cost);
	SetDlgItemTextW(IDC_EDIT_BUYPRICE, temp_cost);

	//设置卖价数据，获取初始值
	double d_price = 400.0;
	CString temp_price;
	temp_price.Format(_T("%.2lf"), d_price);
	SetDlgItemTextW(IDC_EDIT_SELLPRICE, temp_price);

	//设定定时器
	SetTimer(1, 1000, NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CDlgQO::OnCbnSelchangeComboContract()
{
	// TODO:  在此添加控件通知处理程序代码
	// TODO:下拉框
	CComboBox* ccb;
	ccb = (CComboBox*)GetDlgItem(IDC_COMBO_CONTRACT);
	int sel = ccb->GetCurSel();
	CString str;
	str.Format(_T("%d"), sel);
	CString strContent;
	ccb->GetLBText(sel, strContent); 
	//strContent.Format(_T("%s"),ccb->GetItemData(sel));
	//str.Append(strContent);
	MessageBox(str + " " + strContent);

	//为了防止当使用下拉框的时候，其他快捷键无法使用的问题
	(CButton*)GetDlgItem(IDC_BUTTON_VARIETY1)->SetFocus();
}


void CDlgQO::OnBnClickedButtonVariety1()
{
	// TODO: 实现7.品种一的功能
	MessageBox(_T("Hello,7.品种1"));
}


void CDlgQO::OnBnClickedButtonVariety2()
{
	// TODO: 实现8.品种二的功能
	MessageBox(_T("Hello,8.品种2"));
}


void CDlgQO::OnBnClickedButtonVariety3()
{
	// TODO: 实现9.品种三的功能
	MessageBox(_T("Hello,9.品种3"));
}


void CDlgQO::OnBnClickedButtonSell1()
{
	// TODO: 实现按钮1①卖的功能
	MessageBox(_T("Hello，1①卖"));
}


void CDlgQO::OnBnClickedButtonSell2()
{
	// TODO: 实现按钮2②卖的功能
	MessageBox(_T("Hello，2②卖"));
}


void CDlgQO::OnBnClickedButtonSell3()
{
	// TODO: 实现按钮3③卖的功能
	MessageBox(_T("Hello，3③卖"));
}


void CDlgQO::OnBnClickedButtonBuy1()
{
	// TODO:实现按钮1①买的功能
	MessageBox(_T("Hello，1①买"));
}


void CDlgQO::OnBnClickedButtonBuy2()
{
	// TODO: 实现按钮2②买的功能
	MessageBox(_T("Hello，2②买"));
}


void CDlgQO::OnBnClickedButtonBuy3()
{
	// TODO: 实现按钮3③买的功能
	MessageBox(_T("Hello，3③买"));
}


void CDlgQO::OnBnClickedButtonRegularorder()
{
	// TODO: 实现0.选择常规单量的功能
	MessageBox(_T("Hello,0.选择常规单量"));
}


void CDlgQO::OnBnClickedButtonAnomalycontrol()
{
	// TODO: 实现.异常控制的功能
	MessageBox(_T("Hello,.异常控制"));
}


void CDlgQO::OnBnClickedButtonSubtract()
{
	// TODO: 实现减仓的功能
	MessageBox(_T("Hello,-.减仓"));
}


void CDlgQO::OnBnClickedButtonAdd()
{
	// TODO: 实现加仓的功能
	MessageBox(_T("Hello,+.加仓"));
}


void CDlgQO::OnBnClickedButtonEnter()
{
	// TODO: 实现Enter的功能
	MessageBox(_T("Hello,Enter"));
}


BOOL CDlgQO::PreTranslateMessage(MSG* pMsg)
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
