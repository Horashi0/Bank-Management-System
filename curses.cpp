#include "stdio.h"
#include "ncurses.h"
#include "curses.hpp"

using namespace std;

int main() {
  initscr(); // Initialise NCURSES mode
  noecho(); // Doesnt print out users input
  curs_set(0); // nvisible, normal, or very visible for visibility equal to 0, 1, or 2

  // Window is half the size of the terminal and centered in the middle
  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);

  WINDOW *win = newwin(yMax/2, xMax/2, yMax/4, xMax/4);
  box(win, 0, 0);

  Menu menus[3] = {
    Menu("File", 'f'),
    Menu("Edit", 'e'),
    Menu("Options", 'o'),
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
