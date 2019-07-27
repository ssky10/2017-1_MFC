// Info.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "DD.h"
#include "Info.h"
#include "afxdialogex.h"


// CInfo 대화 상자입니다.

IMPLEMENT_DYNAMIC(CInfo, CDialogEx)

CInfo::CInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_INFO, pParent)
	, mName(_T(""))
	, mAddr4(_T(""))
	, mTel(_T(""))
	, mAge(0)
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
	DDX_Text(pDX, IDC_TEL, mTel);
	DDX_CBIndex(pDX, IDC_AGE, mAge);
}


BEGIN_MESSAGE_MAP(CInfo, CDialogEx)
END_MESSAGE_MAP()


// CInfo 메시지 처리기입니다.


BOOL CInfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	for (int i = 0; i < 100; i++) {
		CString s;
		s.Format(L"%d", i+1);
		mCtrlAge.InsertString(i, s);
	}
	mCtrlAge.SetCurSel(23);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
