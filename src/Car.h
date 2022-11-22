#ifndef __CRAZY_CAR__CAR_H__
#define __CRAZY_CAR__CAR_H__

#include "Rocket.h"
#include "Control.h"
#include <vector>
#include <string>
class CCar:public CControl
{
public:
	int m_Speed;
	int m_Health;
	int m_X;
	int m_Y;
	int m_Score;
	bool hidden;

public:
	virtual void draw_car();
	void move();
	void fire();
	bool impinge();
	bool collect_score();
	void hide();
	void show();
	std::string heath();

	CCar(void);
	~CCar(void);
};

#endif
