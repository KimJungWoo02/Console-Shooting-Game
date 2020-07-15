#include "Include.h"
CTerret::CTerret()
{
	m_wBColor = CYAN;
	m_wFColor = CYAN;
	m_dwLimitTime = 15000;
	m_dwStandTime = GetTickCount();
	m_dwStand_Draw = GetTickCount();
	m_dwLimit_Draw = 1000;
	m_nCount = m_dwLimitTime / 1000;
	m_dwLimit_Monster = 5000;
	m_dwStand_Monster = GetTickCount();
}
CTerret::~CTerret()
{

}
void CTerret::Clipping()
{
	if (m_dwLimitTime + m_dwStandTime <= GetTickCount())
	{
		Disable();
		m_nCount = m_dwLimitTime / 1000;
	}
}
void CTerret::Draw()
{
	CUnit::Draw();
	if (m_bUse == true)
	{
		DrawStrEx3(m_nX, m_nY + 1, m_cCount, WHITE, BLACK);
		DrawCharEx3(m_nX - 1, m_nY, '(', LIGHTBLUE, BLACK);
		DrawCharEx3(m_nX + 1, m_nY, ')', LIGHTBLUE, BLACK);
	}
}
void CTerret::Update()
{
	sprintf(m_cCount, "%d", m_nCount);
	if (m_bUse == true)
	{
		if (m_dwLimit_Draw + m_dwStand_Draw <= GetTickCount())
		{
			m_dwStand_Draw = GetTickCount();
			m_nCount--;
		}

		if (m_nCount <= 0)
		{
			Disable();
			m_nCount = m_dwLimitTime / 1000;
		}
	}
	Clipping();
}
void CTerret::Init()
{

}