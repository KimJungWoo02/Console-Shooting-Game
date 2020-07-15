#include "Include.h"
CHeroPickState::CHeroPickState()
{
	for (int i = 0; i < E_HERO_MAX; i++)
	{
		m_bUse[i] = true;
		m_wFcolor[i] = WHITE;
	}
	m_bUse[E_HERO_1] = true;
	m_wFcolor[E_HERO_1] = LIGHTBLUE;
	m_wFColor = WHITE;
	m_wBColor = BLACK;
	m_bMsg = false;
	m_nHero = 0;
	m_nIndex = 0;
	m_nX = 60;
	m_nY = 13;
	m_nVal = 0;
	m_nBomb = 0;
	m_nRazer = 0;
	m_nShield = 0;
	m_nBullet = 0;
	m_nHp = 0;
	m_dwBullet_Reload = 0;
	m_dwLimitTime = 100;
	m_dwStandTime = GetTickCount();
	m_dwMsgLimit = 2000;
	m_dwMsgStand = GetTickCount();
	m_dwBullet_Time = 0;
	m_dwMoveStand = GetTickCount();
	m_dwMoveLimit = 30;
}
CHeroPickState::~CHeroPickState()
{

}
void CHeroPickState::Draw()
{
	DrawStrEx3(30, 23, "NORMAL", m_wFcolor[E_HERO_1], BLACK);
	DrawStrEx3(50, 23, "SMG", m_wFcolor[E_HERO_2], BLACK);
	DrawStrEx3(67, 23, "DG", m_wFcolor[E_HERO_3], BLACK);
	DrawStrEx3(88, 23, "TERRET", m_wFcolor[E_HERO_4], BLACK);

	DrawCharEx3(m_nX - 1, m_nY - 1, g_cHero[m_nIndex][0][0], m_wFColor, m_wBColor);
	DrawCharEx3(m_nX, m_nY - 1, g_cHero[m_nIndex][0][1], m_wFColor, m_wBColor);
	DrawCharEx3(m_nX + 1, m_nY - 1, g_cHero[m_nIndex][0][2], m_wFColor, m_wBColor);
	DrawCharEx3(m_nX - 1, m_nY, g_cHero[m_nIndex][1][0], m_wFColor, m_wBColor);
	DrawCharEx3(m_nX, m_nY, g_cHero[m_nIndex][1][1], m_wFColor, m_wBColor);
	DrawCharEx3(m_nX + 1, m_nY, g_cHero[m_nIndex][1][2], m_wFColor, m_wBColor);
	DrawCharEx3(m_nX - 1, m_nY + 1, g_cHero[m_nIndex][2][0], m_wFColor, m_wBColor);
	DrawCharEx3(m_nX + 1, m_nY + 1, g_cHero[m_nIndex][2][2], m_wFColor, m_wBColor);

	DrawStrEx3(47, 17, "Press Tab to select your hero.", CYAN, BLACK);
}
void CHeroPickState::Start()
{
	m_nHero = 0;
	m_nIndex = 0;
}
void CHeroPickState::Update()
{
	for (int i = 0; i < E_HERO_MAX; i++)
	{
		if (m_nIndex == i)
		{
			continue;
		}
		m_wFcolor[i] = WHITE;
	}
	if (m_dwLimitTime + m_dwStandTime <= GetTickCount())
	{
		m_dwStandTime = GetTickCount();
		if (IsKey(VK_LEFT))
		{
			m_nIndex--;
			Clipping();
			m_wFcolor[m_nIndex] = LIGHTBLUE;
		}
		if (IsKey(VK_RIGHT))
		{
			m_nIndex++;
			Clipping();
			m_wFcolor[m_nIndex] = LIGHTBLUE;
		}
	}

	if (IsKey(VK_TAB))
	{
		if (m_nIndex == 0)
		{
			m_nHero = 0;
			m_nBomb = 3;
			m_nRazer = 3;
			m_nShield = 2;
			m_nBullet = 500;
			m_nHp = 30;
			m_dwBullet_Reload = 5000;
			m_dwBullet_Time = 48;
			g_CMng.m_CStateCtrl.StateChange(E_GAME);
		}
		if (m_nIndex == 1)
		{
			if (m_bUse[E_HERO_2] == true)
			{
				m_nHero = 1;
				m_nBomb = 1;
				m_nRazer = 3;
				m_nShield = 5;
				m_nBullet = 200;
				m_dwBullet_Reload = 2000;
				m_nHp = 30;
				m_dwBullet_Time = 35;
				g_CMng.m_CStateCtrl.StateChange(E_GAME);
			}
			else
			{
				m_bMsg = true;
				m_dwMsgStand = GetTickCount();
			}
		}
		if (m_nIndex == 2)
		{
			if (m_bUse[E_HERO_3] == true)
			{
				m_nHero = 2;
				m_nBomb = 2;
				m_nRazer = 3;
				m_nShield = 2;
				m_nBullet = 500;
				m_dwBullet_Reload = 5000;
				m_nHp = 20;
				m_dwBullet_Time = 300;
				g_CMng.m_CStateCtrl.StateChange(E_GAME);
			}
			else
			{
				m_bMsg = true;
				m_dwMsgStand = GetTickCount();
			}
		}
		if (m_nIndex == 3)
		{
			if (m_bUse[E_HERO_4] == true)
			{
				m_nHero = 3;
				m_nBomb = 2;
				m_nRazer = 2;
				m_nShield = 7;
				m_nBullet = 100;
				m_dwBullet_Reload = 2000;
				m_nHp = 25;
				m_dwBullet_Time = 45;
				g_CMng.m_CStateCtrl.StateChange(E_GAME);
			}
			else
			{
				m_bMsg = true;
				m_dwMsgStand = GetTickCount();
			}
		}
	}
	if (m_dwMoveLimit + m_dwMoveStand <= GetTickCount())
	{
		m_dwMoveStand = GetTickCount();
		if (m_nVal == 0)
		{
			m_nX++;
			if (m_nX == 80)
			{
				m_nVal = 1;
			}
		}

		if (m_nVal == 1)
		{
			if (m_nX == 40)
			{
				m_nVal = 0;
			}
			m_nX--;
		}
	}


	if (m_bMsg == true)
	{
		DrawStrEx3(50, 15, "You do not have this hero.", LIGHTRED, BLACK);
		if (m_dwMsgStand + m_dwMsgLimit <= GetTickCount())
		{
			m_bMsg = false;
		}
	}
}
void CHeroPickState::Exit()
{

}
void CHeroPickState::Clipping()
{
	if (m_nIndex < E_HERO_1)
	{
		m_nIndex = E_HERO_MAX - 1;
	}
	if (m_nIndex > E_HERO_MAX - 1)
	{
		m_nIndex = E_HERO_1;
	}
}