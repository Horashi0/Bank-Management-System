#include "ncurses.h"
#include <string>

using namespace std;

#ifndef __MENU_H_
#define __MENU_H_

class Menu
{
    public:
        Menu(string text, char trigger)
        {
            this->text = text;
            this->trigger = trigger;
        }

        string text;
        char trigger;     
};

class MenuBar
{
    public:
        MenuBar(WINDOW *win, Menu *menus, int numMenus)
        {
            this->win = win;
            this->menus = menus
        }








        void centralText(WINDOW *win, string text, int startRowDivider)
        {
            int startRow = win->_maxy / startRowDivider;
            int centerCol = win->_maxx / 2;
            int halfLength = text.length() / 2;
            int centralised = centerCol - halfLength;
            
            mvwprintw(win, startRow, centralised, text.c_str());
        }

        void draw(Menu menu, bool isSelected)
        {

        }

        void handleTrigger(char trigger, int numMenus)
        {
            for(int i = 0; i < numMenus; i++)
            {
                if(trigger == this->menus[i].trigger)
                {
                    
                }
            }
        }
};

#endif