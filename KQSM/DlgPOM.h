#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CDlgPOM 对话框

class CDlgPOM : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgPOM)

public:
	CDlgPOM(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgPOM();

// 对话框数据
	enum { IDD = IDD_DIALOG_POM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 止损价
	CEdit m_ZHISUN;
	// 止盈价
	CEdit m_ZHIYING;
	// 浮动止损
	CEdit m_FLOATZHISUN;
	// 数量
	CEdit m_NUMBER;
	// 表单LIST
	CListCtrl m_LIST;
	// 有效期
	CComboBox m_VALID;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBnClickedButtonEdit();
	afx_msg void OnBnClickedButtonShutdown();
};
