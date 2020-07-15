class CBarrier :public CUnit
{
public:
	int m_nTime;		//시간 측정용 변수

public:
	CBarrier();
	~CBarrier();
public:
	virtual void Update();
	virtual void Draw();
	virtual void Clipping();
	//virtual void Enable(int nX, int nY);
	//virtual void Disable();
	virtual void Init();
};