
// GGView.h : CGGView Ŭ������ �������̽�
//

#pragma once
#include "afxwin.h"


class CGGView : public CFormView
{
protected: // serialization������ ��������ϴ�.
	CGGView();
	DECLARE_DYNCREATE(CGGView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_GG_FORM };
#endif

// Ư���Դϴ�.
public:
	CGGDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~CGGView();
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
	CListBox Lb;
};

#ifndef _DEBUG  // GGView.cpp�� ����� ����
inline CGGDoc* CGGView::GetDocument() const
   { return reinterpret_cast<CGGDoc*>(m_pDocument); }
#endif

