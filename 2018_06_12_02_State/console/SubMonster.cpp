#include "Include.h"
CSubMonster::CSubMonster()
{
	m_wBColor = LIGHTBLUE;
	m_wFColor = LIGHTBLUE;
	m_dwLimitTime = 20;
	m_dwStandTime = GetTickCount();
	m_dwBulletStand = GetTickCount();
	m_dwBulletLimit = 300;
}
CSubMonster::~CSubMonster()
{

}
void CSubMonster::Clipping()
{
	if (m_nY > 30)
	{
		Disable();
	}
}
void CSubMonster::Draw()
{
	CUnit::Draw();
}
void CSubMonster::Update()
{
	if (m_bUse == true)
	{
		if (m_dwLimitTime + m_dwStandTime <= GetTickCount())
		{
			m_dwStandTime = GetTickCount();
			m_nY += m_nSpeed;
		}
	}
	Clipping();
}
void CSubMonster::Init()
{

}

////////////////////////////////////////

CSubBullet::CSubBullet()
{
	m_wBColor = BLACK;
	m_wFColor = LIGHTBLUE;
	m_cName = '|';
	m_dwLimitTime = 15;
	m_dwStandTime = GetTickCount();
	m_nSpeed = 2;
}
CSubBullet::~CSubBullet()
{

}
void CSubBullet::Clipping()
{
	if (m_nY > 30)
	{
		Disable();
	}
}
void CSubBullet::Draw()
{
	CUnit::Draw();
}
void CSubBullet::Update()
{
	if (m_bUse == true)
	{
		if (m_dwLimitTime + m_dwStandTime <= GetTickCount())
		{
			m_dwStandTime = GetTickCount();
			m_nY += m_nSpeed;
		}
	}
	Clipping();
}
void CSubBullet::Init()
{

}