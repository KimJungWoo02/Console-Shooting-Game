class CSkill : public CUnit
{
public:

public:
	CSkill();
	~CSkill();
public:
	virtual void Update();
	virtual void Draw();
	virtual void Clipping();
	//virtual void Enable(int nX, int nY);
	//virtual void Disable();
	virtual void Init();
};

//////////////////////////////////////////////////////

class CSkill_1 : public CUnit
{
public:
	int m_nVal;

public:
	CSkill_1();
	~CSkill_1();
public:
	virtual void Update();
	virtual void Draw();
	//virtual void Clipping();
	//virtual void Enable(int nX, int nY);
	//virtual void Disable();
	virtual void Init();
};

class CSkill_2 : public CUnit
{
public:

public:
	CSkill_2();
	~CSkill_2();
public:
	virtual void Update();
	//virtual void Draw();
	//virtual void Clipping();
	//virtual void Enable(int nX, int nY);
	//virtual void Disable();
	virtual void Init();
};