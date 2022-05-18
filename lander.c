#include "lander.h"
#include "terrainGen.c"

void lander()
{
    WINDOW *window;

    //float max_y = 0, max_x = 0;

    int userInput;
    int height, width, start_y, start_x;
    int next_x = 0;
    int direction = 0;

    height = 32;
    width = 128;
    start_y = start_x = 0;

    initscr();
    noecho();
    curs_set(FALSE);
    cbreak();
    keypad(stdscr, true);
    start_color(); /* Start the color functionality */

    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);

    //getmaxyx(stdscr, max_y, max_x);

    mvprintw(15, 48, "Press Any Key To Continue");
    getch();

    do
    {
        clear();
        window = newwin(height, width, start_y, start_x); /* create a new window */
        refresh();
        box(window, 0, 0);
        wrefresh(window);

        // starsBackground();
        terrainGen();
        attron(COLOR_PAIR(1));
        // wborder(window, '|', '|', '-', '-', '+', '+', '+', '+');
        attroff(COLOR_PAIR(1));
        mvprintw(1, 35, "ALTITUDE:         %d", abs(y - 29));
        mvprintw(2, 35, "HORIZONTAL SPEED: %d", xMove);
        mvprintw(3, 35, "VERTICAL SPEED:   %d", yMove);
        mvprintw(1, 1, "SCORE: %d", score);
        mvprintw(2, 1, "FUEL:  %d", fuel);

        attron(COLOR_PAIR(2));
        mvprintw(y, x + 1, "/\\");
        attroff(COLOR_PAIR(2));

        attron(COLOR_PAIR(3));
        mvprintw(y + 1, x + 1, "*");
        mvprintw(y + 1, x + 2, "*");
        attroff(COLOR_PAIR(3));

        // mvprintw(y + 2, x + 1, "''");

        // refresh();

        // nodelay(stdscr, TRUE); // use of no delay so the game doesn't pause to wait for user input
        /*half delay used to make it easier to control the ship*/

        halfdelay(3);
        userInput = getch(); // get user input

        /*Vertical Movement*/
        if (userInput == KEY_UP)
        {
            fuel--;
            yMove--;
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

        /*x axis border collision*/
        if (x > 126)
        {
            x = 124;
            xMove = 0;
        }
        else if (x < 0)
        {
            x = 0;
            xMove = 0;
        }

        /*y axis border collision*/
        if (y > 30)
        {
            y = 29;
            yMove = 0;
        }
        else if (y < 0)
        {
            y = 1;
            yMove = 0;
        }

    } while (fuel > 0);

    /*Game Restart*/

    mvprintw(10, 10, "GAME OVER! You have no fuel");
    mvprintw(11, 10, "Press Enter to Play Again");

    userInput = getch(); // get user input

    if (userInput == KEY_ENTER)
    {
        mvprintw(15, 10, "TEST");
        fuel = 100;
        x = -8, y = 4;
        yMove = START_YSPEED;
        xMove = START_XSPEED;
        void main();
    }
    else if (userInput != KEY_UP)
    {
        for (int i = 1; i < 5; i++)
        {
            mvprintw(15, 48, "Exiting in: %d", i);
            endwin(); /* close window */
        }
    }
}