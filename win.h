#ifndef CRAZY_CARS_WIN_H
#define CRAZY_CARS_WIN_H

#include "win.cpp"

WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);

#endif
