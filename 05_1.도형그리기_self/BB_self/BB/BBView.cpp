
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
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CBBView ����/�Ҹ�

CBBView::CBBView()
	:pt_cnt(0)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	type = LINE;
	tmp_pt_cnt = 0;
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
	xy1 = xy2 = point;
	CView::OnLButtonDown(nFlags, point);
}


void CBBView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if(xy.x>point.x) AddPT(pt, point, xy);
	else AddPT(pt, xy, point);
	pt_cnt++;
	Invalidate(); //OnDraw�Լ� �ڵ�����
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	for (int i = 0; i < pt_cnt; i++) {
		if (pt[i].x1- 10 > point.x) break;
		if ((pt[i].x1- 10 <= point.x) && (pt[i].x2+ 10 >= point.x)) {
			if (CheckPT(point, pt[i])) {
				DeletePT(pt, i);
				pt_cnt--;
			}
		}
	}
	Invalidate(); //OnDraw�Լ� �ڵ�����
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
