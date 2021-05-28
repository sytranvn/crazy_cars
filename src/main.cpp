#include "Console.h"
#include "Racing.h"

int main() {
  CConsole *cc = new CConsole();
  CRacing race;
  CLambor lamb, lamb_2;
  CF1 f1, f1_2;
  CBugatti butti, butti_2;
  race.BonusManage();
  race.ObsManage();
  string nickname;
MainMenu:
  cc->clear();
  race.PrintMenu();
  while (1) {
    // if (cc->get_key(49))
    // 	goto Game1;
    // if (cc->get_key(50))
    // 	goto Game2;
    // if (cc->get_key(51))
    // 	goto HiScore;
    // if (cc->get_key(52))
    // 	goto Help;
    // if (cc->get_key(53))
    return 0;
  }
  int count;

// Game 1 player
Game1:
  count = 0;
  race.ClearScreen();
  race.Maplvl1();
  race.BonusList.resize(1);
  race.ObsList.resize(1);
  lamb.m_X = 13;
  lamb.m_Y = 15;
  f1.m_X = 25;
  f1.m_Y = 15;
  butti.m_X = 37;
  butti.m_Y = 15;
  f1.draw_car();
  butti.draw_car();
  lamb.draw_car();
  f1.ShowCar();
  butti.ShowCar();
  lamb.ShowCar();
  CRacing::MapChar[25][13] = (char)31;
  CRacing::MapColor[25][13] = 126;
  int type = 2;
  while (!cc->get_key(VK_SPACE)) {
    race.PrintRace();
    if (cc->get_key(VK_LEFT)) {
      if (type == 2) {
        CRacing::MapChar[25][13] = ' ';
        CRacing::MapColor[25][13] = 119;
        CRacing::MapChar[13][13] = (char)31;
        CRacing::MapColor[13][13] = 126;
        // f1.hide();
        // lamb.ShowCar();
        type = 1;
      }
      if (type == 3) {
        CRacing::MapChar[37][13] = ' ';
        CRacing::MapColor[37][13] = 119;
        CRacing::MapChar[25][13] = (char)31;
        CRacing::MapColor[25][13] = 126;
        // butti.hide();
        // f1.ShowCar();
        type = 2;
      }
    }
    if (cc->get_key(VK_RIGHT)) {
      if (type == 2) {
        CRacing::MapChar[25][13] = ' ';
        CRacing::MapColor[25][13] = 119;
        CRacing::MapChar[37][13] = (char)31;
        CRacing::MapColor[37][13] = 126;
        // f1.hide();
        // butti.ShowCar();
        type = 3;
      }
      if (type == 1) {
        CRacing::MapChar[13][13] = ' ';
        CRacing::MapColor[13][13] = 119;
        CRacing::MapChar[25][13] = (char)31;
        CRacing::MapColor[25][13] = 126;
        // lamb.hide();
        // f1.ShowCar();
        type = 2;
      }
    }
    cout << "Select a car and press SPACE to start!";
    race.ClearScreen();
  } // select car
  f1.hide();
  butti.hide();
  lamb.hide(); // select car
  cc->clear();
  if (type == 1)
    race.cars[1] = new CLambor;
  else if (type == 2)
    race.cars[1] = new CF1;
  else
    race.cars[1] = new CBugatti;
  race.SetControl2();
  race.cars[1]->m_X = 26;
  race.cars[1]->m_Y = 30;
  int baseHP = race.cars[1]->m_Health;
  while (race.cars[1]->m_Health >= 0) {
    race.ClearScreen();
    for (int j = 0; j < race.ObsList.size(); j++) {
      race.ObsList[j].DrawObs();
    }
    for (int i = 0; i < race.BonusList.size(); i++) {
      if (race.BonusList[i].m_Y < 34)
        race.BonusList[i].DrawS();
    }
    race.cars[1]->draw_car();
    race.PrintRace();
    cout << endl << "Health: ";
    for (int i = 0; i <= baseHP; i++)
      if (i < race.cars[1]->m_Health)
        cout << (char)3;
      else
        cout << ' ';
    cout << endl
         << "Score: " << race.cars[1]->m_Score << "\t\tLevel: " << race.m_Level;
    if (race.cars[1]->collect_score())
      race.BonusWon();
    race.cars[1]->move();
    if (race.cars[1]->impinge()) {
      race.cars[1]->m_Health--;
    }
    for (int j = 0; j < race.ObsList.size(); j++) {
      race.ObsList[j].EraseObs();
    }
    for (int i = 0; i < race.BonusList.size(); i++) {
      race.BonusList[i].EraseS();
    }

    count++;
    if (race.m_Level == 1 && count % 10 == 0 && race.ObsList.size() < 6) {
      race.ObsList.push_back(CObstacle());
    } else if (race.m_Level == 2 && count % 20 == 0 &&
               race.ObsList.size() < 9) {
      race.ObsList.push_back(CObstacle());
    } else if (race.m_Level == 3 && count % 50 == 0 &&
               race.ObsList.size() < 12) {
      race.ObsList.push_back(CObstacle());
    }
    if (count % 3 == 0 && race.BonusList.size() < 40)
      race.BonusList.push_back(CBonus());
    race.ObsManage();
    race.BonusManage();
    race.cars[1]->m_Score += race.cars[1]->m_Speed;
    if (count == 150) {
      race.m_Level += 1;
      if (race.m_Level % 3 == 2)
        race.Maplvl2();
      if (race.m_Level % 3 == 0)
        race.Maplvl3();
      if (race.m_Level % 3 == 1)
        race.Maplvl1();
      count = 0;
    }
  } // xe chay

  CRacing::f_write.open("records.txt", ios_base::app);
  cout << "\nYour nick name: ";
  getline(cin, nickname);
  CRacing::f_write << nickname << "," << race.cars[1]->m_Score << endl;
  CRacing::f_write.close();
  cout << endl << "Play again (Y/N)?";
  while (1) {
    if (cc->get_key(89)) {
      cc->clear();
      goto Game1;
    } else if (cc->get_key(78)) {
      cc->clear();
      goto MainMenu;
    }
  }

  // Game 2 player
Game2:
  count = 0;
  race.ClearScreen();
  race.Maplvl1();
  race.BonusList.resize(1);
  race.ObsList.resize(1);

  lamb.m_X = 13;
  lamb.m_Y = 9;
  f1.m_X = 25;
  f1.m_Y = 9;
  butti.m_X = 37;
  butti.m_Y = 9;

  lamb_2.m_X = 13;
  lamb_2.m_Y = 16;
  f1_2.m_X = 25;
  f1_2.m_Y = 16;
  butti_2.m_X = 37;
  butti_2.m_Y = 16;

  f1.draw_car();
  butti.draw_car();
  lamb.draw_car();
  f1.ShowCar();
  butti.ShowCar();
  lamb.ShowCar();

  f1_2.draw_car();
  butti_2.draw_car();
  lamb_2.draw_car();
  f1_2.ShowCar();
  butti_2.ShowCar();
  lamb_2.ShowCar();

  CRacing::MapChar[25][7] = (char)31;
  CRacing::MapColor[25][7] = 126;
  CRacing::MapChar[25][14] = (char)31;
  CRacing::MapColor[25][14] = 124;

  int type1 = 2;
  int type2 = 2;
  bool spaced = false;
  bool entered = false;
  while (!spaced || !entered) {
    race.PrintRace();
    if (cc->get_key(13))
      entered = true;
    if (cc->get_key(32))
      spaced = true;
    if (cc->get_key(VK_LEFT)) {
      if (type2 == 2) {
        CRacing::MapChar[25][14] = ' ';
        CRacing::MapColor[25][14] = 119;
        CRacing::MapChar[13][14] = (char)31;
        CRacing::MapColor[13][14] = 126;
        // f1.hide();
        // lamb.ShowCar();
        type2 = 1;
      }
      if (type2 == 3) {
        CRacing::MapChar[37][14] = ' ';
        CRacing::MapColor[37][14] = 119;
        CRacing::MapChar[25][14] = (char)31;
        CRacing::MapColor[25][14] = 126;
        // butti.hide();
        // f1.ShowCar();
        type2 = 2;
      }
    }
    if (cc->get_key(VK_RIGHT)) {
      if (type2 == 2) {
        CRacing::MapChar[25][14] = ' ';
        CRacing::MapColor[25][14] = 119;
        CRacing::MapChar[37][14] = (char)31;
        CRacing::MapColor[37][14] = 126;
        // f1.hide();
        // butti.ShowCar();
        type2 = 3;
      }
      if (type2 == 1) {
        CRacing::MapChar[13][14] = ' ';
        CRacing::MapColor[13][14] = 119;
        CRacing::MapChar[25][14] = (char)31;
        CRacing::MapColor[25][14] = 126;
        // lamb.hide();
        // f1.ShowCar();
        type2 = 2;
      }
    }
    if (cc->get_key(65)) {
      if (type1 == 2) {
        CRacing::MapChar[25][7] = ' ';
        CRacing::MapColor[25][7] = 119;
        CRacing::MapChar[13][7] = (char)31;
        CRacing::MapColor[13][7] = 124;
        // f1.hide();
        // lamb.ShowCar();
        type1 = 1;
      }
      if (type1 == 3) {
        CRacing::MapChar[37][7] = ' ';
        CRacing::MapColor[37][7] = 119;
        CRacing::MapChar[25][7] = (char)31;
        CRacing::MapColor[25][7] = 124;
        // butti.hide();
        // f1.ShowCar();
        type1 = 2;
      }
    }
    if (cc->get_key(68)) {
      if (type1 == 2) {
        CRacing::MapChar[25][7] = ' ';
        CRacing::MapColor[25][7] = 119;
        CRacing::MapChar[37][7] = (char)31;
        CRacing::MapColor[37][7] = 124;
        // f1.hide();
        // butti.ShowCar();
        type1 = 3;
      }
      if (type1 == 1) {
        CRacing::MapChar[13][7] = ' ';
        CRacing::MapColor[13][7] = 119;
        CRacing::MapChar[25][7] = (char)31;
        CRacing::MapColor[25][7] = 124;
        // lamb.hide();
        // f1.ShowCar();
        type1 = 2;
      }
    }
    cout << "Select cars and press SPACE/ENTER to start!";
    race.ClearScreen();
  }
  f1.hide();
  f1_2.hide();
  butti.hide();
  butti_2.hide();
  lamb.hide();
  lamb_2.hide();
  cc->clear();
  if (type1 == 1) {
    race.cars[0] = new CLambor;
  } else if (type1 == 2) {
    race.cars[0] = new CF1;
  } else
    race.cars[0] = new CBugatti;
  if (type2 == 1) {
    race.cars[1] = new CLambor;
  } else if (type2 == 2) {
    race.cars[1] = new CF1;
  } else
    race.cars[1] = new CBugatti;

  int baseHP1 = race.cars[0]->m_Health;
  int baseHP2 = race.cars[1]->m_Health;

  race.SetControl1();
  race.SetControl2();

  race.cars[0]->m_X = 14;
  race.cars[0]->m_Y = 30;
  race.cars[1]->m_X = 39;
  race.cars[1]->m_Y = 30;

  while (race.cars[0]->m_Health >= 0 && race.cars[1]->m_Health >= 0) {
    race.ClearScreen();
    for (int j = 0; j < race.ObsList.size(); j++) {
      race.ObsList[j].DrawObs();
    }
    race.cars[0]->draw_car();
    race.cars[1]->draw_car();
    race.PrintRace();
    race.cars[0]->move();
    race.cars[1]->move();
    if (race.cars[0]->impinge()) {
      race.cars[0]->m_Health--;
    }
    if (race.cars[1]->impinge()) {
      race.cars[1]->m_Health--;
    }
    cout << "Health: ";
    for (int i = 0; i <= baseHP1; i++)
      if (i < race.cars[0]->m_Health)
        cout << (char)3;
      else
        cout << ' ';
    cout << "\t\t\t";
    for (int i = baseHP2; i >= 0; i--)
      if (i > race.cars[1]->m_Health)
        cout << ' ';
      else
        cout << (char)3;
    for (int j = 0; j < race.ObsList.size(); j++) {
      race.ObsList[j].EraseObs();
    }
    count++;
    if (race.m_Level == 1 && count % 10 == 0 && race.ObsList.size() < 6) {
      race.ObsList.push_back(CObstacle());
    } else if (race.m_Level == 2 && count % 20 == 0 &&
               race.ObsList.size() < 9) {
      race.ObsList.push_back(CObstacle());
    } else if (race.m_Level == 3 && count % 50 == 0 &&
               race.ObsList.size() < 12) {
      race.ObsList.push_back(CObstacle());
    }
    race.ObsManage();
    if (count == 150) {
      race.m_Level += 1;
      if (race.m_Level % 3 == 2)
        race.Maplvl2();
      if (race.m_Level % 3 == 0)
        race.Maplvl3();
      if (race.m_Level % 3 == 1)
        race.Maplvl1();
      count = 0;
    }
  }
  cout << endl;
  if (race.cars[0]->m_Health > race.cars[1]->m_Health)
    cout << "Player 1 win!!!";
  else
    cout << "Player 2 win!!!";
  cout << endl << "Play again (Y/N)?";
  while (1) {
    if (cc->get_key(89)) {
      cc->clear();
      goto Game2;
    } else if (cc->get_key(78)) {
      cc->clear();
      goto MainMenu;
    }
  }

HiScore:
  cc->clear();
  CRacing::f_read.open("records.txt");
  race.LoadRecords();
  CRacing::f_read.close();
  cout << endl << endl << "Back [SPACE]...";
  while (1) {
    if (cc->get_key(VK_SPACE))
      break;
  }
  goto MainMenu;

// Help
Help:

  cc->clear();
  // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
  cout << "HELP" << endl;
  // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
  cout << "Single mode: use " << (char)27 << (char)24 << (char)26 << (char)25
       << " keys to move car, collect $ amap\nand avoid obstracles.";
  cout << endl
       << "PvP mode : P1 uses AWDS keys, P2 uses " << (char)27 << (char)24
       << (char)26 << (char)25 << "keys. The\nsurvivor will win.";
  // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
  cout << endl << "Back [SPACE]...";
  while (1) {
    if (cc->get_key(VK_SPACE))
      break;
  }
  goto MainMenu;
  return 0;
}