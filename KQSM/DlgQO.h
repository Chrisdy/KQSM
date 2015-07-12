#pragma once


// CDlgQO 对话框

class CDlgQO : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgQO)

public:
	CDlgQO(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgQO();

// 对话框数据
	enum { IDD = IDD_DIALOG_QO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	//声明快捷键列表
	HACCEL m_hAccelTable;

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeComboContract();
	afx_msg void OnBnClickedButtonVariety1();
	afx_msg void OnBnClickedButtonVariety2();
	afx_msg void OnBnClickedButtonVariety3();
	afx_msg void OnBnClickedButtonSell1();
	afx_msg void OnBnClickedButtonSell2();
	afx_msg void OnBnClickedButtonSell3();
	afx_msg void OnBnClickedButtonBuy1();
	afx_msg void OnBnClickedButtonBuy2();
	afx_msg void OnBnClickedButtonBuy3();
	afx_msg void OnBnClickedButtonRegularorder();
	afx_msg void OnBnClickedButtonAnomalycontrol();
	afx_msg void OnBnClickedButtonSubtract();
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonEnter();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
