class CShopState : public CState
{
public:
	DWORD m_dwStandTime;
	DWORD m_dwLimitTime;
	WORD m_wFcolor_[E_SHOP_MAX];
	WORD m_wBColor;
	bool m_bUse[E_SHOP_MAX];
	char m_cCoin[256];
	int m_nY;
	int m_nX;
	int m_nCoin;
	int m_nCoinMul;
public:
	CShopState();
	~CShopState();
public:
	void Clipping();
	virtual void Start();
	virtual void Update();
	virtual void Draw();
	virtual void Exit();
	//virtual void Enable(int nX, int nY);
	//virtual void Disable();
	//virtual void Init();
};