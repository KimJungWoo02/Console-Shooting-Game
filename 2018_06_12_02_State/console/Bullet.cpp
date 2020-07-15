#include "Include.h"
CBullet::CBullet()
{
	m_cName = '|';
	m_wBColor = BLACK;
	m_wFColor = GREEN;
	m_dwStandTime = GetTickCount();
	m_dwLimitTime = 20;
	m_nBeY = 0;
}
CBullet::~CBullet()
{

}
void CBullet::Clipping()
{
	CUnit::Clipping();
}
void CBullet::Draw()
{
	CUnit::Draw();
}
void CBullet::Update()
{
	if (m_bUse == true)
	{
		if (m_dwLimitTime + m_dwStandTime <= GetTickCount())
		{
			m_nY -= m_nSpeed;
			m_dwStandTime = GetTickCount();
		}
	}
	Clipping();
}
void CBullet::Init()
{
	Disable();
}