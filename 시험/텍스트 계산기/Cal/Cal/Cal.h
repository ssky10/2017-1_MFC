
// Cal.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.

#define NEDIT 0
#define EDIT1 1
#define EDIT2 2



// CCalApp:
// �� Ŭ������ ������ ���ؼ��� Cal.cpp�� �����Ͻʽÿ�.
//

class CCalApp : public CWinApp
{
public:
	CCalApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CCalApp theApp;