#pragma once
#include "afxwin.h"


// CDlgUSM �Ի���

class CDlgUSM : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgUSM)

public:
	CDlgUSM(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgUSM();

// �Ի�������
	enum { IDD = IDD_DIALOG_USM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	//������ݼ��б�
	HACCEL m_hAccelTable;

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonSave();
	afx_msg void OnBnClickedRadioSub21();
	afx_msg void OnBnClickedRadioSub22();
	afx_msg void OnBnClickedRadioSub2();
	afx_msg void OnBnClickedRadioSub1();
	afx_msg void OnBnClickedRadioRevoke2();
	afx_msg void OnBnClickedRadioRevoke1();
	// ��ʱ������
	CEdit m_REVOKESEC;
	// ��������ѡ�����_RADIOBUTTON
	CButton m_RADIO_REVOKE;
	// �����ɹ������������á�ѡ�����_RADIOBUTTON
	CButton m_RADIO_REVOKESUB;
	// �ط�ί��ѡ�����ñ���_RADIOBUTTON
	CButton m_RADIO_REVOKESUB2;
	// �����ɹ�������������_�ط�ί��_����ί�м۸�ƫ�Ƶ�
	CEdit m_REVOKESUB_NEWPOINT;
	// �����ɹ�������������_�ط�ί��_ԭί�м۸�ƫ�Ƶ�
	CEdit m_REVOKESUB_OLDPOINT;
};
