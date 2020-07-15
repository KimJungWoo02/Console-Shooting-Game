#include "Include.h"
#include "Extern.h"

CUnit::CUnit()
{
	m_bUse = false;
	m_cName = 'U';
	m_nX = 0;
	m_nY = 0;
	m_nAttack = 1;
	m_nHp = 10;
	m_nSpeed = 1;
	m_wBColor = YELLOW;
	m_wFColor = RED;
	m_dwStandTime = GetTickCount();
}

CUnit::~CUnit()
{

}

void CUnit::Update()
{


}

void CUnit::Draw()
{
	if (m_bUse == true)
	{
		DrawCharEx3(m_nX, m_nY, m_cName, m_wFColor, m_wBColor);
	}
}

void CUnit::Clipping()
{
	if (m_bUse)
	{
		if (m_nY < 5)
		{
			Disable();
		}
	}
}

void CUnit::Enable(int nX, int nY)
{
	m_bUse = true;

	m_nX = nX;
	m_nY = nY;
}

void CUnit::Disable()
{
	m_bUse = false;

	m_nX = -100;
	m_nY = -100;
}
void CUnit::Init()
{
	m_bUse = false;
	m_cName = 'U';
	m_nX = -100;
	m_nY = -100;
	m_nAttack = 1;
	m_nHp = 10;
	m_nSpeed = 1;
	m_wBColor = YELLOW;
	m_wFColor = RED;
}