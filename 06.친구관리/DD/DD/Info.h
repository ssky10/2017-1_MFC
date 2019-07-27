#pragma once
#include "afxwin.h"


// CInfo ��ȭ �����Դϴ�.

class CInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CInfo)

public:
	CInfo(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CInfo();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CComboBox mCtrlAge;
	CListBox mCtrlAddr1;
	CListBox mCtrlAddr2;
	CListBox mCtrlAddr3;
	CString mName;
	int mMarried;
	int mSex;
//	CStatic mCtrlkids;
	afx_msg void OnSelchangeAddr1();
	afx_msg void OnSelchangeAddr2();
//	afx_msg void OnSelchangeAddr3();
	void DispAddr3(int idx, int cul);
	CButton mCtrlKids0;
	CButton mCtrlKids1;
	CButton mCtrlKids2;
	CButton mCtrlKids3;
};
