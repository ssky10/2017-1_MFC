
// MFC_0View.cpp : CMFC_0View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
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

// CMFC_0View 생성/소멸

CMFC_0View::CMFC_0View()
	: m_strWindowSize(_T(""))
	, m_strOutText(_T(""))
	, m_bDrag(false)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFC_0View::~CMFC_0View()
{
}

BOOL CMFC_0View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFC_0View 그리기

void CMFC_0View::OnDraw(CDC* pDC)
{
	CMFC_0Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	pDC->TextOut(10, 10, m_strWindowSize);
	CRect rect;
	GetClientRect(&rect);
	pDC->DrawText(m_strOutText, rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
}


// CMFC_0View 인쇄

BOOL CMFC_0View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFC_0View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFC_0View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMFC_0View 진단

#ifdef _DEBUG
void CMFC_0View::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_0View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_0Doc* CMFC_0View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_0Doc)));
	return (CMFC_0Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFC_0View 메시지 처리기


void CMFC_0View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	m_strWindowSize.Format(_T("윈도우창의 크기는 가로:%d, 세로:%d입니다."), cx, cy);
	Invalidate();
}


void CMFC_0View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_strOutText.Format(_T("%c의 키보드가 눌러졌습니다."), nChar);
	Invalidate();

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CMFC_0View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_bDrag = true;
	m_strOutText.Format(_T("마우스 왼쪽 버튼이 눌러졌습니다."));
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}


void CMFC_0View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_bDrag = false;

	CView::OnLButtonUp(nFlags, point);
}


void CMFC_0View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_strOutText.Format(_T("마우스 오른쪽 버튼을 눌렀습니다."));
	Invalidate();
	CView::OnRButtonDown(nFlags, point);
}


void CMFC_0View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bDrag == true)
		m_strOutText.Format(_T("마우스 드래그 중입니다."));
	else
		m_strOutText.Format(_T("마우스 이동 중입니다."));
	Invalidate();
	CView::OnMouseMove(nFlags, point);
}
