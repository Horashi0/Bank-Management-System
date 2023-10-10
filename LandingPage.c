#include <curses.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include <wchar.h>

void printCentered(WINDOW *win, char* text);
void logoWinCreation(uint16_t stdscrRows, uint16_t stdscrColumns);
void menuWinCreation(uint16_t stdscrRows, uint16_t stdscrColumns);

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

void menuWinCreation(uint16_t stdscrRows, uint16_t stdscrColumns)
{
  double defaultMenuSizeRow, defaultMenuSizeColumn, defaultMenuPositionColumn;
  double rowWidth, columnLength, positionValue;

  defaultMenuSizeRow = 16;
  defaultMenuSizeColumn = 1.5;
  defaultMenuPositionColumn = defaultMenuSizeColumn * 0.125;

  rowWidth = stdscrRows/defaultMenuSizeRow;
  columnLength = stdscrColumns/defaultMenuSizeColumn;
  positionValue = stdscrColumns*defaultMenuPositionColumn;

  WINDOW* menuWin1 = newwin(rowWidth, columnLength, stdscrRows*0.4, positionValue);
  WINDOW* menuWin2 = newwin(rowWidth, columnLength, stdscrRows*0.5, positionValue);
  WINDOW* menuWin3 = newwin(rowWidth, columnLength, stdscrRows*0.6, positionValue);
  WINDOW* menuWin4 = newwin(rowWidth, columnLength, stdscrRows*0.7, positionValue);

  wbkgd(menuWin1, COLOR_PAIR(1));
  wbkgd(menuWin2, COLOR_PAIR(1));
  wbkgd(menuWin3, COLOR_PAIR(1));
  wbkgd(menuWin4, COLOR_PAIR(1));

  wrefresh(menuWin1);
  wrefresh(menuWin2);
  wrefresh(menuWin3);
  wrefresh(menuWin4);

  int ch = wgetch(menuWin4);
  while(ch)
  {

  }
}

void logoWinCreation(uint16_t stdscrRows, uint16_t stdscrColumns)
{
  char title[30] = "Horashio Banking System - HBS";
  
  WINDOW* logoWin = newwin(stdscrRows/12, stdscrColumns/2, stdscrRows*0.1, stdscrColumns/4);
  wbkgd(logoWin, COLOR_PAIR(1));

  printCentered(logoWin, title);
  wrefresh(logoWin);
}

void printCentered(WINDOW *win, char* text)
{
  uint16_t winRows, winColumns;
  uint16_t length, centerColumn, centerRow, halfLength, adjustedColumn;
  
  getmaxyx(win, winRows, winColumns);

  length = strlen(text);

  centerColumn = winColumns / 2;
  centerRow = winRows / 2;
  halfLength = length / 2;
  adjustedColumn = centerColumn - halfLength;

  mvwprintw(win, centerRow, adjustedColumn, text);   
}
