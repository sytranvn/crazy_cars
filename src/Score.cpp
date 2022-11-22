#include "Score.h"
#include "Racing.h"

CScore::CScore(void)
{
}

void CScore::Input()
{
    getline(CRacing::f_read,Name,',');
    CRacing::f_read>>Score;
}

int CScore::RSc()
{
    return Score;
}
string CScore::RNn()
{
    return Name;
}
CScore::~CScore(void)
{
}
