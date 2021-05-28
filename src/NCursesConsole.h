
#include <ncurses.h>

#ifndef __CRAZY_CAR__NC_CONSOLE_H__
#define __CRAZY_CAR__NC_CONSOLE_H__

#include "Console.h"



typedef struct _win_border_struct {
	chtype 	ls, rs, ts, bs,
	 	tl, tr, bl, br;
} WIN_BORDER;

typedef struct _WIN_struct {

	int startx, starty;
	int height, width;
	WIN_BORDER border;
} WIN;

class CNCursesConsole : public CConsole
{
  public:
    CNCursesConsole CNursesConsole(int height, int width, int starty, int startx);
    void Clear();
    void SetTitle(std::string title);
    void SetWindowSize(std::size_t row, std::size_t col);
    void Refresh();
    void Write(std::string, std::size_t row, std::size_t col);
    void Close();

    ~CNCursesConsole();
  private:
    int ch;
    WIN *local_win;
};

inline void init_win_params(WIN *p_win)
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

#endif