#include "main.h"
#include "menu.c"
#include "lander.c"

void initialize()
{
  initscr();    /* initialize screen */
  keypad(stdscr, true);
  noecho();
  curs_set(FALSE);
  start_color();    /* Start the color functionality */
  cbreak();

  titleLogo();
  titleMoon();
  titleControls();
  titleRules();

  input = getch();

  /* User can select difficulty and map */
  switch (input)
  {
  case '1':
    fuel = DIFFICULTY_ONE;
    map = 0;
    break;
  case '2':
    fuel = DIFFICULTY_TWO;
    map = 1;
    break;
  case '3':
    fuel = DIFFICULTY_THREE;
    map = 2;
    break;
  case '4':
    fuel = DIFFICULTY_FOUR;
    map = 3;
    break;
  default:    /* if the user presses something other than 1 - 4. set the difficulty to 1 by default and map to 0. */
    fuel = DIFFICULTY_ONE;
    map = 0;
    break;
  }

  score = 0;    /* set score to 0*/
  lander();
}

void main()
{
  initialize();
}