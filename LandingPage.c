#include <curses.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <wchar.h>

void printCentered(WINDOW *win, const char* text);
void logoWinCreation(uint16_t stdscrRows, uint16_t stdscrColumns);
void menuWinCreation(uint16_t screenHeight, uint16_t screenWidth);

int main()
{
  initscr();
  cbreak();
  noecho();

  // Colour section
  if(!has_colors())
  {
      puts("Sorry, your machine isnt supported on this program.");
      endwin();
  }
  start_color();

  // Pair 1, Foreground white, Background blue
  init_pair(1, COLOR_WHITE, COLOR_BLUE);
  
  uint16_t stdscrRows, stdscrColumns;
  getmaxyx(stdscr, stdscrRows, stdscrColumns);

  // Calling window creation functions
  logoWinCreation(stdscrRows, stdscrColumns);
  menuWinCreation(stdscrRows, stdscrColumns);
}

void menuWinCreation(uint16_t screenHeight, uint16_t screenWidth)
{
  double height, width, x, menuHeight, menuWidth, menuX;

  height = 0.0625; // 1/16th in decimal
  width = 0.7;
  x = width/2;

  menuHeight = screenHeight*height;
  menuWidth = screenWidth*width;
  menuX = screenWidth*x;
  menuX = (screenWidth - menuWidth) / 2;

  WINDOW* menuWin1 = newwin(menuHeight, menuWidth, screenHeight*0.4, menuX);
  WINDOW* menuWin2 = newwin(menuHeight, menuWidth, screenHeight*0.5, menuX);
  WINDOW* menuWin3 = newwin(menuHeight, menuWidth, screenHeight*0.6, menuX);
  WINDOW* menuWin4 = newwin(menuHeight, menuWidth, screenHeight*0.7, menuX);

  wbkgd(menuWin1, COLOR_PAIR(1));
  wbkgd(menuWin2, COLOR_PAIR(1));
  wbkgd(menuWin3, COLOR_PAIR(1));
  wbkgd(menuWin4, COLOR_PAIR(1));

  const char* const menuTitles[] = {
    "1. Create new account",
    "2. Log into existing account",
    "3. Update information on existing",
    "4. Transfer money",
  };

  printCentered(menuWin1, menuTitles[0]);
  wrefresh(menuWin1);

  printCentered(menuWin2, menuTitles[1]);
  wrefresh(menuWin2);

  printCentered(menuWin3, menuTitles[2]);
  wrefresh(menuWin3);

  printCentered(menuWin4, menuTitles[3]);
  wrefresh(menuWin4);
  
  int ch = wgetch(menuWin4);
  while(ch)
  {

  }
}

void logoWinCreation(uint16_t stdscrRows, uint16_t stdscrColumns)
{
  const char* title = "Horashio Banking System - HBS";
  
  WINDOW* logoWin = newwin(stdscrRows/12, stdscrColumns/2, stdscrRows*0.1, stdscrColumns/4);
  wbkgd(logoWin, COLOR_PAIR(1));

  printCentered(logoWin, title);
  wrefresh(logoWin);
}

void printCentered(WINDOW *win, const char* text)
{
  uint16_t winRows, winColumns;
  uint16_t length, centerColumn, centerRow, halfLength, adjustedColumn;
  
  getmaxyx(win, winRows, winColumns);

  length = strlen(text);

  centerColumn = winColumns / 2;
  centerRow = winRows / 2;
  halfLength = length / 2;
  if(halfLength % 2 != 0)
  {
    halfLength++;
  }
  adjustedColumn = centerColumn - halfLength;

  mvwprintw(win, centerRow, adjustedColumn, text);   
}
