// DlgQO.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "KQSM.h"
#include "DlgQO.h"
#include "afxdialogex.h"


// CDlgQO �Ի���

IMPLEMENT_DYNAMIC(CDlgQO, CDialogEx)

CDlgQO::CDlgQO(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgQO::IDD, pParent)
{
	//��ݼ��б��ʼ��
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


// CDlgQO ��Ϣ�������


void CDlgQO::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CDialogEx::OnTimer(nIDEvent);

	CEdit* cEditCapital;
	cEditCapital = (CEdit*)GetDlgItem(IDC_EDIT_CAPITAL);
	CString oldCapital;
	cEditCapital->GetWindowTextW(oldCapital);

	//CString to int
	int capital = _ttoi(oldCapital);
	//�����ʽ���ʾ����
	SetDlgItemInt(IDC_EDIT_CAPITAL, --capital);
	/*
	��һ��������ʾ���ݵķ�ʽ����Edit Control����һ������m_Capital���޸���ֵ����ʾ
	CString curCapital;
	curCapital.Format(_T("%d"), capital);
	m_Capital.SetWindowTextW(curCapital);
	*/

	//���ÿɿ���d_kekaiҪʵʱ��ȡ
	double d_kekai = 101.0;
	CString temp_kekai;
	temp_kekai.Format(_T("%.2lf"), d_kekai);
	SetDlgItemTextW(IDC_EDIT_KEKAI, temp_kekai);

	//����Ҫ����d_yaokaiҪʵʱ��ȡ
	double d_yaokai = 201.0;
	CString temp_yaokai;
	temp_yaokai.Format(_T("%.2lf"), d_yaokai);
	SetDlgItemTextW(IDC_EDIT_YAOKAI, temp_yaokai);

	//������ۣ�d_costҪʵʱ��ȡ
	double d_cost = 301.0;
	CString temp_cost;
	temp_cost.Format(_T("%.2lf"), d_cost);
	SetDlgItemTextW(IDC_EDIT_BUYPRICE, temp_cost);

	//�������ۣ�d_priceҪʵʱ��ȡ
	double d_price = 401.0;
	CString temp_price;
	temp_price.Format(_T("%.2lf"), d_price);
	SetDlgItemTextW(IDC_EDIT_SELLPRICE, temp_price);
}


BOOL CDlgQO::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//�����ʽ�ı���,�ⲿ�ṩ����
	int capital;
	//����Ϊ1000
	capital = 1000;
	CString capitalStr;
	capitalStr.Format(_T("%d"), capital);
	SetDlgItemInt(IDC_EDIT_CAPITAL, capital);
	//m_Capital.SetWindowTextW(capitalStr);


	//���ÿɿ����ݣ���ȡ��ʼֵ
	double d_kekai = 100.0;
	CString temp_kekai;
	temp_kekai.Format(_T("%.2lf"), d_kekai);
	SetDlgItemTextW(IDC_EDIT_KEKAI, temp_kekai);

	//����Ҫ�����ݣ���ȡ��ʼֵ
	double d_yaokai = 200.0;
	CString temp_yaokai;
	temp_yaokai.Format(_T("%.2lf"), d_yaokai);
	SetDlgItemTextW(IDC_EDIT_YAOKAI, temp_yaokai);

	//����������ݣ���ȡ��ʼֵ
	double d_cost = 300.0;
	CString temp_cost;
	temp_cost.Format(_T("%.2lf"), d_cost);
	SetDlgItemTextW(IDC_EDIT_BUYPRICE, temp_cost);

	//�����������ݣ���ȡ��ʼֵ
	double d_price = 400.0;
	CString temp_price;
	temp_price.Format(_T("%.2lf"), d_price);
	SetDlgItemTextW(IDC_EDIT_SELLPRICE, temp_price);

	//�趨��ʱ��
	SetTimer(1, 1000, NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}


void CDlgQO::OnCbnSelchangeComboContract()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	// TODO:������
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

	//Ϊ�˷�ֹ��ʹ���������ʱ��������ݼ��޷�ʹ�õ�����
	(CButton*)GetDlgItem(IDC_BUTTON_VARIETY1)->SetFocus();
}


void CDlgQO::OnBnClickedButtonVariety1()
{
	// TODO: ʵ��7.Ʒ��һ�Ĺ���
	MessageBox(_T("Hello,7.Ʒ��1"));
}


void CDlgQO::OnBnClickedButtonVariety2()
{
	// TODO: ʵ��8.Ʒ�ֶ��Ĺ���
	MessageBox(_T("Hello,8.Ʒ��2"));
}


void CDlgQO::OnBnClickedButtonVariety3()
{
	// TODO: ʵ��9.Ʒ�����Ĺ���
	MessageBox(_T("Hello,9.Ʒ��3"));
}


void CDlgQO::OnBnClickedButtonSell1()
{
	// TODO: ʵ�ְ�ť1�����Ĺ���
	MessageBox(_T("Hello��1����"));
}


void CDlgQO::OnBnClickedButtonSell2()
{
	// TODO: ʵ�ְ�ť2�����Ĺ���
	MessageBox(_T("Hello��2����"));
}


void CDlgQO::OnBnClickedButtonSell3()
{
	// TODO: ʵ�ְ�ť3�����Ĺ���
	MessageBox(_T("Hello��3����"));
}


void CDlgQO::OnBnClickedButtonBuy1()
{
	// TODO:ʵ�ְ�ť1����Ĺ���
	MessageBox(_T("Hello��1����"));
}


void CDlgQO::OnBnClickedButtonBuy2()
{
	// TODO: ʵ�ְ�ť2����Ĺ���
	MessageBox(_T("Hello��2����"));
}


void CDlgQO::OnBnClickedButtonBuy3()
{
	// TODO: ʵ�ְ�ť3����Ĺ���
	MessageBox(_T("Hello��3����"));
}


void CDlgQO::OnBnClickedButtonRegularorder()
{
	// TODO: ʵ��0.ѡ�񳣹浥���Ĺ���
	MessageBox(_T("Hello,0.ѡ�񳣹浥��"));
}


void CDlgQO::OnBnClickedButtonAnomalycontrol()
{
	// TODO: ʵ��.�쳣���ƵĹ���
	MessageBox(_T("Hello,.�쳣����"));
}


void CDlgQO::OnBnClickedButtonSubtract()
{
	// TODO: ʵ�ּ��ֵĹ���
	MessageBox(_T("Hello,-.����"));
}


void CDlgQO::OnBnClickedButtonAdd()
{
	// TODO: ʵ�ּӲֵĹ���
	MessageBox(_T("Hello,+.�Ӳ�"));
}


void CDlgQO::OnBnClickedButtonEnter()
{
	// TODO: ʵ��Enter�Ĺ���
	MessageBox(_T("Hello,Enter"));
}


BOOL CDlgQO::PreTranslateMessage(MSG* pMsg)
{
	// TODO:  �ڴ����ר�ô����/����û���
	//��ݼ���Ϣ����
	if (m_hAccelTable)
	{
		if (::TranslateAccelerator(m_hWnd, m_hAccelTable, pMsg))
		{
			return(TRUE);
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
