#include "ZButton.h"
#include "ZUIRender.h"

#define BUTTON_CLASS_NAME _T("ZUI Button Class")

CZButton::CZButton(void)
: m_dwState(BS_NORMAL)
{
	m_dwStyle = DT_SINGLELINE | DT_VCENTER | DT_CENTER;
}

CZButton::~CZButton(void)
{
}

LPCTSTR CZButton::GetClassName()
{
	return BUTTON_CLASS_NAME;
}

BOOL CZButton::HandleEvent(EVENT& e)
{
	BOOL bHandled = TRUE;
	switch(e.dwEventID)
	{
	case E_MOUSEMOVE:
		m_dwState = BS_HOVER;
		Invalidate();
		break;
	case E_MOUSELEAVE:
	case E_LBUTTONUP:
		m_dwState = BS_NORMAL;
		Invalidate();
		break;
	case E_LBUTTONDOWN:
		m_dwState = BS_PUSH;
		Invalidate();
		break;
	default:
		bHandled = FALSE;
		break;
	}
	return bHandled;
}

VOID CZButton::OnPaintStateImage(HDC hDC)
{
	if(!m_aStateImage[m_dwState].IsEmpty())
	{
		CZUIRender::DrawImage(hDC, m_aStateImage[m_dwState], m_rcSize);
	}
}

VOID CZButton::SetStateImage(DWORD dwState, LPCTSTR lpszPath)
{
	m_aStateImage[dwState] = lpszPath;
}
