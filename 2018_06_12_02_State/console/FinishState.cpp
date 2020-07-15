#include "Include.h"
CFinishState::CFinishState()
{

}
CFinishState::~CFinishState()
{

}
void CFinishState::Draw()
{
	DrawStrEx3(55, 14, "Game Complete", WHITE, BLACK);
	DrawStrEx3(50, 16, "FINAL SCORE", WHITE, BLACK);
	DrawStrEx3(65, 16, g_CMng.m_CGameState.m_CUi.m_cScore, WHITE, BLACK);
}
void CFinishState::Update()
{
	if (IsKey(VK_H))
	{
		g_CMng.m_CStateCtrl.StateChange(E_MENU);
	}
}
void CFinishState::Exit()
{

}
void CFinishState::Start()
{

}