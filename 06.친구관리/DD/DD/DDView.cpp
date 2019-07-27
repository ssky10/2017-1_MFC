
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

CString Addr1[4] = { L"경남",L"경북",L"부산",L"서울" };
CString Addr2[4][5] = { { L"거창군",L"고성군",L"사천시",L"진주시",L"창원시" },
				  	  { L"군위군",L"영천시"},
					  { L"동래구",L"사상구",L"해운대구"},
					  { L"강남구",L"서초구"} };
CString Addr3[4][5][6] = {{{ L"geo1",L"geo2",L"geo3",L"geo4",L"geo5"},{ L"go1",L"go2",L"go3",L"go4",L"go5",L"go6"},{ L"sa1",L"sa2"},{ L"jin1",L"jin2",L"jin3"},{ L"ch1"}},
						{{ L"gun1",L"gun2"},{ L"yc1"}},
						{{ L"dong1",L"dong2",L"dong3"},{ L"sa1",L"sa2"},{ L"hae1",L"hae2",L"hae3"}},
						{{ L"gang1",L"gang2"},{L"cho1",L"cho2",L"cho3"}}};
int Addr1Cnt = 4, Addr2Cnt[4] = { 5,2,3,2 }, Addr3Cnt[4][5] = { {5,6,2,3,1},{2,1},{3,2,3},{2,3} };

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
		mCtrlList.AddString(c.mName);		
	}
}
