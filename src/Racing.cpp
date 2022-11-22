#include "Racing.h"

char CRacing::MapChar[55][35];
int CRacing::MapColor[55][35];
int CRacing::m_Level;
ifstream CRacing::f_read;
ofstream CRacing::f_write;

CRacing::CRacing(void)
{
    m_Level=1;
    ObsList.resize(1);
    BonusList.resize(1);
}

void CRacing::ObsManage()
{
    for (int i=0;i<ObsList.size();i++)
    {
        if (ObsList[i].m_Y>34)
        {
            bool check;
            ObsList[i].m_Y=0;
            do
            {
                check=false;
                ObsList[i].m_X=rand()%30+11;
                for (int j=0;j<ObsList.size();j++)
                {
                    if (i!=j&&abs(ObsList[i].m_X-ObsList[j].m_X)+abs(ObsList[i].m_Y-ObsList[j].m_Y)<4)
                    {
                        check=false;
                        break;
                    }
                    else if (abs(ObsList[i].m_X-ObsList[j].m_X)==2&&abs(ObsList[i].m_Y-ObsList[j].m_Y)==2)
                    {
                        check=false;
                        break;
                    }
                    check=true;
                }
            } while (check==false);
        }
    }
}

void CRacing::BonusWon()
{
    for (int i=0; i< BonusList.size(); i++)
    {
        if (MapChar[BonusList[i].m_X-1][BonusList[i].m_Y-1]==(char)203||MapChar[BonusList[i].m_X+1][BonusList[i].m_Y-1]==(char)203||MapChar[BonusList[i].m_X][BonusList[i].m_Y-1]==(char)203)
        {
            MapChar[BonusList[i].m_X][BonusList[i].m_Y]=' ';
            BonusList[i].m_Y=35;
        }
    }
}

void CRacing::BonusManage()
{
    for (int i=0;i<BonusList.size();i++)
    {
        if (BonusList[i].m_Y>70)
        {
            BonusList[i].m_Y=0;
            do 
            {
                BonusList[i].m_X=rand()%30+11;
            } while(MapChar[BonusList[i].m_X][BonusList[i].m_Y]!=' ');
        }
    }
}

void CRacing::Maplvl1()
{
    for (int i=0; i<6;i++)
    {    
        for (int j=0;j<35;j++)
        {
            MapChar[i][j]=(char)176;
            MapColor[i][j]=74;
        }
    } 
    for (int i=45; i<55;i++)
    {    
        for (int j=0;j<35;j++)
        {
            MapChar[i][j]=(char)176;
            MapColor[i][j]=74;
        }
    } 
    for (int j=0;j<35;j++)
    {
        MapChar[7][j]=(char)174;
        MapChar[8][j]=(char)175;
        MapColor[7][j]=128;
        MapColor[8][j]=128;
        MapChar[42][j]=(char)174;
        MapChar[43][j]=(char)175;
        MapColor[42][j]=128;
        MapColor[43][j]=128;
        MapChar[6][j]='#';
        MapColor[6][j]=79;
        MapChar[44][j]='#';
        MapColor[44][j]=79;
    }
    for (int i=9;i<42;i++)
    {
        for (int j=0;j<35;j++)
        {
            MapChar[i][j]=' ';
            MapColor[i][j]=112;
        }                              
    }
    
}

void CRacing::Maplvl2()
{
    for (int i=0;i<6;i++)
    {
        for (int j=0;j<35;j++)
        {
            MapColor[i][j]=159;
        }
    }
    for (int i=45;i<55;i++ )
    {
        for (int j=0;j<35;j++)
        {
            MapColor[i][j]=159;
        }
    }
    for (int j=0;j<35;j++)
    {
            MapColor[6][j]=252;
            MapChar[6][j]='X';
            MapColor[44][j]=252;
            MapChar[44][j]='X';
    }
}

void CRacing::Maplvl3()
{
    for (int i=0;i<6;i++)
    {
        for (int j=0;j<35;j++)
        {
            if (j%6<3||i==0||i==5)
            {
                MapChar[i][j]=(char)219;
                if (j%6==0||i==0||i==5)
                {
                    MapColor[i][j]=119;
                }
                else MapColor[i][j]=127;
            }
            else
            {
                MapColor[i][j]=227;
                if (j%6==3)
                {
                    if (i==1) MapChar[i][j]=(char)201;
                    else if (i==4) MapChar[i][j]=187;
                    else MapChar[i][j]=203;
                }
                else if (j%6==4)
                {
                    if (i==1) MapChar[i][j]=(char)204;
                    else if (i==4) MapChar[i][j]=185;
                    else MapChar[i][j]=206;
                }
                else
                {
                    if (i==1) MapChar[i][j]=(char)211;
                    else if (i==4) MapChar[i][j]=189;
                    else MapChar[i][j]=208;
                }
            }

        }
    }
    for (int i=45;i<55;i++)
    {
        for (int j=0;j<35;j++)
        {
            if (j%6<3||i==45||i==54)
            {
                MapChar[i][j]=(char)219;
                if (j%6==0||i==45||i==54)
                {
                    MapColor[i][j]=119;
                }
                else MapColor[i][j]=127;
            }
            else
            {
                MapColor[i][j]=227;
                if (j%6==3)
                {
                    if (i==46) MapChar[i][j]=(char)201;
                    else if (i==53) MapChar[i][j]=187;
                    else MapChar[i][j]=203;
                }
                else if (j%6==4)
                {
                    if (i==46) MapChar[i][j]=(char)204;
                    else if (i==53) MapChar[i][j]=185;
                    else MapChar[i][j]=206;
                }
                else
                {
                    if (i==46) MapChar[i][j]=(char)211;
                    else if (i==53) MapChar[i][j]=189;
                    else MapChar[i][j]=208;
                }
            }

        }
    }
    for (int j=0;j<35;j++)
    {
        MapColor[6][j]=170;
        MapColor[44][j]=170;
        if (j%5==0)
        {
            MapChar[6][j]=(char)4;
            MapChar[44][j]=(char)4;
        }
        else
        {
            MapChar[6][j]=(char)177;
            MapChar[44][j]=(char)177;    
        }
    }
}

void CRacing::SetControl1()
{
    car1->m_Down=83;
    car1->m_Left=65;
    car1->m_Right=68;
    car1->m_Up=87;
    car1->m_Score=0;
}
void CRacing::SetControl2()
{
    car2->m_Down=40;
    car2->m_Left=37;
    car2->m_Right=39;
    car2->m_Up=38;
    car2->m_Score=0;
}
void CRacing::PrintRace()
{
    for (int i=2; i<34; i++)
    {
        for (int j=0;j<55;j++)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),MapColor[j][i]);
            cout<<MapChar[j][i];
        }
        cout<<endl;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}

void CRacing::ClearScreen()
{
    HANDLE hOut;
    COORD Position;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}

void CRacing::PrintMenu()
{
    cout<<endl<<endl;
    for (int i=0;i<15;i++)
    {
        for (int j=0;j<55;j++)
        {
            if (Menu[i][j]=='$')
            {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
                cout<<Menu[i][j];
            }
            else if (Menu[i][j]=='O')
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
                cout<<(char)174;
            }
            else if (Menu[i][j]=='o')
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
                cout<<(char)123;
            }
            else cout<<' ';
        }
        cout<<endl;
    }
    cout<<"\n\n\n\t1. New game 1 player\t2. New game 2 players\n\t3. High scores\t\t4. Help\n\t5. Exit";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
}
CRacing::~CRacing(void)
{
}

void CRacing::LoadRecords()
{
    CScore scccc;
    vector <int> tint(5,0);
    while (!f_read.eof())
    {
        scccc.Input();
        L_Scores.push_back(scccc);
        for (int j=0;j<5;j++)
        {
            if (L_Scores[L_Scores.size()-1].RSc()>L_Scores[tint[j]].RSc())
            {
                tint.pop_back();
                tint.insert(tint.begin()+j,L_Scores.size()-1);
                break;
            }
        }
    }
    cout<<"Top 5:"<<endl;
    for (int i=0;i<5;i++)
    {
        cout<<i+1<<"."<<L_Scores[tint[i]].RNn()<<"   "<<L_Scores[tint[i]].RSc()<<endl<<endl;
    }
}
