#include "CenteredMenu.h"
#include <ncurses.h>

int main()
{
    initscr();
    start_color();

    std::vector<std::string> options = {"option A","option B","option C","option D","option E","option F","option G","option H","option I","option J","option K","option L"};
    int option_selected = cms::centered_menu("CENTERED MENU", options);

    mvprintw(LINES/2, COLS/2, "%d", option_selected);
    getch();

    endwin();
    return 0;
}
