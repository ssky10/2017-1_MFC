
// DDView.cpp : CDDView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "DD.h"
#endif

#include "DDDoc.h"
#include "DDView.h"
#include "Info.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDDView

IMPLEMENT_DYNCREATE(CDDView, CFormView)

BEGIN_MESSAGE_MAP(CDDView, CFormView)
	ON_BN_CLICKED(IDC_INSERT, &CDDView::OnBnClickedInsert)
END_MESSAGE_MAP()

// CDDView 생성/소멸

CDDView::CDDView()
	: CFormView(IDD_DD_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CDDView::~CDDView()
{
}

void CDDView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, mCtrlList);
}

BOOL CDDView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CDDView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDDView 진단

#ifdef _DEBUG
void CDDView::AssertValid() const
{
	CFormView::AssertValid();
}

void CDDView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDDDoc* CDDView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDDDoc)));
	return (CDDDoc*)m_pDocument;
}
#endif //_DEBUG


// CDDView 메시지 처리기


void CDDView::OnBnClickedInsert()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CInfo c;

	if (c.DoModal() == IDOK) {
		CString s;
		s.Format(_T("%s\t%s\t%s\t%d"), c.mName, c.mAddr4, c.mTel, c.mAge);
		mCtrlList.AddString(s);
	}
}
