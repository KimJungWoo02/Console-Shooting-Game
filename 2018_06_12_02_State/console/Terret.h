class CTerret :public CUnit
{
public:
	DWORD m_dwStandTime;
	DWORD m_dwLimitTime;
	DWORD m_dwStand_Draw;
	DWORD m_dwLimit_Draw;
	DWORD m_dwStand_Monster;
	DWORD m_dwLimit_Monster;
	int m_nCount;
	char m_cCount[256];
public:
	CTerret();
	~CTerret();
public:
	virtual void Update();
	virtual void Draw();
	virtual void Clipping();
	//virtual void Enable(int nX, int nY);
	//virtual void Disable();
	virtual void Init();
};