#include "Include.h"
CMenuState::CMenuState()
{
	m_nX = 54;
	m_nY = 20;
	m_wFcolor = WHITE;
	m_wBcolor = BLACK;
	m_wBcolor_Menu = WHITE;
	m_dwStandTime = GetTickCount();
	m_dwLimitTime = 100;
	m_dwLimitTime_Menu = 3500;
	m_dwStandTime_Menu = GetTickCount();
}
CMenuState::~CMenuState()
{

}
void CMenuState::Draw()
{
	DrawStrEx3(55, 20, "Game Start", m_wFcolor, m_wBcolor);
	DrawStrEx3(55, 22, "Shop", m_wFcolor, m_wBcolor);
	DrawStrEx3(55, 24, "Game Quit", LIGHTRED, m_wBcolor);
	DrawStrEx3(m_nX, m_nY, ">", m_wFcolor, m_wBcolor);

	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 120; j++)
		{
			if (g_nMenu[i][j] == 1)
			{
				DrawFillBoxEx3(j, i, 1, 1, m_wBcolor_Menu);
			}
		}
	}
}
void CMenuState::Exit()
{

}
void CMenuState::Start()
{

}
void CMenuState::Update()
{
	if (m_dwLimitTime + m_dwStandTime <= GetTickCount())
	{
		m_dwStandTime = GetTickCount();
		if (IsKey(VK_UP))
		{
			m_nY = m_nY - 2;
		}
		if (IsKey(VK_DOWN))
		{
			m_nY = m_nY + 2;
		}
	}
	if (m_nY < 20)
	{
		m_nY = 20;
	}
	if (m_nY > 24)
	{
		m_nY = 24;
	}

	if (IsKey(VK_SPACE))
	{
		if (m_nY == 20)
		{
			g_CMng.m_CStateCtrl.StateChange(E_HEROPICK);
		}
		if (m_nY == 22)
		{
			g_CMng.m_CStateCtrl.StateChange(E_SHOP);
		}
		if (m_nY == 24)
		{
			g_CMng.m_bLoop = false;
		}
	}
	if (m_dwLimitTime_Menu + m_dwStandTime_Menu < GetTickCount())
	{
		m_dwStandTime_Menu = GetTickCount();
		m_wBcolor_Menu = rand() % 12;
	}
}