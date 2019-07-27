
// CCView.h : CCCView 클래스의 인터페이스
//

#pragma once


class CCCView : public CView
{
protected: // serialization에서만 만들어집니다.
	CCCView();
	DECLARE_DYNCREATE(CCCView)

// 특성입니다.
public:
	CCCDoc* GetDocument() const;

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
	virtual ~CCCView();
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
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);

public:
	int GetIdx4Insert(CCCDoc* p);
	void DispFr(FR *f, CDC* p);
	int SerchText(CPoint xy);
	afx_msg void OnDestroy();
	virtual void OnInitialUpdate();
};

#ifndef _DEBUG  // CCView.cpp의 디버그 버전
inline CCCDoc* CCCView::GetDocument() const
   { return reinterpret_cast<CCCDoc*>(m_pDocument); }
#endif

