#include "Racing.h"
#using <mscorlib.dll>
using namespace System;
int main()
{
	Console::SetWindowSize(55,40);
	Console::Title= "Crazy Cars by Tran Dung Sy & Nguyen The Anh";
	CRacing race;
	CLambor lamb,lamb2;
	CF1 f1,f12;
   	CBugatti buti,buti2;
	race.BonusManage();
	race.ObsManage();
	string nickname;
MainMenu:
	Console::Clear();
	race.PrintMenu();
	while (1)
	{
		if (GetAsyncKeyState(49))
			goto Game1;
		if (GetAsyncKeyState(50))
			goto Game2;
		if (GetAsyncKeyState(51))
			goto HiScore;
		if (GetAsyncKeyState(52))
			goto Help;
		if (GetAsyncKeyState(53))
			return 0;
	}	
	int count;

//Game 1 player
Game1:
	count=0;
	race.ClearScreen();
	race.Maplvl1();
	race.BonusList.resize(1);
	race.ObsList.resize(1);
	lamb.m_X=13; lamb.m_Y=15;
	f1.m_X=25; f1.m_Y=15;
	buti.m_X=37; buti.m_Y=15;
	f1.DrawCar();  buti.DrawCar(); lamb.DrawCar();
	f1.ShowCar();  buti.ShowCar(); lamb.ShowCar();
	CRacing::MapChar[25][13]=(char)31;
	CRacing::MapColor[25][13]=126;
	int type=2;
	while (!GetAsyncKeyState(VK_SPACE))
	{	race.PrintRace();
		if (GetAsyncKeyState(VK_LEFT))
		{
			if (type==2)
			{
				CRacing::MapChar[25][13]=' ';
				CRacing::MapColor[25][13]=119;
				CRacing::MapChar[13][13]=(char)31;
				CRacing::MapColor[13][13]=126;
				//f1.StopShow();
				//lamb.ShowCar();
				type=1;
			}
			if (type==3)
			{
				CRacing::MapChar[37][13]=' ';
				CRacing::MapColor[37][13]=119;
				CRacing::MapChar[25][13]=(char)31;
				CRacing::MapColor[25][13]=126;
				//buti.StopShow();
				//f1.ShowCar();
				type=2;
			}
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			if (type==2)
			{
				CRacing::MapChar[25][13]=' ';
				CRacing::MapColor[25][13]=119;
				CRacing::MapChar[37][13]=(char)31;
				CRacing::MapColor[37][13]=126;
				//f1.StopShow();
				//buti.ShowCar();
				type=3;
			}
			if (type==1)
			{
				CRacing::MapChar[13][13]=' ';
				CRacing::MapColor[13][13]=119;
				CRacing::MapChar[25][13]=(char)31;
				CRacing::MapColor[25][13]=126;
				//lamb.StopShow();
				//f1.ShowCar();
				type=2;
			}
		}
		cout<<"Select a car and press SPACE to start!";
		race.ClearScreen();
	}		//select car
	f1.StopShow(); buti.StopShow(); lamb.StopShow();	// select car
	Console::Clear();
	if (type==1)
		race.car2=new CLambor;
	else if (type==2)
		race.car2=new CF1;
	else race.car2=new CBugatti;
	race.SetControl2();
	race.car2->m_X=26;
	race.car2->m_Y=30;
	int baseHP=race.car2->m_Health;
	while  (race.car2->m_Health>=0)
	{
		race.ClearScreen();
		for (int j=0;j<race.ObsList.size();j++)
		{
			race.ObsList[j].DrawObs();
		}
		for (int i=0;i<race.BonusList.size();i++)
		{
			if (race.BonusList[i].m_Y<34)
				race.BonusList[i].DrawS();
		}
		race.car2->DrawCar();
		race.PrintRace();
		cout<<endl<<"Health: "; for (int i=0;i<=baseHP;i++) if (i<race.car2->m_Health) cout<<(char)3; else cout<<' ';
		cout<<endl<<"Score: "<<race.car2->m_Score<<"\t\tLevel: "<<race.m_Level;
		if (race.car2->CollectScore())
			race.BonusWon();
		race.car2->Move();
		if (race.car2->Impinge())
		{
			race.car2->m_Health--;
			Beep(500,75);
		}
		for (int j=0;j<race.ObsList.size();j++)
		{
			race.ObsList[j].EraseObs();
		}
		for (int i=0;i<race.BonusList.size();i++)
		{
			race.BonusList[i].EraseS();
		}

		count++;  
		if (race.m_Level==1&&count%10==0&&race.ObsList.size()<6)
		{
			race.ObsList.push_back(CObstacle());
		}
		else if (race.m_Level==2&&count%20==0&&race.ObsList.size()<9)
		{
			race.ObsList.push_back(CObstacle());
		}
		else if (race.m_Level==3&&count%50==0&&race.ObsList.size()<12)
		{
			race.ObsList.push_back(CObstacle());
		}
		if (count%3==0&&race.BonusList.size()<40) race.BonusList.push_back(CBonus());
		race.ObsManage();
		race.BonusManage();
		race.car2->m_Score+=race.car2->m_Speed;
		if (count==150)
		{
			race.m_Level+=1;
			if (race.m_Level%3==2)
				race.Maplvl2();
			if (race.m_Level%3==0)
				race.Maplvl3();
			if (race.m_Level%3==1)
				race.Maplvl1();
			count=0;
		}		
	}	 //xe chay
	Sleep(3000);
	CRacing::f_write.open("records.txt",ios_base::app);
	cout<<"\nYour nick name: ";
	getline(cin,nickname);
	CRacing::f_write<<nickname<<","<<race.car2->m_Score<<endl;
	CRacing::f_write.close();
	cout<<endl<<"Play again (Y/N)?";
	while (1)
	{
		if (GetAsyncKeyState(89))
		{
			Console::Clear();
			goto Game1;
		}
		else if (GetAsyncKeyState(78))
		{	
			Console::Clear();
			goto MainMenu;
		}
	}

 //Game 2 player
Game2:
	count=0;
	race.ClearScreen();
	race.Maplvl1();
	race.BonusList.resize(1);
	race.ObsList.resize(1);

	lamb.m_X=13; lamb.m_Y=9;
	f1.m_X=25; f1.m_Y=9;
	buti.m_X=37; buti.m_Y=9;

	lamb2.m_X=13; lamb2.m_Y=16;
	f12.m_X=25; f12.m_Y=16;
	buti2.m_X=37; buti2.m_Y=16;

	f1.DrawCar();  buti.DrawCar(); lamb.DrawCar();
	f1.ShowCar();  buti.ShowCar(); lamb.ShowCar();

	f12.DrawCar();  buti2.DrawCar(); lamb2.DrawCar();
	f12.ShowCar();  buti2.ShowCar(); lamb2.ShowCar();

	CRacing::MapChar[25][7]=(char)31;
	CRacing::MapColor[25][7]=126;
	CRacing::MapChar[25][14]=(char)31;
	CRacing::MapColor[25][14]=124;

	int type1=2;	 int type2=2;
	bool spaced=false; bool entered=false;
	while (!spaced||!entered)
	{
		race.PrintRace();
		if (GetAsyncKeyState(13))
			entered=true;
		if (GetAsyncKeyState(32))
			spaced=true;
		if (GetAsyncKeyState(VK_LEFT))
		{
			if (type2==2)
			{
				CRacing::MapChar[25][14]=' ';
				CRacing::MapColor[25][14]=119;
				CRacing::MapChar[13][14]=(char)31;
				CRacing::MapColor[13][14]=126;
				//f1.StopShow();
				//lamb.ShowCar();
				type2=1;
			}
			if (type2==3)
			{
				CRacing::MapChar[37][14]=' ';
				CRacing::MapColor[37][14]=119;
				CRacing::MapChar[25][14]=(char)31;
				CRacing::MapColor[25][14]=126;
				//buti.StopShow();
				//f1.ShowCar();
				type2=2;
			}
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			if (type2==2)
			{
				CRacing::MapChar[25][14]=' ';
				CRacing::MapColor[25][14]=119;
				CRacing::MapChar[37][14]=(char)31;
				CRacing::MapColor[37][14]=126;
				//f1.StopShow();
				//buti.ShowCar();
				type2=3;
			}
			if (type2==1)
			{
				CRacing::MapChar[13][14]=' ';
				CRacing::MapColor[13][14]=119;
				CRacing::MapChar[25][14]=(char)31;
				CRacing::MapColor[25][14]=126;
				//lamb.StopShow();
				//f1.ShowCar();
				type2=2;
			}
		}
		if (GetAsyncKeyState(65))
		{
			if (type1==2)
			{
				CRacing::MapChar[25][7]=' ';
				CRacing::MapColor[25][7]=119;
				CRacing::MapChar[13][7]=(char)31;
				CRacing::MapColor[13][7]=124;
				//f1.StopShow();
				//lamb.ShowCar();
				type1=1;
			}
			if (type1==3)
			{
				CRacing::MapChar[37][7]=' ';
				CRacing::MapColor[37][7]=119;
				CRacing::MapChar[25][7]=(char)31;
				CRacing::MapColor[25][7]=124;
				//buti.StopShow();
				//f1.ShowCar();
				type1=2;
			}
		}
		if (GetAsyncKeyState(68))
		{
			if (type1==2)
			{
				CRacing::MapChar[25][7]=' ';
				CRacing::MapColor[25][7]=119;
				CRacing::MapChar[37][7]=(char)31;
				CRacing::MapColor[37][7]=124;
				//f1.StopShow();
				//buti.ShowCar();
				type1=3;
			}
			if (type1==1)
			{
				CRacing::MapChar[13][7]=' ';
				CRacing::MapColor[13][7]=119;
				CRacing::MapChar[25][7]=(char)31;
				CRacing::MapColor[25][7]=124;
				//lamb.StopShow();
				//f1.ShowCar();
				type1=2;
			}
		}
		cout<<"Select cars and press SPACE/ENTER to start!";
		race.ClearScreen();
	}
	f1.StopShow(); f12.StopShow(); buti.StopShow(); buti2.StopShow(); lamb.StopShow(); lamb2.StopShow();
	Console::Clear();
	if (type1==1)
	{
		race.car1 = new CLambor;
	}
	else if (type1==2)
	{
		race.car1 = new CF1;
	}
	else race.car1 = new CBugatti;
	if (type2==1)
	{
		race.car2 = new CLambor;
	}
	else if (type2==2)
	{
		race.car2 = new CF1;
	}
	else race.car2 = new CBugatti;

	int baseHP1=race.car1->m_Health;
	int baseHP2=race.car2->m_Health;

	race.SetControl1();
	race.SetControl2();

	race.car1->m_X=14;
	race.car1->m_Y=30;
	race.car2->m_X=39;
	race.car2->m_Y=30;

	while (race.car1->m_Health>=0&&race.car2->m_Health>=0)
	{
		race.ClearScreen();
		for (int j=0;j<race.ObsList.size();j++)
		{
			race.ObsList[j].DrawObs();
		}
		race.car1->DrawCar();
		race.car2->DrawCar();
		race.PrintRace();
		race.car1->Move();
		race.car2->Move();
		if (race.car1->Impinge())
		{
			race.car1->m_Health--;
			Beep(700,75);
		}
		if (race.car2->Impinge())
		{
			race.car2->m_Health--;
			Beep(500,75);
		}
		cout<<"Health: ";
		for (int i=0;i<=baseHP1;i++) if (i<race.car1->m_Health) cout<<(char)3; else cout<<' ';
		cout<<"\t\t\t";
		for (int i=baseHP2;i>=0;i--) if (i>race.car2->m_Health) cout<<' '; else cout<<(char)3;
		for (int j=0;j<race.ObsList.size();j++)
		{
			race.ObsList[j].EraseObs();
		}
		count++;  
		if (race.m_Level==1&&count%10==0&&race.ObsList.size()<6)
		{
			race.ObsList.push_back(CObstacle());
		}
		else if (race.m_Level==2&&count%20==0&&race.ObsList.size()<9)
		{
			race.ObsList.push_back(CObstacle());
		}
		else if (race.m_Level==3&&count%50==0&&race.ObsList.size()<12)
		{
			race.ObsList.push_back(CObstacle());
		}
		race.ObsManage();
		if (count==150)
		{
			race.m_Level+=1;
			if (race.m_Level%3==2)
				race.Maplvl2();
			if (race.m_Level%3==0)
				race.Maplvl3();
			if (race.m_Level%3==1)
				race.Maplvl1();
			count=0;
		}
	}
	cout<<endl;
	if (race.car1->m_Health>race.car2->m_Health)
		cout<<"Player 1 win!!!"; else cout<<"Player 2 win!!!"; cout<<endl<<"Play again (Y/N)?";
	while (1)
	{
		if (GetAsyncKeyState(89))
		{
			Console::Clear();
			goto Game2;
		}
		else if (GetAsyncKeyState(78))
		{	
			Console::Clear();
			goto MainMenu;
		}
	}

HiScore:
	Console::Clear();
	CRacing::f_read.open("records.txt");
	race.LoadRecords();
	CRacing::f_read.close();
	cout<<endl<<endl<<"Back [SPACE]...";
	while (1)
	{
		if (GetAsyncKeyState(VK_SPACE))
			break;
	}
	goto MainMenu;

//Help
Help:

	Console::Clear();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	cout<<"HELP"<<endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	cout<<"Single mode: use "<<(char)27<<(char)24<<(char)26<<(char)25<<" keys to move car, collect $ amap\nand avoid obstracles.";
	cout<<endl<<"PvP mode : P1 uses AWDS keys, P2 uses "<<(char)27<<(char)24<<(char)26<<(char)25<<"keys. The\nsurvivor will win.";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	cout<<endl<<"Back [SPACE]..."; 
	while (1)
	{
		if (GetAsyncKeyState(VK_SPACE))
			break;
	}
	goto MainMenu;
	return 0;
}