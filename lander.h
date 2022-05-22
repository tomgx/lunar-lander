/* Libraries */
#include <ncurses.h>
#include <stdlib.h>

/* Constants */
#define START_XSPEED 10.0
#define START_YSPEED 0.0
#define START_FUEL 100
#define START_X 1
#define START_Y 5

/* Global variables */
int x = START_X;                /* x starting position */   
int y = START_Y;                /* y starting position */
int fuel = START_FUEL;          /* starting fuel */
int score = 0;                  /* starting score */
float yMove = START_YSPEED;     /* starting vertical velocity */
float xMove = START_XSPEED;     /* starting horizontal velocity */
int map;                        /* map selection */
int frameCounter;               /* counter for how many frames have passed by */
int userInput;
int height, width, startY, startX;
int next_x = 0;
int direction = 0;

/* Functions */
int terrainGenAndCollision(int map);
void initialize();