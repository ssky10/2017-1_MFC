
// BBView.cpp : CBBView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "BB.h"
#endif

#include "BBDoc.h"
#include "BBView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBBView

IMPLEMENT_DYNCREATE(CBBView, CView)

BEGIN_MESSAGE_MAP(CBBView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CBBView 생성/소멸

CBBView::CBBView()
	:pt_cnt(0)
{
	// TODO: 여기에 생성 코드를 추가합니다.
	type = LINE;
	tmp_pt_cnt = 0;
}

CBBView::~CBBView()
{
}

BOOL CBBView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CBBView 그리기

void CBBView::OnDraw(CDC* pDC)
{
	CBBDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	DrawPT(pDC);
}


// CBBView 인쇄

BOOL CBBView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CBBView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CBBView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CBBView 진단

#ifdef _DEBUG
void CBBView::AssertValid() const
{
	CView::AssertValid();
}

void CBBView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBBDoc* CBBView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBBDoc)));
	return (CBBDoc*)m_pDocument;
}
#endif //_DEBUG


// CBBView 메시지 처리기


void CBBView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	xy1 = xy2 = point;
	CView::OnLButtonDown(nFlags, point);
}


void CBBView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if(xy.x>point.x) AddPT(pt, point, xy);
	else AddPT(pt, xy, point);
	pt_cnt++;
	Invalidate(); //OnDraw함수 자동실행
	CView::OnLButtonUp(nFlags, point);
}


void CBBView::DrawPT(CDC* p)
{
	for (int i = 0; i < pt_cnt; i++) {
		p->MoveTo(pt[i].x1, pt[i].y1);
		p->LineTo(pt[i].x2, pt[i].y2);
	}
}


void CBBView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	for (int i = 0; i < pt_cnt; i++) {
		if (pt[i].x1- 10 > point.x) break;
		if ((pt[i].x1- 10 <= point.x) && (pt[i].x2+ 10 >= point.x)) {
			if (CheckPT(point, pt[i])) {
				DeletePT(pt, i);
				pt_cnt--;
			}
		}
	}
	Invalidate(); //OnDraw함수 자동실행
	CView::OnRButtonDown(nFlags, point);
}

void CBBView::AddPT(PT* p, CPoint xy1, CPoint xy2)
{
	int i;

	for (i = pt_cnt-1; i >= 0; i--) {
		if (p[i].x1 > xy1.x) p[i + 1] = p[i];
		else break;
	}
	p[i+1] = TransPT(xy1.x, xy1.y, xy2.x, xy2.y);
	
	return;	
}


void CBBView::DeletePT(PT* p, int num)
{
	for (int i = num; i < pt_cnt; i++) {
		p[i] = p[i + 1];
	}

}

bool CBBView::CheckPT(CPoint point, PT xy)
{
	int A;
	if ((xy.x2 - xy.x1)<10) {
		if (xy.y1 > xy.y2)
			if ((xy.y1 >= point.y) && (xy.y2 <= point.y)) return true;
			else return false;
		else
			if ((xy.y1 <= point.y) && (xy.y2 >= point.y)) return true;
			else return false;
	}
	else {
		A = (xy.y1 - xy.y2)*(point.x - xy.x1) / (xy.x1 - xy.x2) - (point.y - xy.y1);
		if ( abs(A) <ERR) return true;
		else return false;
	}

}


PT CBBView::TransPT(int x1, int y1, int x2, int y2)
{
	PT A;
	A.x1 = x1;
	A.y1 = y1;
	A.x2 = x2;
	A.y2 = y2;
	return A;
}
