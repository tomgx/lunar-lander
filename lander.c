#include "lander.h"
#include "terrainGen.c"

int lander()
{
    WINDOW *window;

    // float max_y = 0, max_x = 0;

    int userInput;
    int height, width, start_y, start_x;
    int next_x = 0;
    int direction = 0;

    height = 32;
    width = 128;
    start_y = start_x = 0;

    initscr();
    keypad(stdscr, true);
    noecho();
    curs_set(FALSE);
    cbreak();
    start_color(); /* Start the color functionality */

    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);

    // getmaxyx(stdscr, max_y, max_x);

    mvprintw(15, 48, "Press Any Key To Continue");
    getch();

    do
    {
        clear();
        window = newwin(height, width, start_y, start_x); /* create a new window */
        refresh();
        box(window, 0, 0);
        wrefresh(window);
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

    while (true)
    {

        userInput = getch(); // get user input
        attron(COLOR_PAIR(1));
        mvprintw(13, 48, "GAME OVER! You have no fuel");
        attroff(COLOR_PAIR(1));
        attron(A_BOLD);
        mvprintw(14, 50, "Press 'R' to Play Again");
        mvprintw(15, 49, "Press 'Q' to Quit the Game");
        attroff(A_BOLD);
        refresh();
        if (userInput == 'r' || userInput == 'R') // restart game if user press r
        {
            clear();
            x = -8, y = 4;
            yMove = START_YSPEED;
            xMove = START_XSPEED;
            fuel = START_FUEL;
            lander();
        }
        else if (userInput == 'q' || userInput == 'Q') // quit program is user presses q
        {
            endwin(); // exit ncurses
            exit(0);  // exit program
        }
    }
}