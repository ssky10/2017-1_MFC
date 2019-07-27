// Info.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "DD.h"
#include "Info.h"
#include "afxdialogex.h"


extern CString Addr1[4], Addr2[4][5], Addr3[4][5][6];
extern int Addr1Cnt, Addr2Cnt[4], Addr3Cnt[4][5];

// CInfo ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CInfo, CDialogEx)

CInfo::CInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_INFO, pParent)
	, mName(_T(""))
	, mMarried(0)
	, mSex(0)
	, mClimb(0)
	, mBike(0)
	, mFish(0)
	, mGame(0)
	, mRead(0)
	, mWeb(0)
	, mAddr1(0)
	, mAddr2(0)
	, mAddr3(0)
	, mAge(23)
	, mTel(_T(""))
{

}

CInfo::~CInfo()
{
}

void CInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_AGE, mCtrlAge);
	DDX_Text(pDX, IDC_NAME, mName);
	DDX_Text(pDX, IDC_ADDR4, mAddr4);
	DDX_Radio(pDX, IDC_SINGLE, mMarried);
	DDX_Radio(pDX, IDC_MALE, mSex);
	DDX_Radio(pDX, IDC_ZERO, mKids);
	DDX_Check(pDX, IDC_CLIMB, mClimb);
	DDX_Check(pDX, IDC_BIKE, mBike);
	DDX_Check(pDX, IDC_FISH, mFish);
	DDX_Check(pDX, IDC_GAME, mGame);
	DDX_Check(pDX, IDC_READ, mRead);
	DDX_Check(pDX, IDC_WEB, mWeb);
	DDX_Text(pDX, IDC_TEL, mTel);
	DDX_Control(pDX, IDC_ADDR1, mCtrlAddr1);
	DDX_Control(pDX, IDC_ADDR2, mCtrlAddr2);
	DDX_Control(pDX, IDC_ADDR3, mCtrlAddr3);
}


BEGIN_MESSAGE_MAP(CInfo, CDialogEx)
	ON_LBN_SELCHANGE(IDC_ADDR1, &CInfo::OnSelchangeAddr1)
	ON_LBN_SELCHANGE(IDC_ADDR2, &CInfo::OnSelchangeAddr2)
	ON_BN_CLICKED(IDC_SINGLE, &CInfo::OnClickedSingle)
	ON_COMMAND(IDC_DOUBLE, &CInfo::OnDouble)
	ON_BN_CLICKED(IDOK, &CInfo::OnBnClickedOk)
END_MESSAGE_MAP()


// CInfo �޽��� ó�����Դϴ�.


BOOL CInfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CString S;
	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	for (int i = 0; i < Addr1Cnt; i++) {
		S.Format(L"%s, %d", Addr1[i], sizeof(Addr1[i]));
		mCtrlAddr1.InsertString(i, S);
	}
	mCtrlAddr1.SetCurSel(mAddr1);

	for (int i = 0; i < Addr2Cnt[0]; i++) {
		S.Format(L"%s, %d", Addr2[0][i], sizeof(Addr2[0][i]));
		mCtrlAddr2.InsertString(i, S);
	}
	mCtrlAddr2.SetCurSel(mAddr2);

	for (int i = 0; i < Addr3Cnt[0][0]; i++)
		mCtrlAddr3.InsertString(i, Addr3[0][0][i]);
	mCtrlAddr3.SetCurSel(mAddr3);

	for (int i = 0; i < 100; i++) {
		CString s;
		s.Format(L"%d", i+1);
		mCtrlAge.InsertString(i, s);
	}
	mCtrlAge.SetCurSel(mAge);

	if(mMarried==0)
		EnableKids(false);	

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CInfo::OnSelchangeAddr1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int idx = mCtrlAddr1.GetCurSel();

	mCtrlAddr2.ResetContent();

	for (int i = 0; i < Addr2Cnt[idx]; i++)
		mCtrlAddr2.InsertString(i, Addr2[idx][i]);
	mCtrlAddr2.SetCurSel(0);

	DispAddr3(idx, 0);
}


void CInfo::OnSelchangeAddr2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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


void CInfo::OnClickedSingle()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	EnableKids(false);
}


void CInfo::OnDouble()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	EnableKids(true);
}


void CInfo::EnableKids(bool flag)
{
	for (int i = 0; i < 4; i++) {
		(CButton*)GetDlgItem(IDC_ZERO + i)->EnableWindow(flag);
	}
}


void CInfo::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	mAddr1 = mCtrlAddr1.GetCurSel();
	mAddr2 = mCtrlAddr2.GetCurSel();
	mAddr3 = mCtrlAddr3.GetCurSel();
	mAge = mCtrlAge.GetCurSel();
	CDialogEx::OnOK();
}
