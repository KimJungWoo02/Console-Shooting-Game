#include "Include.h"
CMonster::CMonster()
{
	m_wBColor = YELLOW;
	m_wFColor = YELLOW;
	m_dwStandTime = GetTickCount();
	m_dwLimitTime = 20;
}
CMonster::~CMonster()
{

}
void CMonster::Clipping()
{
	if (m_nY > 29)
	{
		Disable();
	}
}
void CMonster::Draw()
{
	CUnit::Draw();
}
void CMonster::Update()
{
	if (m_bUse == true)
	{
		if (m_dwStandTime + m_dwLimitTime <= GetTickCount())
		{
			m_dwStandTime = GetTickCount();
			m_nY += m_nSpeed;
		}
	}
	Clipping();
}
void CMonster::Init()
{
	Disable();
}