class CLogoState : public CState
{
public:
	bool m_bUse;
	DWORD m_dwLimitTime;
	DWORD m_dwStandTime;
	int m_nVal;
	int m_nVal2;
public:
	CLogoState();
	~CLogoState();

public:
	virtual void Start();
	virtual void Update();
	virtual void Draw();
	virtual void Exit();
	//virtual void Init();
};