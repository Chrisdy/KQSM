#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CDlgSYSSET �Ի���

class CDlgSYSSET : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgSYSSET)

public:
	CDlgSYSSET(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgSYSSET();

// �Ի�������
	enum { IDD = IDD_DIALOG_SYSSET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	
	// �˿ں�
	CEdit m_PORT;
	// BrokerID
	CEdit m_BROKERID;
	// �û���
	CEdit m_USERNAME;
	// ����
	CEdit m_PASSWORD;
	// IP��ַ
	CIPAddressCtrl m_IPADDRESS;
	afx_msg void OnBnClickedButtonConnect();
	afx_msg void OnBnClickedButtonShutdown();
};
