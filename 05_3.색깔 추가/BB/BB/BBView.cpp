
// BBView.cpp : CBBView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "BB.h"
#endif

#include "BBDoc.h"
#include "BBView.h"
#include "TextDlg.h"

extern CString pFont[4];

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CBBView

IMPLEMENT_DYNCREATE(CBBView, CView)

BEGIN_MESSAGE_MAP(CBBView, CView)
	// ǥ�� �μ� ����Դϴ�.
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
	ON_COMMAND(IDM_COLOR, &CBBView::OnColor)
	ON_UPDATE_COMMAND_UI(IDM_COLOR, &CBBView::OnUpdateColor)
	ON_COMMAND(IDM_TEXT, &CBBView::OnText)
END_MESSAGE_MAP()

// CBBView ����/�Ҹ�

CBBView::CBBView()
	:pt_cnt(0)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	type = LINE;
	tmp_pt_cnt = 0;
	mColor = RGB(0, 0, 0);
}

CBBView::~CBBView()
{
}

BOOL CBBView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CBBView �׸���

void CBBView::OnDraw(CDC* pDC)
{
	CBBDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	DrawPT(pDC);
}


// CBBView �μ�

BOOL CBBView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CBBView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CBBView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CBBView ����

#ifdef _DEBUG
void CBBView::AssertValid() const
{
	CView::AssertValid();
}

void CBBView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBBDoc* CBBView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBBDoc)));
	return (CBBDoc*)m_pDocument;
}
#endif //_DEBUG


// CBBView �޽��� ó����


void CBBView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	x1 = x2 = point.x;
	y1 = y2 = point.y;
	CView::OnLButtonDown(nFlags, point);
}


void CBBView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (type != FREEDRAW) {
		pt[pt_cnt].x1 = x1;
		pt[pt_cnt].y1 = y1;
		pt[pt_cnt].x2 = point.x;
		pt[pt_cnt].y2 = point.y;
	}
	else {
		tmp_pt[tmp_pt_cnt].x1 = point.x;
		tmp_pt[tmp_pt_cnt].y1 = point.y;
		tmp_pt_cnt++;
		pt[pt_cnt].line = (FREELINE*)malloc(tmp_pt_cnt * sizeof(FREELINE));
		memcpy(pt[pt_cnt].line, tmp_pt, tmp_pt_cnt * sizeof(FREELINE));
		pt[pt_cnt].x1 = tmp_pt_cnt;
		tmp_pt_cnt = 0;
	}
	pt[pt_cnt].col = mColor;
	pt[pt_cnt++].type = type;
	Invalidate(); //OnDraw�Լ� �ڵ�����
	CView::OnLButtonUp(nFlags, point);
}


void CBBView::DrawPT(CDC* p)
{
	CBrush br;
	CPen pen;

	for (int i = 0; i < pt_cnt; i++) {		
		br.CreateSolidBrush(pt[i].col);
		pen.CreatePen(PS_SOLID, 2, pt[i].col);
		p->SelectObject(&br);
		p->SelectObject(&pen);
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
			for (int j = 0; j < pt[i].x1 - 1; j++) {
				p->MoveTo(pt[i].line[j].x1, pt[i].line[j].y1);
				p->LineTo(pt[i].line[j + 1].x1, pt[i].line[j + 1].y1);
			}
			break;
		default:
			break;
		}
		br.DeleteObject();
		pen.DeleteObject();
	}
}


void CBBView::OnEllipse()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	type = ELLIPSE;
}


void CBBView::OnFree()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	type = FREEDRAW;
}


void CBBView::OnLine()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	type = LINE;
}


void CBBView::OnRect()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	type = RECTANGLE;
}


void CBBView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.	
	if (nFlags&MK_LBUTTON) {
		CClientDC dc(this);
		CBrush br;
		CPen pen;
		br.CreateSolidBrush(mColor);
		dc.SelectObject(&br);
		if (type == LINE) {
			pen.CreatePen(PS_SOLID, 2, mColor);
			dc.SelectObject(&pen);
			//dc.SetROP2(R2_XORPEN);
			dc.SetROP2(R2_NOTXORPEN);
			dc.MoveTo(x1, y1);
			dc.LineTo(x2, y2);
			dc.MoveTo(x1, y1);
			dc.LineTo(point.x, point.y);
			x2 = point.x;
			y2 = point.y;
		}
		else if (type == RECTANGLE) {
			pen.CreatePen(PS_SOLID, 2, mColor);
			dc.SelectObject(&pen);
			//dc.SetROP2(R2_XORPEN);
			dc.SetROP2(R2_NOTXORPEN);
			dc.Rectangle(x1, y1, x2, y2);
			dc.Rectangle(x1, y1, point.x, point.y);
			x2 = point.x;
			y2 = point.y;
		}
		else if (type == ELLIPSE) {
			pen.CreatePen(PS_SOLID, 2, mColor);
			dc.SelectObject(&pen);
			//dc.SetROP2(R2_XORPEN);
			dc.SetROP2(R2_NOTXORPEN);
			dc.Ellipse(x1, y1, x2, y2);
			dc.Ellipse(x1, y1, point.x, point.y);
			x2 = point.x;
			y2 = point.y;
		}
		else if (type == FREEDRAW) {
			pen.CreatePen(PS_SOLID, 2, mColor);
			dc.SelectObject(&pen);
			dc.SetROP2(R2_NOTXORPEN);
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
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->SetCheck(type == ELLIPSE);
}


void CBBView::OnUpdateFree(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->SetCheck(type == FREEDRAW);
}


void CBBView::OnUpdateLine(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->SetCheck(type == LINE);
}


void CBBView::OnUpdateRect(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	pCmdUI->SetCheck(type == RECTANGLE);
}


void CBBView::OnColor()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CColorDialog c;
	if (c.DoModal() == IDOK)
		mColor = c.GetColor();
}


void CBBView::OnUpdateColor(CCmdUI *pCmdUI)
{
	// TODO: ���⿡ ��� ������Ʈ UI ó���� �ڵ带 �߰��մϴ�.
	
}


void CBBView::OnText()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	CTextDlg t;

	if (t.DoModal() == IDOK) {
		CClientDC dc(this);
		CFont f;
		//f.CreatePointFont(t.Cb.GetCurSel() + 1, pFont[t.Lb.GetCurSel()]);
		f.CreatePointFont((t.a + 1)*10, pFont[t.b]);
		dc.SelectObject(&f);
		dc.TextOut(100, 200, t.mText);
	}
}
