#include <cstdlib>
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

#include "banner.h"
#include "win.h"

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

  while (true)
  {
    
    banner(game_win);

    banner_car(game_win, 7, carx++);

    wrefresh(game_win);

    usleep(30000);

    if (carx >= col - 15) carx = 2;
  }

  getchar();

  endwin();

  return 0;
}
