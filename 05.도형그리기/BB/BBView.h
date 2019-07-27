
// BBView.h : CBBView 클래스의 인터페이스
//

#pragma once

typedef struct {
	int x1, y1;
} FREELINE;


typedef struct {
	int x1, y1, x2, y2;
	FREELINE* line;
	int type;
} PT;

class CBBView : public CView
{
protected: // serialization에서만 만들어집니다.
	CBBView();
	DECLARE_DYNCREATE(CBBView)

// 특성입니다.
public:
	CBBDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CBBView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnEllipse();
	afx_msg void OnFree();
	afx_msg void OnLine();
	afx_msg void OnRect();

	PT pt[1000];
	int pt_cnt;
	FREELINE tmp_pt[10000];
	int tmp_pt_cnt;
	int type;
	int x1, y1, x2, y2;

	void DrawPT(CDC* p);

	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnUpdateEllipse(CCmdUI *pCmdUI);
	afx_msg void OnUpdateFree(CCmdUI *pCmdUI);
	afx_msg void OnUpdateLine(CCmdUI *pCmdUI);
	afx_msg void OnUpdateRect(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // BBView.cpp의 디버그 버전
inline CBBDoc* CBBView::GetDocument() const
   { return reinterpret_cast<CBBDoc*>(m_pDocument); }
#endif

