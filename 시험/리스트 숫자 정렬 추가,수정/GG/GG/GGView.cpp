
// GGView.cpp : CGGView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "GG.h"
#endif

#include "GGDoc.h"
#include "GGView.h"
#include "EditNum.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGGView

IMPLEMENT_DYNCREATE(CGGView, CFormView)

BEGIN_MESSAGE_MAP(CGGView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CGGView::OnBnClickedButton1)
END_MESSAGE_MAP()

// CGGView 생성/소멸

CGGView::CGGView()
	: CFormView(IDD_GG_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CGGView::~CGGView()
{
}

void CGGView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, Lb);
}

BOOL CGGView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CGGView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CGGView 진단

#ifdef _DEBUG
void CGGView::AssertValid() const
{
	CFormView::AssertValid();
}

void CGGView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CGGDoc* CGGView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGGDoc)));
	return (CGGDoc*)m_pDocument;
}
#endif //_DEBUG


// CGGView 메시지 처리기


void CGGView::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CEditNum n;
	int index1=-1;
	CString a = L"";

	if (Lb.GetCurSel() != -1) {
		index1 = Lb.GetCurSel();
		Lb.GetText(index1, n.mNum);
	}
	
	if (n.DoModal() == IDOK) {
		int num[100];
		int j=0;
		for (int i = 0; n.mNum.GetLength()+1 > i; i++) {
			if (n.mNum[i] == ' ') {
				num[j++] = _wtoi(a);
				if(j!=0){
					for (int k = 0; k < j; k++) {
						if (num[k] > num[j - 1]) {
							int temp;
							temp = num[k];
							num[k] = num[j - 1];
							num[j - 1] = temp;
						}
					}
				}
				a = "";
			}
			else a += n.mNum[i];
		}
		num[j++] = _wtoi(a);
		if (j != 0) {
			for (int k = 0; k < j; k++) {
				if (num[k] > num[j - 1]) {
					int temp;
					temp = num[k];
					num[k] = num[j - 1];
					num[j - 1] = temp;
				}
			}
		}
		a = "";
		for (int i = 0; i < j; i++) {
			CString b;
			b.Format(L"%d ", num[i]);
			a += b;
		}
		if (index1 == -1) {
			Lb.AddString(a);
		}
		else {
			Lb.DeleteString(index1);
			Lb.InsertString(index1, a);
		}
	}
}
