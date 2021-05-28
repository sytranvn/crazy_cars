#ifndef __CRAZY_CAR__OBSTACLE_H__
#define __CRAZY_CAR__OBSTACLE_H__

class CObstacle
{
public:
	int m_X;
	int m_Y;
	void DrawObs();
	void EraseObs();
	CObstacle(void);
	~CObstacle(void);
};

#endif