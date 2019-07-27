
// BBView.h : CBBView Ŭ������ �������̽�
//

#pragma once

typedef struct {
	int x1, y1, x2, y2;
} PT;

class CBBView : public CView
{
protected: // serialization������ ��������ϴ�.
	CBBView();
	DECLARE_DYNCREATE(CBBView)

// Ư���Դϴ�.
public:
	CBBDoc* GetDocument() const;

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
	virtual ~CBBView();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	PT pt[1000];
	int pt_cnt;
	void DrawPT(CDC* p);
	void AddPT(PT* p, CPoint xy1, CPoint xy2);
	void DeletePT(PT* p, int num);
	CPoint xy;
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	bool CheckPT(CPoint point, PT xy);
	PT TransPT(int x1, int y1, int x2, int y2);
};

#ifndef _DEBUG  // BBView.cpp�� ����� ����
inline CBBDoc* CBBView::GetDocument() const
   { return reinterpret_cast<CBBDoc*>(m_pDocument); }
#endif

