#include <ncurses.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>


#define SECOND 1000
#define START_XSPEED 10
#define START_YSPEED 0
#define START_FUEL 100

/*ship starting position*/
int x = -4, y = 4;
int fuel = START_FUEL;
int score = 0;
int yMove = START_YSPEED;
int xMove = START_XSPEED;