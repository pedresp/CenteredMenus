#include "CenteredMenu.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int centered_menu(char* title, const char** options, int options_size){
    //disable echo and cursor
    noecho();
    curs_set(FALSE);

    //method variables
    int option_selected = 0, menux = COLS/2, menuy = LINES/2, submenux = menux - 2, submenuy = menuy - 4;
    bool pressed_enter = false;
    ITEM** items;
    MENU* my_menu;
    WINDOW* menu_window, *menu_subwindow;
    //std::vector<char*> centered_cstrings;

    //items and menu creation
    items = (ITEM**)malloc(sizeof(ITEM*)*(options_size + 1));
    for (int i = 0; i < options_size; i++){
        //centered_cstrings.push_back(centered_string(submenux, options[i]));
        items[i] = new_item(options[i], "");
    }
    items[options_size] = (ITEM*)NULL;
    my_menu = new_menu((ITEM**)items);
    
    //mvprintw(LINES - 1, 0, "Prees ESC to Exit");

    //window creation
    menu_window = newwin(menuy, menux, menuy/2, menux/2);
    werase(menu_window);
    box(menu_window, 0, 0);
    keypad(menu_window, TRUE);
    menu_subwindow = derwin(menu_window, submenuy, submenux, 3, 1);

    //setting menu
    set_menu_win(my_menu, menu_window);
    set_menu_sub(my_menu, menu_subwindow);
    set_menu_format(my_menu, submenuy, 1);

    set_menu_mark(my_menu, "");
    mvwprintw(menu_window, 1, menux/2 - strlen(title)/2, "%s", title);

    post_menu(my_menu);
    refresh();

    // menu's main loop
    int c;
    while (!pressed_enter && (c = wgetch(menu_window)) != 27)
    {
        switch (c)
        {
        case KEY_DOWN:
            if (option_selected != options_size - 1)
                ++option_selected;
            menu_driver(my_menu, REQ_DOWN_ITEM);
            break;
        case KEY_UP:
            if (option_selected)
                --option_selected;
            menu_driver(my_menu, REQ_UP_ITEM);
            break;
        case 10:
            pressed_enter = true;
            break;            
        default:
            break;
        }
        wrefresh(menu_window);
    }
    
    //erase window content
    werase(menu_window);
    werase(menu_subwindow);
    wrefresh(menu_window);
    wrefresh(menu_subwindow);
    
    //free resources
    delwin(menu_window);
    unpost_menu(my_menu);
    free_menu(my_menu);

    for (int i = 0; i < options_size; i++){
        free_item(items[i]);
        //delete[] centered_cstrings[i];
    }

    free(items);

    return pressed_enter?option_selected:-1;
}
