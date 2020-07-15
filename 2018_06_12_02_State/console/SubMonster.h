class CSubMonster :public CUnit
{
public:
	DWORD m_dwBulletStand;
	DWORD m_dwBulletLimit;
public:
	CSubMonster();
	~CSubMonster();
public:
	virtual void Update();
	virtual void Draw();
	virtual void Clipping();
	//virtual void Enable(int nX, int nY);
	//virtual void Disable();
	virtual void Init();
};
class CSubBullet :public CUnit
{
public:
	CSubBullet();
	~CSubBullet();
public:
	virtual void Update();
	virtual void Draw();
	virtual void Clipping();
	//virtual void Enable(int nX, int nY);
	//virtual void Disable();
	virtual void Init();
};