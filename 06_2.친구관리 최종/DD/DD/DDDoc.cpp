
// DDDoc.cpp : CDDDoc 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "DD.h"
#endif

#include "DDDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CDDDoc

IMPLEMENT_DYNCREATE(CDDDoc, CDocument)

BEGIN_MESSAGE_MAP(CDDDoc, CDocument)
END_MESSAGE_MAP()


// CDDDoc 생성/소멸

CDDDoc::CDDDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.
	mFrCnt = 0;
}

CDDDoc::~CDDDoc()
{
}

BOOL CDDDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CDDDoc serialization

void CDDDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}

void CDDDoc::SaveData()
{
	CFile f;
	if (f.Open(L"aa.dat", CFile::modeWrite | CFile::modeCreate)) {
		for (int i = 0; i < mFrCnt; i++)
			if (mFr[i] == NULL);
			else f.Write(mFr[i], sizeof(FR));			
		f.Close();
	}
}

void CDDDoc::LoadData()
{
	CFile f;
	FR fr;
	if (f.Open(L"aa.dat", CFile::modeRead)) {
		while (f.Read(&fr, sizeof(FR)) ){
			mFr[mFrCnt] = (FR*)malloc(sizeof(FR));
			memcpy(mFr[mFrCnt], &fr, sizeof(FR));
			mFrCnt++;
		}
		f.Close();
	}
}


#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CDDDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CDDDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CDDDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CDDDoc 진단

#ifdef _DEBUG
void CDDDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDDDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDDDoc 명령
