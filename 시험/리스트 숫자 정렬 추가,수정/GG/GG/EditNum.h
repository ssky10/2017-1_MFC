#pragma once


// CEditNum 대화 상자입니다.

class CEditNum : public CDialogEx
{
	DECLARE_DYNAMIC(CEditNum)

public:
	CEditNum(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CEditNum();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EDITNUM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString mNum;
};
