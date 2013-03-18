#include "ZStatic.h"

#define STATIC_CLASS_NAME _T("ZUI Static Class")

CZStatic::CZStatic(void)
: m_dwColor(0)
, m_dwStyle(DT_CENTER)
{
}

CZStatic::~CZStatic(void)
{
}

LPCTSTR CZStatic::GetClassName()
{
	return STATIC_CLASS_NAME;
}

BOOL CZStatic::HandleEvent(EVENT& e)
{
	return FALSE;
}

VOID CZStatic::OnPaintText(HDC hDC)
{
	::DrawText(hDC, m_strText, -1, m_rcSize, m_dwStyle);
}

VOID CZStatic::SetText(LPCTSTR lpszText)
{
	ATLASSERT(lpszText != NULL);
	m_strText = lpszText;
}

LPCTSTR CZStatic::GetText()
{
	return m_strText;
}

VOID CZStatic::SetTextColor(DWORD dwColor)
{
	m_dwColor = dwColor;
}

DWORD CZStatic::GetTextColor()
{
	return m_dwColor;
}

VOID CZStatic::SetTextStyle(DWORD dwStyle)
{
	m_dwStyle = dwStyle;
}

DWORD CZStatic::GetTextStyle()
{
	return m_dwStyle;
}
