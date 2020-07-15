#include "Include.h"
CEffect::CEffect()
{
	m_nIndex = -1;
	m_dwLimitTime = 250;
	m_dwStandTime = GetTickCount();
	m_wBColor = BLACK;
	m_wFColor = LIGHTRED;
}
CEffect::~CEffect()
{

}
void CEffect::Draw()
{
	if (m_bUse == true)
	{
		DrawCharEx3(m_nX - 1, m_nY - 1, g_cEffects[m_nIndex][0][0], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX, m_nY - 1, g_cEffects[m_nIndex][0][1], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX + 1, m_nY - 1, g_cEffects[m_nIndex][0][2], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX - 1, m_nY, g_cEffects[m_nIndex][1][0], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX, m_nY, g_cEffects[m_nIndex][1][1], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX + 1, m_nY, g_cEffects[m_nIndex][1][2], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX - 1, m_nY + 1, g_cEffects[m_nIndex][2][0], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX, m_nY + 1, g_cEffects[m_nIndex][2][1], m_wFColor, m_wBColor);
		DrawCharEx3(m_nX + 1, m_nY + 1, g_cEffects[m_nIndex][2][2], m_wFColor, m_wBColor);
	}
}
void CEffect::Update()
{
	if (m_bUse == true)
	{
		if (m_dwLimitTime + m_dwStandTime <= GetTickCount())
		{
			m_nIndex++;
			m_dwStandTime = GetTickCount();
		}
		if (m_nIndex > 3)
		{
			m_nIndex = -1;
			Disable();
		}
	}
}
void CEffect::Init()
{
	m_nIndex = -1;
	Disable();
	m_dwStandTime = GetTickCount();
}