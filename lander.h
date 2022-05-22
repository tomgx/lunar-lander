/* Libraries */
#include <ncurses.h>
#include <stdlib.h>

/* Constants */
#define START_XSPEED 10.0       /* starting horizontal velocity */
#define START_YSPEED 0.0        /* starting vertical velocity */
#define START_FUEL 100          /* starting fuel */
#define START_X 1               /* x starting position */   
#define START_Y 5               /* y starting position */
#define START_SCORE 0           /* starting score */

/* Global variables */
int x = START_X;                
int y = START_Y;                
int fuel = START_FUEL;
int score = START_SCORE;                  
float yMove = START_YSPEED;     
float xMove = START_XSPEED;     
int map;                        /* map selection */
int frameCounter;               /* counter for how many frames have passed by */
int userInput;                  /* user input */
int height, width, startY, startX;
int next_x = 0;
int direction = 0;

/* Functions */
int terrainGenAndCollision(int map);
void initialize();