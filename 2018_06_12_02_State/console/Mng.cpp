#include "Include.h"
#include "Extern.h"

CMng::CMng()
{
	m_bLoop = true;

	//// 상태 추가
	m_CStateCtrl.StateAdd(E_LOGO, &m_CLogoState);
	m_CStateCtrl.StateAdd(E_MENU, &m_CMenuState);
	m_CStateCtrl.StateAdd(E_GAME, &m_CGameState);
	m_CStateCtrl.StateAdd(E_RESULT, &m_CResultState);
	m_CStateCtrl.StateAdd(E_HEROPICK, &m_CHeroPickState);
	m_CStateCtrl.StateAdd(E_SHOP, &m_CShopState);
	m_CStateCtrl.StateAdd(E_FINISH, &m_CFinishState);

	////상태
	m_CStateCtrl.StateChange(E_LOGO);
}

CMng::~CMng()
{

}

void CMng::Update()
{
	if (IsKey(VK_F1))
	{
		m_CGameState.m_CUi.m_nHp++;
	}

	if (IsKey(VK_F2))
	{
		m_CGameState.m_CUi.m_nScore += 1000;
	}
	m_CStateCtrl.Update();
}

void CMng::Draw()
{
	m_CStateCtrl.Draw();
}

