#include "Include.h"
CBoss::CBoss()
{
	m_nHp = D_BOSS_MAX;
	m_wBColor = BLACK;
	m_wFColor = WHITE;
	m_nX = 60;
	m_nY = 12;
	m_dwStandTime = GetTickCount();
	m_dwLimitTime = 200;
	m_nVal = 0;
	m_bUse = false;
	m_bColor = false;
	m_wMainColor = WHITE;
}
CBoss::~CBoss()
{

}
void CBoss::Draw()
{
	if (g_CMng.m_CGameState.m_nStage == 5)
	{
		DrawCharEx3(m_nX - 2, m_nY - 2, g_cBoss2[0][0], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX - 1, m_nY - 2, g_cBoss2[0][1], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX, m_nY - 2, g_cBoss2[0][2], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX + 1, m_nY - 2, g_cBoss2[0][3], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX + 2, m_nY - 2, g_cBoss2[0][4], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX - 2, m_nY - 1, g_cBoss2[1][0], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX - 1, m_nY - 1, g_cBoss2[1][1], m_wMainColor, m_wMainColor);
		DrawCharEx3(m_nX, m_nY - 1, g_cBoss2[1][2], m_wMainColor, m_wMainColor);
		DrawCharEx3(m_nX + 1, m_nY - 1, g_cBoss2[1][3], m_wMainColor, m_wMainColor);
		DrawCharEx3(m_nX + 2, m_nY - 1, g_cBoss2[1][4], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX - 2, m_nY, g_cBoss2[2][0], m_wMainColor, m_wMainColor);
		DrawCharEx3(m_nX - 1, m_nY, g_cBoss2[2][1], m_wMainColor, m_wMainColor);
		DrawCharEx3(m_nX, m_nY, g_cBoss2[2][2], BLUE, BLUE);
		DrawCharEx3(m_nX + 1, m_nY, g_cBoss2[2][3], m_wMainColor, m_wMainColor);
		DrawCharEx3(m_nX + 2, m_nY, g_cBoss2[2][4], m_wMainColor, m_wMainColor);
		DrawCharEx3(m_nX - 2, m_nY + 1, g_cBoss2[3][0], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX - 1, m_nY + 1, g_cBoss2[3][1], m_wMainColor, m_wMainColor);
		DrawCharEx3(m_nX, m_nY + 1, g_cBoss2[3][2], m_wMainColor, m_wMainColor);
		DrawCharEx3(m_nX + 1, m_nY + 1, g_cBoss2[3][3], m_wMainColor, m_wMainColor);
		DrawCharEx3(m_nX + 2, m_nY + 1, g_cBoss2[3][4], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX - 2, m_nY + 2, g_cBoss2[4][0], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX - 1, m_nY + 2, g_cBoss2[4][1], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX, m_nY + 2, g_cBoss2[4][2], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX + 1, m_nY + 2, g_cBoss2[4][3], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX + 2, m_nY + 2, g_cBoss2[4][4], m_wFColor, m_wBColor);
	}

	if (g_CMng.m_CGameState.m_nStage == 4)
	{
		DrawCharEx3(m_nX - 2, m_nY - 2, g_cBoss[0][0], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX - 1, m_nY - 2, g_cBoss[0][1], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX, m_nY - 2, g_cBoss[0][2], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX + 1, m_nY - 2, g_cBoss[0][3], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX + 2, m_nY - 2, g_cBoss[0][4], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX - 2, m_nY - 1, g_cBoss[1][0], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX - 1, m_nY - 1, g_cBoss[1][1], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX, m_nY - 1, g_cBoss[1][2], m_wMainColor, m_wMainColor);
		DrawCharEx3(m_nX + 1, m_nY - 1, g_cBoss[1][3], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX + 2, m_nY - 1, g_cBoss[1][4], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX - 2, m_nY, g_cBoss[2][0], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX - 1, m_nY, g_cBoss[2][1], m_wMainColor, m_wMainColor);
		DrawCharEx3(m_nX, m_nY, g_cBoss[2][2], GREEN, GREEN);
		DrawCharEx3(m_nX + 1, m_nY, g_cBoss[2][3], m_wMainColor, m_wMainColor);
		DrawCharEx3(m_nX + 2, m_nY, g_cBoss[2][4], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX - 2, m_nY + 1, g_cBoss[3][0], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX - 1, m_nY + 1, g_cBoss[3][1], m_wMainColor, m_wMainColor);
		DrawCharEx3(m_nX, m_nY + 1, g_cBoss[3][2], m_wMainColor, m_wMainColor);
		DrawCharEx3(m_nX + 1, m_nY + 1, g_cBoss[3][3], m_wMainColor, m_wMainColor);
		DrawCharEx3(m_nX + 2, m_nY + 1, g_cBoss[3][4], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX - 2, m_nY + 2, g_cBoss[4][0], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX - 1, m_nY + 2, g_cBoss[4][1], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX, m_nY + 2, g_cBoss[4][2], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX + 1, m_nY + 2, g_cBoss[4][3], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX + 2, m_nY + 2, g_cBoss[4][4], m_wFColor, m_wBColor);
	}
}
void CBoss::Update()
{
	if (m_nVal == 0)
	{
		if (m_dwLimitTime + m_dwStandTime <= GetTickCount())
		{
			m_dwStandTime = GetTickCount();
			m_nX++;
		}
	}
	if (m_nVal == 1)
	{
		if (m_dwLimitTime + m_dwStandTime <= GetTickCount())
		{
			m_dwStandTime = GetTickCount();
			m_nX--;
		}
	}
	if (m_nHp <= 0 && g_CMng.m_CGameState.m_nStage == 5)
	{
		g_CMng.m_CStateCtrl.StateChange(E_FINISH);
		if (m_bUse == false)
		{
			m_nHp = D_BOSS2_MAX;
			m_bUse = true;
		}
	}
	if (m_nHp <= 0)
	{
		g_CMng.m_CGameState.m_nStage = 5;
		g_CMng.m_CGameState.m_CUi.m_nScore += 10000;
		m_nHp = D_BOSS2_MAX;
		g_CMng.m_CGameState.m_CTimeClass.m_dwBossBullet_Limit = 200;
		g_CMng.m_CGameState.CreateEffect(m_nX, m_nY, WHITE);
	}
	m_wMainColor = WHITE;
	m_wBColor = BLACK;
	m_wFColor = WHITE;
	Clipping();
}
void CBoss::Clipping()
{
	if (m_nX == 75)
	{
		m_nVal = 1;
	}
	if (m_nX == 45)
	{
		m_nVal = 0;
	}
}
void CBoss::Init()
{
	m_nX = 60;
	m_nY = 10;
	m_nHp = 150;
	m_bUse = false;
}
CBossBullet::CBossBullet()
{
	m_cName = '|';
	m_wBColor = BLACK;
	m_wFColor = LIGHTBLUE;
}
CBossBullet::~CBossBullet()
{

}
void CBossBullet::Clipping()
{
	if (m_nY > 30)
	{
		Disable();
	}
}
void CBossBullet::Draw()
{
	CUnit::Draw();
}
void CBossBullet::Update()
{
	if (m_bUse == true)
	{
		m_nY += m_nSpeed;
	}
	Clipping();
}
void CBossBullet::Init()
{
	Disable();
}