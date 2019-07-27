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
