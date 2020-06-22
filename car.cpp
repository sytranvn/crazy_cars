#include <ncurses.h>
#include <string>

#include "win.h"

class Car {
  private:
    int x, y;
    std::string type;
    
  public:
    Car(int _x, int _y) : x(_x), y(_y) {}

    void print(WINDOW *game_win) {
        // mvwprintw(game_win, y,     x + 0, "O^^O" );
        // mvwprintw(game_win, y + 1, x + 1,  "||"  );
        // mvwprintw(game_win, y + 2, x + 1,  "||"  );
        // mvwprintw(game_win, y + 3, x + 0, "O==O" );
    }
};
