#ifndef __CRAZY_CAR__CAR_H__
#define __CRAZY_CAR__CAR_H__

#include "Rocket.h"
#include "Control.h"
#include <vector>
#include <string>
#include <ncurses.h>

class CCar:public CControl
{
public:
	int m_Speed;
	int m_Health;
	int m_X;
	int m_Y;
	int m_Score;
	bool hidden;
	int m_key_up = KEY_UP, m_key_down = KEY_DOWN, m_key_left = KEY_LEFT, m_key_right = KEY_RIGHT;

public:
	virtual void draw_car();
	virtual void show_car();
	void move(WINDOW *win);
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
