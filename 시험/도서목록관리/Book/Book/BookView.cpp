
// BookView.cpp : CBookView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Book.h"
#endif

#include "BookDoc.h"
#include "BookView.h"
#include "AddBook.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBookView

IMPLEMENT_DYNCREATE(CBookView, CFormView)

BEGIN_MESSAGE_MAP(CBookView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CBookView::OnBnClickedButton1)
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CBookView ����/�Ҹ�

CBookView::CBookView()
	: CFormView(IDD_BOOK_FORM)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CBookView::~CBookView()
{
}

void CBookView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, mCtrlList);
}

BOOL CBookView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void CBookView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	LV_COLUMN col;
	WCHAR name[4][8] = { L"å�̸�", L"���ǻ�",L"����",L"���" };
	int width[4] = { 100,70,70,50 };
	for (int i = 0; i < 4; i++) {
		col.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
		col.fmt = LVCFMT_CENTER;
		col.pszText = name[i];
		col.iSubItem = i;
		col.cx = width[i];
		col.cchTextMax = width[i];
		mCtrlList.InsertColumn(i, &col);
	}
	mCtrlList.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	GetDocument()->LoadData();
	Invalidate();
}


// CBookView ����

#ifdef _DEBUG
void CBookView::AssertValid() const
{
	CFormView::AssertValid();
}

void CBookView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CBookDoc* CBookView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBookDoc)));
	return (CBookDoc*)m_pDocument;
}
#endif //_DEBUG


void CBookView::Invalidate()
{
	CFormView::Invalidate();
	CBookDoc *p = GetDocument();
	for (int i = 0; i < p->mFrCnt; i++)
		DispFr2(p->mFr[i], i);
}

// CBookView �޽��� ó����


void CBookView::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CAddBook b;

	b.mLag = 0;
	if (b.DoModal() == IDOK) {
		SaveFr(b);
		DispFr();
		//OnBnClickedButton1();
	}
}


void CBookView::SaveFr(CAddBook &d)
{
	CBookDoc *p = GetDocument(); int cnt = p->mFrCnt;
	p->mFr[cnt] = (FR*)calloc(1, sizeof(FR));
	wcscpy(p->mFr[cnt]->name, d.mName);
	p->mFr[cnt]->cop = d.mList;
	wcscpy(p->mFr[cnt]->pay, d.mPay);
	p->mFr[cnt]->lang = d.mLag;
	p->mFrCnt++;
}

void CBookView::DispFr() {
	CBookDoc *p = GetDocument(); int cnt = (p->mFrCnt) - 1;
	CString S, addr;
	mCtrlList.InsertItem(cnt, p->mFr[cnt]->name);
	S.Format(L"���ǻ�%d", p->mFr[cnt]->cop + 1);
	mCtrlList.SetItemText(cnt, 1, S);
	mCtrlList.SetItemText(cnt, 2, p->mFr[cnt]->pay);
	switch(p->mFr[cnt]->lang){
	case 0:
		mCtrlList.SetItemText(cnt, 3, L"�ѱ�");
		break;
	case 1:
		mCtrlList.SetItemText(cnt, 3, L"����");
		break;
	case 2:
		mCtrlList.SetItemText(cnt, 3, L"�Ͼ�");
		break;
	case 3:
		mCtrlList.SetItemText(cnt, 3, L"��Ÿ");
		break;
	}
}

void CBookView::DispFr2(FR *fr, int idx) {
	CString S;
	mCtrlList.InsertItem(idx, fr->name);
	S.Format(L"���ǻ�%d", fr->cop + 1);
	mCtrlList.SetItemText(idx, 1, S);
	mCtrlList.SetItemText(idx, 2, fr->pay);
	switch (fr->lang) {
	case 0:
		mCtrlList.SetItemText(idx, 3, L"�ѱ�");
		break;
	case 1:
		mCtrlList.SetItemText(idx, 3, L"����");
		break;
	case 2:
		mCtrlList.SetItemText(idx, 3, L"�Ͼ�");
		break;
	case 3:
		mCtrlList.SetItemText(idx, 3, L"��Ÿ");
		break;
	}
}


void CBookView::OnDestroy()
{
	CFormView::OnDestroy();
	GetDocument()->SaveData();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}
