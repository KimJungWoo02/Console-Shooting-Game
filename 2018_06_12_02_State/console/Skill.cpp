#include "Include.h"
CSkill::CSkill()
{
	m_cName = '-';
	m_wBColor = BLACK;
	m_wFColor = RED;
	m_dwLimitTime = 100;
	m_dwStandTime = GetTickCount();
}
CSkill::~CSkill()
{

}
void CSkill::Draw()
{
	for (int i = 1; i < 119; i++)
	{
		DrawCharEx3(m_nX + i, m_nY, m_cName, m_wFColor, m_wBColor);
	}
}
void CSkill::Update()
{
	if (m_bUse == true)
	{
		if (m_dwLimitTime + m_dwStandTime <= GetTickCount())
		{
			m_dwStandTime = GetTickCount();
			m_nY -= m_nSpeed;
		}
	}
	Clipping();
}
void CSkill::Clipping()
{
	if (m_nY < 7)
	{
		Disable();
	}
}
void CSkill::Init()
{
	Disable();
}
////////////////////////////////////////////////////////////////
CSkill_1::CSkill_1()
{
	m_nVal = 0;
	m_dwLimitTime = 1000;
	m_dwStandTime = GetTickCount();
	m_wFColor = RED;
	m_wBColor = BLACK;
	m_cName = '*';
}
CSkill_1::~CSkill_1()
{

}
void CSkill_1::Draw()
{
	if (m_bUse == true)
	{
		DrawCharEx3(m_nX, m_nY + 4, g_cBomb[0], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX, m_nY + 3, g_cBomb[1], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX, m_nY + 2, g_cBomb[2], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX, m_nY + 1, g_cBomb[3], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX, m_nY, g_cBomb[4], m_wFColor, m_wBColor);
	}
}
void CSkill_1::Update()
{
	if (m_bUse == true)
	{
		if (m_dwLimitTime + m_dwStandTime <= GetTickCount())
		{
			m_dwStandTime = GetTickCount();
			m_nY -= m_nSpeed;
		}
	}
}
void CSkill_1::Init()
{
	Disable();
}
////////////////////////////////////////////////////////////////////
CSkill_2::CSkill_2()
{
	m_dwLimitTime = 10000;
	m_dwStandTime = GetTickCount();
}
CSkill_2::~CSkill_2()
{

}
void CSkill_2::Update()
{
	if (IsKey(VK_C))
	{
		if (g_CMng.m_CGameState.m_nSKill_2_CollDown > 0)
		{
			if (m_bUse == false)
			{
				if (m_dwLimitTime + m_dwStandTime <= GetTickCount())
				{
					g_CMng.m_CGameState.m_nSKill_2_CollDown--;
					m_dwStandTime = GetTickCount();
					m_bUse = true;
					g_CMng.m_CGameState.m_CHero.m_wFColor = GREEN;
				}
			}
		}
	}
	if (m_dwLimitTime + m_dwStandTime <= GetTickCount() && m_bUse == true)
	{
		g_CMng.m_CGameState.m_CHero.m_wFColor = WHITE;
		m_bUse = false;
	}
}
void CSkill_2::Init()
{
	Disable();
}