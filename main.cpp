#include "CenteredMenu.h"
#include <ncurses.h>

int main()
{
    initscr();
    start_color();

    std::vector<std::string> options = {"option A","option B","option C","option D","option E","option F"};
    cms::centered_menu("CENTERED MENU", options);

    endwin();
    return 0;
}
