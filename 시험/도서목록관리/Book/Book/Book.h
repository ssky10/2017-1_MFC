
// Book.h : Book ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.

typedef struct
{
	WCHAR name[20], pay[14];
	char cop, lang;
}FR;


// CBookApp:
// �� Ŭ������ ������ ���ؼ��� Book.cpp�� �����Ͻʽÿ�.
//

class CBookApp : public CWinApp
{
public:
	CBookApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CBookApp theApp;
