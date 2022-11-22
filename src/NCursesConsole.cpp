#include "NCursesConsole.h"

CNCursesConsole CNCursesConsole::CNursesConsole(int _height, int _width, int _starty, int _startx)
{
    local_win = stdscr;
    startx = _startx, starty = _starty, height = _height, width = _width;
    return *this;
}

void CNCursesConsole::Clear()
{
    wclear(local_win);
}

void CNCursesConsole::Refresh()
{
    wrefresh(local_win);
}
