
// BB.h : BB ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.

#define LINE 1
#define ELLIPSE 2
#define RECTANGLE 3
#define FREEDRAW 4
#define ERASER 5

#define ERR 10

// CBBApp:
// �� Ŭ������ ������ ���ؼ��� BB.cpp�� �����Ͻʽÿ�.
//

class CBBApp : public CWinAppEx
{
public:
	CBBApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CBBApp theApp;
