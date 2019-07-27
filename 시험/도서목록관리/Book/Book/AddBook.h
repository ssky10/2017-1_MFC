#pragma once
#include "afxwin.h"


// CAddBook 대화 상자입니다.

class CAddBook : public CDialogEx
{
	DECLARE_DYNAMIC(CAddBook)

public:
	CAddBook(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CAddBook();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int mLag;
	CListBox mCtrlList;
	int mList;
	CString mName;
	CString mPay;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
