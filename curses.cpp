#include "stdio.h"
#include "ncurses.h"
#include "curses.hpp"
#include <iostream>

using namespace std;

int main() {
  initscr(); // Initialise ncurses mode
  noecho(); // Doesnt print out users input
  curs_set(0); // nvisible, normal, or very visible for visibility equal to 0, 1, or 2

  // Check for terminal colour compatibility and create colours

  if(!has_colors())
  {
    return -1;
  }

  start_color(); // Initialise ncurses colour mode
  init_pair(1, COLOR_WHITE, COLOR_BLUE);
  init_pair(2, COLOR_BLUE, COLOR_WHITE);

  // Window is half the size of the terminal and centered in the middle
  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);
  WINDOW *win = newwin(yMax/2, xMax/2, yMax/4, xMax/4);

  wbkgd(win, COLOR_PAIR(2));
  wbkgd(stdscr, COLOR_PAIR(1));
  refresh();

  MenuBar menubar;
  menubar.centralText(stdscr, "HORASHIO BANKING SYSTEM", 8);

  Menu menus[4]
  {
    Menu("1. Create new account", '1'),
    Menu("2. Log into existing account", '2'),
    Menu("3. Update information on existing account", '3'),
    Menu("4. Transfer money", '4'),
  };
  string hello = "hello";
  mvwprintw(win, 0, 0, hello.c_str());
  mvwprintw(win, 1, 0, hello.c_str());

  char ch;
  while(ch = wgetch(win))
  {
    
  }
  
  endwin(); // End ncurses mode
}
