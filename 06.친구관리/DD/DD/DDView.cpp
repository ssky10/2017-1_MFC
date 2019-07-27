
// DDView.cpp : CDDView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "DD.h"
#endif

#include "DDDoc.h"
#include "DDView.h"
#include "Info.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CString Addr1[4] = { L"�泲",L"���",L"�λ�",L"����" };
CString Addr2[4][5] = { { L"��â��",L"����",L"��õ��",L"���ֽ�",L"â����" },
				  	  { L"������",L"��õ��"},
					  { L"������",L"���",L"�ؿ�뱸"},
					  { L"������",L"���ʱ�"} };
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

// CDDView ����/�Ҹ�

CDDView::CDDView()
	: CFormView(IDD_DD_FORM)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

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
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void CDDView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDDView ����

#ifdef _DEBUG
void CDDView::AssertValid() const
{
	CFormView::AssertValid();
}

void CDDView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDDDoc* CDDView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDDDoc)));
	return (CDDDoc*)m_pDocument;
}
#endif //_DEBUG


// CDDView �޽��� ó����


void CDDView::OnBnClickedInsert()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CInfo c;

	if (c.DoModal() == IDOK) {
		mCtrlList.AddString(c.mName);		
	}
}
