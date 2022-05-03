#include "lander.h"

/**currently the game physics are locked to 1 second**/

#define DELAY 500000

void terrainGen();

int lander()
{
    float x = 0, y = 4; /* starting position of ship */
    float max_y = 0, max_x = 0;
    float next_y = 0;
    float next_x = 0;

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

        terrainGen();

        // usleep(DELAY);

        // next_x = x + horizontal;
        // next_y = y + horizontal;

        /* TODO: implement collsion detection with border*/
        // direction *= -1;
        // direction_y *= -1;

        /* convert float to int for display */
        int x_int = (int)START_XSPEED - (timer) / 2.5;
        int y_int = (int)y - 4; /* -4 because the ship starts at x(4) */

        x += x_int;
        y += START_YSPEED * (timer) / 2;

        // float xSpeed = (STARTSPEED-x);
        // float ySpeed = (y * timer);

        mvprintw(0, 30, "HORIZONTAL SPEED  %d", *&x_int);
        mvprintw(1, 30, "VERTICAL SPEED  %d", *&y_int);

        // if()

        refresh();
        usleep(DELAY);
        timer++;

        // napms(SECOND); /* 1 second delay */
    } // while (timer > 0);

    endwin(); /* close window */
}

void terrainGen()
{
    /* mountain #1 */
    for (terrainY = 21, terrainX = 11; terrainY<30, terrainX> 2;)
    {
        mvprintw(terrainY, terrainX, "/");
        terrainY++;
        terrainX--;
    }
    for (terrainY = 21, terrainX = 12; terrainY > 30, terrainX < 21;)
    {
        mvprintw(terrainY, terrainX, "\\");
        terrainY++;
        terrainX++;
    }

    /* mountain #2 */
    for (terrainY = 26, terrainX = 24; terrainY<30, terrainX> 20;)
    {
        mvprintw(25, 25, "/2X");
        mvprintw(terrainY, terrainX, "/");
        terrainY++;
        terrainX--;
    }
    for (terrainY = 25, terrainX = 28; terrainY < 30, terrainX < 33;)
    {
        mvprintw(24, 26, "___");
        mvprintw(terrainY, terrainX, " \\");
        terrainY++;
        terrainX++;
    }

    /* mountain #3 */
    for (terrainY = 29, terrainX = 34; terrainY > 25, terrainX < 38;)
    {
        mvprintw(terrainY, terrainX, "/");
        terrainY--;
        terrainX++;
    }
    for (terrainY = 26, terrainX = 38; terrainY < 30, terrainX < 42;)
    {
        mvprintw(terrainY, terrainX, "\\");
        terrainY++;
        terrainX++;
    }

    /* mountain #4 */
    for (terrainY = 29, terrainX = 42; terrainY > 22, terrainX < 49;)
    {
        mvprintw(terrainY, terrainX, "/");
        terrainY--;
        terrainX++;
    }
    for (terrainY = 23, terrainX = 49; terrainY < 30, terrainX < 56;)
    {
        mvprintw(terrainY, terrainX, "\\");
        terrainY++;
        terrainX++;
    }
    /* end of terrain */

    refresh();
}