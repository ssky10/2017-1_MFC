// EditNum.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "GG.h"
#include "EditNum.h"
#include "afxdialogex.h"


// CEditNum ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CEditNum, CDialogEx)

CEditNum::CEditNum(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_EDITNUM, pParent)
	, mNum(_T(""))
{

}

CEditNum::~CEditNum()
{
}

void CEditNum::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, mNum);
}


BEGIN_MESSAGE_MAP(CEditNum, CDialogEx)
END_MESSAGE_MAP()


// CEditNum �޽��� ó�����Դϴ�.
