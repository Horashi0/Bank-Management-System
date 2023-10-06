#include <stdio.h>
#include <string.h>
#include <ncurses/ncurses.h>

void printCentered(WINDOW *win, char* text);
void logoWinCreation();

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

   logoWinCreation();
}

void logoWinCreation()
{
    uint16_t stdscrRows, stdscrColumns;
    getmaxyx(stdscr, stdscrRows, stdscrColumns);

    WINDOW* logoWin = newwin(stdscrRows/6, stdscrColumns/2, stdscrRows/10, stdscrColumns/4);
    wbkgd(logoWin, COLOR_PAIR(1));

    uint16_t logoWinRows, logoWinColumns;
    getmaxyx(logoWin, logoWinRows, logoWinColumns);

    char title[30] = "Horashio Banking Sytem - HBS";

    printCentered(logoWin, title);

    int ch = wgetch(logoWin);
    while(ch)
    {

    }
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