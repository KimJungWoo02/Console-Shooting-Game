class CHeroPickState : public CState
{
public:
	bool m_bUse[E_HERO_MAX];
	bool m_bMsg;
	///////////////////////			�� ����ε��� �ɷ�ġ
	int m_nRazer;					//������
	int m_nBomb;					//��ź ����
	int m_nShield;					//���� ����
	int m_nBullet;					//�Ѿ� ����
	int m_nHp;						//����� Hp
	DWORD m_dwBullet_Time;			//�Ѿ� �߻� ������
	DWORD m_dwBullet_Reload;		//�Ѿ� ���� �ð�
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