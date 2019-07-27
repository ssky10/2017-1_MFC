
// DDView.cpp : CDDView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "DD.h"
#endif

#include "Info.h"
#include "DDDoc.h"
#include "DDView.h"

#define CLIMBING 5
#define FISHING 4
#define GAME 3
#define READ 2 
#define BIKE 1
#define WEB 0



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
	ON_WM_DESTROY()
	ON_NOTIFY(NM_CLICK, IDC_LIST, &CDDView::OnClickList)
	ON_BN_CLICKED(IDC_DELETE, &CDDView::OnClickedDelete)
	ON_BN_CLICKED(IDC_OPDATE, &CDDView::OnBnClickedOpdate)
END_MESSAGE_MAP()

// CDDView ����/�Ҹ�

CDDView::CDDView()
	: CFormView(IDD_DD_FORM)
	, idx(-1)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	//idx = 0;
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

void CDDView::Invalidate()
{
	CFormView::Invalidate();
	CDDDoc *p=GetDocument();
	for (int i = 0; i < p->mFrCnt; i++)
		DispFr2(p->mFr[i], i);
}

void CDDView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	LV_COLUMN col;
	WCHAR name[8][6] = { L"Name", L"Addr",L"Tel",L"age",L"sex",L"merry",L"kids",L"hobby" };
	int width[8] = { 60,250,70,25,25,30,30,100 };
	for (int i = 0; i < 8; i++) {
		col.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
		col.fmt = LVCFMT_CENTER;
		col.pszText = name[i];
		col.iSubItem =i;
		col.cx = width[i];
		col.cchTextMax = width[i];
		mCtrlList.InsertColumn(i, &col);
	}
	mCtrlList.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	GetDocument()->LoadData();
	Invalidate();
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
	c.mMarried = 0;
	c.mKids = 0;
	if (c.DoModal() == IDOK) {
		DispFr(SaveFr(c));
	}
}


int CDDView::SaveFr(CInfo &d)
{
	CDDDoc *p = GetDocument(); int cnt = GetIdx4Insert(p);
	p->mFr[cnt] = (FR*)calloc(1,sizeof(FR));
	wcscpy(p->mFr[cnt]->name, d.mName);
	p->mFr[cnt]->addr1 = d.mAddr1;
	p->mFr[cnt]->addr2 = d.mAddr2;
	p->mFr[cnt]->addr3 = d.mAddr3;
	wcscpy(p->mFr[cnt]->addr4, d.mAddr4);
	wcscpy(p->mFr[cnt]->tel, d.mTel);
	p->mFr[cnt]->age = d.mAge;
	p->mFr[cnt]->sex = d.mSex;
	p->mFr[cnt]->married = d.mMarried;
	p->mFr[cnt]->kids = d.mKids;
	p->mFr[cnt]->hobby = BindHobbyChar(&d);
	if(cnt == p->mFrCnt) p->mFrCnt++;
	return cnt;
}

int CDDView::SaveFr2(CInfo &d, int cnt)
{
	CDDDoc *p = GetDocument();
	p->mFr[cnt] = (FR*)calloc(1, sizeof(FR));
	wcscpy(p->mFr[cnt]->name, d.mName);
	p->mFr[cnt]->addr1 = d.mAddr1;
	p->mFr[cnt]->addr2 = d.mAddr2;
	p->mFr[cnt]->addr3 = d.mAddr3;
	wcscpy(p->mFr[cnt]->addr4, d.mAddr4);
	wcscpy(p->mFr[cnt]->tel, d.mTel);
	p->mFr[cnt]->age = d.mAge;
	p->mFr[cnt]->sex = d.mSex;
	p->mFr[cnt]->married = d.mMarried;
	p->mFr[cnt]->kids = d.mKids;
	p->mFr[cnt]->hobby = BindHobbyChar(&d);
	return cnt;
}

void CDDView::DispFr(int cnt) {
	CDDDoc *p = GetDocument(); //int cnt = (p->mFrCnt)-1;
	CString s,addr;
	mCtrlList.InsertItem(cnt,p->mFr[cnt]->name);
	BindAddrStr(addr, p->mFr[cnt]);
	mCtrlList.SetItemText(cnt, 1, addr);
	mCtrlList.SetItemText(cnt, 2,p->mFr[cnt]->tel);
	s.Format(L"%d", (p->mFr[cnt]->age) + 1);
	mCtrlList.SetItemText(cnt, 3,s);
	mCtrlList.SetItemText(cnt, 4,(p->mFr[cnt]->sex? L"��":L"��"));
	mCtrlList.SetItemText(cnt, 5,(p->mFr[cnt]->married ? L"��ȥ" : L"��ȥ"));
	s.Format(L"%d��", p->mFr[cnt]->kids);
	mCtrlList.SetItemText(cnt, 6, s);
	MakeHobbyStr(s, p->mFr[cnt]);
	mCtrlList.SetItemText(cnt, 7, s);
}

void CDDView::DispFr2(FR *fr, int idx) {
	CString s, addr;
	mCtrlList.InsertItem(idx, fr->name);
	BindAddrStr(addr, fr);
	mCtrlList.SetItemText(idx, 1, addr);
	mCtrlList.SetItemText(idx, 2, fr->tel);
	s.Format(L"%d", (fr->age) + 1);
	mCtrlList.SetItemText(idx, 3, s);
	mCtrlList.SetItemText(idx, 4, (fr->sex ? L"��" : L"��"));
	mCtrlList.SetItemText(idx, 5, (fr->married ? L"��ȥ" : L"��ȥ"));
	s.Format(L"%d��", fr->kids);
	mCtrlList.SetItemText(idx, 6, s);
	MakeHobbyStr(s, fr);
	mCtrlList.SetItemText(idx, 7, s);
}


void CDDView::BindAddrStr(CString &s, FR *f) {
	s.Format(L"%s %s %s %s", Addr1[f->addr1], Addr2[f->addr1][f->addr2], Addr3[f->addr1][f->addr2][f->addr3], f->addr4);
}

char CDDView::BindHobbyChar(CInfo *d)
{
	char c = 0;
	c = d->mClimb << CLIMBING |
		d->mFish << FISHING |
		d->mGame << GAME |
		d->mRead << READ |
		d->mBike << BIKE |
		d->mWeb << WEB;
	return c;
}

void CDDView::MakeHobbyStr(CString &s, FR *f)
{
	s = L"";
	if (f->hobby & (0x01 << CLIMBING)) s += L"��� ";
	if (f->hobby & (0x01 << FISHING)) s += L"���� ";
	if (f->hobby & (0x01 << GAME)) s += L"���� ";
	if (f->hobby & (0x01 << READ)) s += L"���� ";
	if (f->hobby & (0x01 << BIKE)) s += L"������ ";
	if (f->hobby & (0x01 << WEB)) s += L"������";
}


void CDDView::OnDestroy()
{
	CFormView::OnDestroy();
	GetDocument()->SaveData();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


void CDDView::OnClickList(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	idx = pNMItemActivate->iItem;
	*pResult = 0;
}


void CDDView::OnClickedDelete()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (idx == -1) MessageBox(L"����Ʈ�� ������ �ּ���.");
	else {
		CDDDoc *p = GetDocument();
		free(p->mFr[idx]);
		p->mFr[idx] = NULL;
		mCtrlList.DeleteItem(idx);
	}
}


void CDDView::OnBnClickedOpdate()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (idx == -1) MessageBox(L"����Ʈ�� ������ �ּ���.");
	else {
		CInfo c;
		CDDDoc *p = GetDocument();
		
		SetCinfoView(c, p->mFr[idx]);

		if (c.DoModal() == IDOK) {
			mCtrlList.DeleteItem(idx);
			DispFr(SaveFr2(c,idx));
		}
	}
}


int CDDView::GetIdx4Insert(CDDDoc* p)
{
	int i;
	for (i = 0; i < p->mFrCnt; i++)
		if (p->mFr[i] == 0) return i;
	return i;
}


void CDDView::SetCinfoView(CInfo &c, FR *f)
{
	//c.mName.AppendFormat(f->name);
	c.mName = f->name;
	c.mAddr1 = f->addr1;
	c.mAddr2 = f->addr2;
	c.mAddr3 = f->addr3;
	c.mAddr4.AppendFormat(f->addr4);
	c.mTel.AppendFormat(f->tel);
	c.mAge = f->age;
	c.mSex = f->sex;
	c.mMarried = f->married;
	c.mKids = f->kids;
	char hobby = f->hobby;
	if (hobby & (0x01 << CLIMBING)) c.mClimb = 1;
	if (hobby & (0x01 << FISHING)) c.mFish = 1;
	if (hobby & (0x01 << GAME)) c.mGame = 1;
	if (hobby & (0x01 << READ)) c.mRead = 1;
	if (hobby & (0x01 << BIKE)) c.mBike = 1;
	if (hobby & (0x01 << WEB)) c.mWeb = 1;
	//c.mWeb = (hobby & (0x01 << WEB)) >> WEB;
}
