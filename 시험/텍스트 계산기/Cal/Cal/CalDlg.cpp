
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
	, Focus(0)
{
	Focus = NEDIT;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
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
	ON_EN_SETFOCUS(IDC_N1, &CCalDlg::OnSetfocusN1)
	ON_EN_SETFOCUS(IDC_N2, &CCalDlg::OnSetfocusN2)
	ON_BN_CLICKED(IDC_DOT, &CCalDlg::OnBnClickedDot)
	ON_BN_CLICKED(IDC_PLUS, &CCalDlg::OnBnClickedPlus)
	ON_BN_CLICKED(IDC_MINUS, &CCalDlg::OnBnClickedMinus)
	ON_EN_SETFOCUS(IDC_N3, &CCalDlg::OnSetfocusN3)
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


void CCalDlg::OnSetfocusN1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Focus = EDIT1;
}


void CCalDlg::OnSetfocusN2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Focus = EDIT2;
}


void CCalDlg::ClickedNum(CString val)
{
	if (Focus == NEDIT) {
		return;
	}
	else
	{
		OpenClipboard();
		EmptyClipboard();
		CString str = val;
		HGLOBAL hGlobal = GlobalAlloc(GHND | GMEM_SHARE, (str.GetLength() + 1) * sizeof(TCHAR));
		LPWSTR pGlobal = (LPWSTR)GlobalLock(hGlobal);	
		lstrcatW(pGlobal, str);
		SetClipboardData(CF_TEXT, hGlobal);
		CloseClipboard();

		if(Focus==EDIT1)
			((CEdit*)GetDlgItem(IDC_N1))->Paste();
		else
			((CEdit*)GetDlgItem(IDC_N2))->Paste();
	}
}


void CCalDlg::OnBnClickedDot()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString A;
	if (Focus == EDIT1) GetDlgItemTextW(IDC_N1, A);
	else if (Focus == EDIT2) GetDlgItemTextW(IDC_N2, A);
	else
		return;

	if (A.Find('.') == -1)
		ClickedNum(L".");
	else
		return;
}


void CCalDlg::OnBnClickedPlus()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString A, B;
	GetDlgItemTextW(IDC_N1, A);
	GetDlgItemTextW(IDC_N2, B);

	DispCurVal(_wtof(A) + _wtof(B));

	SetDlgItemTextW(IDC_N1, L"");
	SetDlgItemTextW(IDC_N2, L"");
}

void CCalDlg::DispCurVal(double val)
{
	CString S1, S2;

	for (int i = 12; i >= 0; i--) {
		S1.Format(L"%%.%dlf", i);
		S2.Format(S1, val);
		if (i == 0) break;
		else if (S2.Right(1) == "0") S2.Delete(S2.GetLength() - 1);
		else break;
	}

	SetDlgItemTextW(IDC_N3, S2);
}

void CCalDlg::OnBnClickedMinus()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CString A, B;
	GetDlgItemTextW(IDC_N1, A);
	GetDlgItemTextW(IDC_N2, B);

	DispCurVal(_wtof(A) - _wtof(B));

	SetDlgItemTextW(IDC_N1, L"");
	SetDlgItemTextW(IDC_N2, L"");
}


void CCalDlg::OnSetfocusN3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Focus = NEDIT;
}
