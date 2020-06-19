#include <cstdlib>
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

#include "banner.h"
#include "win.h"

#define sleepms(x) usleep(x * 1000)

int main (int argc, char *args[])
{
  initscr();
  nodelay(stdscr,FALSE);

  int row, col;
	getmaxyx(stdscr, row, col);

  int cary = 7, carx = 2;

  noecho();

  timeout(300);

  WINDOW *game_win;
  game_win = create_newwin(row - 2, col, 0, 0);

  curs_set(0);

  while (carx < col - BANNER_CAR_WIDTH)
  {
    
    banner(game_win);

    banner_car(game_win, 7, carx++);

    wrefresh(game_win);

    sleepms(30);
  }

  // curs_set(1);

  getchar();

  endwin();

  return 0;
}
