#include "CenteredMenu.h"
#include <algorithm>

int cms::centered_menu(std::string title, std::vector<std::string> options){
    //method variables
    int option_selected = 0, menux = COLS/2, menuy = LINES/2;
    ITEM** items;
    MENU* my_menu;
    WINDOW* menu_window;

    //items creation
    items = new ITEM*[options.size() + 1];
    for (int i = 0; i < (int)options.size(); i++){
        items[i] = new_item(options[i].c_str(), "");
    }
    items[options.size()] = (ITEM*)NULL;
    my_menu = new_menu((ITEM**)items);
    
    mvprintw(LINES - 1, 0, "Prees ESC to Exit");

    //window creation
    menu_window = newwin(menuy, menux, menuy/2, menux/2);
    keypad(menu_window, TRUE);

    set_menu_win(my_menu, menu_window);
    set_menu_sub(my_menu, derwin(menu_window, menuy - 3, menux - 1, 3, 1));

    set_menu_mark(my_menu, "");
    mvwprintw(menu_window, 1, menux/2, "MY MENU");

    post_menu(my_menu);
    refresh();

    int c;
    while ((c = wgetch(menu_window)) != 27)
    {
        switch (c)
        {
        case KEY_DOWN:
            menu_driver(my_menu, REQ_DOWN_ITEM);
            break;
        case KEY_UP:
            menu_driver(my_menu, REQ_UP_ITEM);
            break;
        default:
            break;
        }
        wrefresh(menu_window);
    }
    
    delwin(menu_window);
    unpost_menu(my_menu);
    free_menu(my_menu);

    for (int i = 0; i < (int)options.size(); i++)
        free_item(items[i]);

    delete[] items;

    return option_selected;
}
