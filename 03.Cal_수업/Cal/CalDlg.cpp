
// CalDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "Cal.h"
#include "CalDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalDlg 대화 상자



CCalDlg::CCalDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CAL_DIALOG, pParent)
	, PreVal(0)
	, CurValReal(0)
	, AfterDotCnt(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	CurVal = CurOp = PreVal = PreOp = AfterDotCnt = 0;
	CurValReal = 0.0;
}

void CCalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCalDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_1, &CCalDlg::OnBnClicked1)
	ON_BN_CLICKED(IDC_2, &CCalDlg::OnBnClicked2)
	ON_BN_CLICKED(IDC_3, &CCalDlg::OnBnClicked3)
	ON_BN_CLICKED(IDC_4, &CCalDlg::OnBnClicked4)
	ON_BN_CLICKED(IDC_5, &CCalDlg::OnBnClicked5)
	ON_BN_CLICKED(IDC_6, &CCalDlg::OnBnClicked6)
	ON_BN_CLICKED(IDC_7, &CCalDlg::OnBnClicked7)
	ON_BN_CLICKED(IDC_8, &CCalDlg::OnBnClicked8)
	ON_BN_CLICKED(IDC_9, &CCalDlg::OnBnClicked9)
	ON_BN_CLICKED(IDC_0, &CCalDlg::OnBnClicked0)
	ON_BN_CLICKED(IDC_00, &CCalDlg::OnBnClicked00)
	ON_BN_CLICKED(IDC_DOT, &CCalDlg::OnBnClickedDot)
	ON_BN_CLICKED(IDC_PLUS, &CCalDlg::OnBnClickedPlus)
	ON_BN_CLICKED(IDC_MINUS, &CCalDlg::OnBnClickedMinus)
	ON_BN_CLICKED(IDC_BACK, &CCalDlg::OnBnClickedBack)
	ON_BN_CLICKED(IDC_MUL, &CCalDlg::OnBnClickedMul)
	ON_BN_CLICKED(IDC_DIVIDE, &CCalDlg::OnBnClickedDivide)
	ON_BN_CLICKED(IDC_EQUAL, &CCalDlg::OnBnClickedEqual)
END_MESSAGE_MAP()


// CCalDlg 메시지 처리기

BOOL CCalDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	SetDlgItemTextW(IDC_RES, L"0");

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CCalDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CCalDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CCalDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalDlg::OnBnClicked1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (AfterDotCnt) ClickedNumReal(1);
	else ClickedNum(1);
}


void CCalDlg::OnBnClicked2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (AfterDotCnt) ClickedNumReal(2);
	else ClickedNum(2);
}


void CCalDlg::OnBnClicked3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (AfterDotCnt) ClickedNumReal(3);
	else ClickedNum(3);
}


void CCalDlg::OnBnClicked4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (AfterDotCnt) ClickedNumReal(4);
	else ClickedNum(4);
}


void CCalDlg::OnBnClicked5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (AfterDotCnt) ClickedNumReal(5);
	else ClickedNum(5);
}


void CCalDlg::OnBnClicked6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (AfterDotCnt) ClickedNumReal(6);
	else ClickedNum(6);
}


void CCalDlg::OnBnClicked7()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (AfterDotCnt) ClickedNumReal(7);
	else ClickedNum(7);
}


void CCalDlg::OnBnClicked8()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (AfterDotCnt) ClickedNumReal(8);
	else ClickedNum(8);
}


void CCalDlg::OnBnClicked9()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (AfterDotCnt) ClickedNumReal(9);
	else ClickedNum(9);
}


void CCalDlg::OnBnClicked0()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (AfterDotCnt) ClickedNumReal(0);
	else ClickedNum(0);
}


void CCalDlg::OnBnClicked00()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (AfterDotCnt) ClickedNumReal(10);
	else ClickedNum(10);
}


void CCalDlg::OnBnClickedDot()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (AfterDotCnt != 0) return;
	AfterDotCnt++;
	DispValDot(CurVal, CurValReal, AfterDotCnt);
}


void CCalDlg::OnBnClickedBack()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (AfterDotCnt == 0) {
		CurVal /= 10;
		DispCurVal(CurVal);
	}
	else {
		if (AfterDotCnt == 1) {
			AfterDotCnt = 0;
			DispCurVal(CurVal);
			return;
		}
		CString S;
		S.Format(L"%%.%df", AfterDotCnt-1);
		S.Format(S, CurValReal);
		S.Delete(AfterDotCnt--);
		//CurValReal = atof((char*)S.GetString());
		CurValReal = _wtof(S);
		DispValDot(CurVal, CurValReal, AfterDotCnt);
	}

	/*if (AfterDotCnt == 0) {
		if (CurVal == 0) return;
		CurVal /= 10;
		DispCurVal(CurVal);
	}
	else if (AfterDotCnt == 1) {
		DispCurVal(CurVal);
		CurValReal = 0.0;
		AfterDotCnt = 0;
	}
	else {
		int temp;
		temp = CurValReal / PowerOf(--AfterDotCnt);
		temp /= 10;
		CurValReal = temp * PowerOf(AfterDotCut - 1);
		DispValDot(CurVal, CurValReal, AfterDotCnt);
	}*/

}

void CCalDlg::OnBnClickedPlus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Operate0();
	DispCurVal(PreVal);
	PreOp = PLUS;
}


void CCalDlg::OnBnClickedMinus()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Operate0();
	DispCurVal(PreVal);
	PreOp = MINUS;
}


void CCalDlg::OnBnClickedMul()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Operate0();
	DispCurVal(PreVal);
	PreOp = MUL;
}


void CCalDlg::OnBnClickedDivide()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Operate0();
	DispCurVal(PreVal);
	PreOp = DIVIDE;
}


void CCalDlg::OnBnClickedEqual()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Operate0();
	if(AfterDotCnt==0) DispCurVal(PreVal);
	else DispValDot(PreVal, CurValReal, AfterDotCnt);
	PreVal = 0;
	PreOp = NOOP;
	
}


// 숫자버튼 클릭시 이벤트 함수
void CCalDlg::ClickedNum(int val)
{
	if (val == 10)
		CurVal *= 100;
	else
		CurVal = CurVal * 10 + val;
	DispCurVal(CurVal);
}

// 소수점 이하에서 숫자를 입력받았을 때
void CCalDlg::ClickedNumReal(int val)
{
	if (val == 0) AfterDotCnt++;
	else if (val == 10) AfterDotCnt += 2;
	else CurValReal += val*PowerOf(AfterDotCnt++);

	DispValDot(CurVal, CurValReal, AfterDotCnt);
}


// 숫자값을 화면에 출력
void CCalDlg::DispCurVal(int val)
{
	SetDlgItemInt(IDC_RES, val);
}


// 실수 숫자를 화면에 출력
void CCalDlg::DispValDot(int val1, float val2, int dot_cut)
{
	CString S;
	//if (dot_cut == 1) S.Format(L"%d.", val1);
	//else {
		S.Format(L"%%.%df", max(dot_cut - 1,1));
		S.Format(S, val1 + val2);
	//}
	SetDlgItemTextW(IDC_RES, S);
}


void CCalDlg::Operate0()
{
	switch (PreOp)
	{
	case NOOP:
	case PLUS:
		PreVal += CurVal + CurValReal; break;
	case MINUS:
		PreVal -= CurVal + CurValReal; break;
	case MUL:
		PreVal *= CurVal + CurValReal; break;
	case DIVIDE:
		PreVal /= CurVal + CurValReal; break;
	}
	CurVal = 0;
}


// 0.1의 제곱근 반환
float CCalDlg::PowerOf(int cut)
{
	float f = 0.1f;
	while (--cut > 0)
		f = f*0.1f;
	return f;
}



