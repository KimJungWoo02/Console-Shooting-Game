#include "Include.h"
CResultState::CResultState()
{
	m_wBcolor = BLACK;
	m_wFcolor = WHITE;
}
CResultState::~CResultState()
{

}
void CResultState::Draw()
{
	DrawStrEx3(56, 20, "SCORE :", m_wFcolor, m_wBcolor);
	DrawStrEx3(64, 20, g_CMng.m_CGameState.m_CUi.m_cScore, m_wFcolor, m_wBcolor);
	DrawStrEx3(53, 22, "TIME : H", m_wFcolor, m_wBcolor);
	DrawStrEx3(61, 22, g_CMng.m_CGameState.m_CUi.m_cHour, m_wFcolor, m_wBcolor);
	DrawStrEx3(64, 22, "M", m_wFcolor, m_wBcolor);
	DrawStrEx3(65, 22, g_CMng.m_CGameState.m_CUi.m_cMin, m_wFcolor, m_wBcolor);
	DrawStrEx3(68, 22, "S", m_wFcolor, m_wBcolor);
	DrawStrEx3(69, 22, g_CMng.m_CGameState.m_CUi.m_cSec, m_wFcolor, m_wBcolor);
	DrawStrEx3(57, 15, "Game Over", RED, BLACK);
	DrawStrEx3(53, 18, "Hero Change - TAB", WHITE, BLACK);
	DrawStrEx3(52, 17, "Game Restart  - R", WHITE, BLACK);
}
void CResultState::Exit()
{

}
void CResultState::Start()
{

}
void CResultState::Update()
{
	if (IsKey(VK_TAB))
	{
		g_CMng.m_CStateCtrl.StateChange(E_HEROPICK);
	}
	if (IsKey(VK_R))
	{
		g_CMng.m_CStateCtrl.StateChange(E_GAME);
	}
}