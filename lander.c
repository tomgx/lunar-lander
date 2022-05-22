#include "lander.h"
#include "terrainAndCollision.c"

int lander()
{
    WINDOW *window;
    
    /* window height and width */
    height = 33;
    width = 128;
    startY = startX = 0;

    /* colour pairs */
    init_pair(2, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);

    halfdelay(3);   /* delay between frames */

    do
    {
        erase();                                                      
        refresh();
        window = newwin(height, width, startY, startX);             /* create a new window */
        box(window, 0, 0);
        wborder(window, '|', '|', '-', '-', '+', '+', '+', '+');    /* window border */
        wrefresh(window);
        frameCounter++;     /* frame counter */
        terrainGenAndCollision(chooseLevel[map]);   /* terrain generation after user selects difficulty */

        mvprintw(1, 2, "SCORE: %d", score);
        mvprintw(2, 2, "FUEL:  %d", fuel);
        mvprintw(3, 2, "FRAME COUNTER: %d", frameCounter);
        mvprintw(1, 99, "ALTITUDE:         %d", abs(y - 29));
        mvprintw(2, 99, "HORIZONTAL SPEED: %f", xMove);
        mvprintw(3, 99, "VERTICAL SPEED:   %f", yMove);

        mvprintw(2, 45, "- - - - LUNAR LANDER - - - -");
        
        for(int i = 1; i < 127; i++){
        mvprintw(4, i, "-");
        }
        for(int j = 1; j < 4; j++){
            mvprintw(j, 21, "|");
            mvprintw(j, 95, "|");
        }

        /* print out the lander */
        attron(COLOR_PAIR(2));
        mvprintw(y, x + 1, "/\\");
        attroff(COLOR_PAIR(2));

        attron(COLOR_PAIR(3));
        mvprintw(y + 1, x + 1, "*");
        mvprintw(y + 1, x + 2, "*");
        attroff(COLOR_PAIR(3));

        /* get user input */
        userInput = getch(); 

        /*Vertical Movement*/
        if (userInput == KEY_UP)
        {
            fuel--;
            yMove--;
        }
        else if (yMove == 5)
        {
            yMove = 5;              /* clamp (y)vertical velocity */
        }
        else if (yMove != 5)
        {
            yMove = yMove + 0.5;    /* gravity value */
        }

        /*Horizontal Movement*/
        if (userInput == KEY_LEFT)
        {
            fuel--;                 /* remove fuel when key is pressed */
            xMove--;
        }
        else if (userInput == KEY_RIGHT)
        {
            fuel--;
            xMove++;
        }
        else if (xMove > 0)
        {
            xMove = xMove - 0.5;
        }
        else if (xMove < 0)
        {
            xMove = xMove + 0.5;    /* resistance value */
        }
        else if (xMove == 0)
        {
            xMove = 0;              /* clamp (x)horizontal velocity */
        }

        /* set x and y coords */
        x += xMove;
        y += yMove;

        /* x axis border collision */
        if (x > 123)
        {
            x = 123;
            xMove = 0;
        }
        else if (x < 1)
        {
            x = 1;
            xMove = 0;
        }

        /* y axis border collision */
        if (y > 32)
        {
            y = 32;
            yMove = 0;
        }
        else if (y < 5)
        {
            y = 5;
            yMove = 0;
        }

    } while (fuel > 0);     /* while fuel is greater than 0, continue game loop */

    while (true)
    {
        userInput = getch();        /* get user input */ 
        attron(COLOR_PAIR(1));
        mvprintw(13, 48, "GAME OVER! You have no fuel");
        attroff(COLOR_PAIR(1));
        attron(A_BOLD);
        mvprintw(14, 50, "Press 'R' to Play Again");
        mvprintw(15, 49, "Press 'Q' to Quit the Game");
        attroff(A_BOLD);
        refresh();
        
        if (userInput == 'r' || userInput == 'R')       /* restart game if user press 'r' */
        {
            /* clear the screen and reset all values back to the start*/
            clear();        
            x = START_X, y = START_Y;
            yMove = START_YSPEED;
            xMove = START_XSPEED;
            fuel = START_FUEL;
            frameCounter = 0;
            initialize();       /* execute function */
        }
        else if (userInput == 'q' || userInput == 'Q')      /* exit program if user presses 'q' */
        {
            endwin();       /* exit ncurses */
            exit(0);        /* exit program */
        }
    }
}

/* function - after landing or crashing, wait for user input before going back to game */
void pressToStart()
{
    cbreak();
    mvprintw(15, 48, "Press Any Key To Continue");
    getch();        /* wait for user input*/
    lander();
}