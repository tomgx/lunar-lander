int terrainX, terrainY;

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
}