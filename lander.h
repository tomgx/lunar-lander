#include <ncurses.h>
#include <unistd.h>
#include <math.h>


#define SECOND 1000
#define START_XSPEED 10
#define START_YSPEED 0.5
int terrainX, terrainY;

    int timer = 0;
    int timerTwo = 10;

/*ship starting position*/
int x = 0, y = 4;