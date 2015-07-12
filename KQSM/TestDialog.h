#pragma once
#include "afxcmn.h"


// TestDialog 对话框

class TestDialog : public CDialogEx
{
	DECLARE_DYNAMIC(TestDialog)

public:
	TestDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TestDialog();

// 对话框数据
	enum { IDD = IDD_DIALOG_TEST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedWizfinish();
	virtual BOOL OnInitDialog();
	CListCtrl m_SpiMessage;
	afx_msg void OnLvnItemchangedListTestMessage(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButtonLoginin();
};
