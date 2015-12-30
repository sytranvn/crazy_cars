#include "Bugatti.h"
#include "Racing.h"

void CBugatti::DrawCar()
{
	CRacing::MapChar[m_X][m_Y] = (char)30;
	CRacing::MapColor[m_X][m_Y] = 207;
	CRacing::MapChar[m_X][m_Y-1]=(char)203;
	CRacing::MapColor[m_X][m_Y-1]=12;
	CRacing::MapChar[m_X + 1][m_Y] = (char)185;
	CRacing::MapColor[m_X + 1][m_Y] = 12;

	CRacing::MapChar[m_X - 1][m_Y] = (char)204;
	CRacing::MapColor[m_X - 1][m_Y] =12;
	CRacing::MapChar[m_X - 1][m_Y + 1] = (char)223;
	CRacing::MapColor[m_X - 1][m_Y + 1] = 121;
	CRacing::MapChar[m_X - 1][m_Y - 1] = (char)222;
	CRacing::MapColor[m_X - 1][m_Y - 1] = 121;

	CRacing::MapChar[m_X + 1][m_Y + 1] = (char)223;
	CRacing::MapColor[m_X + 1][m_Y + 1] =121;
	CRacing::MapChar[m_X + 1][m_Y - 1] = (char)221;
	CRacing::MapColor[m_X + 1][m_Y - 1] = 121;
	CRacing::MapChar[m_X][m_Y+1]=(char)127;
	CRacing::MapColor[m_X][m_Y+1]=126;
}


void CBugatti::ShowCar()
{
	for (int i=-3;i<m_Health-4;i++)
	{
		CRacing::MapChar[m_X+i][m_Y+3]=(char)3;
		CRacing::MapColor[m_X+i][m_Y+3]=124;
	}
	for (int i=-3;i<m_Speed-4;i++)
	{
		CRacing::MapChar[m_X+i][m_Y+4]=(char)16;
		CRacing::MapColor[m_X+i][m_Y+4]=126;
	}
}

void CBugatti::StopShow()
{
	for (int i=-4;i<m_Health-4;i++)
	{
		CRacing::MapChar[m_X+i][m_Y+3]=' ';
		CRacing::MapColor[m_X+i][m_Y+3]=119;
	}
	for (int i=-4;i<m_Speed-4;i++)
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

CBugatti::CBugatti(void)
{
	m_Speed=9;
	m_Health=6;
	m_Score=0;
}

CBugatti::~CBugatti(void)
{}