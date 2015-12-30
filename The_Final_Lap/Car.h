#pragma once
#include "Rocket.h"
#include "Control.h"
#include <vector>
using namespace std;
class CCar:public CControl
{
public:
	int m_Speed;
	int m_Health;
	int m_X;
	int m_Y;
	int m_Score;
public:
	virtual void DrawCar();
	void Move();
	void Fire();
	bool Impinge();
	bool CollectScore();
	CCar(void);
	~CCar(void);
};

