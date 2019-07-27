
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
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	Op = 0;
	PreVal = 0.0;
	CurVal = "0";
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
	ClickedNum(L"1");
}


void CCalDlg::OnBnClicked2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ClickedNum(L"2");
}


void CCalDlg::OnBnClicked3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ClickedNum(L"3");
}


void CCalDlg::OnBnClicked4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ClickedNum(L"4");
}


void CCalDlg::OnBnClicked5()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ClickedNum(L"5");
}


void CCalDlg::OnBnClicked6()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ClickedNum(L"6");
}


void CCalDlg::OnBnClicked7()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ClickedNum(L"7");
}


void CCalDlg::OnBnClicked8()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ClickedNum(L"8");
}


void CCalDlg::OnBnClicked9()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ClickedNum(L"9");
}


void CCalDlg::OnBnClicked0()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ClickedNum(L"0");
}


void CCalDlg::OnBnClicked00()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ClickedNum(L"00");
}


void CCalDlg::OnBnClickedDot()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ClickedNum(L".");
}


void CCalDlg::OnBnClickedBack()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CurVal.Delete(CurVal.GetLength()-1);
	if (CurVal == "") CurVal = "0";
	SetDlgItemTextW(IDC_RES, CurVal);
}


void CCalDlg::OnBnClickedPlus()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Operate0();
	DispCurVal(PreVal);
	Op = PLUS;
}


void CCalDlg::OnBnClickedMinus()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Operate0();
	DispCurVal(PreVal);
	Op = MINUS;
}


void CCalDlg::OnBnClickedMul()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Operate0();
	DispCurVal(PreVal);
	Op = MUL;
}


void CCalDlg::OnBnClickedDivide()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Operate0();
	DispCurVal(PreVal);
	Op = DIVIDE;
}


void CCalDlg::OnBnClickedEqual()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Operate0();
	DispCurVal(PreVal);
	Op = EQUAL;
	PreVal = 0;
}


// ���ڹ�ư Ŭ���� �̺�Ʈ �Լ�
void CCalDlg::ClickedNum(CString val)
{
	if (CurVal == "0")
		if (val == "00") CurVal = "0";
		else if (val == ".") CurVal = "0.";
		else CurVal = val;
	else CurVal += val;
	SetDlgItemTextW(IDC_RES, CurVal);
}


// �Ǽ��� ���� ȭ�鿡 ���
void CCalDlg::DispCurVal(double val)
{
	CString S1,S2;

	for (int i = 13; i >= 0; i--) {
		S1.Format(L"%%.%dlf", i);
		S2.Format(S1, val);
		if (i == 0) break;
		else if (S2.Right(1) == "0") S2.Delete(S2.GetLength() - 1);
		else break;
	}
	
	SetDlgItemTextW(IDC_RES, S2);
}


void CCalDlg::Operate0()
{
	switch (Op)
	{
	case EQUAL:
		GetDlgItemTextW(IDC_RES, CurVal);
	case NOOP:
	case PLUS:
		PreVal += _wtof(CurVal); break;
	case MINUS:
		PreVal -= _wtof(CurVal); break;
	case MUL:
		PreVal *= _wtof(CurVal); break;
	case DIVIDE:
		PreVal /= _wtof(CurVal); break;
	}
	CurVal = "0";
}