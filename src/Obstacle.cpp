#include "Obstacle.h"
#include "Racing.h"

void CObstacle::DrawObs()
{
	CRacing::MapChar[m_X+1][m_Y+1] = (char)31;
	CRacing::MapColor[m_X+1][m_Y+1]=126;
	CRacing::MapChar[m_X][m_Y+1] = (char)25;
	CRacing::MapColor[m_X][m_Y+1]=114;
	CRacing::MapChar[m_X-1][m_Y+1] = (char)31;
	CRacing::MapColor[m_X-1][m_Y+1]=126;

	CRacing::MapChar[m_X-1][m_Y] = (char)240;
	CRacing::MapColor[m_X-1][m_Y]=116;
	CRacing::MapChar[m_X][m_Y] = (char)177;
	CRacing::MapColor[m_X][m_Y]=124;
	CRacing::MapChar[m_X+1][m_Y]= (char)240;
	CRacing::MapColor[m_X+1][m_Y]=116;

	CRacing::MapChar[m_X-1][m_Y-1] = (char)240;
	CRacing::MapColor[m_X-1][m_Y-1]=116;
	CRacing::MapChar[m_X][m_Y-1] = (char)178;
	CRacing::MapColor[m_X][m_Y-1]=124;
	CRacing::MapChar[m_X+1][m_Y-1] =(char)240;
	CRacing::MapColor[m_X+1][m_Y-1]=116;
}

void CObstacle::EraseObs()
{
	CRacing::MapChar[m_X-1][m_Y-1] = ' ';
	CRacing::MapColor[m_X-1][m_Y-1]=112;
	CRacing::MapChar[m_X-1][m_Y+1] = ' ';
	CRacing::MapColor[m_X-1][m_Y+1]=112;
	CRacing::MapChar[m_X-1][m_Y] = ' ';
	CRacing::MapColor[m_X-1][m_Y]=112;

	CRacing::MapChar[m_X+1][m_Y-1] =' ';
	CRacing::MapColor[m_X+1][m_Y-1]=112;
	CRacing::MapChar[m_X+1][m_Y+1] = ' ';
	CRacing::MapColor[m_X+1][m_Y+1]=112;
	CRacing::MapChar[m_X+1][m_Y]=' ';
	CRacing::MapColor[m_X+1][m_Y]=112;

	CRacing::MapChar[m_X][m_Y-1] = ' ';
	CRacing::MapColor[m_X][m_Y-1]=112;
	CRacing::MapChar[m_X][m_Y+1] = ' ';
	CRacing::MapColor[m_X][m_Y+1]=112;
	CRacing::MapChar[m_X][m_Y] = ' ';
	CRacing::MapColor[m_X][m_Y]=112;
	m_Y+=CRacing::m_Level;
}

CObstacle::CObstacle(void)
{
	m_Y=100000;
	m_X=20;
}

CObstacle::~CObstacle(void)
{
}