#include "Include.h"
CLogoState::CLogoState()
{
	m_dwLimitTime = 1;
	m_dwStandTime = GetTickCount();
	m_nVal = 10;
	m_nVal2 = 41;
	m_bUse = false;
}
CLogoState::~CLogoState()
{

}
void CLogoState::Draw()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 120; j++)
		{
			if (g_bLogo[i][j] == 1)
			{
				DrawFillBoxEx3(j, i, 1, 1, WHITE);
			}
		}
	}
}
void CLogoState::Exit()
{

}
void CLogoState::Start()
{

}
void CLogoState::Update()
{
	if (m_dwLimitTime + m_dwStandTime <= GetTickCount())
	{
		m_nVal2++;
		m_dwStandTime = GetTickCount();
		if (m_nVal2 == 75)
		{
			m_nVal++;
			m_nVal2 = 42;
		}
		if (g_nLogo[m_nVal][m_nVal2] == 1)
		{
			g_bLogo[m_nVal][m_nVal2] = 1;
		}
	}
	if (IsAnyKey())
	{
		g_CMng.m_CStateCtrl.StateChange(E_MENU);
		m_bUse = true;
	}
	if (m_nVal >= 19 && m_bUse == false)
	{
		DrawStrEx3(53, 22, "Press any key", YELLOW, BLACK);
	}
}