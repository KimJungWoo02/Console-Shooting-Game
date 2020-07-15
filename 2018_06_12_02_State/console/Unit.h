#pragma once

#include "Include.h"

class CUnit
{
public:
	bool	m_bUse;
	int		m_nX;
	int		m_nY;
	char	m_cName;
	int		m_nSpeed;
	int		m_nHp;
	int		m_nAttack;
	WORD	m_wFColor;
	WORD	m_wBColor;
	DWORD m_dwStandTime;
	DWORD m_dwLimitTime;

public:
	CUnit();
	~CUnit();

public:
	virtual void Update();
	virtual void Draw();

	virtual void Clipping();
	virtual void Enable(int nX, int nY);
	virtual void Disable();
	virtual void Init();
};