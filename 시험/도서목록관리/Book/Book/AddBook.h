#pragma once
#include "afxwin.h"


// CAddBook ��ȭ �����Դϴ�.

class CAddBook : public CDialogEx
{
	DECLARE_DYNAMIC(CAddBook)

public:
	CAddBook(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CAddBook();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ADD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
