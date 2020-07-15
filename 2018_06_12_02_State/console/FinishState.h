class CFinishState : public CState
{
public:

public:
	CFinishState();
	~CFinishState();
public:
	virtual void Start();
	virtual void Update();
	virtual void Draw();
	virtual void Exit();
	//virtual void Enable(int nX, int nY);
	//virtual void Disable();
	//virtual void Init();
};