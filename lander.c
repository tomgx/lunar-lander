#include "lander.h"

/**currently the game physics are locked to 1 second**/

#define DELAY 500000

void terrainGen();
// void playerMovement();

int lander()
{
    // int x = 0, y = 4; /* starting position of ship */
    float max_y = 0, max_x = 0;
    float next_y = 0;
    float next_x = 0;

    int yMove = 0;
    int xMove = START_XSPEED;

    initscr();
    noecho();
    curs_set(FALSE);
    cbreak();
    keypad(stdscr, true);

    // Global var `stdscr` is created by the call to `initscr()`
    getmaxyx(stdscr, max_y, max_x);

    while (true)
    {
        clear();
        mvprintw(1, 0, "COUNTER  %d", yMove);
        mvprintw(3, 0, "COUNTER2  %d", xMove);
        mvprintw(0, 0, "SCORE  0000");
        mvprintw(2, 0, "FUEL  1000");
        mvprintw(y, x, " /\\");
        mvprintw(y + 1, x, " **");
        terrainGen();

        mvprintw(0, 30, "HORIZONTAL SPEED  %d", xMove);
        mvprintw(1, 30, "VERTICAL SPEED  %d", yMove);

        refresh();

        /*display physics values*/
        // int displayX = (int)START_XSPEED - (timer) / 2.5;
        // int displayY = (int)y - 4; /* -4 because the ship starts at x(4) */

        int intPut;
        intPut = getch(); // get user input

        nodelay(stdscr, TRUE); // use of no delay so the game doesn't pause to wait for user input

        /*Vertical Movement*/
        if (intPut == KEY_UP)
        {
            yMove--;
            halfdelay(3);
        }
        else if (yMove == 5)
        {
            yMove = 5; /*clamp (y)vertical velocity*/
        }
        else if (yMove != 5)
        {
            yMove++;
        }

        /*Horizontal Movement*/
        if (intPut == KEY_LEFT)
        {
            xMove--;
        }
        else if (intPut == KEY_RIGHT)
        {
            xMove++;
        }
        else if (xMove > 0)
        {
            xMove--;
        }
        else if (xMove < 0)
        {
            xMove++;
        }
        else if (xMove == 0)
        {
            xMove = 0; /*clamp (x)horizontal velocity*/
        }

        /*set x and y coords*/
        x += xMove;
        y += yMove;

        refresh();
    }

    endwin(); /* close window */
}

/* For the landing pad. determine whether the lander lands on a certain symbol. e.g. --*/
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