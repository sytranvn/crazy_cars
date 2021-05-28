#ifndef __CRAZY_CAR__ROCKET_H__
#define __CRAZY_CAR__ROCKET_H__

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

#endif