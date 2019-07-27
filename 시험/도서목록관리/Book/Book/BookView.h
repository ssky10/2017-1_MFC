
// BookView.h : CBookView Ŭ������ �������̽�
//

#pragma once
#include "afxcmn.h"
#include "AddBook.h"


class CBookView : public CFormView
{
protected: // serialization������ ��������ϴ�.
	CBookView();
	DECLARE_DYNCREATE(CBookView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_BOOK_FORM };
#endif

// Ư���Դϴ�.
public:
	CBookDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.
	virtual void Invalidate();

// �����Դϴ�.
public:
	virtual ~CBookView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
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

#ifndef _DEBUG  // BookView.cpp�� ����� ����
inline CBookDoc* CBookView::GetDocument() const
   { return reinterpret_cast<CBookDoc*>(m_pDocument); }
#endif

