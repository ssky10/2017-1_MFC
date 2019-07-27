
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
	ON_COMMAND(IDM_ELLIPSE, &CBBView::OnEllipse)
	ON_COMMAND(IDM_FREE, &CBBView::OnFree)
	ON_COMMAND(IDM_LINE, &CBBView::OnLine)
	ON_COMMAND(IDM_RECT, &CBBView::OnRect)
	ON_WM_MOUSEMOVE()
	ON_UPDATE_COMMAND_UI(IDM_ELLIPSE, &CBBView::OnUpdateEllipse)
	ON_UPDATE_COMMAND_UI(IDM_FREE, &CBBView::OnUpdateFree)
	ON_UPDATE_COMMAND_UI(IDM_LINE, &CBBView::OnUpdateLine)
	ON_UPDATE_COMMAND_UI(IDM_RECT, &CBBView::OnUpdateRect)
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
	x1 = x2 = point.x;
	y1 = y2 = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CBBView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (type != FREEDRAW) {
		pt[pt_cnt].x1 = x1;
		pt[pt_cnt].y1 = y1;
		pt[pt_cnt].x2 = point.x;
		pt[pt_cnt].y2 = point.y;
	} else {
		tmp_pt[tmp_pt_cnt].x1 = point.x;
		tmp_pt[tmp_pt_cnt].y1 = point.y;
		tmp_pt_cnt++;
		pt[pt_cnt].line = (FREELINE*)malloc(tmp_pt_cnt*sizeof(FREELINE));
		memcpy(pt[pt_cnt].line, tmp_pt, tmp_pt_cnt * sizeof(FREELINE));
		pt[pt_cnt].x1 = tmp_pt_cnt;
		tmp_pt_cnt = 0;
	}
	pt[pt_cnt++].type = type;
	Invalidate(); //OnDraw함수 자동실행
	CView::OnLButtonUp(nFlags, point);
}


void CBBView::DrawPT(CDC* p)
{
	for (int i = 0; i < pt_cnt; i++) {
		switch (pt[i].type)
		{
		case LINE:
			p->MoveTo(pt[i].x1, pt[i].y1);
			p->LineTo(pt[i].x2, pt[i].y2);
			break;
		case RECTANGLE:
			p->Rectangle(pt[i].x1, pt[i].y1, pt[i].x2, pt[i].y2);
			break;
		case ELLIPSE:
			p->Ellipse(pt[i].x1, pt[i].y1, pt[i].x2, pt[i].y2);
			break;
		case FREEDRAW:
			for (int j = 0; j < pt[i].x1-1; j++) {
				p->MoveTo(pt[i].line[j].x1, pt[i].line[j].y1);
				p->LineTo(pt[i].line[j+1].x1, pt[i].line[j+1].y1);
			}
			break;
		default:
			break;
		}
	}
}


void CBBView::OnEllipse()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	type = ELLIPSE;
}


void CBBView::OnFree()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	type = FREEDRAW;
}


void CBBView::OnLine()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	type = LINE;
}


void CBBView::OnRect()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	type = RECTANGLE;
}


void CBBView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.	
	if (nFlags&MK_LBUTTON) {
		CClientDC dc(this);
		CBrush br;
		CPen pen;
		br.CreateStockObject(NULL_BRUSH);
		dc.SelectObject(&br);
		if (type == LINE) {
			pen.CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
			dc.SelectObject(&pen);
			dc.SetROP2(R2_XORPEN);
			//dc.SetROP2(R2_NOTXORPEN);
			dc.MoveTo(x1, y1);
			dc.LineTo(x2, y2);
			dc.MoveTo(x1, y1);
			dc.LineTo(point.x, point.y);
			x2 = point.x;
			y2 = point.y;
		}
		else if (type == RECTANGLE) {
			pen.CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
			dc.SelectObject(&pen);
			dc.SetROP2(R2_XORPEN);
			//dc.SetROP2(R2_NOTXORPEN);
			dc.Rectangle(x1, y1, x2, y2);
			dc.Rectangle(x1, y1, point.x, point.y);
			x2 = point.x;
			y2 = point.y;
		}
		else if (type == ELLIPSE) {
			pen.CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
			dc.SelectObject(&pen);
			dc.SetROP2(R2_XORPEN);
			//dc.SetROP2(R2_NOTXORPEN);
			dc.Ellipse(x1, y1, x2, y2);
			dc.Ellipse(x1, y1, point.x, point.y);
			x2 = point.x;
			y2 = point.y;
		}
		else if (type == FREEDRAW) {
			dc.MoveTo(x1, y1);
			dc.LineTo(point.x, point.y);
			tmp_pt[tmp_pt_cnt].x1 = x1;
			tmp_pt[tmp_pt_cnt].y1 = y1;
			x1 = point.x;
			y1 = point.y;
			tmp_pt_cnt++;
		}
		
	}

	CView::OnMouseMove(nFlags, point);
}


void CBBView::OnUpdateEllipse(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(type == ELLIPSE);
}


void CBBView::OnUpdateFree(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(type == FREEDRAW);
}


void CBBView::OnUpdateLine(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(type == LINE);
}


void CBBView::OnUpdateRect(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(type == RECTANGLE);
}
