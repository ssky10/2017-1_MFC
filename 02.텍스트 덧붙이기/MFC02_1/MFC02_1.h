
// MFC02_1.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CMFC02_1App:
// �� Ŭ������ ������ ���ؼ��� MFC02_1.cpp�� �����Ͻʽÿ�.
//

class CMFC02_1App : public CWinApp
{
public:
	CMFC02_1App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CMFC02_1App theApp;