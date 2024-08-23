#include <ncurses.h>

int main()
{
    initscr();
    start_color();
    getch();

    endwin();
    return 0;
}
