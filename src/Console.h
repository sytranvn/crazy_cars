#include <iostream>
#include <string>

#ifndef __CRAZY_CAR__CONSOLE_H__

#define __CRAZY_CAR__CONSOLE_H__

#define VK_SPACE 1
#define VK_LEFT 2
#define VK_RIGHT 3
class CConsole
{
public:
  CConsole(void);

  virtual void set_title(std::string title);
  virtual void set_window_size(std::size_t row, std::size_t col);
  virtual void clear();
  virtual void refresh();
  virtual void write(std::string, std::size_t row, std::size_t col);
  virtual void close();
  virtual bool get_key(std::size_t key);

  protected:
    int n_row;
    int n_col;
};

#endif