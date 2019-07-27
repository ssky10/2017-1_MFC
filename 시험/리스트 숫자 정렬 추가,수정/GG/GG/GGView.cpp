
// GGView.cpp : CGGView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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

// CGGView ����/�Ҹ�

CGGView::CGGView()
	: CFormView(IDD_GG_FORM)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

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
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void CGGView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CGGView ����

#ifdef _DEBUG
void CGGView::AssertValid() const
{
	CFormView::AssertValid();
}

void CGGView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CGGDoc* CGGView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGGDoc)));
	return (CGGDoc*)m_pDocument;
}
#endif //_DEBUG


// CGGView �޽��� ó����


void CGGView::OnBnClickedButton1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
