#pragma once
#include "afxwin.h"


// CTextDlg ��ȭ �����Դϴ�.

class CTextDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTextDlg)

public:
	CTextDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CTextDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEXT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString mText;
	CListBox Lb;
	CComboBox Cb;
	int a, b;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
