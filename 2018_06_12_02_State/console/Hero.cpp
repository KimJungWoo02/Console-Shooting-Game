#include "Include.h"
CHero::CHero()
{
	m_bUse = true;
	m_wBColor = WHITE;
	m_wFColor = WHITE;
	m_nX = 60;
	m_nY = 20;
	m_dwLimitTime = 10;
	m_dwStandTime = GetTickCount();
}
CHero::~CHero()
{

}
void CHero::Clipping()
{
	if (m_nX > 117)
	{
		m_nX--;
	}
	if (m_nX < 2)
	{
		m_nX++;
	}
	if (m_nY > 28)
	{
		m_nY--;
	}
	if (m_nY < 7)
	{
		m_nY++;
	}
}
void CHero::Draw()
{
	DrawCharEx3(m_nX - 1, m_nY - 1, g_cHero[g_CMng.m_CHeroPickState.m_nHero][0][0], m_wFColor, m_wBColor);
	DrawCharEx3(m_nX, m_nY - 1, g_cHero[g_CMng.m_CHeroPickState.m_nHero][0][1], m_wFColor, m_wBColor);
	DrawCharEx3(m_nX + 1, m_nY - 1, g_cHero[g_CMng.m_CHeroPickState.m_nHero][0][2], m_wFColor, m_wBColor);
	DrawCharEx3(m_nX - 1, m_nY, g_cHero[g_CMng.m_CHeroPickState.m_nHero][1][0], m_wFColor, m_wBColor);
	DrawCharEx3(m_nX, m_nY, g_cHero[g_CMng.m_CHeroPickState.m_nHero][1][1], m_wFColor, m_wBColor);
	DrawCharEx3(m_nX + 1, m_nY, g_cHero[g_CMng.m_CHeroPickState.m_nHero][1][2], m_wFColor, m_wBColor);
	DrawCharEx3(m_nX - 1, m_nY + 1, g_cHero[g_CMng.m_CHeroPickState.m_nHero][2][0], m_wFColor, m_wBColor);
	DrawCharEx3(m_nX + 1, m_nY + 1, g_cHero[g_CMng.m_CHeroPickState.m_nHero][2][2], m_wFColor, m_wBColor);
}
void CHero::Update()
{
	if (m_dwLimitTime + m_dwStandTime <= GetTickCount())
	{
		m_dwStandTime = GetTickCount();
		if (IsKey(VK_LEFT))
		{
			m_nX--;
			DrawCharEx3(m_nX, m_nY + 1, g_cHero[g_CMng.m_CHeroPickState.m_nHero][2][1], m_wFColor, m_wBColor);
		}
		if (IsKey(VK_RIGHT))
		{
			m_nX++;
			DrawCharEx3(m_nX, m_nY + 1, g_cHero[g_CMng.m_CHeroPickState.m_nHero][2][1], m_wFColor, m_wBColor);
		}
		if (IsKey(VK_UP))
		{
			m_nY--;
			DrawCharEx3(m_nX, m_nY + 1, g_cHero[g_CMng.m_CHeroPickState.m_nHero][2][1], m_wFColor, m_wBColor);
		}
		if (IsKey(VK_DOWN))
		{
			m_nY++;
			DrawCharEx3(m_nX, m_nY + 1, g_cHero[g_CMng.m_CHeroPickState.m_nHero][2][1], m_wFColor, m_wBColor);
		}
	}
	Clipping();
}
void CHero::Init()
{
	m_bUse = true;
	m_wBColor = BLACK;
	m_wFColor = WHITE;
	m_nX = 60;
	m_nY = 20;
}