#include "lander.h"

/**currently the game physics are locked to 1 second**/

void lander()
{
    float x = 0, y = 4;
    float max_y = 0, max_x = 0;
    float next_y = 0;
    float next_x = 0;
    float horizontal = 4;
    float vertical = 1;
    int timer = 0;

    initscr();
    noecho();
    curs_set(FALSE);

    // Global var `stdscr` is created by the call to `initscr()`
    getmaxyx(stdscr, max_y, max_x);

    // initscr();
    // curs_set(0);

    do
    {
        clear();
        mvprintw(1, 0, "TIME  %d", *&timer);
        mvprintw(0, 0, "SCORE  0000");
        mvprintw(2, 0, "FUEL  0000");
        mvprintw(y, x, " /\\");
        mvprintw(y + 1, x, " **");

        /* Hard coded test terrain */
        mvprintw(21, 11, "/");
        mvprintw(22, 10, "/");
        mvprintw(23, 9, "/");
        mvprintw(24, 8, "/");
        mvprintw(25, 7, "/");
        mvprintw(26, 6, "/");
        mvprintw(27, 5, "/");
        mvprintw(28, 4, "/");
        mvprintw(29, 3, "/");

        mvprintw(21, 12, "\\");
        mvprintw(22, 13, "\\");
        mvprintw(23, 14, "\\");
        mvprintw(24, 15, "\\");
        mvprintw(25, 16, "\\");
        mvprintw(26, 17, "\\");
        mvprintw(27, 18, "\\");
        mvprintw(28, 19, "\\");
        mvprintw(29, 20, "\\");

        mvprintw(25, 25, "/2X");
        mvprintw(26, 24, "/");
        mvprintw(27, 23, "/");
        mvprintw(28, 22, "/");
        mvprintw(29, 21, "/");

        mvprintw(24, 26, "___");
        mvprintw(25, 28, " \\");
        mvprintw(26, 29, " \\");
        mvprintw(27, 30, " \\");
        mvprintw(28, 31, " \\");
        mvprintw(29, 32, " \\");
        /* end of terrain */

        refresh();

        // usleep(DELAY);

        next_x = x + horizontal;
        next_y = y + horizontal;

        /* TODO: implement collsion detection with border*/
        // direction *= -1;
        // direction_y *= -1;

        y += vertical;
        x += horizontal;
        refresh();
        timer++;
        napms(SECOND); /* 1 second delay */
    } while (timer > 0);

    endwin(); /* close window */
}