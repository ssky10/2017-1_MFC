// TextDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "BB.h"
#include "TextDlg.h"
#include "afxdialogex.h"

CString pFont[4] = { L"����ü",L"Arial",L"Hobo BT" ,L"Sans Serif" };

// CTextDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CTextDlg, CDialogEx)

CTextDlg::CTextDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TEXT, pParent)
	, mText(_T(""))
{

}

CTextDlg::~CTextDlg()
{
}

void CTextDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TEXT, mText);
	DDX_Control(pDX, IDC_TYPE, Lb);
	DDX_Control(pDX, IDC_SIZE, Cb);
}


BEGIN_MESSAGE_MAP(CTextDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CTextDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CTextDlg �޽��� ó�����Դϴ�.


BOOL CTextDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	CString s;
	for (int i = 0; i < 50; i++) {
		s.Format(L"%d", i + 1);
		Cb.InsertString(i, s);
	}
	for (int i = 0; i < 4; i++)
		Lb.InsertString(i, pFont[i]);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CTextDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	a = Cb.GetCurSel();
	b = Lb.GetCurSel();
	CDialogEx::OnOK();
}
