#include <ncurses.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>

#define SECOND 1000
#define START_XSPEED 12
#define START_YSPEED 0
#define START_FUEL 100
#define START_X -4
#define START_Y 4

/*ship starting position*/
int x = START_X, y = START_Y;
int fuel = START_FUEL;
int score = 0;
int yMove = START_YSPEED;
int xMove = START_XSPEED;
int map;