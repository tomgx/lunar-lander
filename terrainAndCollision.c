#include "terrainAndCollision.h"

int landSuccess(int multiplier)
{
    erase();
    yMove = 0;
    xMove = 0;
    attron(COLOR_PAIR(4));
    attron(A_BOLD);
    attron(A_UNDERLINE);
    mvprintw(13, 55, "+%d POINTS", multiplier);
    attroff(A_UNDERLINE);
    attroff(A_BOLD);
    mvprintw(14, 47, "Successful Landing: +15 Fuel");
    attroff(COLOR_PAIR(4));
    fuel = fuel + 15;
    score = score + multiplier;
    x = START_X, y = START_Y;
    yMove = START_YSPEED;
    xMove = START_XSPEED;
    pressToStart();
}

void landerCollision()
{
    erase();
    attron(COLOR_PAIR(1));
    mvprintw(14, 48, "You have crashed: -20 FUEL");
    attroff(COLOR_PAIR(1));
    fuel = fuel - 20;
    x = START_X, y = START_Y;
    yMove = START_YSPEED;
    xMove = START_XSPEED;
    pressToStart();
}

int terrainGenAndCollision(int map)
{

    int coordY = 26;
    srand(map);

    for (int counter = 3; counter < 125; counter++)
    {
        int random = rand() % (7 - 2 - 0) + 0;
        double randomVal;
        randomVal = (double)rand() / RAND_MAX * 1.0;

        if (randomVal < random * 1 / 3)
        {

            mvprintw(coordY--, counter++, "/");
            mvprintw(coordY, counter++, "__");

            if ((x + 1 == counter) && (y + 1 >= coordY + 1) || (y + 1 >= coordY + 1) && (x + 2 == counter)) // collision detection for '__'
            {
                if (yMove <= 2 & xMove == 0)
                {
                    y = coordY;
                    landSuccess(50);
                }
                else
                {
                    y = coordY;
                    landerCollision();
                }
            }
            else if ((x + 1 == counter - 2) && (y + 1 >= coordY + 2) || (y + 1 >= coordY + 2) && (x + 2 == counter - 2))
            { // collision detection for '/'
                landerCollision();
            }
        }
        else if (randomVal < random * 2 / 3)
        {

            mvprintw(coordY++ + 1, counter++, "\\");
            mvprintw(coordY, counter++, "__");
            if ((x + 1 == counter) && (y + 1 >= coordY + 1) || (y + 1 >= coordY + 1) && (x + 2 == counter))
            {

                if (yMove <= 2 & xMove == 0)
                {
                    y = coordY;
                    landSuccess(50);
                }
                else
                {
                    y = coordY;
                    landerCollision();
                }
            }
            else if ((x + 1 == counter - 2) && (y + 1 >= coordY) || (y + 1 >= coordY) && (x + 2 == counter - 2))
            { // collision detection for '/'
                landerCollision();
            }

            if ((x + 1 == counter) && (y + 1 > coordY + 1) || (y + 1 > coordY + 1) && (x + 2 == counter)) // collision detection
            {
                if (yMove <= 2 & xMove == 0)
                {
                    y = coordY;
                    landSuccess(50);
                }
                else
                {
                    y = coordY + 1;
                    landerCollision();
                }
            }
        }
        else
        {
            mvprintw(coordY, counter++ - 1, "___");

            int scoreMulti[] = {2, 3, 4, 5};
            if (counter % 5 == 4)
            {
                mvprintw(coordY - 1, counter - 3, "^  ^"); // landing pad indication
                mvprintw(coordY + 1, counter - 3, "|%dX|", scoreMulti[rand() % 4]);

                if ((x + 1 == counter - 2) && (y + 1 > coordY) || (y + 1 > coordY) && (x + 2 == counter - 2)) // collision detection
                {
                    if (yMove <= 2 & xMove == 0)
                    {
                        y = coordY;
                        landSuccess(100);
                    }
                    else
                    {
                        y = coordY;
                        landerCollision();
                    }
                }
            }
            else if ((x + 1 == counter - 2) && (y + 1 >= coordY + 1) || (y + 1 >= coordY + 1) && (x + 2 == counter - 2))
            {
                if (yMove <= 2 & xMove == 0)
                {
                    y = coordY + 1;
                    landSuccess(50); // if lander lands on flat land with no multiplier.
                }
                else
                {
                    y = coordY + 1;
                    landerCollision();
                }
            }

            // star generation
            for (int starsCounter = 0; starsCounter < 1; starsCounter++)
            {
                mvprintw(rand() % (20 + 1 - 4) + 4, rand() % (120 + 1 - 4) + 4, ".");
            }
        }
    }
}