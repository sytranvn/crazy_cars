#include "F1.h"
#include "Racing.h"

void CF1::DrawCar()
{
	CRacing::MapChar[m_X][m_Y] = (char)206;
	CRacing::MapColor[m_X][m_Y] = 154;
	CRacing::MapChar[m_X][m_Y-1]=(char)203;
	CRacing::MapColor[m_X][m_Y-1]=250;
	CRacing::MapChar[m_X + 1][m_Y] = (char)185;
	CRacing::MapColor[m_X + 1][m_Y] = 250;

	CRacing::MapChar[m_X - 1][m_Y] = (char)204;
	CRacing::MapColor[m_X - 1][m_Y] =250;
	CRacing::MapChar[m_X - 1][m_Y + 1] = (char)223;
	CRacing::MapColor[m_X - 1][m_Y + 1] = 112;
	CRacing::MapChar[m_X - 1][m_Y - 1] = (char)222;
	CRacing::MapColor[m_X - 1][m_Y - 1] = 112;

	CRacing::MapChar[m_X + 1][m_Y + 1] = (char)223;
	CRacing::MapColor[m_X + 1][m_Y + 1] =112;
	CRacing::MapChar[m_X + 1][m_Y - 1] = (char)221;
	CRacing::MapColor[m_X + 1][m_Y - 1] = 112;
	CRacing::MapChar[m_X][m_Y+1]=(char)127;
	CRacing::MapColor[m_X][m_Y+1]=124;
}

void CF1::ShowCar()
{
	for (int i=-3;i<m_Health-3;i++)
	{
		CRacing::MapChar[m_X+i][m_Y+3]=(char)3;
		CRacing::MapColor[m_X+i][m_Y+3]=124;
	}
	for (int i=-3;i<m_Speed-3;i++)
	{
		CRacing::MapChar[m_X+i][m_Y+4]=(char)16;
		CRacing::MapColor[m_X+i][m_Y+4]=126;
	}
}

void CF1::StopShow()
{
	for (int i=-3;i<m_Health-3;i++)
	{
		CRacing::MapChar[m_X+i][m_Y+3]=' ';
		CRacing::MapColor[m_X+i][m_Y+3]=119;
	}
	for (int i=-3;i<m_Speed-3;i++)
	{
		CRacing::MapChar[m_X+i][m_Y+4]=' ';
		CRacing::MapColor[m_X+i][m_Y+4]=119;
	}
	for (int i=-1;i<2;i++)
	{
		for (int j=-1;j<2;j++)
		{
			CRacing::MapChar[m_X+i][m_Y+j]=' ';
			CRacing::MapColor[m_X+i][m_Y+j]=119;
		}
	}
}

CF1::CF1(void)
{
	m_Speed=10;
	m_Health=5;
	m_Score=0;
}


CF1::~CF1(void)
{
}
