#pragma once
#include "afxwin.h"


// CInfo 대화 상자입니다.

class CInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CInfo)

public:
	CInfo(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CInfo();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INFO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
