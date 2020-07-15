class CItem : public CUnit
{
public:
	int m_nRandom;
	int m_nVal;
public:
	CItem();
	~CItem();
public:
	virtual void Update();
	virtual void Draw();
	virtual void Clipping();
	//virtual void Enable(int nX, int nY);
	//virtual void Disable();
	virtual void Init();
};