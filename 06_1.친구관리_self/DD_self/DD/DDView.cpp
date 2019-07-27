
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
		CString s;
		s.Format(_T("%s\t%s\t%s\t%d"), c.mName, c.mAddr4, c.mTel, c.mAge);
		mCtrlList.AddString(s);
	}
}
