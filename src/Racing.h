#pragma once
#include <vector>
#include <iostream>
// #include <Windows.h>
#include <fstream>
#include "Lambor.h"
#include "F1.h"
#include "Bugatti.h"
#include "Obstacle.h"
#include "Bonus.h"
#include "Score.h"
using namespace std;
const 	char Menu[15][55] ={"   $$$$$$   $$$$$$$      $$     $$$$$$$$   $      $   ",
					    	"  $      $  $      $    $  $          $     $    $    ",
					    	"  $         $      $   $    $        $       $  $     ",
						    "  $         $$$$$$$   $$$$$$$$     $          $$      ",
						    "  $      $  $     $   $      $   $            $       ",
							"   $$$$$$   $      $  $      $  $$$$$$$$$    $        ",
							"                                                      ",
							"          OOOOOOOOO OOOO  OOOOOOO         oooooooo    ",
							"        ooo    OO  OO  OO  OO    OO      oo   oo      ",
							"       ooo        OO    OO  OO     OO   oo   oo       ",
							"      oo         OO      OO  OO     OO    oo          ",
							"   oooOO         OOOOOOOOOOOO  OOOOOO        oo       ",
							"  OO       OOO  OOOOOOOOOOOOOO OOOOOOOO   oo   oo     ",
							"  OOOOOOOOOOO  OOO        OOOO OO     OO   ooooo      "};

class CRacing
{
public:
		CCar * cars[2];
		vector <CObstacle> ObsList;
		vector <CBonus> BonusList;
		vector <CScore> L_Scores;
public:
	static int m_Level;
	static char MapChar[55][35];
	static int MapColor[55][35];
	static ifstream f_read;
	static ofstream f_write;
	void LoadRecords();
	void BonusManage();
	void Maplvl1();
	void Maplvl2();
	void Maplvl3();
	void BonusWon();
	void ObsManage();
	void PrintRace();
	void ClearScreen();
	void SetControl1();
	void SetControl2();
	void PrintMenu();
	CRacing(void);
	~CRacing(void);
};

