// DlgUSM.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "KQSM.h"
#include "DlgUSM.h"
#include "afxdialogex.h"


// CDlgUSM �Ի���

IMPLEMENT_DYNAMIC(CDlgUSM, CDialogEx)

CDlgUSM::CDlgUSM(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgUSM::IDD, pParent)
{
	//��ݼ��б��ʼ��
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


// CDlgUSM ��Ϣ�������

BOOL CDlgUSM::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_REVOKESEC.EnableWindow(FALSE);
	m_REVOKESUB_OLDPOINT.EnableWindow(FALSE);
	m_REVOKESUB_NEWPOINT.EnableWindow(FALSE);
	m_RADIO_REVOKE.SetCheck(TRUE);
	m_RADIO_REVOKESUB.SetCheck(TRUE);
	//m_RADIO_REVOKESUB2.SetCheck(TRUE);

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CButton *bn1 = (CButton *)this->GetDlgItem(IDC_RADIO_SUB2_1);
	bn1->EnableWindow(FALSE);
	CButton *bn2 = (CButton *)this->GetDlgItem(IDC_RADIO_SUB2_2);
	bn2->EnableWindow(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}

BOOL CDlgUSM::PreTranslateMessage(MSG* pMsg)
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

//�������
void CDlgUSM::OnBnClickedButtonStart()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	MessageBox(_T("R")); 
}

//��������
void CDlgUSM::OnBnClickedButtonSave()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	MessageBox(_T("S"));
}

//����ί�м۸�
void CDlgUSM::OnBnClickedRadioSub21()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_REVOKESUB_NEWPOINT.EnableWindow(TRUE);
	m_REVOKESUB_OLDPOINT.EnableWindow(FALSE);
}

//ԭί�м۸�
void CDlgUSM::OnBnClickedRadioSub22()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_REVOKESUB_NEWPOINT.EnableWindow(FALSE);
	m_REVOKESUB_OLDPOINT.EnableWindow(TRUE);
}

//�ط�ί��
void CDlgUSM::OnBnClickedRadioSub2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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

//�޲���
void CDlgUSM::OnBnClickedRadioSub1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_REVOKESUB_NEWPOINT.EnableWindow(FALSE);
	m_REVOKESUB_OLDPOINT.EnableWindow(FALSE);

	CButton *bn1 = (CButton *)this->GetDlgItem(IDC_RADIO_SUB2_1);
	CButton *bn2 = (CButton *)this->GetDlgItem(IDC_RADIO_SUB2_2);
	bn1->EnableWindow(FALSE);
	bn2->EnableWindow(FALSE);
	m_RADIO_REVOKESUB2.SetCheck(FALSE);
}

//��ʱ����
void CDlgUSM::OnBnClickedRadioRevoke2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_REVOKESEC.EnableWindow(TRUE);
}

//���ɽ�������
void CDlgUSM::OnBnClickedRadioRevoke1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	m_REVOKESEC.EnableWindow(FALSE);
}