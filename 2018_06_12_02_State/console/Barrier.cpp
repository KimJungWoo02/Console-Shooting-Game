#include "Include.h"

CBarrier::CBarrier()
{
	m_dwLimitTime = 10000;
	m_dwStandTime = GetTickCount();
	m_nTime = 0;
	m_wBColor = RED;
	m_wFColor = RED;
}
CBarrier::~CBarrier()
{

}
void CBarrier::Draw()
{
	CUnit::Draw();
}
void CBarrier::Init()
{
	m_nTime = 0;
	Disable();
}
void CBarrier::Update()
{
	Clipping();
}
void CBarrier::Clipping()
{
	if (m_bUse == true)
	{
		if (m_dwLimitTime + m_dwStandTime <= GetTickCount())
		{
			m_dwStandTime = GetTickCount();
			if (m_nTime == 1)
			{
				Disable();
				m_nTime = 0;
			}
			m_nTime++;
		}
	}
}