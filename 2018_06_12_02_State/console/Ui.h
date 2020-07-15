class CUi : public CUnit
{
public:
	int m_nScore;
	int m_nIndex;
	int m_nHp;
	int m_nX;
	int m_nY;
	int m_nBullet;
	int m_nSec;			//경기 시간 측정 변수
	char m_cSec[256];
	int m_nMin;			//경기 시간 측정 변수
	char m_cMin[256];
	int m_nHour;		//경기 시간 측정 변수
	char m_cGage[256];
	char m_cBoss[256];
	char m_cHour[256];
	char m_cScore[256];
	char m_cHp[256];
	char m_cSkill[256];
	char m_cSkill_1[256];
	char m_cSkill_2[256];
	char m_cBullet[256];
	char m_cBossHp[256];
	WORD m_wBcolor;
	WORD m_wFcolor[E_SKILL_MAX];
	DWORD m_dwStandTime;
	DWORD m_dwLimitTIme;
public:
	CUi();
	~CUi();
public:
	virtual void Update();
	virtual void Draw();
	//virtual void Clipping();
	//virtual void Enable(int nX, int nY);
	//virtual void Disable();
	virtual void Init();
};
