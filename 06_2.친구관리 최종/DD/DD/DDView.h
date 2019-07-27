
// DDView.h : CDDView 클래스의 인터페이스
//

#pragma once
#include "afxwin.h"
#include "Info.h"


class CDDView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CDDView();
	DECLARE_DYNCREATE(CDDView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_DD_FORM };
#endif

// 특성입니다.
public:
	CDDDoc* GetDocument() const;

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
	virtual ~CDDView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedInsert();
	CListCtrl mCtrlList;
	int SaveFr(CInfo &d);
	int SaveFr2(CInfo &d, int cnt);
	void DispFr(int cnt);
	void BindAddrStr(CString &s,FR *f);
	char BindHobbyChar(CInfo *d);
	void MakeHobbyStr(CString &s, FR *f);
	void DispFr2(FR *fr, int idx);
	afx_msg void OnDestroy();
	afx_msg void OnClickList(NMHDR *pNMHDR, LRESULT *pResult);
	int idx;
	afx_msg void OnClickedDelete();
	afx_msg void OnBnClickedOpdate();
	int GetIdx4Insert(CDDDoc* p);
	void SetCinfoView(CInfo &c, FR *f);
};

#ifndef _DEBUG  // DDView.cpp의 디버그 버전
inline CDDDoc* CDDView::GetDocument() const
   { return reinterpret_cast<CDDDoc*>(m_pDocument); }
#endif

