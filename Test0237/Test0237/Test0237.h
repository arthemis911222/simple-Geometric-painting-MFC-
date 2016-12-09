
// Test0237.h : Test0237 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CTest0237App:
// 有关此类的实现，请参阅 Test0237.cpp
//

class CTest0237App : public CWinApp
{
public:
	CTest0237App();


// 重写
public:
	virtual BOOL InitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTest0237App theApp;
