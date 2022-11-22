

#ifndef __CRAZY_CAR__NC_CONSOLE_H__
#define __CRAZY_CAR__NC_CONSOLE_H__

#include <ncurses.h>
#include <string>
class CNCursesConsole
{
  public:
    CNCursesConsole() {
       local_win = stdscr;
       startx = 0, starty = 0, height = 10, width = 10;
    };
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
    WINDOW *local_win;
    int startx, starty;
    int height, width;

};

#endif
