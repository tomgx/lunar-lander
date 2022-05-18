#include "lander.h"
#include "terrainGen.c"

/*TODO: collision detection - if user(x,y) is at specific coordinates and at a certain speed - do something*/


int lander()
{
    float max_y = 0, max_x = 0;
    int yMove = START_YSPEED;
    int xMove = START_XSPEED;
    int fuel = START_FUEL;
    int userInput;

    initscr();
    noecho();
    curs_set(FALSE);
    cbreak();
    keypad(stdscr, true);
    start_color();			/* Start the color functionality */

    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);



    // Global var `stdscr` is created by the call to `initscr()`
    getmaxyx(stdscr, max_y, max_x);

    mvprintw(10, 10, "Press ENTER to start game");
    getch();

    do
    {
        clear();
        terrainGen();
        attron(COLOR_PAIR(1));
        wborder(stdscr, '|', '|', '-', '-', '+', '+', '+', '+');
        attroff(COLOR_PAIR(1));
        mvprintw(0, 30, "HORIZONTAL SPEED  %d", xMove);
        mvprintw(1, 30, "VERTICAL SPEED  %d", yMove);
        mvprintw(0, 0, "SCORE  0000");
        mvprintw(1, 0, "FUEL  %d", fuel);

        attron(COLOR_PAIR(2));
        mvprintw(y, x + 1, "/\\");
        attroff(COLOR_PAIR(2));

        attron(COLOR_PAIR(3));
        mvprintw(y + 1, x + 1, "*");
        mvprintw(y + 1, x + 2, "*");
        attroff(COLOR_PAIR(3));

        //mvprintw(y + 2, x + 1, "''");
            


        refresh();

        // nodelay(stdscr, TRUE); // use of no delay so the game doesn't pause to wait for user input
        halfdelay(3); /*half delay used to make it easier to control the ship*/
        userInput = getch();   // get user input


        /*Vertical Movement*/
        if (userInput == KEY_UP)
        {
            fuel--;
            yMove--;
        }
        else if (yMove == 8)
        {
            yMove = 8; /*clamp (y)vertical velocity*/
        }
        else if (yMove != 8)
        {
            yMove++;
        }

        /*Horizontal Movement*/
        if (userInput == KEY_LEFT)
        {
            fuel--;
            xMove--;
        }
        else if (userInput == KEY_RIGHT)
        {
            fuel--;
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
    } while (fuel != 0);

    // if (fuel == 0)
    // {
        clear();
        for (int i = 5; i >= 0; i--)
        {
            mvprintw(10, 10, "GAME OVER! You have no fuel");
            mvprintw(11, 16, "Restarting in %d", i);
            usleep(1000000);
            refresh();
        // }
        // need to make game loop
    }

    endwin(); /* close window */
}