
// MFCfirst3.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCfirst3App:
// �йش����ʵ�֣������ MFCfirst3.cpp
//

class CMFCfirst3App : public CWinApp
{
public:
	CMFCfirst3App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCfirst3App theApp;