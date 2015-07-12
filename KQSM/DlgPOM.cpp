// DlgPOM.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "KQSM.h"
#include "DlgPOM.h"
#include "afxdialogex.h"


// CDlgPOM �Ի���

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


// CDlgPOM ��Ϣ�������


BOOL CDlgPOM::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	int n = 100;
	CString str;
	str.Format(_T("%d"), n);
	//TODO:�޸ĳ�ʼ��
	this->m_ZHISUN.SetWindowTextW(str);
	this->m_ZHIYING.SetWindowTextW(str);
	this->m_FLOATZHISUN.SetWindowTextW(str);
	this->m_NUMBER.SetWindowTextW(str);

	// TODO: �б�   
	CRect rect;

	// ��ȡ��������б���ͼ�ؼ���λ�úʹ�С   
	m_LIST.GetClientRect(&rect);

	// Ϊ�б���ͼ�ؼ����ȫ��ѡ�к�դ����   
	m_LIST.SetExtendedStyle(m_LIST.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	// Ϊ�б���ͼ�ؼ��������   
	m_LIST.InsertColumn(0, _T("����ʱ��"), LVCFMT_CENTER, rect.Width()*3/12, 0);
	m_LIST.InsertColumn(1, _T("����"), LVCFMT_CENTER, rect.Width()*3/24, 1);
	m_LIST.InsertColumn(2, _T("ֹ���"), LVCFMT_CENTER, rect.Width()*2/12, 2);
	m_LIST.InsertColumn(3, _T("����ֹ��"), LVCFMT_CENTER, rect.Width()*2/12, 2);
	m_LIST.InsertColumn(4, _T("ֹӯ��"), LVCFMT_CENTER, rect.Width()*2/12, 2);
	m_LIST.InsertColumn(5, _T("��Ч"), LVCFMT_CENTER, rect.Width()*3/24, 2);

	/*
	// ���б���ͼ�ؼ��в����б���������б������ı�   
	m_LIST.InsertItem(0, _T("Java"));
	m_LIST.SetItemText(0, 1, _T("100"));
	// m_LIST.SetItemText(0, 2, _T("100"));   
	m_LIST.InsertItem(1, _T("C"));
	m_LIST.SetItemText(1, 1, _T("2"));
	//m_LIST.SetItemText(1, 2, _T("2"));   
	*/

	
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CDlgPOM::OnBnClickedButtonAdd()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	//��������һ����¼
	CString c_TIME;
	CString c_ZHISUN;
	CString c_ZHIYING;
	CString c_FLOATZHISUN;
	CString c_NUMBER;
	CString c_VALID;

	//��ȡ��ǰʱ��
	SYSTEMTIME st;	
	GetLocalTime(&st);
	c_TIME.Format(_T("%4d-%2d-%2d %2d:%2d"), st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute);


	//��ȡ����ӵļ�¼��
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������

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
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//�Ӹ��жϣ����ĸ�ScrollBar������
	if (pScrollBar == (CScrollBar*)GetDlgItem(IDC_SB_ZHISUN)){
		CString str;
		this->m_ZHISUN.GetWindowTextW(str);

		int n = _ttoi(str);
		switch (nSBCode)
		{
			// ������Ϲ���һ��
		case SB_LINEUP:
			n++;
			break;
			// ������¹���һ��
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
			// ������Ϲ���һ��
		case SB_LINEUP:
			n++;
			break;
			// ������¹���һ��
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
			// ������Ϲ���һ��
		case SB_LINEUP:
			n++;
			break;
			// ������¹���һ��
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
			// ������Ϲ���һ��
		case SB_LINEUP:
			n++;
			break;
			// ������¹���һ��
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CDlgPOM::OnBnClickedButtonShutdown()
{
	// TODO:  �رոô���(�ֲֶ�������Dialog)
	EndDialog(IDCANCEL);
}
