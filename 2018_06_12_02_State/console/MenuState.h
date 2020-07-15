class CMenuState : public CState
{
public:
	int m_nX;
	int m_nY;
	WORD m_wFcolor;
	WORD m_wBcolor;
	WORD m_wBcolor_Menu;
	DWORD m_dwStandTime;
	DWORD m_dwLimitTime;
	DWORD m_dwStandTime_Menu;
	DWORD m_dwLimitTime_Menu;
public:
	CMenuState();
	~CMenuState();
public:
	virtual void Start();
	virtual void Update();
	virtual void Draw();
	virtual void Exit();
	//virtual void Init();
};