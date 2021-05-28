#ifndef __CRAZY_CAR__LAMBOR_H__
#define __CRAZY_CAR__LAMBOR_H__

#include "Car.h"
class CLambor:public CCar
{
public:
	void DrawCar();
	void ShowCar();
	void StopShow();
	//void Fire();
	CLambor(void);
	~CLambor(void);

};

#endif