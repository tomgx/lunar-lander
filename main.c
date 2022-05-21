#include "main.h"
//#include "menu.c"
#include "lander.c"
#include "menu.c"

void initialize()
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
    map = 0;
    break;
  case '2':
    fuel = 80;
    map = 1;
    break;
  case '3':
    fuel = 60;
    map = 2;
    break;
  case '4':
    fuel = 40;
    map = 3;
    break;
  default: // if the user presses something other than 1 - 4. set the fuel to 100 by default.
    fuel = 100;
    map = 0;
    break;
  }
  score = 0;
  lander();
}

int perlinNoise(int map)
{

  int coordY = 26;
  srand(map);

  for (int counter = 0; counter < 127; counter++)
  {
    int random = rand() % (7 - 2 - 0) + 0;
    double randomVal;
    randomVal = (double)rand() / RAND_MAX * 1.0;

    if (randomVal < random * 1 / 3)
    {
      mvprintw(coordY--, counter++, "/");
      mvprintw(coordY, counter++, "__");
    }
    else if (randomVal < random * 2 / 3)
    {
      mvprintw(coordY++ +1, counter++, "\\");
      mvprintw(coordY, counter++, "__");
    }
    else
    {
      mvprintw(coordY, counter++ -1, "___");

      int scoreMulti[] = {2, 3, 4, 5};
      if (counter % 5 == 4)
      {
        mvprintw(coordY + 1, counter - 2, "%dX", scoreMulti[rand() % 4]);
      }
    }

    // star generation
    for(int starsCounter = 0; starsCounter < 1; starsCounter++){
      mvprintw(rand() % (20 + 1 - 4) + 4, rand() % (120 + 1 - 4) + 4, ".");
    }

  }
}


void main()
{

  initialize();
}
