#pragma once

#include "resource.h"

#define ZUI_DEBUG

#ifdef ZUI_DEBUG

#include "ZGlobal.h"
#include "ZWindow.h"
#include "ZStatic.h"
#include "ZButton.h"
#include "ZDef.h"
#include "ZUIMgr.h"

LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

class CMyWindow : public CZWindow, public INotify
{
public:
	CMyWindow()
	{
		//CZStatic* pStatic = new CZStatic();
		//pStatic->SetText(_T("Hello ZUI!"));
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
		}
		return hWnd;
	}

	VOID AddCtrl()
	{
		RECT rc = {0};
		pButton = new CZButton();
		pButton->SetText(_T("Hello ZUI!"));
		pButton->SetStateImage(ST_NORMAL, _T("button_normal.bmp"));
		pButton->SetStateImage(ST_HOVER, _T("button_hover.bmp"));
		pButton->SetStateImage(ST_PUSH, _T("button_push.bmp"));
		pButton->SetStateImage(ST_FOCUS, _T("button_normal.bmp"));
		pButton->SetBorderSize(1);
		pButton->SetBorderFocusColor(0xFF0000);
		SIZE sz = {5, 5};
		pButton->SetBorderRound(sz);
		rc.right = 75;
		rc.bottom = 24;
		pButton->SetSize(rc);
		m_pRootCtrl->AddChild(pButton);

		pButton2 = new CZButton();
		pButton2->SetText(_T("Button"));
		pButton2->SetStateImage(ST_NORMAL, _T("button_normal.bmp"));
		pButton2->SetStateImage(ST_HOVER, _T("button_hover.bmp"));
		pButton2->SetStateImage(ST_PUSH, _T("button_push.bmp"));
		pButton2->SetStateImage(ST_FOCUS, _T("button_normal.bmp"));
		pButton2->SetBorderSize(3);
		pButton2->SetBorderFocusColor(0xFF00);
		pButton2->SetBorderRound(sz);
		rc.left = 100;
		rc.right = 100 + 75;
		rc.top = 100;
		rc.bottom = 100 + 24;
		pButton2->SetSize(rc);
		m_pRootCtrl->AddChild(pButton2);

		m_pZUIMgr->AddNotifier(this);
	}

	VOID Notify(const NOTIFY& notify)
	{
		if(N_CLICK == notify.dwNotifyID && pButton2 == notify.pCtrl)
		{
			MessageBox(m_hWnd, _T("Äãµã»÷ÁËButton!"), _T("Notify"), MB_OK);
			PostQuitMessage(0);
		}
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
		//case WM_CREATE:
		//	{
		//		LONG styleValue = ::GetWindowLong(*this, GWL_STYLE);
		//		styleValue &= ~WS_CAPTION;
		//		::SetWindowLong(*this, GWL_STYLE, styleValue | WS_CLIPSIBLINGS | WS_CLIPCHILDREN);
		//		bHandled = TRUE;
		//		return 0;
		//	}
		//	break;
		default:
			bHandled = TRUE;
			return WndProc(m_hWnd, uMsg, wParam, lParam);
			break;
		}
	}

private:
	CZButton* pButton;
	CZButton* pButton2;
};

#endif
