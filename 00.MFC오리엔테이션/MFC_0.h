
// MFC_0.h : MFC_0 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMFC_0App:
// �� Ŭ������ ������ ���ؼ��� MFC_0.cpp�� �����Ͻʽÿ�.
//

class CMFC_0App : public CWinAppEx
{
public:
	CMFC_0App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC_0App theApp;
