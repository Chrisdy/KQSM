
// KQSMDoc.cpp : CKQSMDoc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "KQSM.h"
#endif

#include "KQSMDoc.h"

#include <propkey.h>
#include "TestDialog.h"
#include "DlgQO.h"
#include "DlgPOM.h"
#include "DlgSYSSET.h"
#include "DlgUSM.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CKQSMDoc

IMPLEMENT_DYNCREATE(CKQSMDoc, CDocument)

BEGIN_MESSAGE_MAP(CKQSMDoc, CDocument)
	ON_COMMAND(ID_TEST, &CKQSMDoc::OnTest)
	ON_COMMAND(ID_MENU_QO, &CKQSMDoc::OnMenuQo)
	ON_COMMAND(ID_MENU_POM, &CKQSMDoc::OnMenuPom)
	ON_COMMAND(ID_MENU_SYSSET, &CKQSMDoc::OnMenuSysset)
	ON_COMMAND(ID_USM, &CKQSMDoc::OnUsm)
END_MESSAGE_MAP()


// CKQSMDoc ����/����

CKQSMDoc::CKQSMDoc()
{
	// TODO:  �ڴ����һ���Թ������

}

CKQSMDoc::~CKQSMDoc()
{
}

BOOL CKQSMDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO:  �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// CKQSMDoc ���л�

void CKQSMDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO:  �ڴ���Ӵ洢����
	}
	else
	{
		// TODO:  �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void CKQSMDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void CKQSMDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:     strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void CKQSMDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CKQSMDoc ���

#ifdef _DEBUG
void CKQSMDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CKQSMDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CKQSMDoc ����


void CKQSMDoc::OnTest()
{
	// TODO:  �ڴ���������������
	TestDialog testDialog;
	testDialog.DoModal();
}


void CKQSMDoc::OnMenuQo()
{
	// TODO:  �ڴ���������������
	CDlgQO qoDlg;
	qoDlg.DoModal();
}


void CKQSMDoc::OnMenuPom()
{
	// TODO:  �ڴ���������������
	CDlgPOM pomDlg;
	pomDlg.DoModal();
}


void CKQSMDoc::OnMenuSysset()
{
	// TODO:  �ڴ���������������
	CDlgSYSSET syssetDlg;
	syssetDlg.DoModal();
}


void CKQSMDoc::OnUsm()
{
	// TODO:  �ڴ���������������
	CDlgUSM usmDlg;
	usmDlg.DoModal();
}
