#pragma once
#include "afxwin.h"


// CDlgUSM 对话框

class CDlgUSM : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgUSM)

public:
	CDlgUSM(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgUSM();

// 对话框数据
	enum { IDD = IDD_DIALOG_USM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	//声明快捷键列表
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
	// 延时的秒数
	CEdit m_REVOKESEC;
	// 撤单设置选项变量_RADIOBUTTON
	CButton m_RADIO_REVOKE;
	// 撤单成功后续处理设置—选项变量_RADIOBUTTON
	CButton m_RADIO_REVOKESUB;
	// 重发委托选项设置变量_RADIOBUTTON
	CButton m_RADIO_REVOKESUB2;
	// 撤单成功后续处理设置_重发委托_最新委托价格偏移点
	CEdit m_REVOKESUB_NEWPOINT;
	// 撤单成功后续处理设置_重发委托_原委托价格偏移点
	CEdit m_REVOKESUB_OLDPOINT;
};
