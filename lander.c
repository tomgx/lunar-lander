#include "lander.h"
#include "terrainGen.c"

int lander()
{
    float max_y = 0, max_x = 0;
    int yMove = 0;
    int xMove = START_XSPEED;
    int userInput;
    int fuel = 100;
    ;

    initscr();
    noecho();
    curs_set(FALSE);
    cbreak();
    keypad(stdscr, true);

    // Global var `stdscr` is created by the call to `initscr()`
    getmaxyx(stdscr, max_y, max_x);

    do
    {
        clear();
        terrainGen();

        mvprintw(0, 30, "HORIZONTAL SPEED  %d", xMove);
        mvprintw(1, 30, "VERTICAL SPEED  %d", yMove);
        mvprintw(0, 0, "SCORE  0000");
        mvprintw(1, 0, "FUEL  %d", fuel);
        mvprintw(y, x, " /\\");
        mvprintw(y + 1, x, " **");

        refresh();

        userInput = getch(); // get user input

        nodelay(stdscr, TRUE); // use of no delay so the game doesn't pause to wait for user input

        /*Vertical Movement*/
        if (userInput == KEY_UP)
        {
            fuel--;
            yMove--;
            halfdelay(4); /*half delay used to make it easier to control the ship*/
        }
        else if (yMove == 8)
        {
            yMove = 5; /*clamp (y)vertical velocity*/
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
            halfdelay(4);
        }
        else if (userInput == KEY_RIGHT)
        {
            fuel--;
            xMove++;
            halfdelay(4);
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

    if(fuel == 0){
        clear();
        for(int i = 5; i >= 0; i--){
            mvprintw(10,10, "GAME OVER! You have no fuel");
            mvprintw(11,16, "Restarting in %d",i);
            usleep(1000000);
            refresh();
        }
        // need to make game loop

        
        
    }

    endwin(); /* close window */
}