
// MFC_0View.h : CMFC_0View 클래스의 인터페이스
//

#pragma once


class CMFC_0View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMFC_0View();
	DECLARE_DYNCREATE(CMFC_0View)

// 특성입니다.
public:
	CMFC_0Doc* GetDocument() const;

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
	virtual ~CMFC_0View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	// 윈도우 창의 크기나타내 주는 문자열
	CString m_strWindowSize;
	// 마우스나 키보드의 상태 문자열
	CString m_strOutText;
	// 마우스 드래그 여부(왼쪽 마우스 키) 체크
	bool m_bDrag;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC_0View.cpp의 디버그 버전
inline CMFC_0Doc* CMFC_0View::GetDocument() const
   { return reinterpret_cast<CMFC_0Doc*>(m_pDocument); }
#endif

