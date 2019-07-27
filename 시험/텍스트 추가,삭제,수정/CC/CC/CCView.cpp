
// CCView.cpp : CCCView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "CC.h"
#endif

#include "CCDoc.h"
#include "CCView.h"
#include "TextDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCCView

IMPLEMENT_DYNCREATE(CCCView, CView)

BEGIN_MESSAGE_MAP(CCCView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

// CCCView ����/�Ҹ�

CCCView::CCCView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CCCView::~CCCView()
{
}

BOOL CCCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CCCView �׸���

void CCCView::OnDraw(CDC* pDC)
{
	CCCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	int cnt = pDoc->mFrCnt;
	for (int i = 0; i < cnt; i++) {
		if (pDoc->mFr[i] == NULL);
		else {
			DispFr(pDoc->mFr[i],pDC);
		}
	}
	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CCCView �μ�

BOOL CCCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CCCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CCCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CCCView ����

#ifdef _DEBUG
void CCCView::AssertValid() const
{
	CView::AssertValid();
}

void CCCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCCDoc* CCCView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCCDoc)));
	return (CCCDoc*)m_pDocument;
}
#endif //_DEBUG


// CCCView �޽��� ó����


void CCCView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CTextDlg t;
	CCCDoc *p = GetDocument();
	int flg=0;
	int cnt = SerchText(point);
	if (cnt == -1) {
		cnt = GetIdx4Insert(p);
		flg = 1;
	}
	else t.mText = p->mFr[cnt]->txt;

	if (t.DoModal() == IDOK) {
		if (cnt == p->mFrCnt) p->mFr[cnt] = (FR*)malloc(sizeof(FR));
		wcscpy(p->mFr[cnt]->txt,t.mText);
		if(flg==1) p->mFr[cnt]->xy = point;
		else;
		p->mFr[cnt]->len = t.mText.GetLength();
		if (cnt == p->mFrCnt) p->mFrCnt++;
		
		Invalidate();
	}
	
	CView::OnLButtonDown(nFlags, point);
}



void CCCView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	int cnt = SerchText(point);

	if (cnt == -1) return;
	if (MessageBox(L"�����Ͻðڽ��ϱ�?",L"����",1) == IDOK) {
		CCCDoc *p = GetDocument();
		free(p->mFr[cnt]);
		p->mFr[cnt] = NULL;
		if (cnt == p->mFrCnt) p->mFrCnt--;
	}
		
	Invalidate();
	CView::OnRButtonDown(nFlags, point);
}

int CCCView::GetIdx4Insert(CCCDoc* p)
{
	int i;
	for (i = 0; i < p->mFrCnt; i++)
		if (p->mFr[i] == 0) return i;
	return i;
}

void CCCView::DispFr(FR *f, CDC* p)
{
	CFont fo;

	fo.CreatePointFont(200,L"����ü");
	p->SelectObject(&fo);
	p->TextOut(f->xy.x, f->xy.y, f->txt);
}


int CCCView::SerchText(CPoint xy)
{
	CCCDoc *p = GetDocument();
	int cnt = p->mFrCnt;
	for (int i = 0; i < p->mFrCnt; i++)
		if ((xy.x < ((p->mFr[i]->xy.x) + (p->mFr[i]->len * 200))) && (xy.x > (p->mFr[i]->xy.x)))
			if ((xy.y < ((p->mFr[i]->xy.y) + 20)) && (xy.y > (p->mFr[i]->xy.y)))
				return i;
	return -1;
}


void CCCView::OnDestroy()
{
	CView::OnDestroy();

	GetDocument()->SaveData();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


void CCCView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	GetDocument()->LoadData();
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
}
