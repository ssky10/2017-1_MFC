
// MFC_0View.cpp : CMFC_0View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "MFC_0.h"
#endif

#include "MFC_0Doc.h"
#include "MFC_0View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_0View

IMPLEMENT_DYNCREATE(CMFC_0View, CView)

BEGIN_MESSAGE_MAP(CMFC_0View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_SIZE()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CMFC_0View ����/�Ҹ�

CMFC_0View::CMFC_0View()
	: m_strWindowSize(_T(""))
	, m_strOutText(_T(""))
	, m_bDrag(false)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CMFC_0View::~CMFC_0View()
{
}

BOOL CMFC_0View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CMFC_0View �׸���

void CMFC_0View::OnDraw(CDC* pDC)
{
	CMFC_0Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	pDC->TextOut(10, 10, m_strWindowSize);
	CRect rect;
	GetClientRect(&rect);
	pDC->DrawText(m_strOutText, rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}


// CMFC_0View �μ�

BOOL CMFC_0View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CMFC_0View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CMFC_0View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CMFC_0View ����

#ifdef _DEBUG
void CMFC_0View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_0View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_0Doc* CMFC_0View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_0Doc)));
	return (CMFC_0Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_0View �޽��� ó����


void CMFC_0View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.

	m_strWindowSize.Format(_T("������â�� ũ��� ����:%d, ����:%d�Դϴ�."), cx, cy);
	Invalidate();
}


void CMFC_0View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_strOutText.Format(_T("%c�� Ű���尡 ���������ϴ�."), nChar);
	Invalidate();

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMFC_0View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_bDrag = true;
	m_strOutText.Format(_T("���콺 ���� ��ư�� ���������ϴ�."));
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}


void CMFC_0View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_bDrag = false;

	CView::OnLButtonUp(nFlags, point);
}


void CMFC_0View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_strOutText.Format(_T("���콺 ������ ��ư�� �������ϴ�."));
	Invalidate();
	CView::OnRButtonDown(nFlags, point);
}


void CMFC_0View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (m_bDrag == true)
		m_strOutText.Format(_T("���콺 �巡�� ���Դϴ�."));
	else
		m_strOutText.Format(_T("���콺 �̵� ���Դϴ�."));
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}
