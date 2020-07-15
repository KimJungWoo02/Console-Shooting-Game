#include "Include.h"
CBossSkill::CBossSkill()
{
	m_wBColor = LIGHTMAGENTA;
	m_wFColor = LIGHTMAGENTA;
	m_dwLimitTime = 10000;
	m_dwStandTime = GetTickCount();
	m_dwMoveStand = GetTickCount();
	m_dwMoveLimit = 100;
}
CBossSkill::~CBossSkill()
{

}
void CBossSkill::Clipping()
{
	if (m_dwLimitTime + m_dwStandTime <= GetTickCount())
	{
		Disable();
	}
}
void CBossSkill::Draw()
{
	CUnit::Draw();
}
void CBossSkill::Update()
{
	if (m_bUse == true)
	{
		if (m_dwMoveLimit + m_dwMoveStand <= GetTickCount())
		{
			m_dwMoveStand = GetTickCount();
			if (m_nX > g_CMng.m_CGameState.m_CHero.m_nX)
			{
				m_nX--;
			}
			if (m_nX < g_CMng.m_CGameState.m_CHero.m_nX)
			{
				m_nX++;
			}
			if (m_nY > g_CMng.m_CGameState.m_CHero.m_nY)
			{
				m_nY--;
			}
			if (m_nY < g_CMng.m_CGameState.m_CHero.m_nY)
			{
				m_nY++;
			}
		}
	}
	Clipping();
}