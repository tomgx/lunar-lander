#include <ncurses.h>
#include <unistd.h>
#include <math.h>


#define SECOND 1000
#define START_XSPEED 10
#define START_YSPEED -2
#define START_FUEL 100

/*ship starting position*/
int x = -8, y = 4;