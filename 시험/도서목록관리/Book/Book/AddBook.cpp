// AddBook.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Book.h"
#include "AddBook.h"
#include "afxdialogex.h"


// CAddBook ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CAddBook, CDialogEx)

CAddBook::CAddBook(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ADD, pParent)
	, mLag(0)
	, mList(0)
	, mName(_T(""))
	, mPay(_T(""))
{

}

CAddBook::~CAddBook()
{
}

void CAddBook::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_KOR, mLag);
	DDX_Control(pDX, IDC_LIST1, mCtrlList);
	DDX_LBIndex(pDX, IDC_LIST1, mList);
	DDX_Text(pDX, IDC_NAME, mName);
	DDX_Text(pDX, IDC_PAY, mPay);
}


BEGIN_MESSAGE_MAP(CAddBook, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAddBook::OnBnClickedOk)
END_MESSAGE_MAP()


// CAddBook �޽��� ó�����Դϴ�.


void CAddBook::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (mName == "") {
		MessageBox(L"å�̸��� �Է��ϼ���.");
		return;
	}
	CDialogEx::OnOK();
}


BOOL CAddBook::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CString S;
	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	for (int i = 0; i < 7; i++) {
		S.Format(L"���ǻ�%d", i+1);
		mCtrlList.InsertString(i, S);		
	}
	mCtrlList.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
