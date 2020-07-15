class CHeroPickState : public CState
{
public:
	bool m_bUse[E_HERO_MAX];
	bool m_bMsg;
	///////////////////////			°¢ È÷¾î·ÎµéÀÇ ´É·ÂÄ¡
	int m_nRazer;					//·¹ÀÌÀú
	int m_nBomb;					//ÆøÅº °¹¼ö
	int m_nShield;					//½¯µå °¹¼ö
	int m_nBullet;					//ÃÑ¾Ë °¹¼ö
	int m_nHp;						//È÷¾î·Î Hp
	DWORD m_dwBullet_Time;			//ÃÑ¾Ë ¹ß»ç µô·¹ÀÌ
	DWORD m_dwBullet_Reload;		//ÃÑ¾Ë ÀåÀü ½Ã°£
	///////////////////////			
	
	int m_nVal;
	int m_nHero;
	int m_nX;
	int m_nY;
	int m_nIndex;
	WORD m_wFcolor[E_HERO_MAX];
	WORD m_wFColor;
	WORD m_wBColor;
	DWORD m_dwStandTime;
	DWORD m_dwLimitTime;
	DWORD m_dwMsgStand;
	DWORD m_dwMsgLimit;
	DWORD m_dwMoveStand;
	DWORD m_dwMoveLimit;
public:
	CHeroPickState();
	~CHeroPickState();

public:
	void Clipping();
	virtual void Start();
	virtual void Update();
	virtual void Draw();
	virtual void Exit();
	//virtual void Init();
};