#include "Car.h"
#include "Racing.h"

void CCar::move(WINDOW *win)
{
    int k = wgetch(win);
    if (k == m_key_left)
    {
        if (CRacing::MapChar[m_X - 2][m_Y] != (char)175 && CRacing::MapChar[m_X - 2][m_Y] != (char)185 && CRacing::MapChar[m_X - 2][m_Y - 1] != (char)112 && CRacing::MapChar[m_X - 2][m_Y + 1] != (char)221 && CRacing::MapChar[m_X - 2][m_Y] != (char)112 && CRacing::MapChar[m_X - 2][m_Y] != (char)221 && CRacing::MapChar[m_X - 2][m_Y] != (char)185 && CRacing::MapChar[m_X - 2][m_Y + 1] != (char)185 && CRacing::MapChar[m_X - 2][m_Y - 1] != (char)185 && CRacing::MapChar[m_X - 2][m_Y - 1] != (char)223)
        {
            CRacing::MapChar[m_X + 1][m_Y - 1] = ' ';
            CRacing::MapColor[m_X + 1][m_Y] = 112;
            CRacing::MapChar[m_X + 1][m_Y] = ' ';
            CRacing::MapColor[m_X + 1][m_Y] = 112;
            CRacing::MapChar[m_X + 1][m_Y + 1] = ' ';
            CRacing::MapColor[m_X + 1][m_Y + 1] = 112;
            m_X--;
        }
        return;
    }
    if (k == m_key_right)
    {
        if (CRacing::MapChar[m_X + 2][m_Y] != (char)174 && CRacing::MapChar[m_X + 2][m_Y] != (char)204 && CRacing::MapChar[m_X + 2][m_Y] != (char)223 && CRacing::MapChar[m_X + 2][m_Y] != (char)222 && CRacing::MapChar[m_X + 2][m_Y + 1] != (char)222 && CRacing::MapChar[m_X + 2][m_Y + 1] != (char)204 && CRacing::MapChar[m_X + 2][m_Y - 1] != (char)223 && CRacing::MapChar[m_X + 2][m_Y - 1] != (char)204)
        {
            CRacing::MapChar[m_X - 1][m_Y - 1] = ' ';
            CRacing::MapColor[m_X - 1][m_Y] = 112;
            CRacing::MapChar[m_X - 1][m_Y] = ' ';
            CRacing::MapColor[m_X - 1][m_Y] = 112;
            CRacing::MapChar[m_X - 1][m_Y + 1] = ' ';
            CRacing::MapColor[m_X - 1][m_Y + 1] = 112;
            m_X++;
        }
        return;
    }
    if (k == m_key_up)
    {
        if (m_Y > 4 && CRacing::MapChar[m_X][m_Y - 2] != (char)223 && CRacing::MapChar[m_X][m_Y - 2] != (char)127 && CRacing::MapChar[m_X - 1][m_Y - 2] != (char)223 && CRacing::MapChar[m_X + 1][m_Y - 2] != (char)223)
        {
            CRacing::MapChar[m_X - 1][m_Y + 1] = ' ';
            CRacing::MapColor[m_X - 1][m_Y + 1] = 112;
            CRacing::MapChar[m_X][m_Y + 1] = ' ';
            CRacing::MapColor[m_X][m_Y + 1] = 112;
            CRacing::MapChar[m_X + 1][m_Y + 1] = ' ';
            CRacing::MapColor[m_X + 1][m_Y + 1] = 112;
            m_Y--;
        }
        return;
    }
    if (k == m_key_down)
    {
        if (m_Y < 32 && CRacing::MapChar[m_X][m_Y + 2] != (char)203 && CRacing::MapChar[m_X][m_Y + 2] != (char)222 && CRacing::MapChar[m_X][m_Y + 2] != (char)221 && CRacing::MapChar[m_X - 1][m_Y + 2] != (char)203 && CRacing::MapChar[m_X - 1][m_Y + 2] != (char)221 && CRacing::MapChar[m_X + 1][m_Y + 2] != (char)203 && CRacing::MapChar[m_X + 1][m_Y + 2] != (char)222)
        {
            CRacing::MapChar[m_X - 1][m_Y - 1] = ' ';
            CRacing::MapColor[m_X - 1][m_Y - 1] = 112;
            CRacing::MapChar[m_X][m_Y - 1] = ' ';
            CRacing::MapColor[m_X][m_Y - 1] = 112;
            CRacing::MapChar[m_X + 1][m_Y - 1] = ' ';
            CRacing::MapColor[m_X + 1][m_Y - 1] = 112;
            m_Y++;
        }
        return;
    }
}

bool CCar::impinge()
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

bool CCar::collect_score()
{
    if (CRacing::MapChar[m_X-1][m_Y-2]=='$'||CRacing::MapChar[m_X][m_Y-2]=='$'||CRacing::MapChar[m_X+1][m_Y-2]=='$')
    {
        m_Score+=100;
        return true;
    }
    return false;
}

void CCar::fire()
{

}

void CCar::show()
{
    this->hidden = false;
}

void CCar::hide()
{
    this->hidden = true;
}

CCar::CCar(void)
{
}


CCar::~CCar(void)
{
}
