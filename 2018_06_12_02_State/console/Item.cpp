#include "Include.h"
CItem::CItem()
{
	m_nVal = 0;
	m_nRandom = 0;
	m_wBColor = LIGHTGREEN;
	m_wFColor = LIGHTGREEN;
	m_dwLimitTime = 7000;
	m_dwStandTime = GetTickCount();
}
CItem::~CItem()
{

}
void CItem::Clipping()
{
	if (m_dwLimitTime + m_dwStandTime <= GetTickCount())
	{
		Disable();
		m_nRandom = 0;
	}
}
void CItem::Draw()
{
	CUnit::Draw();
}
void CItem::Update()
{
	if (m_bUse == true && m_nVal == 1)
	{
		if (m_nRandom == 1)
		{
			g_CMng.m_CGameState.m_CUi.m_nHp++;
			m_nVal = 0;
			m_bUse = false;
		}
		if (m_nRandom == 2)
		{
			g_CMng.m_CGameState.m_CUi.m_nBullet += 10;
			m_nVal = 0;
			m_bUse = false;
		}
		if (m_nRandom == 3)
		{
			g_CMng.m_CGameState.m_nSKill_2_CollDown++;
			m_nVal = 0;
			m_bUse = false;
		}
	}
	if (m_bUse == true)
	{
		Clipping();
	}
}
void CItem::Init()
{
	Disable();
}