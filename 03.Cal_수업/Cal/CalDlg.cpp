
// CalDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Cal.h"
#include "CalDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CCalDlg ��ȭ ����



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


// CCalDlg �޽��� ó����

BOOL CCalDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	SetDlgItemTextW(IDC_RES, L"0");

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CCalDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CCalDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalDlg::OnBnClicked1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (AfterDotCnt) ClickedNumReal(1);
	else ClickedNum(1);
}


void CCalDlg::OnBnClicked2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (AfterDotCnt) ClickedNumReal(2);
	else ClickedNum(2);
}


void CCalDlg::OnBnClicked3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (AfterDotCnt) ClickedNumReal(3);
	else ClickedNum(3);
}


void CCalDlg::OnBnClicked4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (AfterDotCnt) ClickedNumReal(4);
	else ClickedNum(4);
}


void CCalDlg::OnBnClicked5()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (AfterDotCnt) ClickedNumReal(5);
	else ClickedNum(5);
}


void CCalDlg::OnBnClicked6()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (AfterDotCnt) ClickedNumReal(6);
	else ClickedNum(6);
}


void CCalDlg::OnBnClicked7()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (AfterDotCnt) ClickedNumReal(7);
	else ClickedNum(7);
}


void CCalDlg::OnBnClicked8()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (AfterDotCnt) ClickedNumReal(8);
	else ClickedNum(8);
}


void CCalDlg::OnBnClicked9()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (AfterDotCnt) ClickedNumReal(9);
	else ClickedNum(9);
}


void CCalDlg::OnBnClicked0()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (AfterDotCnt) ClickedNumReal(0);
	else ClickedNum(0);
}


void CCalDlg::OnBnClicked00()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (AfterDotCnt) ClickedNumReal(10);
	else ClickedNum(10);
}


void CCalDlg::OnBnClickedDot()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (AfterDotCnt != 0) return;
	AfterDotCnt++;
	DispValDot(CurVal, CurValReal, AfterDotCnt);
}


void CCalDlg::OnBnClickedBack()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Operate0();
	DispCurVal(PreVal);
	PreOp = PLUS;
}


void CCalDlg::OnBnClickedMinus()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Operate0();
	DispCurVal(PreVal);
	PreOp = MINUS;
}


void CCalDlg::OnBnClickedMul()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Operate0();
	DispCurVal(PreVal);
	PreOp = MUL;
}


void CCalDlg::OnBnClickedDivide()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Operate0();
	DispCurVal(PreVal);
	PreOp = DIVIDE;
}


void CCalDlg::OnBnClickedEqual()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Operate0();
	if(AfterDotCnt==0) DispCurVal(PreVal);
	else DispValDot(PreVal, CurValReal, AfterDotCnt);
	PreVal = 0;
	PreOp = NOOP;
	
}


// ���ڹ�ư Ŭ���� �̺�Ʈ �Լ�
void CCalDlg::ClickedNum(int val)
{
	if (val == 10)
		CurVal *= 100;
	else
		CurVal = CurVal * 10 + val;
	DispCurVal(CurVal);
}

// �Ҽ��� ���Ͽ��� ���ڸ� �Է¹޾��� ��
void CCalDlg::ClickedNumReal(int val)
{
	if (val == 0) AfterDotCnt++;
	else if (val == 10) AfterDotCnt += 2;
	else CurValReal += val*PowerOf(AfterDotCnt++);

	DispValDot(CurVal, CurValReal, AfterDotCnt);
}


// ���ڰ��� ȭ�鿡 ���
void CCalDlg::DispCurVal(int val)
{
	SetDlgItemInt(IDC_RES, val);
}


// �Ǽ� ���ڸ� ȭ�鿡 ���
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


// 0.1�� ������ ��ȯ
float CCalDlg::PowerOf(int cut)
{
	float f = 0.1f;
	while (--cut > 0)
		f = f*0.1f;
	return f;
}



