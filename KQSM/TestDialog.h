#pragma once
#include "afxcmn.h"


// TestDialog �Ի���

class TestDialog : public CDialogEx
{
	DECLARE_DYNAMIC(TestDialog)

public:
	TestDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TestDialog();

// �Ի�������
	enum { IDD = IDD_DIALOG_TEST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedWizfinish();
	virtual BOOL OnInitDialog();
	CListCtrl m_SpiMessage;
	afx_msg void OnLvnItemchangedListTestMessage(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButtonLoginin();
};
