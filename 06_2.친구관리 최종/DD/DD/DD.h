
// DD.h : DD ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.

typedef struct
{
	WCHAR name[20], tel[14];
	char addr1, addr2, addr3; WCHAR addr4[20];
	char age, sex, married, kids, hobby;
}FR;

// CDDApp:
// �� Ŭ������ ������ ���ؼ��� DD.cpp�� �����Ͻʽÿ�.
//

class CDDApp : public CWinApp
{
public:
	CDDApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDDApp theApp;
