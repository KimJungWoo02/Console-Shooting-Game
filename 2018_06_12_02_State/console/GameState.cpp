#include "Include.h"
CGameState::CGameState()
{
	m_nCount = D_COUNT_MAX;
	m_bCount = true;
	m_nStage = 1;
	m_nRandom_rand = 0;
	m_nReload = 0;
}
CGameState::~CGameState()
{

}
void CGameState::StageMng()
{
	if (m_CUi.m_nScore >= 5000 && m_CUi.m_nScore < 15000)
	{
		m_nStage = 2;
	}
	if (m_CUi.m_nScore >= 15000 && m_CUi.m_nScore < 40000)
	{
		m_nStage = 3;
	}
	if (m_CUi.m_nScore >= 40000 && m_nStage < 5)
	{
		m_nStage = 4;
	}
}
void CGameState::Draw()
{
	if (m_bCount == false)
	{
		switch (m_nStage)
		{
		case 1:
			Stage1_Draw();
			break;
		case 2:
			Stage2_Draw();
			break;
		case 3:
			Stage3_Draw();
			break;
		case 4:
			Stage4_Draw();
			break;
		case 5:
			Stage5_Draw();
			break;
		}
		StageMng();
	}
	else
	{
		m_CHero.Draw();
		m_CUi.Draw();
		CountDraw();
	}
}
void CGameState::Update()
{
	if (m_bCount == false)
	{
		if (m_bPause == false)
		{
			switch (m_nStage)
			{
			case 1:
				Stage1_Update();
				break;
			case 2:
				Stage2_Update();
				break;
			case 3:
				Stage3_Update();
				break;
			case 4:
				Stage4_Update();
				break;
			case 5:
				Stage5_Update();
				break;
			}
			StageMng();
		}
		Pause();
	}
	else
	{
		CountUpdate();
	}
}
void CGameState::Exit()
{

}
void CGameState::Start()
{
	m_CHero.Init();
	m_CUi.Init();
	m_CSkill.Init();
	m_CSkill_1.Init();
	m_CBoss.Init();
	m_CTimeClass.Init();
	m_nCount = D_COUNT_MAX;
	m_bCount = true;
	m_nStage = 1;
	m_nSKill_CollDown = g_CMng.m_CHeroPickState.m_nRazer;
	m_nSKill_1_CollDown = g_CMng.m_CHeroPickState.m_nBomb;
	m_nSKill_2_CollDown = g_CMng.m_CHeroPickState.m_nShield;
	m_CTimeClass.m_dwBullet_Reload_Limit = 1000;
	m_CTimeClass.m_dwBulletLimit = g_CMng.m_CHeroPickState.m_dwBullet_Time;
	m_nReload = g_CMng.m_CHeroPickState.m_dwBullet_Reload / 1000;
	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		m_CBullet[i].Init();
		m_CBossBullet[i].Init();
		m_CSubBullet[i].Init();
	}
	for (int i = 0; i < D_MONSTER_MAX; i++)
	{
		m_CMonster[i].Init();
		m_CSubMonster[i].Init();
	}
	for (int i = 0; i < D_EFFECT_MAX; i++)
	{
		m_CEffect[i].Init();
	}
	for (int i = 0; i < D_BARRIER_MAX; i++)
	{
		m_CBarrier[i].Init();
	}
	for (int i = 0; i < D_ITEM_MAX; i++)
	{
		m_CItem[i].Init();
	}
}
void CGameState::Init()
{

}
void CGameState::CreateBullet()
{
	if (IsKey(VK_SPACE))
	{
		if (m_CUi.m_nBullet > 0)
		{
			if (g_CMng.m_CHeroPickState.m_nIndex == 0)
			{
				if (m_CTimeClass.m_dwBulletLimit + m_CTimeClass.m_dwBulletStand <= GetTickCount())
				{
					m_CTimeClass.m_dwBulletStand = GetTickCount();
					for (int i = 0; i < D_BULLET_MAX; i++)
					{
						if (m_CBullet[i].m_bUse == false && m_CBullet[i + 1].m_bUse == false && m_CBullet[i + 2].m_bUse == false)
						{
							m_CBullet[i].Enable(m_CHero.m_nX, m_CHero.m_nY);
							m_CBullet[i + 1].Enable(m_CHero.m_nX - 1, m_CHero.m_nY);
							m_CBullet[i + 2].Enable(m_CHero.m_nX + 1, m_CHero.m_nY);
							m_CUi.m_nBullet -= 3;
							break;
						}
					}
				}
			}

			if (g_CMng.m_CHeroPickState.m_nIndex == 1)
			{
				if (m_CTimeClass.m_dwBulletLimit + m_CTimeClass.m_dwBulletStand <= GetTickCount())
				{
					m_CTimeClass.m_dwBulletStand = GetTickCount();
					for (int i = 0; i < D_BULLET_MAX; i++)
					{
						if (m_CBullet[i].m_bUse == false && m_CBullet[i + 1].m_bUse == false)
						{
							m_CBullet[i].Enable(m_CHero.m_nX - 1, m_CHero.m_nY);
							m_CBullet[i + 1].Enable(m_CHero.m_nX + 1, m_CHero.m_nY);
							m_CUi.m_nBullet -= 2;
							break;
						}
					}
				}
			}

			if (g_CMng.m_CHeroPickState.m_nIndex == 2)
			{
				if (m_CTimeClass.m_dwBulletLimit + m_CTimeClass.m_dwBulletStand <= GetTickCount())
				{
					m_CTimeClass.m_dwBulletStand = GetTickCount();
					for (int i = 0; i < D_BULLET_MAX; i++)
					{
						if (m_CSgBullet[0][i].m_bUse == false && m_CSgBullet[1][i].m_bUse == false && m_CSgBullet[2][i].m_bUse == false && m_CSgBullet[3][i].m_bUse == false && m_CSgBullet[4][i].m_bUse == false)
						{
							//if (m_CHeroSKill.m_bUse == true)
							//{
							//	m_nColor = rand() % 12;
							//	m_CSgBullet[0][i].m_wFColor = m_nColor;
							//	m_CSgBullet[1][i].m_wFColor = m_nColor;
							//	m_CSgBullet[2][i].m_wFColor = m_nColor;
							//	m_CSgBullet[3][i].m_wFColor = m_nColor;
							//	m_CSgBullet[4][i].m_wFColor = m_nColor;
							//	m_CSgBullet[2][i].m_wFColor = m_nColor;
							//}
							//m_CSgBullet[0][i].Enable(m_CHero.m_nX - 1, m_CHero.m_nY - 1);
							//m_CSgBullet[1][i].Enable(m_CHero.m_nX - 2, m_CHero.m_nY - 1);
							//m_CSgBullet[2][i].Enable(m_CHero.m_nX, m_CHero.m_nY - 1);
							//m_CSgBullet[3][i].Enable(m_CHero.m_nX + 1, m_CHero.m_nY - 1);
							//m_CSgBullet[4][i].Enable(m_CHero.m_nX + 2, m_CHero.m_nY - 1);
							//m_CSgBullet[2][i].m_nBeY = m_CSgBullet[2][i].m_nY - 2;
							//m_CUi.m_nBullet -= 5;
							//break;
						}
					}
				}
			}

			if (g_CMng.m_CHeroPickState.m_nIndex == 3)
			{
				if (m_CTimeClass.m_dwBulletLimit + m_CTimeClass.m_dwBulletStand <= GetTickCount())
				{
					m_CTimeClass.m_dwBulletStand = GetTickCount();
					for (int i = 0; i < D_BULLET_MAX; i++)
					{
						if (m_CBullet[i].m_bUse == false)
						{
							m_CBullet[i].Enable(m_CHero.m_nX, m_CHero.m_nY);
							m_CUi.m_nBullet -= 1;
							break;
						}
					}
				}
			}
		}
	}
}
void CGameState::CreateMonster()
{
	if (m_CTimeClass.m_dwLimitMonster + m_CTimeClass.m_dwStandMonster <= GetTickCount())
	{
		m_CTimeClass.m_dwStandMonster = GetTickCount();
		for (int i = 0; i < D_MONSTER_MAX; i++)
		{
			if (m_CMonster[i].m_bUse == false)
			{
				m_CMonster[i].Enable((rand() % 117) + 2, 5);
				break;
			}
		}
	}
}
void CGameState::Bullet_Monster()
{
	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		if (m_CBullet[i].m_bUse == true)
		{
			for (int j = 0; j < D_MONSTER_MAX; j++)
			{
				if (m_CMonster[j].m_bUse == true)
				{
					if (m_CBullet[i].m_nY <= m_CMonster[j].m_nY)
					{
						if (m_CBullet[i].m_nX == m_CMonster[j].m_nX)
						{
							CreateEffect(m_CBullet[i].m_nX, m_CBullet[i].m_nY, YELLOW);
							CreateItem(m_CBullet[i].m_nX, m_CBullet[i].m_nY);
							m_CBullet[i].Disable();
							m_CMonster[j].Disable();
							m_CUi.m_nScore = m_CUi.m_nScore + D_SCORE_50;
							g_CMng.m_CShopState.m_nCoin += g_CMng.m_CShopState.m_nCoinMul * 15;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < D_BULLET_MAX; j++)
		{
			if (m_CSgBullet[i][j].m_bUse == true)
			{
				for (int k = 0; k < D_MONSTER_MAX; k++)
				{
					if (m_CMonster[k].m_bUse == true)
					{
						if (m_CSgBullet[i][j].m_nY <= m_CMonster[k].m_nY)
						{
							if (m_CSgBullet[i][j].m_nX == m_CMonster[k].m_nX)
							{
								CreateEffect(m_CMonster[k].m_nX, m_CMonster[k].m_nY, YELLOW);
								CreateItem(m_CMonster[k].m_nX, m_CMonster[k].m_nY);
								m_CSgBullet[i][j].Disable();
								m_CMonster[k].Disable();
								m_CUi.m_nScore = m_CUi.m_nScore + D_SCORE_50;
								g_CMng.m_CShopState.m_nCoin += g_CMng.m_CShopState.m_nCoinMul * 15;
							}
						}
					}
				}
			}
		}
	}

	///////////////////////////////////////////////////////

	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		if (m_CBullet[i].m_bUse == true)
		{
			for (int j = 0; j < D_MONSTER_MAX; j++)
			{
				if (m_CSubMonster[j].m_bUse == true)
				{
					if (m_CBullet[i].m_nY <= m_CSubMonster[j].m_nY)
					{
						if (m_CBullet[i].m_nX == m_CSubMonster[j].m_nX)
						{
							CreateEffect(m_CBullet[i].m_nX, m_CBullet[i].m_nY, LIGHTBLUE);
							CreateItem(m_CBullet[i].m_nX, m_CBullet[i].m_nY);
							m_CBullet[i].Disable();
							m_CSubMonster[j].Disable();
							m_CUi.m_nScore = m_CUi.m_nScore + D_SCORE_70;
							g_CMng.m_CShopState.m_nCoin += g_CMng.m_CShopState.m_nCoinMul * 15;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < D_BULLET_MAX; j++)
		{
			if (m_CSgBullet[i][j].m_bUse == true)
			{
				for (int k = 0; k < D_MONSTER_MAX; k++)
				{
					if (m_CSubMonster[k].m_bUse == true)
					{
						if (m_CSgBullet[i][j].m_nY <= m_CSubMonster[k].m_nY)
						{
							if (m_CSgBullet[i][j].m_nX == m_CSubMonster[k].m_nX)
							{
								CreateEffect(m_CSubMonster[k].m_nX, m_CSubMonster[k].m_nY, LIGHTBLUE);
								CreateItem(m_CSubMonster[k].m_nX, m_CSubMonster[k].m_nY);
								m_CSgBullet[i][j].Disable();
								m_CSubMonster[k].Disable();
								m_CUi.m_nScore = m_CUi.m_nScore + D_SCORE_70;
								g_CMng.m_CShopState.m_nCoin += g_CMng.m_CShopState.m_nCoinMul * 15;
							}
						}
					}
				}
			}
		}
	}
}
void CGameState::CreateEffect(int nX, int nY, int nColor)
{
	for (int i = 0; i < D_EFFECT_MAX; i++)
	{
		if (m_CEffect[i].m_bUse == false)
		{
			m_CEffect[i].Enable(nX, nY);
			m_CEffect[i].m_wFColor = nColor;
			break;
		}
	}
}
void CGameState::DeadHero()
{
	for (int i = 0; i < D_MONSTER_MAX; i++)
	{
		if (m_CMonster[i].m_bUse == true)
		{
			if (m_CMonster[i].m_nY == m_CHero.m_nY)
			{
				if (m_CMonster[i].m_nX == m_CHero.m_nX)
				{
					m_CUi.m_nHp--;
				}
			}
		}
	}
}
void CGameState::CreateSkill()
{
	if (m_nSKill_CollDown > 0)
	{
		if (IsKey(VK_B))
		{
			if (m_CSkill.m_bUse == false)
			{
				m_CSkill.Enable(0, 29);
				m_nSKill_CollDown--;
			}
		}
	}
	if (m_nSKill_1_CollDown > 0)
	{
		if (IsKey(VK_V))
		{
			if (m_CSkill.m_bUse == false)
			{
				m_CSkill_1.Enable(m_CHero.m_nX, m_CHero.m_nY - 1);
				m_CSkill_1.m_nVal = m_CSkill_1.m_nY - 6;
				m_nSKill_1_CollDown--;
			}
		}
	}
}
void CGameState::Skill_Monster()
{
	if (m_CSkill.m_bUse == true)
	{
		for (int i = 0; i < D_MONSTER_MAX; i++)
		{
			if (m_CMonster[i].m_bUse == true)
			{
				if (m_CMonster[i].m_nY >= m_CSkill.m_nY)
				{
					CreateEffect(m_CMonster[i].m_nX, m_CMonster[i].m_nY, YELLOW);
					m_CMonster[i].Disable();
					m_CUi.m_nScore = m_CUi.m_nScore + (D_SCORE_50 / 2);
					g_CMng.m_CShopState.m_nCoin += g_CMng.m_CShopState.m_nCoinMul * 15;
				}
			}
			if (m_CSubMonster[i].m_bUse == true)
			{
				if (m_CSubMonster[i].m_nY >= m_CSkill.m_nY)
				{
					CreateEffect(m_CSubMonster[i].m_nX, m_CSubMonster[i].m_nY, LIGHTBLUE);
					m_CSubMonster[i].Disable();
					m_CUi.m_nScore = m_CUi.m_nScore + (D_SCORE_70 / 2);
					g_CMng.m_CShopState.m_nCoin += g_CMng.m_CShopState.m_nCoinMul * 15;
				}
			}
		}
	}
	if (m_CSkill_1.m_bUse == true && m_CSkill_1.m_nY <= m_CSkill_1.m_nVal)
	{
		m_CSkill_1.m_bUse = false;
		for (int i = 0; i < D_MONSTER_MAX; i++)
		{
			if (m_CMonster[i].m_bUse == true)
			{
				CreateEffect(m_CMonster[i].m_nX, m_CMonster[i].m_nY, YELLOW);
				m_CMonster[i].Disable();
				m_CUi.m_nScore = m_CUi.m_nScore + (D_SCORE_50 / 2);
				g_CMng.m_CShopState.m_nCoin += g_CMng.m_CShopState.m_nCoinMul * 15;
			}
			if (m_CSubMonster[i].m_bUse == true)
			{
				CreateEffect(m_CSubMonster[i].m_nX, m_CSubMonster[i].m_nY, LIGHTBLUE);
				m_CSubMonster[i].Disable();
				m_CUi.m_nScore = m_CUi.m_nScore + (D_SCORE_70 / 2);
				g_CMng.m_CShopState.m_nCoin += g_CMng.m_CShopState.m_nCoinMul * 15;
			}
		}
	}
}
void CGameState::CountDraw()
{
	if (m_nCount > 0)
	{
		DrawStrEx3(60, 15, m_cCount, WHITE, BLACK);
	}
	else
	{
		DrawStrEx3(55, 15, "Game Start!", WHITE, BLACK);
	}
}
void CGameState::CountUpdate()
{
	sprintf(m_cCount, "%d", m_nCount);
	if (m_CTimeClass.m_dwCountLimit + m_CTimeClass.m_dwCountStand <= GetTickCount())
	{
		m_CTimeClass.m_dwCountStand = GetTickCount();
		m_nCount--;
	}
	if (m_nCount <= -1)
	{
		m_bCount = false;
	}
}

void CGameState::Bullet_Reload()
{
	sprintf(m_cReload, "%d", m_nReload);
	if (m_CUi.m_nBullet <= 0)
	{
		m_CUi.m_nBullet = 0;
		DrawStrEx3(m_CHero.m_nX, m_CHero.m_nY + 1, m_cReload, WHITE, BLACK);
		if (m_CTimeClass.m_dwBullet_Reload_Limit + m_CTimeClass.m_dwBullet_Reload_Stand <= GetTickCount())
		{
			m_CTimeClass.m_dwBullet_Reload_Stand = GetTickCount();
			m_nReload--;
		}
		if (m_nReload <= 0)
		{
			m_CUi.m_nBullet = g_CMng.m_CHeroPickState.m_nBullet;
			m_nReload = g_CMng.m_CHeroPickState.m_dwBullet_Reload / 1000;
		}
	}
}
void CGameState::Barrier_Hero()
{
	for (int i = 0; i < D_BARRIER_MAX; i++)
	{
		if (m_CBarrier[i].m_bUse == true)
		{
			if (m_CBarrier[i].m_nX == m_CHero.m_nX)
			{
				if (m_CBarrier[i].m_nY == m_CHero.m_nY)
				{
					m_CBarrier[i].Disable();
					m_CUi.m_nHp--;
				}
			}
		}
	}
}
void CGameState::CreateBarrier()
{
	if (m_CTimeClass.m_dwBarrier_Stand + m_CTimeClass.m_dwBarrier_Limit <= GetTickCount())
	{
		m_CTimeClass.m_dwBarrier_Stand = GetTickCount();
		for (int i = 0; i < D_BARRIER_MAX; i++)
		{
			if (m_CBarrier[i].m_bUse == false)
			{
				m_CBarrier[i].Enable((rand() % 118) + 1, (rand() % 24) + 6);
				break;
			}
		}
	}
}
void CGameState::Boss_Bullet()
{
	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		if (m_CBullet[i].m_bUse == true)
		{
			if (m_CBullet[i].m_nY < m_CBoss.m_nY)
			{
				if (m_CBullet[i].m_nX == m_CBoss.m_nX)
				{
					m_CBoss.m_nHp--;
					m_CBullet[i].Disable();
					Monster_HitColor();
				}
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < D_BULLET_MAX; j++)
		{
			if (m_CSgBullet[i][j].m_bUse == true)
			{
				if (m_CSgBullet[i][j].m_nY < m_CBoss.m_nY)
				{
					if (m_CSgBullet[i][j].m_nX == m_CBoss.m_nX)
					{
						m_CBoss.m_nHp--;
						m_CSgBullet[i][j].Disable();
						Monster_HitColor();
					}
				}
			}
		}
	}
}
void CGameState::Boss_Hero()
{
	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		if (m_CBossBullet[i].m_bUse == true)
		{
			if (m_CBossBullet[i].m_nY == m_CHero.m_nY)
			{
				if (m_CBossBullet[i].m_nX == m_CHero.m_nX)
				{
					m_CBossBullet[i].Disable();
					m_CUi.m_nHp -= 2;
					if (m_CSkill_2.m_bUse == false)
					{
						m_CUi.m_nHp++;
					}
				}
			}
		}
	}

	if (m_CBossSkill.m_bUse == true)
	{
		if (m_CBossSkill.m_nX == m_CHero.m_nX)
		{
			if (m_CBossSkill.m_nY == m_CHero.m_nY)
			{
				m_CUi.m_nHp -= 5;
				CreateEffect(m_CHero.m_nX, m_CHero.m_nY, LIGHTMAGENTA);
				m_CBossSkill.Disable();
			}
		}
	}
}
void CGameState::CreateBossBullet()
{
	if (m_CTimeClass.m_dwBossBullet_Stand + m_CTimeClass.m_dwBossBullet_Limit <= GetTickCount())
	{
		m_CTimeClass.m_dwBossBullet_Stand = GetTickCount();

		if (m_nStage == 4)
		{
			for (int i = 0; i < D_BULLET_MAX - 1; i++)
			{
				if (m_CBossBullet[i].m_bUse == false && m_CBossBullet[i + 1].m_bUse == false)
				{
					m_CBossBullet[i].Enable(m_CBoss.m_nX - 1, m_CBoss.m_nY + 2);
					m_CBossBullet[i + 1].Enable(m_CBoss.m_nX + 1, m_CBoss.m_nY + 2);
					break;
				}
			}
		}

		if (m_nStage == 5)
		{
			for (int i = 0; i < D_BULLET_MAX - 1; i++)
			{
				if (m_CBossBullet[i].m_bUse == false && m_CBossBullet[i + 1].m_bUse == false && m_CBossBullet[i + 2].m_bUse == false && m_CBossBullet[i + 3].m_bUse == false)
				{
					m_CBossBullet[i].Enable(m_CBoss.m_nX - 1, m_CBoss.m_nY + 2);
					m_CBossBullet[i + 1].Enable(m_CBoss.m_nX + 1, m_CBoss.m_nY + 2);
					m_CBossBullet[i + 2].Enable(m_CBoss.m_nX + 2, m_CBoss.m_nY + 1);
					m_CBossBullet[i + 3].Enable(m_CBoss.m_nX - 2, m_CBoss.m_nY + 1);
					break;
				}
			}
		}
	}
}
void CGameState::CreateItem(int nX, int nY)
{
	m_nRandom_rand = rand() % 100;
	if (m_nRandom_rand >= 80)
	{
		for (int i = 0; i < D_ITEM_MAX; i++)
		{
			if (m_CItem[i].m_bUse == false)
			{
				m_CItem[i].Enable(nX, nY);
				m_CItem[i].m_nRandom = (rand() % 3) + 1;
				m_CItem[i].m_dwStandTime = GetTickCount();
				break;
			}
		}
	}
}
void CGameState::Hero_Item()
{
	for (int i = 0; i < D_ITEM_MAX; i++)
	{
		if (m_CItem[i].m_bUse == true)
		{
			if (m_CHero.m_nX == m_CItem[i].m_nX)
			{
				if (m_CHero.m_nY == m_CItem[i].m_nY)
				{
					m_CItem[i].m_nX = -100;
					m_CItem[i].m_nY = -100;
					m_CItem[i].m_nVal = 1;
				}
			}
		}
	}
}
void CGameState::Monster_HitColor()
{
	m_CBoss.m_wMainColor = LIGHTRED;
	m_CBoss.m_wFColor = LIGHTRED;
}
void CGameState::CreateTerret()
{
	if (g_CMng.m_CHeroPickState.m_nIndex == 3)
	{
		if (IsKey(VK_Z))
		{
			if (m_CTimeClass.m_dwTerret_Limit + m_CTimeClass.m_dwTerret_Stand <= GetTickCount())
			{
				m_CTimeClass.m_dwTerret_Stand = GetTickCount();
				for (int i = 0; i < D_TERRET_MAX; i++)
				{
					if (m_CTerret[i].m_bUse == false)
					{
						m_CTerret[i].Enable(m_CHero.m_nX, m_CHero.m_nY);
						m_CTerret[i].m_dwStandTime = GetTickCount();
						m_CTerret[i].m_dwStand_Draw = GetTickCount();
						break;
					}
				}
			}
		}
	}
}
void CGameState::CreateTerretBullet()
{
	if (m_CTimeClass.m_dwTerretBullet_Limit + m_CTimeClass.m_dwTerretBullet_Stand <= GetTickCount())
	{
		m_CTimeClass.m_dwTerretBullet_Stand = GetTickCount();
		for (int i = 0; i < D_TERRET_MAX; i++)
		{
			if (m_CTerret[i].m_bUse == true)
			{
				for (int j = 0; j < D_BULLET_MAX; j++)
				{
					if (m_CBullet[j].m_bUse == false)
					{
						m_CBullet[j].Enable(m_CTerret[i].m_nX, m_CTerret[i].m_nY - 1);
						break;
					}
				}
			}
		}
	}

	//5초 마다 스폰되어 있는 몬스터 없애주는 기능
	for (int i = 0; i < D_TERRET_MAX; i++)
	{
		if (m_CTerret[i].m_bUse == true)
		{
			if (m_CTerret[i].m_dwLimit_Monster + m_CTerret[i].m_dwStand_Monster <= GetTickCount())
			{
				m_CTerret[i].m_dwStand_Monster = GetTickCount();
				for (int j = 0; j < D_MONSTER_MAX; j++)
				{
					if (m_CMonster[j].m_bUse == true)
					{
						CreateEffect(m_CMonster[j].m_nX, m_CMonster[j].m_nY, YELLOW);
						m_CUi.m_nScore = m_CUi.m_nScore + D_SCORE_50;
						m_CMonster[j].Disable();
						break;
					}
				}
				if (m_nStage > 1)
				{
					for (int j = 0; j < D_MONSTER_MAX; j++)
					{
						if (m_CSubMonster[j].m_bUse == true)
						{
							CreateEffect(m_CSubMonster[j].m_nX, m_CSubMonster[j].m_nY, LIGHTBLUE);
							m_CUi.m_nScore = m_CUi.m_nScore + D_SCORE_70;
							m_CSubMonster[j].Disable();
							break;
						}
					}
				}
			}
		}
	}
}
void CGameState::Hero_Sub()
{
	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		if (m_CSubBullet[i].m_bUse == true)
		{
			if (m_CSubBullet[i].m_nX == m_CHero.m_nX)
			{
				if (m_CSubBullet[i].m_nY == m_CHero.m_nY)
				{
					m_CSubBullet[i].Disable();
					m_CUi.m_nHp--;
				}
			}
		}
	}
}
void CGameState::CreateSubBullet()
{
	for (int i = 0; i < D_MONSTER_MAX; i++)
	{
		if (m_CSubMonster[i].m_dwBulletLimit + m_CSubMonster[i].m_dwBulletStand <= GetTickCount())
		{
			m_CSubMonster[i].m_dwBulletStand = GetTickCount();
			if (m_CSubMonster[i].m_bUse == true)
			{
				for (int j = 0; j < D_BULLET_MAX; j++)
				{
					if (m_CSubBullet[j].m_bUse == false)
					{
						m_CSubBullet[j].Enable(m_CSubMonster[i].m_nX, m_CSubMonster[i].m_nY);
						break;
					}
				}
			}
		}
	}
}
void CGameState::CreateSubMonster()
{
	if (m_CTimeClass.m_dwSubLimit + m_CTimeClass.m_dwSubStand <= GetTickCount())
	{
		m_CTimeClass.m_dwSubStand = GetTickCount();
		for (int i = 0; i < D_MONSTER_MAX; i++)
		{
			if (m_CSubMonster[i].m_bUse == false)
			{
				m_CSubMonster[i].Enable((rand() % 118) + 1, 6);
				break;
			}
		}
	}
}
void CGameState::Pause()
{
	if (IsKey(VK_P))
	{
		if (m_bPause == false)
		{
			m_bPause = true;
		}
	}

	if (IsKey(VK_O))
	{
		if (m_bPause == true)
		{
			m_bPause = false;
		}
	}

	if (m_bPause == true)
	{
		DrawStrEx3(47, 21, "Current game status : Pause", RED, BLACK);
		DrawStrEx3(51, 23, "Press O to disable", RED, BLACK);
	}
}
void CGameState::CreateBossSkill()
{
	if (m_nStage == 5)
	{
		if (m_CBossSkill.m_bUse == false)
		{
			if (m_CTimeClass.m_dwBossSkill_Limit + m_CTimeClass.m_dwBossSkill_Stand <= GetTickCount())
			{
				m_CTimeClass.m_dwBossSkill_Stand = GetTickCount();
				m_CBossSkill.m_dwStandTime = GetTickCount();
				m_CBossSkill.Enable(m_CBoss.m_nX, m_CBoss.m_nY + 3);
			}
		}
	}
}
void CGameState::Stage1_Draw()
{
	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		m_CBullet[i].Draw();
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < D_BULLET_MAX; j++)
		{
			m_CSgBullet[i][j].Draw();
		}
	}
	for (int i = 0; i < D_TERRET_MAX; i++)
	{
		m_CTerret[i].Draw();
	}
	for (int i = 0; i < D_MONSTER_MAX; i++)
	{
		m_CMonster[i].Draw();
	}
	for (int i = 0; i < D_EFFECT_MAX; i++)
	{
		m_CEffect[i].Draw();
	}
	for (int i = 0; i < D_ITEM_MAX; i++)
	{
		m_CItem[i].Draw();
	}
	m_CHero.Draw();
	m_CSkill.Draw();
	m_CSkill_1.Draw();
	m_CUi.Draw();
}
void CGameState::Stage2_Draw()
{
	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		m_CBullet[i].Draw();
		m_CSubBullet[i].Draw();
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < D_BULLET_MAX; j++)
		{
			m_CSgBullet[i][j].Draw();
		}
	}
	for (int i = 0; i < D_TERRET_MAX; i++)
	{
		m_CTerret[i].Draw();
	}
	for (int i = 0; i < D_MONSTER_MAX; i++)
	{
		m_CMonster[i].Draw();
		m_CSubMonster[i].Draw();
	}
	for (int i = 0; i < D_EFFECT_MAX; i++)
	{
		m_CEffect[i].Draw();
	}
	for (int i = 0; i < D_ITEM_MAX; i++)
	{
		m_CItem[i].Draw();
	}
	m_CHero.Draw();
	m_CSkill.Draw();
	m_CSkill_1.Draw();
	m_CUi.Draw();
}
void CGameState::Stage3_Draw()
{
	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		m_CBullet[i].Draw();
		m_CSubBullet[i].Draw();
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < D_BULLET_MAX; j++)
		{
			m_CSgBullet[i][j].Draw();
		}
	}
	for (int i = 0; i < D_TERRET_MAX; i++)
	{
		m_CTerret[i].Draw();
	}
	for (int i = 0; i < D_MONSTER_MAX; i++)
	{
		m_CMonster[i].Draw();
		m_CSubMonster[i].Draw();
	}
	for (int i = 0; i < D_EFFECT_MAX; i++)
	{
		m_CEffect[i].Draw();
	}
	for (int i = 0; i < D_BARRIER_MAX; i++)
	{
		m_CBarrier[i].Draw();
	}
	for (int i = 0; i < D_ITEM_MAX; i++)
	{
		m_CItem[i].Draw();
	}
	m_CHero.Draw();
	m_CSkill.Draw();
	m_CSkill_1.Draw();
	m_CUi.Draw();
}
void CGameState::Stage4_Draw()
{
	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		m_CBullet[i].Draw();
		m_CBossBullet[i].Draw();
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < D_BULLET_MAX; j++)
		{
			m_CSgBullet[i][j].Draw();
		}
	}
	for (int i = 0; i < D_TERRET_MAX; i++)
	{
		m_CTerret[i].Draw();
	}
	for (int i = 0; i < D_BARRIER_MAX; i++)
	{
		m_CBarrier[i].Draw();
	}
	for (int i = 0; i < D_MONSTER_MAX; i++)
	{
		m_CMonster[i].Draw();
	}
	for (int i = 0; i < D_EFFECT_MAX; i++)
	{
		m_CEffect[i].Draw();
	}
	for (int i = 0; i < D_ITEM_MAX; i++)
	{
		m_CItem[i].Draw();
	}
	m_CHero.Draw();
	m_CSkill.Draw();
	m_CSkill_1.Draw();
	m_CUi.Draw();
	m_CBoss.Draw();
}
void CGameState::Stage5_Draw()
{
	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		m_CBullet[i].Draw();
		m_CBossBullet[i].Draw();
		m_CSubBullet[i].Draw();
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < D_BULLET_MAX; j++)
		{
			m_CSgBullet[i][j].Draw();
		}
	}
	for (int i = 0; i < D_TERRET_MAX; i++)
	{
		m_CTerret[i].Draw();
	}
	for (int i = 0; i < D_MONSTER_MAX; i++)
	{
		m_CMonster[i].Draw();
		m_CSubMonster[i].Draw();
	}
	for (int i = 0; i < D_EFFECT_MAX; i++)
	{
		m_CEffect[i].Draw();
	}
	for (int i = 0; i < D_ITEM_MAX; i++)
	{
		m_CItem[i].Draw();
	}
	if (m_nStage == 5)
	{
		m_CBossSkill.Draw();
	}
	m_CHero.Draw();
	m_CSkill.Draw();
	m_CSkill_1.Draw();
	m_CUi.Draw();
	m_CBoss.Draw();
}
void CGameState::Stage1_Update()
{
	m_CHero.Update();
	m_CUi.Update();
	m_CSkill.Update();
	m_CSkill_1.Update();
	m_CSkill_2.Update();
	//////////////////////////
	CreateSkill();
	CreateBullet();
	CreateMonster();
	CreateTerret();
	CreateTerretBullet();
	//////////////////////////
	Bullet_Monster();
	Hero_Item();
	Skill_Monster();
	//////////////////////////

	DeadHero();
	Bullet_Reload();

	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		m_CBullet[i].Update();
		for (int j = 0; j < 5; j++)
		{
			m_CSgBullet[j][i].Update();
		}
	}
	for (int i = 0; i < D_TERRET_MAX; i++)
	{
		m_CTerret[i].Update();
	}
	for (int i = 0; i < D_MONSTER_MAX; i++)
	{
		m_CMonster[i].Update();
	}
	for (int i = 0; i < D_EFFECT_MAX; i++)
	{
		m_CEffect[i].Update();
	}
	for (int i = 0; i < D_ITEM_MAX; i++)
	{
		m_CItem[i].Update();
	}
}
void CGameState::Stage2_Update()
{
	m_CHero.Update();
	m_CUi.Update();
	m_CSkill.Update();
	m_CSkill_1.Update();
	m_CSkill_2.Update();
	//////////////////////////
	CreateSubBullet();
	CreateSubMonster();
	CreateBullet();
	CreateMonster();
	CreateSkill();
	CreateTerret();
	CreateTerretBullet();
	//////////////////////////
	Hero_Sub();
	Bullet_Monster();
	Skill_Monster();
	Hero_Item();
	//////////////////////////
	DeadHero();
	Bullet_Reload();

	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		m_CBullet[i].Update();
		m_CSubBullet[i].Update();
		for (int i = 0; i < D_BULLET_MAX; i++)
		{
			m_CBullet[i].Update();
			for (int j = 0; j < 5; j++)
			{
				m_CSgBullet[j][i].Update();
			}
		}
	}
	for (int i = 0; i < D_TERRET_MAX; i++)
	{
		m_CTerret[i].Update();
	}
	for (int i = 0; i < D_MONSTER_MAX; i++)
	{
		m_CMonster[i].Update();
		m_CSubMonster[i].Update();
	}
	for (int i = 0; i < D_EFFECT_MAX; i++)
	{
		m_CEffect[i].Update();
	}
	for (int i = 0; i < D_ITEM_MAX; i++)
	{
		m_CItem[i].Update();
	}
}
void CGameState::Stage3_Update()
{
	m_CHero.Update();
	m_CUi.Update();
	m_CSkill.Update();
	m_CSkill_1.Update();
	m_CSkill_2.Update();
	//////////////////////////
	CreateSubBullet();
	CreateSubMonster();

	CreateBullet();
	CreateMonster();
	CreateSkill();
	CreateBarrier();
	CreateTerret();
	CreateTerretBullet();
	//////////////////////////
	Hero_Sub();
	Bullet_Monster();
	Skill_Monster();
	m_CSkill_2.Update();
	Hero_Item();
	//////////////////////////
	if (m_CSkill_2.m_bUse == false)
	{
		DeadHero();
		Barrier_Hero();
	}
	Bullet_Reload();

	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		m_CBullet[i].Update();
		m_CSubBullet[i].Update();
		for (int i = 0; i < D_BULLET_MAX; i++)
		{
			m_CBullet[i].Update();
			for (int j = 0; j < 5; j++)
			{
				m_CSgBullet[j][i].Update();
			}
		}
	}
	for (int i = 0; i < D_TERRET_MAX; i++)
	{
		m_CTerret[i].Update();
	}
	for (int i = 0; i < D_MONSTER_MAX; i++)
	{
		m_CMonster[i].Update();
		m_CSubMonster[i].Update();
	}
	for (int i = 0; i < D_EFFECT_MAX; i++)
	{
		m_CEffect[i].Update();
	}
	for (int i = 0; i < D_BARRIER_MAX; i++)
	{
		m_CBarrier[i].Update();
	}
	for (int i = 0; i < D_ITEM_MAX; i++)
	{
		m_CItem[i].Update();
	}
}
void CGameState::Stage4_Update()
{
	m_CHero.Update();
	m_CUi.Update();
	m_CSkill.Update();
	m_CSkill_1.Update();
	m_CSkill_2.Update();
	m_CBoss.Update();
	//////////////////////////
	CreateBullet();
	CreateSkill();
	CreateBarrier();
	CreateBossBullet();
	CreateMonster();
	CreateTerret();
	CreateTerretBullet();
	//////////////////////////
	Bullet_Monster();
	Skill_Monster();
	Boss_Bullet();
	Hero_Item();
	if (m_CSkill_2.m_bUse == false)
	{
		Barrier_Hero();
		Boss_Hero();
	}
	//////////////////////////
	if (m_CSkill_2.m_bUse == false) DeadHero();
	Bullet_Reload();
	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		m_CBullet[i].Update();
		m_CBossBullet[i].Update();
	}
	for (int i = 0; i < D_TERRET_MAX; i++)
	{
		m_CTerret[i].Update();
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < D_BULLET_MAX; j++)
		{
			m_CSgBullet[i][j].Update();
		}
	}
	for (int i = 0; i < D_BARRIER_MAX; i++)
	{
		m_CBarrier[i].Update();
	}
	for (int i = 0; i < D_MONSTER_MAX; i++)
	{
		m_CMonster[i].Update();
	}
	for (int i = 0; i < D_EFFECT_MAX; i++)
	{
		m_CEffect[i].Update();
	}
	for (int i = 0; i < D_ITEM_MAX; i++)
	{
		m_CItem[i].Update();
	}
}
void CGameState::Stage5_Update()
{
	m_CHero.Update();
	m_CUi.Update();
	m_CSkill.Update();
	m_CSkill_1.Update();
	m_CSkill_2.Update();
	m_CBoss.Update();
	//////////////////////////
	CreateSubBullet();
	CreateSubMonster();
	CreateBullet();
	CreateMonster();
	CreateSkill();
	CreateBarrier();
	CreateBossBullet();
	CreateTerret();
	CreateTerretBullet();
	CreateBossSkill();
	//////////////////////////
	Hero_Sub();
	Bullet_Monster();
	Skill_Monster();
	Hero_Item();
	if (m_CSkill_2.m_bUse == false)
	{
		Barrier_Hero();
		Boss_Hero();
	}
	Boss_Bullet();
	//////////////////////////
	if (m_CSkill_2.m_bUse == false) DeadHero();
	Bullet_Reload();
	for (int i = 0; i < D_BULLET_MAX; i++)
	{
		m_CBullet[i].Update();
		m_CBossBullet[i].Update();
		m_CSubBullet[i].Update();
	}
	for (int i = 0; i < D_TERRET_MAX; i++)
	{
		m_CTerret[i].Update();
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < D_BULLET_MAX; j++)
		{
			m_CSgBullet[i][j].Update();
		}
	}
	for (int i = 0; i < D_MONSTER_MAX; i++)
	{
		m_CMonster[i].Update();
		m_CSubMonster[i].Update();
	}
	for (int i = 0; i < D_EFFECT_MAX; i++)
	{
		m_CEffect[i].Update();
	}
	for (int i = 0; i < D_BARRIER_MAX; i++)
	{
		m_CBarrier[i].Update();
	}
	for (int i = 0; i < D_ITEM_MAX; i++)
	{
		m_CItem[i].Update();
	}
	if (m_nStage == 5)
	{
		m_CBossSkill.Update();
	}
}