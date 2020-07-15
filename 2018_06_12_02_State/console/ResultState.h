class CResultState : public CState
{
public:
	WORD m_wFcolor;
	WORD m_wBcolor;
public:
	CResultState();
	~CResultState();

public:
	virtual void Start();
	virtual void Update();
	virtual void Draw();
	virtual void Exit();
	//virtual void Init();
};