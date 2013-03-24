//////////////////////////////////////////////////////////////////////////
// Creator: Z
// Brief: 内部全局定义
// Version: 1.0
// Change:
// 1.2013/3/16 Z/1.0/创建

#pragma once

#include <Windows.h>
#include <atlbase.h>

#define _Z_VER	0x0100	// ZUI version 1.00

// RECT
inline LONG GetRectWidth(const RECT& rc)
{
	return rc.right - rc.left;
}

inline LONG GetRectHeight(const RECT& rc)
{
	return rc.bottom - rc.top;
}

//////////////////////////////////////////////////////////////////////////
// State
#define ST_NORMAL	0x00000000
#define ST_HOVER	0x00000001
#define ST_PUSH		0x00000002
#define ST_FOCUS	0x00000004
#define ST_DISABLE	0x00000008

//////////////////////////////////////////////////////////////////////////
// Event
typedef struct _EVENT
{
	DWORD	dwEventID;
	WPARAM	wParam;
	LPARAM	lParam;
	DWORD	dwTimestamp;
	POINT	ptMouse;
} EVENT, *PEVENT;

#define E_BASE			0x00000000
#define E_MOUSEMOVE		E_BASE + 1
#define E_MOUSELEAVE	E_MOUSEMOVE + 1
#define E_LBUTTONDOWN	E_MOUSELEAVE + 1
#define E_LBUTTONUP		E_LBUTTONDOWN + 1
#define E_SETFOCUS		E_LBUTTONUP + 1
#define E_KILLFOCUS		E_SETFOCUS + 1

//////////////////////////////////////////////////////////////////////////
// Critical Section
typedef CComAutoCriticalSection CZCritSec;
typedef CComCritSecLock<CComAutoCriticalSection> CZCritSecLock;
