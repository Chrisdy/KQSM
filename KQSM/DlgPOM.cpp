// DlgPOM.cpp : 实现文件
//

#include "stdafx.h"
#include "KQSM.h"
#include "DlgPOM.h"
#include "afxdialogex.h"


// CDlgPOM 对话框

IMPLEMENT_DYNAMIC(CDlgPOM, CDialogEx)

CDlgPOM::CDlgPOM(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgPOM::IDD, pParent)
{

}

CDlgPOM::~CDlgPOM()
{
}

void CDlgPOM::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_ZHISUN, m_ZHISUN);
	DDX_Control(pDX, IDC_EDIT_ZHIYING, m_ZHIYING);
	DDX_Control(pDX, IDC_EDIT_FLOATZHISUN, m_FLOATZHISUN);
	DDX_Control(pDX, IDC_EDIT_NUMBER, m_NUMBER);
	DDX_Control(pDX, IDC_LIST_SHOW, m_LIST);
	DDX_Control(pDX, IDC_COMBO_VALID, m_VALID);
}


BEGIN_MESSAGE_MAP(CDlgPOM, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CDlgPOM::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CDlgPOM::OnBnClickedButtonDelete)
	ON_WM_VSCROLL()
	ON_BN_CLICKED(IDC_BUTTON_EDIT, &CDlgPOM::OnBnClickedButtonEdit)
	ON_BN_CLICKED(IDC_BUTTON_SHUTDOWN, &CDlgPOM::OnBnClickedButtonShutdown)
END_MESSAGE_MAP()


// CDlgPOM 消息处理程序


BOOL CDlgPOM::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	int n = 100;
	CString str;
	str.Format(_T("%d"), n);
	//TODO:修改初始化
	this->m_ZHISUN.SetWindowTextW(str);
	this->m_ZHIYING.SetWindowTextW(str);
	this->m_FLOATZHISUN.SetWindowTextW(str);
	this->m_NUMBER.SetWindowTextW(str);

	// TODO: 列表   
	CRect rect;

	// 获取编程语言列表视图控件的位置和大小   
	m_LIST.GetClientRect(&rect);

	// 为列表视图控件添加全行选中和栅格风格   
	m_LIST.SetExtendedStyle(m_LIST.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// 为列表视图控件添加三列   
	m_LIST.InsertColumn(0, _T("设置时间"), LVCFMT_CENTER, rect.Width()*3/12, 0);
	m_LIST.InsertColumn(1, _T("数量"), LVCFMT_CENTER, rect.Width()*3/24, 1);
	m_LIST.InsertColumn(2, _T("止损价"), LVCFMT_CENTER, rect.Width()*2/12, 2);
	m_LIST.InsertColumn(3, _T("浮动止损"), LVCFMT_CENTER, rect.Width()*2/12, 2);
	m_LIST.InsertColumn(4, _T("止盈价"), LVCFMT_CENTER, rect.Width()*2/12, 2);
	m_LIST.InsertColumn(5, _T("有效"), LVCFMT_CENTER, rect.Width()*3/24, 2);

	/*
	// 在列表视图控件中插入列表项，并设置列表子项文本   
	m_LIST.InsertItem(0, _T("Java"));
	m_LIST.SetItemText(0, 1, _T("100"));
	// m_LIST.SetItemText(0, 2, _T("100"));   
	m_LIST.InsertItem(1, _T("C"));
	m_LIST.SetItemText(1, 1, _T("2"));
	//m_LIST.SetItemText(1, 2, _T("2"));   
	*/

	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}


void CDlgPOM::OnBnClickedButtonAdd()
{
	// TODO:  在此添加控件通知处理程序代码
	//添加输入的一条记录
	CString c_TIME;
	CString c_ZHISUN;
	CString c_ZHIYING;
	CString c_FLOATZHISUN;
	CString c_NUMBER;
	CString c_VALID;

	//获取当前时间
	SYSTEMTIME st;	
	GetLocalTime(&st);
	c_TIME.Format(_T("%4d-%2d-%2d %2d:%2d"), st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute);


	//获取已添加的记录数
	int listN = m_LIST.GetItemCount();
	CString str;
	str.Format(_T("%d"),listN);
	//MessageBox(str);
	m_ZHISUN.GetWindowTextW(c_ZHISUN);
	m_ZHIYING.GetWindowTextW(c_ZHIYING);
	m_FLOATZHISUN.GetWindowTextW(c_FLOATZHISUN);
	m_NUMBER.GetWindowTextW(c_NUMBER);
	m_VALID.GetWindowTextW(c_VALID);
	
	//m_LIST.InsertItem(listN, c_TIME);
	m_LIST.InsertItem(0, c_TIME);
	m_LIST.SetItemText(0, 1, c_NUMBER);
	m_LIST.SetItemText(0, 2, c_ZHISUN);
	m_LIST.SetItemText(0, 3, c_FLOATZHISUN);
	m_LIST.SetItemText(0, 4, c_ZHIYING);
	m_LIST.SetItemText(listN, 5, c_VALID);
}


void CDlgPOM::OnBnClickedButtonDelete()
{
	// TODO:  在此添加控件通知处理程序代码

	POSITION pos = m_LIST.GetFirstSelectedItemPosition();
	while (pos)
	{
		int  nSelected = m_LIST.GetNextSelectedItem(pos);
		m_LIST.DeleteItem(nSelected);
		m_LIST.GetFirstSelectedItemPosition();
		pos = m_LIST.GetFirstSelectedItemPosition();
	}
}


void CDlgPOM::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	//加个判断，是哪个ScrollBar触发的
	if (pScrollBar == (CScrollBar*)GetDlgItem(IDC_SB_ZHISUN)){
		CString str;
		this->m_ZHISUN.GetWindowTextW(str);

		int n = _ttoi(str);
		switch (nSBCode)
		{
			// 如果向上滚动一列
		case SB_LINEUP:
			n++;
			break;
			// 如果向下滚动一列
		case SB_LINEDOWN:
			n--;
			break;
		}
		CString str2;
		str2.Format(_T("%d"), n);
		this->m_ZHISUN.SetWindowTextW(str2);
	}
	else if (pScrollBar == (CScrollBar*)GetDlgItem(IDC_SB_ZHIYING)){
		CString str;
		this->m_ZHIYING.GetWindowTextW(str);

		int n = _ttoi(str);
		switch (nSBCode)
		{
			// 如果向上滚动一列
		case SB_LINEUP:
			n++;
			break;
			// 如果向下滚动一列
		case SB_LINEDOWN:
			n--;
			break;
		}
		CString str2;
		str2.Format(_T("%d"), n);
		this->m_ZHIYING.SetWindowTextW(str2);
	}
	else if (pScrollBar == (CScrollBar*)GetDlgItem(IDC_SB_FLOATZHISUN)){
		CString str;
		this->m_FLOATZHISUN.GetWindowTextW(str);

		int n = _ttoi(str);
		switch (nSBCode)
		{
			// 如果向上滚动一列
		case SB_LINEUP:
			n++;
			break;
			// 如果向下滚动一列
		case SB_LINEDOWN:
			n--;
			break;
		}
		CString str2;
		str2.Format(_T("%d"), n);
		this->m_FLOATZHISUN.SetWindowTextW(str2);
	}
	else if (pScrollBar == (CScrollBar*)GetDlgItem(IDC_SB_NUMBER)){
		CString str;
		this->m_NUMBER.GetWindowTextW(str);

		int n = _ttoi(str);
		switch (nSBCode)
		{
			// 如果向上滚动一列
		case SB_LINEUP:
			n++;
			break;
			// 如果向下滚动一列
		case SB_LINEDOWN:
			n--;
			break;
		}
		CString str2;
		str2.Format(_T("%d"), n);
		this->m_NUMBER.SetWindowTextW(str2);
	}

	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}


void CDlgPOM::OnBnClickedButtonEdit()
{
	// TODO:  在此添加控件通知处理程序代码
}


void CDlgPOM::OnBnClickedButtonShutdown()
{
	// TODO:  关闭该窗口(持仓订单管理Dialog)
	EndDialog(IDCANCEL);
}
