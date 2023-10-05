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

  
  
  endwin(); // End ncurses mode
}
