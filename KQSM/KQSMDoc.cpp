
// KQSMDoc.cpp : CKQSMDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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


// CKQSMDoc 构造/析构

CKQSMDoc::CKQSMDoc()
{
	// TODO:  在此添加一次性构造代码

}

CKQSMDoc::~CKQSMDoc()
{
}

BOOL CKQSMDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO:  在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CKQSMDoc 序列化

void CKQSMDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO:  在此添加存储代码
	}
	else
	{
		// TODO:  在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CKQSMDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
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

// 搜索处理程序的支持
void CKQSMDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
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

// CKQSMDoc 诊断

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


// CKQSMDoc 命令


void CKQSMDoc::OnTest()
{
	// TODO:  在此添加命令处理程序代码
	TestDialog testDialog;
	testDialog.DoModal();
}


void CKQSMDoc::OnMenuQo()
{
	// TODO:  在此添加命令处理程序代码
	CDlgQO qoDlg;
	qoDlg.DoModal();
}


void CKQSMDoc::OnMenuPom()
{
	// TODO:  在此添加命令处理程序代码
	CDlgPOM pomDlg;
	pomDlg.DoModal();
}


void CKQSMDoc::OnMenuSysset()
{
	// TODO:  在此添加命令处理程序代码
	CDlgSYSSET syssetDlg;
	syssetDlg.DoModal();
}


void CKQSMDoc::OnUsm()
{
	// TODO:  在此添加命令处理程序代码
	CDlgUSM usmDlg;
	usmDlg.DoModal();
}
