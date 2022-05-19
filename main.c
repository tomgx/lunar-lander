#include "main.h"
//#include "menu.c"
#include "lander.c"
#include "menu.c"

void main()
{
  initscr();
  keypad(stdscr, true);
  noecho();
  curs_set(FALSE);
  start_color(); /* Start the color functionality */
  cbreak();

  titleLogo();
  titleMoon();
  titleControls();
  titleRules();

  int input;
  input = getch(); // wait for user input after printing the main menu

  switch (input)
  {
  case '1':
    fuel = 100;
    break;
  case '2':
    fuel = 80;
    break;
  case '3':
    fuel = 60;
    break;
  case '4':
    fuel = 40;
    break;
  default: // if the user presses something other than 1 - 4. set the fuel to 100 by default.
    fuel = 100;
    break;
  }
  score = 0;
  lander();
}