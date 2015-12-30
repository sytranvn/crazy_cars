#pragma once
class CRocket
{
public:
	int m_X;
	int m_Y;
	int m_Speed;
public:
	void DrawRocket();
	void ClearRocket();
	CRocket(int,int);
	~CRocket(void);
};

