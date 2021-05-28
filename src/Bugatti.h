#ifndef __CRAZY_CAR__BUGATTI_H__
#define __CRAZY_CAR__BUGATTI_H__

#include "Car.h"
class CBugatti:public CCar
{
public:
	void DrawCar();
	void ShowCar();
	void hide();
	CBugatti(void);
	~CBugatti(void);
};

#endif

