class CBullet : public CUnit
{
public:
	int m_nBeY;
public:
	CBullet();
	~CBullet();
public:
	virtual void Update();
	virtual void Draw();
	virtual void Clipping();
	//virtual void Enable(int nX, int nY);
	//virtual void Disable();
	virtual void Init();
};