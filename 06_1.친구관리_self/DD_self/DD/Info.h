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
	CString mName;
	CString mAddr4;
	CString mTel;
	int mAge;
};
