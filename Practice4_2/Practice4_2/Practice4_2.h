
// Practice4_2.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CPractice4_2App:
// �� Ŭ������ ������ ���ؼ��� Practice4_2.cpp�� �����Ͻʽÿ�.
//

class CPractice4_2App : public CWinApp
{
public:
	CPractice4_2App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CPractice4_2App theApp;