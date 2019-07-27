#pragma once
#include "afxwin.h"


// CTextDlg 대화 상자입니다.

class CTextDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTextDlg)

public:
	CTextDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CTextDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEXT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString mText;
	CListBox Lb;
	CComboBox Cb;
	int a, b;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
