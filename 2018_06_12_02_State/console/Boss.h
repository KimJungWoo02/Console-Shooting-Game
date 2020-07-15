class CBoss :public CUnit
{
public:
	int m_nVal;
	bool m_bUse;
	bool m_bColor;
	WORD m_wMainColor;
public:
	CBoss();
	~CBoss();
public:
	virtual void Update();
	virtual void Draw();
	virtual void Clipping();
	//virtual void Enable(int nX, int nY);
	//virtual void Disable();
	virtual void Init();
};

class CBossBullet : public CUnit
{
public:

public:
	CBossBullet();
	~CBossBullet();
public:
	virtual void Update();
	virtual void Draw();
	virtual void Clipping();
	//virtual void Enable(int nX, int nY);
	//virtual void Disable();
	virtual void Init();
};