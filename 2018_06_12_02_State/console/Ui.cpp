#include "Include.h"
CUi::CUi()
{
	m_nX = 54;
	m_nY = 22;
	m_nIndex = 24;
	m_nHp = 0;
	m_nScore = 0;
	m_nSec = 0;
	m_nHour = 0;
	m_nMin = 0;
	m_nBullet = D_BULLET_MAX;
	m_wBcolor = LIGHTGRAY;
	for (int i = 0; i < E_SKILL_MAX; i++)
	{
		m_wFcolor[i] = CYAN;
	}
	m_wFColor = BLACK;
	m_dwStandTime = GetTickCount();
	m_dwLimitTIme = 1000;
}
CUi::~CUi()
{

}
void CUi::Draw()
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 120; j++)
		{
			if (g_nInfoUi[i][j] == 1)
			{
				DrawFillBoxEx3(j, i, 1, 1, m_wBcolor);
			}
		}
	}
	DrawStrEx3(74, 2, m_cHp, LIGHTRED, BLACK);
	DrawStrEx3(28, 2, "BULLET", m_wBcolor, m_wFColor);
	DrawStrEx3(35, 2, m_cBullet, m_wBcolor, m_wFColor);
	DrawStrEx3(52, 2, "SCORE", m_wBcolor, m_wFColor);
	DrawStrEx3(58, 2, m_cScore, m_wBcolor, m_wFColor);
	DrawStrEx3(52, 3, "TIME", m_wBcolor, m_wFColor);
	DrawStrEx3(64, 3, "S", m_wBcolor, m_wFColor);
	DrawStrEx3(65, 3, m_cSec, m_wBcolor, m_wFColor);
	DrawStrEx3(61, 3, "M", m_wBcolor, m_wFColor);
	DrawStrEx3(62, 3, m_cMin, m_wBcolor, m_wFColor);
	DrawStrEx3(58, 3, "H", m_wBcolor, m_wFColor);
	DrawStrEx3(59, 3, m_cHour, m_wBcolor, m_wFColor);
	DrawStrEx3(4, 2, "RAZER", m_wFcolor[E_SKILL_1], BLACK);
	DrawStrEx3(10, 2, m_cSkill, m_wFcolor[E_SKILL_1], BLACK);
	DrawStrEx3(13, 2, "BOMB", m_wFcolor[E_SKILL_2], BLACK);
	DrawStrEx3(18, 2, m_cSkill_1, m_wFcolor[E_SKILL_2], BLACK);
	DrawStrEx3(39, 2, "SHIELD", m_wFcolor[E_SKILL_3], BLACK);
	DrawStrEx3(46, 2, m_cSkill_2, m_wFcolor[E_SKILL_3], BLACK);
	sprintf(m_cScore, "%d", m_nScore);
	sprintf(m_cHp, "HP(%d)", m_nHp);
	sprintf(m_cSec, "%d", m_nSec);
	sprintf(m_cMin, "%d", m_nMin);
	sprintf(m_cHour, "%d", m_nHour);
	sprintf(m_cSkill, "%d", g_CMng.m_CGameState.m_nSKill_CollDown);
	sprintf(m_cSkill_1, "%d", g_CMng.m_CGameState.m_nSKill_1_CollDown);
	sprintf(m_cSkill_2, "%d", g_CMng.m_CGameState.m_nSKill_2_CollDown);
	sprintf(m_cBullet, "%d", m_nBullet);
	sprintf(m_cBossHp, "%d", g_CMng.m_CGameState.m_CBoss.m_nHp);

	for (int i = 0; i < m_nHp; i++)
	{
		DrawCharEx3(81 + i, 2, 'A', LIGHTRED, LIGHTRED);
	}

	if (g_CMng.m_CGameState.m_nStage == 4)
	{
		sprintf(m_cBoss, "BOSS HP(%d)", g_CMng.m_CGameState.m_CBoss.m_nHp);
		DrawStrEx3(54, 6, m_cBoss, LIGHTRED, BLACK);
		for (int i = 0; i < g_CMng.m_CGameState.m_CBoss.m_nHp / 6.25; i++)
		{
			DrawCharEx3(48 + i, 7, '*', WHITE, WHITE);
		}
	}

	if (g_CMng.m_CGameState.m_nStage == 5)
	{
		sprintf(m_cBoss, "BOSS HP(%d)", g_CMng.m_CGameState.m_CBoss.m_nHp);
		DrawStrEx3(54, 6, m_cBoss, LIGHTRED, BLACK);
		for (int i = 0; i < g_CMng.m_CGameState.m_CBoss.m_nHp / 12.5; i++)
		{
			DrawCharEx3(48 + i, 7, '*', WHITE, WHITE);
		}
	}
}
void CUi::Update()
{
	if (m_dwLimitTIme + m_dwStandTime <= GetTickCount())
	{
		m_dwStandTime = GetTickCount();
		m_nSec++;
		if (m_nSec > 59)
		{
			m_nMin++;
			m_nSec = 0;
		}
		if (m_nMin > 59)
		{
			m_nHour++;
			m_nMin = 0;
		}
	}
	if (m_nHp <= 0)
	{
		g_CMng.m_CStateCtrl.StateChange(E_RESULT);
	}
	if (g_CMng.m_CGameState.m_nSKill_CollDown <= 0)
	{
		m_wFcolor[E_SKILL_1] = LIGHTRED;
	}
	if (g_CMng.m_CGameState.m_nSKill_1_CollDown <= 0)
	{
		m_wFcolor[E_SKILL_2] = LIGHTRED;
	}
	if (g_CMng.m_CGameState.m_nSKill_2_CollDown <= 0)
	{
		m_wFcolor[E_SKILL_3] = LIGHTRED;
	}
}
void CUi::Init()
{
	m_nHp = g_CMng.m_CHeroPickState.m_nHp;
	m_nScore = 0;
	m_nSec = 0;
	m_nHour = 0;
	m_nMin = 0;
	m_nBullet = g_CMng.m_CHeroPickState.m_nBullet;
}