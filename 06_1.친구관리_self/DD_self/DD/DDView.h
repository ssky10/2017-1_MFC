
// DDView.h : CDDView Ŭ������ �������̽�
//

#pragma once
#include "afxwin.h"


class CDDView : public CFormView
{
protected: // serialization������ ��������ϴ�.
	CDDView();
	DECLARE_DYNCREATE(CDDView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_DD_FORM };
#endif

// Ư���Դϴ�.
public:
	CDDDoc* GetDocument() const;

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
	virtual ~CDDView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedInsert();
	CListBox mCtrlList;
};

#ifndef _DEBUG  // DDView.cpp�� ����� ����
inline CDDDoc* CDDView::GetDocument() const
   { return reinterpret_cast<CDDDoc*>(m_pDocument); }
#endif

