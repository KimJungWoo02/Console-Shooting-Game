class CBossSkill :public CUnit
{
public:
	DWORD m_dwMoveStand;
	DWORD m_dwMoveLimit;
public:
	CBossSkill();
	~CBossSkill();
public:
	virtual void Update();
	virtual void Draw();
	virtual void Clipping();
	//virtual void Enable(int nX, int nY);
	//virtual void Disable();
	//virtual void Init();
};