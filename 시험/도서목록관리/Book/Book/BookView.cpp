
// BookView.cpp : CBookView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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

// CBookView 생성/소멸

CBookView::CBookView()
	: CFormView(IDD_BOOK_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

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
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CBookView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	LV_COLUMN col;
	WCHAR name[4][8] = { L"책이름", L"출판사",L"가격",L"언어" };
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


// CBookView 진단

#ifdef _DEBUG
void CBookView::AssertValid() const
{
	CFormView::AssertValid();
}

void CBookView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CBookDoc* CBookView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
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

// CBookView 메시지 처리기


void CBookView::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	S.Format(L"출판사%d", p->mFr[cnt]->cop + 1);
	mCtrlList.SetItemText(cnt, 1, S);
	mCtrlList.SetItemText(cnt, 2, p->mFr[cnt]->pay);
	switch(p->mFr[cnt]->lang){
	case 0:
		mCtrlList.SetItemText(cnt, 3, L"한글");
		break;
	case 1:
		mCtrlList.SetItemText(cnt, 3, L"영어");
		break;
	case 2:
		mCtrlList.SetItemText(cnt, 3, L"일어");
		break;
	case 3:
		mCtrlList.SetItemText(cnt, 3, L"기타");
		break;
	}
}

void CBookView::DispFr2(FR *fr, int idx) {
	CString S;
	mCtrlList.InsertItem(idx, fr->name);
	S.Format(L"출판사%d", fr->cop + 1);
	mCtrlList.SetItemText(idx, 1, S);
	mCtrlList.SetItemText(idx, 2, fr->pay);
	switch (fr->lang) {
	case 0:
		mCtrlList.SetItemText(idx, 3, L"한글");
		break;
	case 1:
		mCtrlList.SetItemText(idx, 3, L"영어");
		break;
	case 2:
		mCtrlList.SetItemText(idx, 3, L"일어");
		break;
	case 3:
		mCtrlList.SetItemText(idx, 3, L"기타");
		break;
	}
}


void CBookView::OnDestroy()
{
	CFormView::OnDestroy();
	GetDocument()->SaveData();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}
