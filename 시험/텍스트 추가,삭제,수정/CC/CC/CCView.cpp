
// CCView.cpp : CCCView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "CC.h"
#endif

#include "CCDoc.h"
#include "CCView.h"
#include "TextDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCCView

IMPLEMENT_DYNCREATE(CCCView, CView)

BEGIN_MESSAGE_MAP(CCCView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CCCView 생성/소멸

CCCView::CCCView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CCCView::~CCCView()
{
}

BOOL CCCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CCCView 그리기

void CCCView::OnDraw(CDC* pDC)
{
	CCCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	int cnt = pDoc->mFrCnt;
	for (int i = 0; i < cnt; i++) {
		if (pDoc->mFr[i] == NULL);
		else {
			DispFr(pDoc->mFr[i],pDC);
		}
	}
	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CCCView 인쇄

BOOL CCCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CCCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CCCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CCCView 진단

#ifdef _DEBUG
void CCCView::AssertValid() const
{
	CView::AssertValid();
}

void CCCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCCDoc* CCCView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCCDoc)));
	return (CCCDoc*)m_pDocument;
}
#endif //_DEBUG


// CCCView 메시지 처리기


void CCCView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CTextDlg t;
	CCCDoc *p = GetDocument();
	int flg=0;
	int cnt = SerchText(point);
	if (cnt == -1) {
		cnt = GetIdx4Insert(p);
		flg = 1;
	}
	else t.mText = p->mFr[cnt]->txt;

	if (t.DoModal() == IDOK) {
		if (cnt == p->mFrCnt) p->mFr[cnt] = (FR*)malloc(sizeof(FR));
		wcscpy(p->mFr[cnt]->txt,t.mText);
		if(flg==1) p->mFr[cnt]->xy = point;
		else;
		p->mFr[cnt]->len = t.mText.GetLength();
		if (cnt == p->mFrCnt) p->mFrCnt++;
		
		Invalidate();
	}
	
	CView::OnLButtonDown(nFlags, point);
}



void CCCView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int cnt = SerchText(point);

	if (cnt == -1) return;
	if (MessageBox(L"삭제하시겠습니까?",L"삭제",1) == IDOK) {
		CCCDoc *p = GetDocument();
		free(p->mFr[cnt]);
		p->mFr[cnt] = NULL;
		if (cnt == p->mFrCnt) p->mFrCnt--;
	}
		
	Invalidate();
	CView::OnRButtonDown(nFlags, point);
}

int CCCView::GetIdx4Insert(CCCDoc* p)
{
	int i;
	for (i = 0; i < p->mFrCnt; i++)
		if (p->mFr[i] == 0) return i;
	return i;
}

void CCCView::DispFr(FR *f, CDC* p)
{
	CFont fo;

	fo.CreatePointFont(200,L"명조체");
	p->SelectObject(&fo);
	p->TextOut(f->xy.x, f->xy.y, f->txt);
}


int CCCView::SerchText(CPoint xy)
{
	CCCDoc *p = GetDocument();
	int cnt = p->mFrCnt;
	for (int i = 0; i < p->mFrCnt; i++)
		if ((xy.x < ((p->mFr[i]->xy.x) + (p->mFr[i]->len * 200))) && (xy.x > (p->mFr[i]->xy.x)))
			if ((xy.y < ((p->mFr[i]->xy.y) + 20)) && (xy.y > (p->mFr[i]->xy.y)))
				return i;
	return -1;
}


void CCCView::OnDestroy()
{
	CView::OnDestroy();

	GetDocument()->SaveData();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CCCView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	GetDocument()->LoadData();
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
}
