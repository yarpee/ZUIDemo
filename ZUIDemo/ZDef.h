//////////////////////////////////////////////////////////////////////////
// Creator: Z
// Brief: 全局定义
// Version: 1.0
// Change:
// 1.2013/3/16 Z/1.0/创建

#pragma once

#define _Z_VER	0x0100	// ZUI version 1.00

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
