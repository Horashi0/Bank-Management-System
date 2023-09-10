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

  // Window is half the size of the terminal and centered in the middle
  int yMax, xMax;

  getmaxyx(stdscr, yMax, xMax);

  WINDOW *win = newwin(yMax/2, xMax/2, yMax/4, xMax/4);
  box(win, 0, 0);

  string menu1[] = {"New", "Open", "Save", "Exit"};
  string menu2[] = {"Copy", "Cut", "Paste"};
  string menu3[] = {"Sidebar", "Terminal"};

  Menu menus[3] = 
  {
    Menu("File", 'f', menu1, 4),
    Menu("Edit", 'e', menu2, 3),
    Menu("Options", 'o', menu3, 2)
  };

  MenuBar menubar = MenuBar(win, menus, 3);
  menubar.draw();

  char ch;
  while (ch = wgetch(win))
  {
    menubar.handleTrigger(ch);
    menubar.draw();
  }
  endwin(); // End ncurses mode
}
