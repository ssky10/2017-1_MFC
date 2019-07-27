// Info.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "DD.h"
#include "Info.h"
#include "afxdialogex.h"


// CInfo ��ȭ �����Դϴ�.

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


// CInfo �޽��� ó�����Դϴ�.


BOOL CInfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	for (int i = 0; i < 100; i++) {
		CString s;
		s.Format(L"%d", i+1);
		mCtrlAge.InsertString(i, s);
	}
	mCtrlAge.SetCurSel(23);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
