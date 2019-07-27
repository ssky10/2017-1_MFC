
// DDView.h : CDDView Ŭ������ �������̽�
//

#pragma once
#include "afxwin.h"
#include "Info.h"


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
	virtual void Invalidate();

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

#ifndef _DEBUG  // DDView.cpp�� ����� ����
inline CDDDoc* CDDView::GetDocument() const
   { return reinterpret_cast<CDDDoc*>(m_pDocument); }
#endif

