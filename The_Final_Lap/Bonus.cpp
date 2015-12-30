#include "Bonus.h"
#include "Racing.h"
CBonus::CBonus(void)
{
	m_X=rand()%30+11;
	m_Y=0;
}

void CBonus::DrawS()
{
	CRacing::MapChar[m_X][m_Y]='$';
	CRacing::MapColor[m_X][m_Y]=126;
}

void CBonus::EraseS()
{
	if (m_Y<34)
	{
		CRacing::MapChar[m_X][m_Y]=' ';
		CRacing::MapColor[m_X][m_Y]=112;
	}
	m_Y++;
}
CBonus::~CBonus(void)
{
}