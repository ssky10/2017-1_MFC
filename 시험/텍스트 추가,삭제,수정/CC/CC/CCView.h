
// CCView.h : CCCView Ŭ������ �������̽�
//

#pragma once


class CCCView : public CView
{
protected: // serialization������ ��������ϴ�.
	CCCView();
	DECLARE_DYNCREATE(CCCView)

// Ư���Դϴ�.
public:
	CCCDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CCCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);

public:
	int GetIdx4Insert(CCCDoc* p);
	void DispFr(FR *f, CDC* p);
	int SerchText(CPoint xy);
	afx_msg void OnDestroy();
	virtual void OnInitialUpdate();
};

#ifndef _DEBUG  // CCView.cpp�� ����� ����
inline CCCDoc* CCCView::GetDocument() const
   { return reinterpret_cast<CCCDoc*>(m_pDocument); }
#endif

