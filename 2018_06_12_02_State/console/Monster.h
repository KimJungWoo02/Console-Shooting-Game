class CMonster : public CUnit
{
public:

public:
	CMonster();
	~CMonster();
public:
	virtual void Update();
	virtual void Draw();
	virtual void Clipping();
	//virtual void Enable(int nX, int nY);
	//virtual void Disable();
	virtual void Init();
};