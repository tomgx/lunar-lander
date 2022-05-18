int terrainX, terrainY, terrainX1, terrainY1, terrainX2, terrainY2;

int arrX[] = {11, 10, 9, 8, 7, 6, 5, 4, 3};

int arrY[] = {21, 22, 23, 24, 25, 26, 27, 28, 29};
int arrLen = sizeof arrY / sizeof arrY[0];

void landerCollision()
{
    mvprintw(10, 10, "Collision Detected");
    // exit_curses(1);
}

/* For the landing pad. determine whether the lander lands on a certain symbol. e.g. --*/
void terrainGen()
{
    /* mountain #1 */
    for (int i = 0; i < arrLen; i++)
    {
        mvprintw(arrY[i], arrX[i], "#");                                                          // print left side of mountain
        if ((x + 1 == arrX[i]) && (y + 1 >= arrY[i]) || (y + 1 >= arrY[i]) && (x + 2 == arrX[i])) // collision detection
        {
            landerCollision();
        }
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
        attron(COLOR_PAIR(4));
        mvprintw(24, 26, "___");
        attroff(COLOR_PAIR(4));
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
}