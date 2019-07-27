
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
	ON_WM_MOUSEMOVE()
	ON_COMMAND(IDM_LINE, &CBBView::OnLine)
	ON_COMMAND(IDM_FREE, &CBBView::OnFree)
//	ON_COMMAND(IDM_ERSER, &CBBView::OnErser)
	ON_COMMAND(IDM_ERASER, &CBBView::OnEraser)
	ON_COMMAND(IDM_ELLIPSE, &CBBView::OnEllipse)
	ON_COMMAND(IDM_RECT, &CBBView::OnRect)
	ON_UPDATE_COMMAND_UI(IDM_ELLIPSE, &CBBView::OnUpdateEllipse)
	ON_UPDATE_COMMAND_UI(IDM_ERASER, &CBBView::OnUpdateEraser)
	ON_UPDATE_COMMAND_UI(IDM_FREE, &CBBView::OnUpdateFree)
	ON_UPDATE_COMMAND_UI(IDM_LINE, &CBBView::OnUpdateLine)
	ON_UPDATE_COMMAND_UI(IDM_RECT, &CBBView::OnUpdateRect)
END_MESSAGE_MAP()

// CBBView 생성/소멸

CBBView::CBBView()
	:pt_cnt(0)
{
	// TODO: 여기에 생성 코드를 추가합니다.
	tmp_pt_cnt = 0;
	ab = "";
	type = LINE;
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
	CBrush br;
	br.CreateStockObject(NULL_BRUSH);
	pDC->SelectObject(&br);
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
	xy1 = point;
	tmp_pt_cnt = 0;
	if (type == FREEDRAW) xy2.x = xy2.y = point.x;
	else if (type == ERASER) OnRButtonDown(nFlags, point);
	else xy2 = point;
	CView::OnLButtonDown(nFlags, point);
}


void CBBView::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (type == FREEDRAW) {
		AddPT(pt, xy2, point);
	}
	else if (type == ERASER) return;
	else {
		if (xy1.x>point.x) AddPT(pt, point, xy1);
		else AddPT(pt, xy1, point);
	}
	pt_cnt++;
	//pt[pt_cnt++].type = type;
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
			for (int j = 0; j < pt[i].y1 - 1; j++) {
				p->MoveTo(pt[i].line[j].x1, pt[i].line[j].y1);
				p->LineTo(pt[i].line[j + 1].x1, pt[i].line[j + 1].y1);
			}
			break;
		default:
			break;
		}
	}

	p->TextOut(10, 10, ab);
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

void CBBView::AddPT(PT* p, CPoint XY, CPoint xy)
{
		/*
		int first=0,last=pt_cnt;
		//이진탐색알고리즘
		while (first < last) {

			if (last - first == 1) {
				if (p[first].x1 > xy1.x) first = last;
				else last = first;
			}
			else if (xy1.x < p[(first + last) / 2].x1) {
				first = (first + last) / 2;
			}
			else if (xy1.x > p[(first + last) / 2].x1)
			{
				last = (first + last) / 2;
			}
			else {
				first = (first + last) / 2;
				break;
			}
		}

		for (int j = pt_cnt; j > first; j--) {
			p[j] = p[j - 1];
		}
		p[first] = TransPT(xy1.x, xy1.y, xy2.x, xy2.y);*/
	int i;
	//if (pt_cnt == 0) {
	//	p[0] = TransPT(xy1.x, xy1.y, xy2.x, xy2.y);
	//	return;
	//}
	for (i = pt_cnt-1; i >= 0; i--) {
		if (p[i].x1 > XY.x) p[i + 1] = p[i];
		else break;		
	}
	if (type == FREEDRAW) {
		tmp_pt[tmp_pt_cnt].x1 = xy.x;
		tmp_pt[tmp_pt_cnt].y1 = xy.y;
		tmp_pt_cnt++;
		p[i + 1].line = (FREELINE*)malloc(tmp_pt_cnt * sizeof(FREELINE));
		memcpy(p[i + 1].line, tmp_pt, tmp_pt_cnt * sizeof(FREELINE));
		p[i + 1].y1 = tmp_pt_cnt;
		tmp_pt_cnt = 0;
		p[i + 1].x1 = xy2.x;
		p[i + 1].x2 = xy2.y;
		p[i + 1].type = type;
	}
	else {
		p[i + 1] = TransPT(XY.x, XY.y, xy.x, xy.y);
		p[i + 1].type = type;
	}
	
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
	double A,B;
	double a, b, c;
	bool result=false;

	switch (xy.type)
	{
	case LINE:
		if ((xy.x2 - xy.x1)<ERR) {
			if (xy.y1 > xy.y2)
				if ((xy.y1 >= point.y) && (xy.y2 <= point.y)) result = true;
				else result = false;
			else
				if ((xy.y1 <= point.y) && (xy.y2 >= point.y)) result = true;
				else result = false;
		}
		else {
			A = (xy.y1 - xy.y2)*(point.x - xy.x1) / (xy.x1 - xy.x2) - (point.y - xy.y1);
			if (fabs(A) <ERR) result = true;
			else result = false;
		}
		break;
	case ELLIPSE:
		a = (xy.x2 - xy.x1) / 2;
		b = (xy.y1 - xy.y2) / 2;
		/*
		if (abs(xy.x1 - xy.x2) > abs(xy.y1 - xy.y2)) {
			c = sqrt((a*a) - (b*b));
			if (b > 0) A = sqrt(pow(point.x - (xy.x1 + a - c), 2) + pow(point.y - (xy.y2 + b), 2)) + sqrt(pow(point.x - xy.x2 - (a - c), 2) + pow(point.y - (xy.y2 + b), 2)) - 2 * a;
			else A = sqrt(pow(point.x - (xy.x1 + a - c), 2) + pow(point.y - (xy.y1 - b), 2)) + sqrt(pow(point.x - xy.x2 - (a - c), 2) + pow(point.y - (xy.y1 - b), 2)) - 2 * a;
		}
		else {
			c = sqrt((b*b) - (a*a));
			if (b > 0) A = sqrt(pow(point.y - (xy.y2 + b - c), 2) + pow(point.x - (xy.x1 + a), 2)) + sqrt(pow(point.y - xy.y1 - (b - c), 2) + pow(point.x - (xy.x1 + a), 2)) - 2 * b;
			else A = sqrt(pow(point.y - (xy.y1 - b - c), 2) + pow(point.x - (xy.x1 + a), 2)) + sqrt(pow(point.y - xy.y2 - (-b - c), 2) + pow(point.x - (xy.x1 + a), 2)) - 2 * (-b);
		}*/

		//if (xy.y1 > xy.y2)	A = (pow(point.x - (xy.x1 + a), 2) / (a*a)) + (pow(point.y - (xy.y2 + b), 2) / (b*b)) - 1;
		//else A = (pow(point.x - (xy.x1 + a), 2) / (a*a)) + (pow(point.y - (xy.y1 + b), 2) / (b*b)) - 1;

		//1번if (xy.y1 > xy.y2)	A = (pow(point.x - (xy.x1 + a), 2) / (a*a)) + (pow(point.y - (xy.y2 + b), 2) / (b*b)) - 1;
		//else A = (pow(point.x - (xy.x1 + a), 2) / (a*a)) + (pow(point.y - (xy.y1 - b), 2) / (b*b)) - 1;

		//2번if (xy.y1 > xy.y2)	A = (((point.x - (xy.x1 + a))*(point.x - (xy.x1 + a))) / (a*a)) + (((point.y - (xy.y2 + b))*(point.x - (xy.x2 + b))) / (b*b)) - 1;
		//else A = (((point.x - (xy.x1 + a))*(point.x - (xy.x1 + a))) / (a*a)) + (((point.y - (xy.y1 - b))*(point.x - (xy.y1 - b))) / (b*b)) - 1;

		if (xy.y1 > xy.y2) A = sqrt(pow(b, 2)*pow(point.x-(a+xy.x1), 2) + pow(a, 2)*pow(point.y-(b+xy.y2), 2)) - a*b;
		else A = sqrt(pow(b, 2)*pow(point.x - (a + xy.x1), 2) + pow(a, 2)*pow(point.y - (-b + xy.y1), 2)) + a*b;

		A=sqrt(fabs(A));

		ab.Format(L"%lf / %d / %d / %d / %d", A, point.x, point.y,xy.x1,xy.x2);
		if (A<ERR*2) result = true;
		else result = false;
		break;
	case RECTANGLE:
		if((abs(xy.x1-point.x)<=ERR)||(abs(xy.x2 - point.x)<=ERR)) result = true;
		else if ((abs(xy.y1 - point.y) <= ERR) || (abs(xy.y2 - point.y) <= ERR)) result = true;
		else result = false;
			break;
	case FREEDRAW:
		for (int i = 0; i < xy.y1 - 1; i++) {
			if (abs(xy.line[i].x1 - xy.line[i+1].x1)<ERR) {
				if (xy.line[i].y1 > xy.line[i+1].y1)
					if ((xy.line[i].y1 >= point.y) && (xy.line[i + 1].y1 <= point.y)) result = true;
					else result = false;
				else
					if ((xy.line[i].y1 <= point.y) && (xy.line[i + 1].y1 >= point.y)) result = true;
					else result = false;
			}
			else {
				A = (xy.line[i].y1 - xy.line[i + 1].y1)*(point.x - xy.line[i].x1) / (xy.line[i].x1 - xy.line[i+1].x1) - (point.y - xy.line[i].y1);
				if (fabs(A) <ERR) result = true;
				else result = false;
			}
			if (result) break;
		}
		break;
	default:
		break;
	}

	return result;

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


void CBBView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nFlags&MK_LBUTTON) {
		CClientDC dc(this);
		CBrush br;
		br.CreateStockObject(NULL_BRUSH);
		dc.SelectObject(&br);
		if (type == LINE) {
			dc.SetROP2(R2_NOTXORPEN);
			dc.MoveTo(xy1);
			dc.LineTo(xy2);
			dc.MoveTo(xy1);
			dc.LineTo(point);
			xy2 = point;
		}
		else if (type == RECTANGLE) {
			dc.SetROP2(R2_NOTXORPEN);
			dc.Rectangle(xy1.x, xy1.y, xy2.x, xy2.y);
			dc.Rectangle(xy1.x, xy1.y, point.x, point.y);
			xy2 = point;
		}
		else if (type == ELLIPSE) {
			dc.SetROP2(R2_NOTXORPEN);
			dc.Ellipse(xy1.x, xy1.y, xy2.x, xy2.y);
			dc.Ellipse(xy1.x, xy1.y, point.x, point.y);
			xy2 = point;
		}
		else if (type == FREEDRAW) {
			if (xy2.x > point.x) xy2.x = point.x;
			if (xy2.y < point.x) xy2.y = point.x;
			dc.MoveTo(xy1);
			dc.LineTo(point);
			tmp_pt[tmp_pt_cnt].x1 = xy1.x;
			tmp_pt[tmp_pt_cnt].y1 = xy1.y;
			xy1 = point;
			tmp_pt_cnt++;
		}

	}
	CView::OnMouseMove(nFlags, point);
}


void CBBView::OnLine()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	type = LINE;
}


void CBBView::OnFree()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	type = FREEDRAW;
}


void CBBView::OnEraser()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	type = ERASER;
}


void CBBView::OnEllipse()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	type = ELLIPSE;
}


void CBBView::OnRect()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	type = RECTANGLE;
}


void CBBView::OnUpdateEllipse(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(type == ELLIPSE);
}


void CBBView::OnUpdateEraser(CCmdUI *pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->SetCheck(type == ERASER);
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
