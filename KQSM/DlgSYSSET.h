#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CDlgSYSSET 对话框

class CDlgSYSSET : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgSYSSET)

public:
	CDlgSYSSET(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgSYSSET();

// 对话框数据
	enum { IDD = IDD_DIALOG_SYSSET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	
	// 端口号
	CEdit m_PORT;
	// BrokerID
	CEdit m_BROKERID;
	// 用户名
	CEdit m_USERNAME;
	// 密码
	CEdit m_PASSWORD;
	// IP地址
	CIPAddressCtrl m_IPADDRESS;
	afx_msg void OnBnClickedButtonConnect();
	afx_msg void OnBnClickedButtonShutdown();
};
