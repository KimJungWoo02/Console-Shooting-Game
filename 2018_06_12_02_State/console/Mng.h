#pragma once
#include "Include.h"

class CMng
{

public:
	CStateCtrl	m_CStateCtrl;
	CLogoState m_CLogoState;
	CMenuState m_CMenuState;
	CGameState m_CGameState;
	CResultState m_CResultState;
	CHeroPickState m_CHeroPickState;
	CShopState m_CShopState;
	CFinishState m_CFinishState;



public:
	bool		m_bLoop;


public:
	CMng();
	~CMng();

public:
	void Update();
	void Draw();
};