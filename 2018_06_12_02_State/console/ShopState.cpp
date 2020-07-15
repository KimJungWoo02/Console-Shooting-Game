#include "Include.h"
CShopState::CShopState()
{
	for (int i = 0; i < E_SHOP_MAX; i++)
	{
		m_bUse[i] = false;
		m_wFcolor_[i] = GREEN;
	}
	m_nCoin = 1000000;
	m_nX = 9;
	m_nY = 6;
	m_wBColor = BLACK;
	m_nCoinMul = 1;
	m_dwLimitTime = 80;
	m_dwStandTime = GetTickCount();
}
CShopState::~CShopState()
{

}
void CShopState::Clipping()
{
	if (m_nY < 6)
	{
		m_nY = 6;
	}
	if (m_nY > 12)
	{
		m_nY = 12;
	}
}
void CShopState::Draw()
{
	DrawStrEx3(6, 2, "COIN : ", YELLOW, BLACK);
	DrawStrEx3(14, 2, m_cCoin, YELLOW, BLACK);
	DrawStrEx3(m_nX, m_nY, ">", YELLOW, BLACK);
	DrawStrEx3(10, 6, "1.SMG Hero Unlock(1)/ 50000 G", m_wFcolor_[E_SHOP_1], m_wBColor);
	DrawStrEx3(10, 8, "2.SG Hero Unlock(1)/ 50000 G", m_wFcolor_[E_SHOP_2], m_wBColor);
	DrawStrEx3(10, 10, "3.TERRET Hero Unlock(1)/ 50000 G", m_wFcolor_[E_SHOP_3], m_wBColor);
	DrawStrEx3(10, 12, "4.COIN * 2(1) / 80000 G", m_wFcolor_[E_SHOP_4], m_wBColor);
}
void CShopState::Exit()
{

}
void CShopState::Start()
{

}
void CShopState::Update()
{
	sprintf(m_cCoin, "%d", m_nCoin);
	if (IsKey(VK_TAB))
	{
		if (m_nY == 6 && m_bUse[E_SHOP_1] == false)
		{
			if (m_nCoin >= 50000)
			{
				m_nCoin -= 50000;
				m_bUse[E_SHOP_1] = true;
				m_wFcolor_[E_SHOP_1] = RED;
				g_CMng.m_CHeroPickState.m_bUse[E_HERO_2] = true;
			}
		}
		//if (m_nY == 8 && m_bUse[E_SHOP_2] == false)
		//{
		//	if (m_nCoin >= 50000)
		//	{
		//		m_nCoin -= 50000;
		//		m_bUse[E_SHOP_2] = true;
		//		m_wFcolor_[E_SHOP_2] = RED;
		//		g_CMng.m_CHeroPickState.m_bUse[E_HERO_3] = true;
		//	}
		//}
		if (m_nY == 10 && m_bUse[E_SHOP_3] == false)
		{
			if (m_nCoin >= 50000)
			{
				m_nCoin -= 50000;
				m_bUse[E_SHOP_3] = true;
				m_wFcolor_[E_SHOP_3] = RED;
				g_CMng.m_CHeroPickState.m_bUse[E_HERO_4] = true;
			}
		}
		if (m_nY == 12 && m_bUse[E_SHOP_4] == false)
		{
			if (m_nCoin >= 80000)
			{
				m_nCoin -= 80000;
				m_bUse[E_SHOP_4] = true;
				m_wFcolor_[E_SHOP_4] = RED;
				m_nCoinMul = 2;
			}
		}
	}

	if (IsKey(VK_UP))
	{
		if (m_dwLimitTime + m_dwStandTime <= GetTickCount())
		{
			m_dwStandTime = GetTickCount();
			m_nY -= 2;
		}
	}
	if (IsKey(VK_DOWN))
	{
		if (m_dwLimitTime + m_dwStandTime <= GetTickCount())
		{
			m_dwStandTime = GetTickCount();
			m_nY += 2;
		}
	}
	Clipping();
}