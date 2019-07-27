// Info.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "DD.h"
#include "Info.h"
#include "afxdialogex.h"


extern CString Addr1[4], Addr2[4][5], Addr3[4][5][6];
extern int Addr1Cnt, Addr2Cnt[4], Addr3Cnt[4][5];

// CInfo 대화 상자입니다.

IMPLEMENT_DYNAMIC(CInfo, CDialogEx)

CInfo::CInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_INFO, pParent)
	, mName(_T(""))
	, mMarried(0)
	, mSex(0)
{

}

CInfo::~CInfo()
{
}

void CInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_AGE, mCtrlAge);
	DDX_Control(pDX, IDC_ADDR1, mCtrlAddr1);
	DDX_Control(pDX, IDC_ADDR2, mCtrlAddr2);
	DDX_Control(pDX, IDC_ADDR3, mCtrlAddr3);
	DDX_Text(pDX, IDC_NAME, mName);
	DDX_Radio(pDX, IDC_SINGLE, mMarried);
	DDX_Radio(pDX, IDC_MALE, mSex);
	DDX_Control(pDX, IDC_ZERO, mCtrlKids0);
	DDX_Control(pDX, IDC_ONE, mCtrlKids1);
	DDX_Control(pDX, IDC_TWO, mCtrlKids2);
	DDX_Control(pDX, IDC_THREE, mCtrlKids3);
}


BEGIN_MESSAGE_MAP(CInfo, CDialogEx)
	ON_LBN_SELCHANGE(IDC_ADDR1, &CInfo::OnSelchangeAddr1)
	ON_LBN_SELCHANGE(IDC_ADDR2, &CInfo::OnSelchangeAddr2)
END_MESSAGE_MAP()


// CInfo 메시지 처리기입니다.


BOOL CInfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	for (int i = 0; i < Addr1Cnt; i++)
		mCtrlAddr1.InsertString(i, Addr1[i]);
	mCtrlAddr1.SetCurSel(0);

	for (int i = 0; i < Addr2Cnt[0]; i++)
		mCtrlAddr2.InsertString(i, Addr2[0][i]);
	mCtrlAddr2.SetCurSel(0);

	for (int i = 0; i < Addr3Cnt[0][0]; i++)
		mCtrlAddr3.InsertString(i, Addr3[0][0][i]);
	mCtrlAddr3.SetCurSel(0);

	for (int i = 0; i < 100; i++) {
		CString s;
		s.Format(L"%d", i+1);
		mCtrlAge.InsertString(i, s);
	}
	mCtrlAge.SetCurSel(23);

	mCtrlKids0.EnableWindow(false);
	mCtrlKids1.EnableWindow(false);
	mCtrlKids2.EnableWindow(false);
	mCtrlKids3.EnableWindow(false);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CInfo::OnSelchangeAddr1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int idx = mCtrlAddr1.GetCurSel();

	mCtrlAddr2.ResetContent();

	for (int i = 0; i < Addr2Cnt[idx]; i++)
		mCtrlAddr2.InsertString(i, Addr2[idx][i]);
	mCtrlAddr2.SetCurSel(0);

	DispAddr3(idx, 0);
}


void CInfo::OnSelchangeAddr2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int idx1 = mCtrlAddr1.GetCurSel();
	int idx2 = mCtrlAddr2.GetCurSel();

	DispAddr3(idx1, idx2);
}


void CInfo::DispAddr3(int idx1, int idx2)
{
	mCtrlAddr3.ResetContent();

	for (int i = 0; i < Addr3Cnt[idx1][idx2]; i++)
		mCtrlAddr3.InsertString(i, Addr3[idx1][idx2][i]);
	mCtrlAddr3.SetCurSel(0);
}
