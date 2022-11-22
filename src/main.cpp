#include "NCursesConsole.h"
#include "Racing.h"

int main() {
  CNCursesConsole *cc = new CNCursesConsole();
MainMenu:
  cc->Clear();
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
  int type = 2;
  // while (!cc->get_key(VK_SPACE)) {
  //   race.PrintRace();
  //   if (cc->get_key(VK_LEFT)) {
  //     if (type == 2) {
  //       CRacing::MapChar[25][13] = ' ';
  //       CRacing::MapColor[25][13] = 119;
  //       CRacing::MapChar[13][13] = (char)31;
  //       CRacing::MapColor[13][13] = 126;
  //       // f1.hide();
  //       // lamb.ShowCar();
  //       type = 1;
  //     }
  //     if (type == 3) {
  //       CRacing::MapChar[37][13] = ' ';
  //       CRacing::MapColor[37][13] = 119;
  //       CRacing::MapChar[25][13] = (char)31;
  //       CRacing::MapColor[25][13] = 126;
  //       // butti.hide();
  //       // f1.ShowCar();
  //       type = 2;
  //     }
  //   }
  //   if (cc->get_key(VK_RIGHT)) {
  //     if (type == 2) {
  //       CRacing::MapChar[25][13] = ' ';
  //       CRacing::MapColor[25][13] = 119;
  //       CRacing::MapChar[37][13] = (char)31;
  //       CRacing::MapColor[37][13] = 126;
  //       // f1.hide();
  //       // butti.ShowCar();
  //       type = 3;
  //     }
  //     if (type == 1) {
  //       CRacing::MapChar[13][13] = ' ';
  //       CRacing::MapColor[13][13] = 119;
  //       CRacing::MapChar[25][13] = (char)31;
  //       CRacing::MapColor[25][13] = 126;
  //       // lamb.hide();
  //       // f1.ShowCar();
  //       type = 2;
  //     }
  //   }
  //   cout << "Select a car and press SPACE to start!";
  //   race.ClearScreen();
  // } // select car
  cc->Clear();
  return 0;
}
