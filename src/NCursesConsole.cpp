#include "NCursesConsole.h"
void init_win_params(WIN *p_win);
CNCursesConsole CNCursesConsole::CNursesConsole(int height, int width, int starty,
                                                int startx)
{
  local_win = newwin(height, width, starty, startx);
  keypad(stdscr, TRUE);
  start_color();
  box(local_win, 0 , 0);		/* 0, 0 gives default characters
        * for the vertical and horizontal
        * lines			*/

  noecho();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);

  init_win_params(local_win, win);

  return *this;
}

void CNCursesConsole::Clear()
{
  this->local_win->clear()
}

void init_win_params(WIN *p_win)
{
	p_win->height = 3;
	p_win->width = 10;
	p_win->starty = (LINES - p_win->height)/2;
	p_win->startx = (COLS - p_win->width)/2;

	p_win->border.ls = '|';
	p_win->border.rs = '|';
	p_win->border.ts = '-';
	p_win->border.bs = '-';
	p_win->border.tl = '+';
	p_win->border.tr = '+';
	p_win->border.bl = '+';
	p_win->border.br = '+';

}

void init_win_params(WIN *p_win)
{
	p_win->height = 3;
	p_win->width = 10;
	p_win->starty = (LINES - p_win->height)/2;
	p_win->startx = (COLS - p_win->width)/2;

	p_win->border.ls = '|';
	p_win->border.rs = '|';
	p_win->border.ts = '-';
	p_win->border.bs = '-';
	p_win->border.tl = '+';
	p_win->border.tr = '+';
	p_win->border.bl = '+';
	p_win->border.br = '+';

}