// TextDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "CC.h"
#include "TextDlg.h"
#include "afxdialogex.h"


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
	DDX_Text(pDX, IDC_EDIT1, mText);
}


BEGIN_MESSAGE_MAP(CTextDlg, CDialogEx)
END_MESSAGE_MAP()


// CTextDlg �޽��� ó�����Դϴ�.
