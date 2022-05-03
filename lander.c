#include "lander.h"

/**currently the game physics are locked to 1 second**/

#define DELAY 500000

void lander()
{
    float x = 0, y = 4; /* starting position of ship */
    float max_y = 0, max_x = 0;
    float next_y = 0;
    float next_x = 0;
    float vertical = 0.1;
    float horizontal = 4.5;

    int timer = 0;

    initscr();
    noecho();
    curs_set(FALSE);

    // Global var `stdscr` is created by the call to `initscr()`
    getmaxyx(stdscr, max_y, max_x);

    // initscr();
    // curs_set(0);

    // do
    while (1)
    {
        clear();
        mvprintw(1, 0, "COUNTER  %d", *&timer);
        mvprintw(0, 0, "SCORE  0000");
        mvprintw(2, 0, "FUEL  1000");
        mvprintw(y, x, " /\\");
        mvprintw(y + 1, x, " **");

        /* Hard coded test terrain */
        // 1
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
        //

        // 2
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
        //

        // 3

        mvprintw(29, 34, "/");
        mvprintw(28, 35, "/");
        mvprintw(27, 36, "/");
        mvprintw(26, 37, "/");

        mvprintw(26, 38, "\\");
        mvprintw(27, 39, "\\");
        mvprintw(28, 40, "\\");
        mvprintw(29, 41, "\\");
        //

        // 4

        mvprintw(29, 42, "/");
        mvprintw(28, 43, "/");
        mvprintw(27, 44, "/");
        mvprintw(26, 45, "/");
        mvprintw(25, 46, "/");
        mvprintw(24, 47, "/");
        mvprintw(23, 48, "/");

        mvprintw(23, 49, "\\");
        mvprintw(24, 50, "\\");
        mvprintw(25, 51, "\\");
        mvprintw(26, 52, "\\");
        mvprintw(27, 53, "\\");
        mvprintw(28, 54, "\\");
        mvprintw(29, 55, "\\");

        /* end of terrain */

        refresh();

        // usleep(DELAY);

        next_x = x + horizontal;
        next_y = y + horizontal;

        /* TODO: implement collsion detection with border*/
        // direction *= -1;
        // direction_y *= -1;

        y += vertical * (timer) / 2;
        x += horizontal / 3;

        float xSpeed = (x / timer) * 5;
        float ySpeed = (y * timer) / 10;

        mvprintw(0, 30, "HORIZONTAL SPEED  %f", *&xSpeed);
        mvprintw(1, 30, "VERTICAL SPEED  %f", *&ySpeed);
        refresh();
        usleep(DELAY);
        timer++;

        // napms(SECOND); /* 1 second delay */
    } // while (timer > 0);

    endwin(); /* close window */
}