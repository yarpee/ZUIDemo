//////////////////////////////////////////////////////////////////////////
// Creator: Z
// Brief: Application Module
// Version: 1.0
// Change:
// 1.2013/3/16 Z/1.0/����

#pragma once

#include "ZDef.h"

class CZAppModule
{
public:
	CZAppModule(void);
	~CZAppModule(void);

	BOOL Init(HINSTANCE hInstance);
	VOID Term();

	HINSTANCE GetInstance();

protected:
	CZCritSec m_cs;
	HINSTANCE m_hInstance;
};
