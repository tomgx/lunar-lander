#include "lander.h"
#include "terrainAndCollision.c"

int lander()
{
    WINDOW *window;

    int userInput;
    int height, width, startY, startX;
    int next_x = 0;
    int direction = 0;

    height = 32;
    width = 128;
    startY = startX = 0;

    cbreak();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    init_pair(4, COLOR_GREEN, COLOR_BLACK);

    do
    {
        erase();
        refresh();
        window = newwin(height, width, startY, startX); /* create a new window */
        box(window, 0, 0);
        attron(COLOR_PAIR(1));
        wborder(window, '|', '|', '-', '-', '+', '+', '+', '+');
        attroff(COLOR_PAIR(1));
        wrefresh(window);

        terrainGenAndCollision(chooseLevel[map]); // terrain generation after user selects difficulty

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
            x = START_X, y = START_Y;
            yMove = START_YSPEED;
            xMove = START_XSPEED;
            fuel = START_FUEL;
            initialize();
        }
        else if (userInput == 'q' || userInput == 'Q') // quit program is user presses q
        {
            endwin(); // exit ncurses
            exit(0);  // exit program
        }
    }
}

void pressToStart()
{
    cbreak();
    mvprintw(15, 48, "Press Any Key To Continue");
    getch();
    lander();
}