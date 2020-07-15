class CEffect : public CUnit
{
public:
	int m_nIndex;

public:
	CEffect();
	~CEffect();
public:
	virtual void Update();
	virtual void Draw();
	//virtual void Clipping();
	//virtual void Enable(int nX, int nY);
	//virtual void Disable();
	virtual void Init();
};