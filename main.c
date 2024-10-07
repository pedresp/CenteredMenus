#include "CenteredMenu.h"
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "en_US.UTF-8");

    initscr();
    start_color();

    char* oa = "option A";
    char* ob = "option B";
    char* oc = "option C";
    char* options[3];//,"option D","option E","option F","option G","option H","option I","option J","option K","option L"};

    options[0] = oa;
    options[1] = ob;
    options[2] = oc;

    int option_selected = centered_menu("CENTERED MENU", (const char**)options, 3);

    mvprintw(LINES/2, COLS/2, "%d", option_selected);
    getch();

    endwin();
    return 0;
}
