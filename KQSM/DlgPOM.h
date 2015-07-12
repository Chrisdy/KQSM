#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CDlgPOM �Ի���

class CDlgPOM : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgPOM)

public:
	CDlgPOM(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgPOM();

// �Ի�������
	enum { IDD = IDD_DIALOG_POM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	// ֹ���
	CEdit m_ZHISUN;
	// ֹӯ��
	CEdit m_ZHIYING;
	// ����ֹ��
	CEdit m_FLOATZHISUN;
	// ����
	CEdit m_NUMBER;
	// ��LIST
	CListCtrl m_LIST;
	// ��Ч��
	CComboBox m_VALID;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBnClickedButtonEdit();
	afx_msg void OnBnClickedButtonShutdown();
};
