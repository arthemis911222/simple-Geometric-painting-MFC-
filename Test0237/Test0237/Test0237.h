
// Test0237.h : Test0237 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CTest0237App:
// �йش����ʵ�֣������ Test0237.cpp
//

class CTest0237App : public CWinApp
{
public:
	CTest0237App();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTest0237App theApp;
