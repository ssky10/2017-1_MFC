// AddBook.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Book.h"
#include "AddBook.h"
#include "afxdialogex.h"


// CAddBook 대화 상자입니다.

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


// CAddBook 메시지 처리기입니다.


void CAddBook::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (mName == "") {
		MessageBox(L"책이름을 입력하세요.");
		return;
	}
	CDialogEx::OnOK();
}


BOOL CAddBook::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CString S;
	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	for (int i = 0; i < 7; i++) {
		S.Format(L"출판사%d", i+1);
		mCtrlList.InsertString(i, S);		
	}
	mCtrlList.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
