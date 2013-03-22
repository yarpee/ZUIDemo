#pragma once

#include "resource.h"

#define ZUI_DEBUG

#ifdef ZUI_DEBUG

#include "ZGlobal.h"
#include "ZWindow.h"
#include "ZStatic.h"
#include "ZButton.h"

LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

class CMyWindow : public CZWindow
{
public:
	CMyWindow()
	{
		//CZStatic* pStatic = new CZStatic();
		//pStatic->SetText(_T("Hello ZUI!"));
		CZButton* pButton = new CZButton();
		pButton->SetText(_T("Hello ZUI!"));
		pButton->SetStateImage(BS_NORMAL, _T("button_normal.bmp"));
		pButton->SetStateImage(BS_HOVER, _T("button_hover.bmp"));
		pButton->SetStateImage(BS_PUSH, _T("button_push.bmp"));
		m_pRootCtrl = pButton;
	}

	~CMyWindow()
	{
		delete m_pRootCtrl;
		m_pRootCtrl = NULL;
	}

	HWND Create(DWORD dwStyle, DWORD dwExStyle, RECT& rc)
	{
		HWND hWnd = NULL;
		if(RegisterWindowClass())
		{
			hWnd = CreateZWindow(dwStyle, dwExStyle, rc);
			RECT rc = {0};
			::GetClientRect(m_hWnd, &rc);
			rc.right = 75;
			rc.bottom = 24;
			m_pRootCtrl->SetSize(rc);
		}
		return hWnd;
	}

protected:
	virtual HICON GetClassIcon(BOOL bSmall = FALSE)
	{
		if(bSmall)
		{
			return LoadIcon(GetInstance(), MAKEINTRESOURCE(IDI_SMALL));
		}
		else
		{
			return LoadIcon(GetInstance(), MAKEINTRESOURCE(IDI_ZUIDEMO));
		}
	}

	virtual LPCTSTR GetClassMenuName()
	{
		return MAKEINTRESOURCE(IDC_ZUIDEMO);
	}

	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		switch(uMsg)
		{
		case WM_PAINT:
		case WM_MOUSEMOVE:
		case WM_LBUTTONDOWN:
		case WM_LBUTTONUP:
			bHandled = FALSE;
			return 0;
			break;
		default:
			bHandled = TRUE;
			return WndProc(m_hWnd, uMsg, wParam, lParam);
			break;
		}
	}
};

#endif
