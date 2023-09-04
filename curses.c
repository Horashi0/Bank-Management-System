#include "stdio.h"
#include "ncurses.h"
int main() {
  initscr(); // Initialise NCURSES mode
  noecho(); // Doesnt print out users input
  curs_set(0); // nvisible, normal, or very visible for visibility equal to 0, 1, or 2

  // Window is half the size of the terminal and centered in the middle
  int yMax, xMax;
  getmaxyx(stdscr, yMax, xMax);

  WINDOW *win = newwin(yMax/2, xMax/2, yMax/4, xMax/4);
  box(win, 0, 0);

  mvwprintw(win, 0, 2, "File");
  mvwprintw(win, 0, 7, "Edit");
  mvwprintw(win, 0, 12, "Options");

  char ch;
  while (ch = wgetch(win))
  {
    switch(ch)
    {
      case 'f':
      wattron(win, A_STANDOUT);
        mvwprintw(win, 0, 2, "File");
      wattroff(win, A_STANDOUT);
        mvwprintw(win, 0, 7, "Edit");
        mvwprintw(win, 0, 12, "Options");
        break;
      case 'e':
        wattron(win, A_STANDOUT);
        mvwprintw(win, 0, 7, "Edit");
        wattroff(win, A_STANDOUT);
        mvwprintw(win, 0, 2, "File");
        mvwprintw(win, 0, 12, "Options");
        break;
      case 'o':
        wattron(win, A_STANDOUT);
        mvwprintw(win, 0, 12, "Options");
        wattroff(win, A_STANDOUT);
          mvwprintw(win, 0, 2, "File");
          mvwprintw(win, 0, 7, "Edit");
        break;
      default:
      mvwprintw(win, 0, 2, "File");
      mvwprintw(win, 0, 7, "Edit");
      mvwprintw(win, 0, 12, "Options");
        break;
    }
  }
  endwin(); // End ncurses mode
}
