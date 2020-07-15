class CGameState : public CState
{
public:
	CHero m_CHero;
	CBullet m_CBullet[D_BULLET_MAX];
	CBullet m_CSgBullet[5][D_BULLET_MAX];
	CMonster m_CMonster[D_MONSTER_MAX];
	CSubBullet m_CSubBullet[D_BULLET_MAX];
	CSubMonster m_CSubMonster[D_MONSTER_MAX];
	CEffect m_CEffect[D_EFFECT_MAX];
	CUi m_CUi;
	CSkill m_CSkill;
	CSkill_2 m_CSkill_2;
	CSkill_1 m_CSkill_1;
	CBarrier m_CBarrier[D_BARRIER_MAX];
	CBoss m_CBoss;
	CBossBullet m_CBossBullet[D_BULLET_MAX];
	CTimeClass m_CTimeClass;
	CItem m_CItem[D_ITEM_MAX];
	CTerret m_CTerret[D_TERRET_MAX];
	CBossSkill m_CBossSkill;

	/////////////////////////

	bool m_bCount;
	bool m_bPause;
	char m_cCount[256];
	char m_cReload[256];
	int m_nRandom_rand;
	int m_nCount;
	int m_nStage;
	int m_nColor;
	int m_nSKill_CollDown;
	int m_nSKill_1_CollDown;
	int m_nSKill_2_CollDown;
	int m_nReload;
public:
	CGameState();
	~CGameState();
public:
	virtual void Start();
	virtual void Update();
	virtual void Draw();
	virtual void Exit();

	//////////////////////////

	void Init();
	void CreateBullet();
	void CreateMonster();
	void Bullet_Monster();
	void CreateEffect(int nX, int nY, int nColor);

	void Bullet_Reload();

	void DeadHero();
	void CreateSkill();
	void CreateBarrier();
	void CreateBossBullet();
	void CreateItem(int nX, int nY);
	void CreateTerret();
	void CreateTerretBullet();
	void CreateSubMonster();
	void CreateSubBullet();
	void CreateBossSkill();


	void Skill_Monster();
	void Barrier_Hero();
	void Boss_Bullet();
	void Boss_Hero();
	void Hero_Item();
	void Hero_Sub();


	void Pause();

	void CountDraw();
	void CountUpdate();
	void StageMng();
	void Monster_HitColor();

	void Stage1_Draw();
	void Stage2_Draw();
	void Stage3_Draw();
	void Stage4_Draw();
	void Stage5_Draw();

	void Stage1_Update();
	void Stage2_Update();
	void Stage3_Update();
	void Stage4_Update();
	void Stage5_Update();
};