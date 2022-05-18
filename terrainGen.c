
int terrainX, terrainY, terrainX1, terrainY1, terrainX2, terrainY2;

// getmaxyx(stdscr, max_y, max_x);
// int arrGround[] = {}

/*Mountain 1 Left Side*/
int mtnOneLeftX[] = {10, 9, 8, 7, 6, 5, 4, 3};
int mtnOneLeftY[] = {23, 24, 25, 26, 27, 28, 29, 30};
int mtnOneLeftSize = sizeof mtnOneLeftY / sizeof mtnOneLeftY[0];

/*Mountain 1 Right Side*/
int mtnOneRightX[] = {18, 17, 16, 15, 14, 13, 12, 11};
int mtnOneRightY[] = {30, 29, 28, 27, 26, 25, 24, 23};
int mtnOneRightSize = sizeof mtnOneRightY / sizeof mtnOneRightY[0];

/*Mountain 2 Left Side*/
int mtnTwoLeftX[] = {19, 20, 21, 22};
int mtnTwoLeftY[] = {30, 29, 28, 27};
int mtnTwoLeftSize = sizeof mtnTwoLeftY / sizeof mtnTwoLeftY[0];

/*Mountain 2 Right Side*/
int mtnTwoRightX[] = {27, 28, 29, 30};
int mtnTwoRightY[] = {27, 28, 29, 30};
int mtnTwoRightSize = sizeof mtnTwoRightY / sizeof mtnTwoRightY[0];

int landPadOne[] = {23, 24, 25, 26};
int sizeOfLandPadOne = sizeof landPadOne / sizeof landPadOne[0];

void lander();

void landSuccess()
{
    yMove = 0;
    xMove = 0;
    //mvprintw(13, 50, "Press ANY KEY continue");
    attron(COLOR_PAIR(4));
    mvprintw(14, 48, "Successful Landing: +15 Fuel");
    attroff(COLOR_PAIR(4));
    fuel = fuel + 15;
    score = score + 50;
    x = -8, y = 4;
    yMove = START_YSPEED;
    xMove = START_XSPEED;
    lander();
}

void landerCollision()
{  
    
    //mvprintw(13, 50, "Press ANY KEY continue");
    attron(COLOR_PAIR(1));
    mvprintw(14, 48, "You have crashed: -20 FUEL");
    attroff(COLOR_PAIR(1));
    fuel = fuel - 20;
    x = -8, y = 4;
    yMove = START_YSPEED;
    xMove = START_XSPEED;
    lander();

    // TODO: go to the beginning of game loop
    // exit_curses(1);
}

void starsBackground()
{
    int randomY = rand() % 32;
    int randomX = rand() % 128;

    for (int i = 0; i < 40; i++)
    {
        mvprintw(randomY, randomX, "*");
    }
}


void terrainGen()
{

    /*Ground generation*/
    for (int i = 1; i < 127; i++)
    {
        mvprintw(30, i, "-");
        if ((x + 1 == i) && (y + 1 >= 30) || (y + 1 >= 30) && (x + 2 == i)) // collision detection
        {
            landerCollision();
        }
    }

    /*                         Mountain One                        */
    /*Mountain 1 Left Side*/
    for (int i = 0; i < mtnOneLeftSize; i++)
    {

        attron(COLOR_PAIR(1));
        mvprintw(mtnOneLeftY[i], mtnOneLeftX[i], "/");
        attroff(COLOR_PAIR(1));                                                                                               // print left side of mountain
        if ((x + 1 == mtnOneLeftX[i]) && (y + 1 >= mtnOneLeftY[i]) || (y + 1 >= mtnOneLeftY[i]) && (x + 2 == mtnOneLeftX[i])) // collision detection
        {
            landerCollision();
        }
    }
    /*Mountain 1 Right Side*/
    for (int i = 0; i < mtnOneRightSize; i++)
    {
        attron(COLOR_PAIR(1));
        mvprintw(mtnOneRightY[i], mtnOneRightX[i], "\\");
        attroff(COLOR_PAIR(1));
        if ((x + 1 == mtnOneRightX[i]) && (y + 1 >= mtnOneRightY[i]) || (y + 1 >= mtnOneRightY[i]) && (x + 2 == mtnOneRightX[i])) // collision detection
        {
            landerCollision();
        }
    }

    /*                         Mountain Two                        */
    /*Mountain 2 Left Side*/
    for (int i = 0; i < mtnTwoLeftSize; i++)
    {
        mvprintw(27, 24, "2X");
        attron(COLOR_PAIR(1));
        mvprintw(mtnTwoLeftY[i], mtnTwoLeftX[i], "/");
        attroff(COLOR_PAIR(1));
        if ((x + 1 == mtnTwoLeftX[i]) && (y + 1 >= mtnTwoLeftY[i]) || (y + 1 >= mtnTwoLeftY[i]) && (x + 2 == mtnTwoLeftX[i])) // collision detection
        {
            landerCollision();
        }
    }
    /*Mountain 2 Right Side*/
    for (int i = 0; i < mtnTwoRightSize; i++)
    {
        attron(COLOR_PAIR(1));
        mvprintw(mtnTwoRightY[i], mtnTwoRightX[i], "\\");
        attroff(COLOR_PAIR(1));
        if ((x + 1 == mtnTwoRightX[i]) && (y + 1 >= mtnTwoRightY[i]) || (y + 1 >= mtnTwoRightY[i]) && (x + 2 == mtnTwoRightX[i])) // collision detection
        {
            landerCollision();
        }
        attron(COLOR_PAIR(4));
        mvprintw(26, 23, "____");
        attroff(COLOR_PAIR(4));
        for(int j = 0; j < sizeOfLandPadOne; j++){
        if ((x + 1 == landPadOne[j]) && (y + 1 >= 27) || (y + 1 >= 27) && (x + 2 == landPadOne[j])) //
        {
            if (yMove < 3 & xMove == 0)
            {
                y = 25;
                landSuccess();
            }
            else
            {
                landerCollision();
            }
        }
        }
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
}