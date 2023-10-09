#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <ncurses.h>

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

  logoWinCreation(stdscrRows, stdscrColumns);
  
  menuWinCreation(stdscrRows, stdscrColumns);
}

void menuWinCreation(uint16_t stdscrRows, uint16_t stdscrColumns)
{
  WINDOW* menuWin1 = newwin(stdscrRows/7, stdscrColumns/1.5, stdscrRows/2, (stdscrColumns/6));
  wbkgd(menuWin1, COLOR_PAIR(1));
  int ch = wgetch(menuWin1);
  while(ch)
  {

  }
}

void logoWinCreation(uint16_t stdscrRows, uint16_t stdscrColumns)
{
  WINDOW* logoWin = newwin(stdscrRows/6, stdscrColumns/2, stdscrRows/10, stdscrColumns/4);
  wbkgd(logoWin, COLOR_PAIR(1));

  uint16_t logoWinRows, logoWinColumns;
  getmaxyx(logoWin, logoWinRows, logoWinColumns);

  char title[30] = "Horashio Banking Sytem - HBS";

  printCentered(logoWin, title);

  //int ch = wgetch(logoWin);
  //while(ch)
  //{
  
  //}
}

void printCentered(WINDOW *win, char* text)
{
  uint16_t winRows, winColumns;
  getmaxyx(win, winRows, winColumns);

  uint16_t length = strlen(text);

  uint16_t centerColumn = winColumns / 2;
  uint16_t centerRow = winRows / 2;
  uint16_t halfLength = length / 2;
  uint16_t adjustedColumn = centerColumn - halfLength;

  mvwprintw(win, centerRow, adjustedColumn, text);   
}
