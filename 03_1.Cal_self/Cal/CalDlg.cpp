
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
	, DeciPlace(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	CurVal = CurOp = PreVal = PreOp = DeciPlace = 0;
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
	ClickedNum(1);
}


void CCalDlg::OnBnClicked2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ClickedNum(2);
}


void CCalDlg::OnBnClicked3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ClickedNum(3);
}


void CCalDlg::OnBnClicked4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ClickedNum(4);
}


void CCalDlg::OnBnClicked5()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ClickedNum(5);
}


void CCalDlg::OnBnClicked6()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ClickedNum(6);
}


void CCalDlg::OnBnClicked7()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ClickedNum(7);
}


void CCalDlg::OnBnClicked8()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ClickedNum(8);
}


void CCalDlg::OnBnClicked9()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ClickedNum(9);
}


void CCalDlg::OnBnClicked0()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ClickedNum(0);
}


void CCalDlg::OnBnClicked00()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ClickedNum(10);
}


void CCalDlg::OnBnClickedDot()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	DeciPlace = 1;
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


// ���ڹ�ư Ŭ���� �̺�Ʈ �Լ�
void CCalDlg::ClickedNum(double val)
{
	if (DeciPlace == 0) {
		if (val == 10)
			CurVal *= 100;
		else
			CurVal = CurVal * 10 + val;
		DispCurVal(CurVal);
	}
	else
	{
		if (DeciPlace == 7) return;
		for (int i = 0; i < DeciPlace; i++) val /= 10;
		CurVal += val;
		DispCurVal(CurVal);
		DeciPlace++;
	}

	
}


// ���ڰ��� ȭ�鿡 ���
void CCalDlg::DispCurVal(double val)
{
	CString A;
	//A.Format(L"%%.%df", DeciPlace);
	//A.Format(A, val);
	A.Format(L"%f", val);
	SetDlgItemText(IDC_RES, A);	
}


void CCalDlg::Operate0()
{
	switch (PreOp)
	{
	case NOOP:
	case PLUS:
		PreVal += CurVal; break;
	case MINUS:
		PreVal -= CurVal; break;
	case MUL:
		PreVal *= CurVal; break;
	case DIVIDE:
		PreVal /= CurVal; break;
	}
	CurVal = DeciPlace = 0;
}



void CCalDlg::OnBnClickedBack()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int temp1, temp2;
	CString Stemp;
	GetDlgItemTextW(IDC_RES, Stemp);
	CurVal = _wtof(Stemp);
	if (CurVal == 0) return;
	if (DeciPlace == 0) {
		temp1 = CurVal/10;
		CurVal = temp1;
	}
	else {
		temp1 = CurVal;
		CurVal -= temp1;
		for (int i = 0; i < DeciPlace-1; i++) CurVal *= 10;
		temp2 = CurVal / 10;
		Stemp.Format(L"%d.%d", temp1, temp2);
		CurVal = _wtof(Stemp);
		DeciPlace--;
	}
	DispCurVal(CurVal);	
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
