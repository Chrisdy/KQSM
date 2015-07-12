
// KQSMView.cpp : CKQSMView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "KQSM.h"
#endif

#include "KQSMDoc.h"
#include "KQSMView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CKQSMView

IMPLEMENT_DYNCREATE(CKQSMView, CView)

BEGIN_MESSAGE_MAP(CKQSMView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CKQSMView ����/����

CKQSMView::CKQSMView()
{
	// TODO:  �ڴ˴���ӹ������

}

CKQSMView::~CKQSMView()
{
}

BOOL CKQSMView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CKQSMView ����

void CKQSMView::OnDraw(CDC* /*pDC*/)
{
	CKQSMDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CKQSMView ��ӡ

BOOL CKQSMView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CKQSMView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CKQSMView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// CKQSMView ���

#ifdef _DEBUG
void CKQSMView::AssertValid() const
{
	CView::AssertValid();
}

void CKQSMView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CKQSMDoc* CKQSMView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKQSMDoc)));
	return (CKQSMDoc*)m_pDocument;
}
#endif //_DEBUG


// CKQSMView ��Ϣ�������
