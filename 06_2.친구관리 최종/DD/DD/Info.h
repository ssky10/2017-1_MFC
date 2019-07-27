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

	CString mName;
	CString mTel;
	CString mAddr4;

	int mMarried;
	int mSex;
	int mAddr1;
	int mAddr2;
	int mAddr3;
	int mAge;
	int mKids;
	int mClimb;
	int mBike;
	int mFish;
	int mGame;
	int mRead;
	int mWeb;


	afx_msg void OnSelchangeAddr1();
	afx_msg void OnSelchangeAddr2();
	afx_msg void OnClickedSingle();
	afx_msg void OnDouble();
	afx_msg void OnBnClickedOk();

	void DispAddr3(int idx, int cul);
	void EnableKids(bool flag);
	CListBox mCtrlAddr1;
	CListBox mCtrlAddr2;
	CListBox mCtrlAddr3;
};
