#include "Car.h"
#include "Racing.h"
void CCar::DrawCar()
{
}


void CCar::Move()
{
	if (GetAsyncKeyState(m_Left))
	{
		if (CRacing::MapChar[m_X-2][m_Y]!=(char)175&&CRacing::MapChar[m_X-2][m_Y]!=(char)185&&CRacing::MapChar[m_X-2][m_Y-1]!=(char)112&&CRacing::MapChar[m_X-2][m_Y+1]!=(char)221&&CRacing::MapChar[m_X-2][m_Y]!=(char)112&&CRacing::MapChar[m_X-2][m_Y]!=(char)221&&CRacing::MapChar[m_X-2][m_Y]!=(char)185&&CRacing::MapChar[m_X-2][m_Y+1]!=(char)185&&CRacing::MapChar[m_X-2][m_Y-1]!=(char)185&&CRacing::MapChar[m_X-2][m_Y-1]!=(char)223)
		{
			CRacing::MapChar[m_X+1][m_Y-1]=' ';
			CRacing::MapColor[m_X+1][m_Y]=112;
			CRacing::MapChar[m_X+1][m_Y]=' ';
			CRacing::MapColor[m_X+1][m_Y]=112;
			CRacing::MapChar[m_X+1][m_Y+1]=' ';
			CRacing::MapColor[m_X+1][m_Y+1]=112;
			m_X--;
		}
	}
	if (GetAsyncKeyState(m_Right))
	{
		if (CRacing::MapChar[m_X+2][m_Y]!=(char)174&&CRacing::MapChar[m_X+2][m_Y]!=(char)204&&CRacing::MapChar[m_X+2][m_Y]!=(char)223&&CRacing::MapChar[m_X+2][m_Y]!=(char)222&&CRacing::MapChar[m_X+2][m_Y+1]!=(char)222&&CRacing::MapChar[m_X+2][m_Y+1]!=(char)204&&CRacing::MapChar[m_X+2][m_Y-1]!=(char)223&&CRacing::MapChar[m_X+2][m_Y-1]!=(char)204)
		{
			CRacing::MapChar[m_X-1][m_Y-1]=' ';
			CRacing::MapColor[m_X-1][m_Y]=112;
			CRacing::MapChar[m_X-1][m_Y]=' ';
			CRacing::MapColor[m_X-1][m_Y]=112;
			CRacing::MapChar[m_X-1][m_Y+1]=' ';
			CRacing::MapColor[m_X-1][m_Y+1]=112;
			m_X++;
		}
	}
	if (GetAsyncKeyState(m_Up))
	{
		if (m_Y>4&&CRacing::MapChar[m_X][m_Y-2]!=(char)223&&CRacing::MapChar[m_X][m_Y-2]!=(char)127&&CRacing::MapChar[m_X-1][m_Y-2]!=(char)223&&CRacing::MapChar[m_X+1][m_Y-2]!=(char)223)
		{
			CRacing::MapChar[m_X-1][m_Y+1]=' ';
			CRacing::MapColor[m_X-1][m_Y+1]=112;
			CRacing::MapChar[m_X][m_Y+1]=' ';
			CRacing::MapColor[m_X][m_Y+1]=112;
			CRacing::MapChar[m_X+1][m_Y+1]=' ';
			CRacing::MapColor[m_X+1][m_Y+1]=112;
			m_Y--;
		}
	}
	if (GetAsyncKeyState(m_Down))
	{
		if (m_Y<32&&CRacing::MapChar[m_X][m_Y+2]!=(char)203&&CRacing::MapChar[m_X][m_Y+2]!=(char)222&&CRacing::MapChar[m_X][m_Y+2]!=(char)221&&CRacing::MapChar[m_X-1][m_Y+2]!=(char)203&&CRacing::MapChar[m_X-1][m_Y+2]!=(char)221&&CRacing::MapChar[m_X+1][m_Y+2]!=(char)203&&CRacing::MapChar[m_X+1][m_Y+2]!=(char)222)
		{
			CRacing::MapChar[m_X-1][m_Y-1]=' ';
			CRacing::MapColor[m_X-1][m_Y-1]=112;
			CRacing::MapChar[m_X][m_Y-1]=' ';
			CRacing::MapColor[m_X][m_Y-1]=112;
			CRacing::MapChar[m_X+1][m_Y-1]=' ';
			CRacing::MapColor[m_X+1][m_Y-1]=112;
			m_Y++;
		}
	}
}


bool CCar::Impinge()
{
	for (int i=m_X-2;i<=m_X+2;i++)
	{
		for (int j=m_Y-2;j<m_Y-1;j++)
		{
			if (CRacing::MapChar[i][j]==(char)177)
				return true;
		}
	}
	return false;
}

bool CCar::CollectScore()
{
	if (CRacing::MapChar[m_X-1][m_Y-2]=='$'||CRacing::MapChar[m_X][m_Y-2]=='$'||CRacing::MapChar[m_X+1][m_Y-2]=='$')
	{
		m_Score+=100;
		return true;
	}
	return false;
}

void CCar::Fire()
{
	
}
CCar::CCar(void)
{
}


CCar::~CCar(void)
{
}
