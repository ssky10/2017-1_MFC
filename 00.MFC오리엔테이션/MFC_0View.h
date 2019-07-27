
// MFC_0View.h : CMFC_0View Ŭ������ �������̽�
//

#pragma once


class CMFC_0View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMFC_0View();
	DECLARE_DYNCREATE(CMFC_0View)

// Ư���Դϴ�.
public:
	CMFC_0Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CMFC_0View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	// ������ â�� ũ�⳪Ÿ�� �ִ� ���ڿ�
	CString m_strWindowSize;
	// ���콺�� Ű������ ���� ���ڿ�
	CString m_strOutText;
	// ���콺 �巡�� ����(���� ���콺 Ű) üũ
	bool m_bDrag;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFC_0View.cpp�� ����� ����
inline CMFC_0Doc* CMFC_0View::GetDocument() const
   { return reinterpret_cast<CMFC_0Doc*>(m_pDocument); }
#endif

