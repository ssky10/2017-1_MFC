
// CC.h : CC ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.

typedef struct {
	WCHAR txt[40];
	CPoint xy;
	int len;
}FR;


// CCCApp:
// �� Ŭ������ ������ ���ؼ��� CC.cpp�� �����Ͻʽÿ�.
//

class CCCApp : public CWinAppEx
{
public:
	CCCApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCCApp theApp;
