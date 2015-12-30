#pragma once
#include "Car.h"
class CBugatti:public CCar
{
public:
	void DrawCar();
	void ShowCar();
	void StopShow();
	CBugatti(void);
	~CBugatti(void);
};

