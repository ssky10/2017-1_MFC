#pragma once


// CEditNum ��ȭ �����Դϴ�.

class CEditNum : public CDialogEx
{
	DECLARE_DYNAMIC(CEditNum)

public:
	CEditNum(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CEditNum();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EDITNUM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString mNum;
};
