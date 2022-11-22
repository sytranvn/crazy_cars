#include "Lambor.h"
#include "Racing.h"

void CLambor::DrawCar()
{
    
    CRacing::MapChar[m_X][m_Y] = (char)177;
    CRacing::MapColor[m_X][m_Y] = 14;
    CRacing::MapChar[m_X][m_Y-1]=(char)203;
    CRacing::MapColor[m_X][m_Y-1]=14;
    CRacing::MapChar[m_X + 1][m_Y] = (char)185;
    CRacing::MapColor[m_X + 1][m_Y] = 14;
    CRacing::MapChar[m_X - 1][m_Y] = (char)204;
    CRacing::MapColor[m_X - 1][m_Y] =14;
    CRacing::MapChar[m_X - 1][m_Y + 1] = (char)223;
    CRacing::MapColor[m_X - 1][m_Y + 1] = 116;
    CRacing::MapChar[m_X + 1][m_Y + 1] = (char)223;
    CRacing::MapColor[m_X + 1][m_Y + 1] =116;
    CRacing::MapChar[m_X - 1][m_Y - 1] = (char)222;
    CRacing::MapColor[m_X - 1][m_Y - 1] = 116;
    CRacing::MapChar[m_X + 1][m_Y - 1] = (char)221;
    CRacing::MapColor[m_X + 1][m_Y - 1] = 116;
    CRacing::MapChar[m_X][m_Y+1]=(char)127;
    CRacing::MapColor[m_X][m_Y+1]=124;
}



void CLambor::ShowCar()
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

void CLambor::StopShow()
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

CLambor::CLambor(void)
{
    m_Speed=8;
    m_Health=8;
    m_Score=0;
}

CLambor::~CLambor(void)
{
}
