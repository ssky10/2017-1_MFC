
// Cal.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CCalApp:
// �� Ŭ������ ������ ���ؼ��� Cal.cpp�� �����Ͻʽÿ�.
//

#define NOOP 0
#define PLUS 1
#define MINUS 2
#define MUL 3
#define DIVIDE 4


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