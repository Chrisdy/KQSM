
// KQSMView.h : CKQSMView ��Ľӿ�
//

#pragma once


class CKQSMView : public CView
{
protected: // �������л�����
	CKQSMView();
	DECLARE_DYNCREATE(CKQSMView)

// ����
public:
	CKQSMDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CKQSMView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // KQSMView.cpp �еĵ��԰汾
inline CKQSMDoc* CKQSMView::GetDocument() const
   { return reinterpret_cast<CKQSMDoc*>(m_pDocument); }
#endif

