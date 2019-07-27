
// BookView.h : CBookView 클래스의 인터페이스
//

#pragma once
#include "afxcmn.h"
#include "AddBook.h"


class CBookView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CBookView();
	DECLARE_DYNCREATE(CBookView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_BOOK_FORM };
#endif

// 특성입니다.
public:
	CBookDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual void Invalidate();

// 구현입니다.
public:
	virtual ~CBookView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CListCtrl mCtrlList;
	void SaveFr(CAddBook &d);
	void DispFr();
	void DispFr2(FR *fr, int idx);
	afx_msg void OnDestroy();
};

#ifndef _DEBUG  // BookView.cpp의 디버그 버전
inline CBookDoc* CBookView::GetDocument() const
   { return reinterpret_cast<CBookDoc*>(m_pDocument); }
#endif

