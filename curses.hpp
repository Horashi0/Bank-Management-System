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

        int start_x;
        string text;
        char trigger;

};

class MenuBar 
{
    public:
        MenuBar(WINDOW *win, Menu* menus, int num_menus)
        {
            this->win = win;
            this->menus = menus;
            this->num_menus = num_menus; 
            this->selected_menu = -1;
            int current_pos = 2;

            for(int i = 0; i < num_menus; i++)
            {
                this->menus[i].start_x = current_pos;
                current_pos += this->menus[i].text.length() + 1;
            }
        }

        void draw()
        {
            for(int i = 0; i < num_menus; i++)
            {
                int start_x = this->menus[i].start_x;
                string text = this->menus[i].text;
                if(selected_menu == i)
                {
                    wattron(win, A_STANDOUT);
                   
                }
                mvwprintw(win, 0, start_x, text.c_str());
                wattroff(win, A_STANDOUT);
                
            }
        }

        void handleTrigger(char trigger)
        {
            for(int i = 0; i < num_menus; i++)
            {
                if(trigger == this->menus[i].trigger)
                {
                    selected_menu = i;
                }
            }
            
        }







        WINDOW * win;
        Menu * menus;
        int num_menus;
        int selected_menu;
};

#endif