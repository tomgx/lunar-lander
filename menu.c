#include "menu.h"

int menu()
{

  getmaxyx(stdscr, yMax, xMax);
  WINDOW *menu;

  char choices[3][9] = {"PLAY", "SETTINGS", "EXIT"};
  char letters[10];

  initscr();                                             /* initialize Ncurses; */
  menu = newwin(yMax / 2, xMax / 2, yMax / 4, xMax / 4); /* create a new window */
  box(menu, 0, 0);                                       /* sets borders for window */

  /* now print all the choices and highlight the first choice */
  for (highlight = 0; highlight < 3; highlight++)
  {
    if (highlight == 0)
      wattron(menu, A_STANDOUT); /* highlights the first item */
    else
      wattroff(menu, A_STANDOUT);
    sprintf(letters, "%-9s", choices[highlight]); /* string print */
    mvwprintw(menu, highlight + 1, 2, "%s", letters);
  }

  wrefresh(menu); /* update the screen */
  highlight = 0;
  noecho();           /* disable echoing of characters on the screen */
  keypad(menu, TRUE); /* enable keyboard input for the window */
  curs_set(0);        /* hide the default screen cursor */

  while (ch = wgetch(menu))
  {                                               /* loop forever until user presses ctrl + c */
    sprintf(letters, "%-9s", choices[highlight]); /* right pad with spaces to make the items appear with even width */
    mvwprintw(menu, highlight + 1, 2, "%s", letters);

    /* use a variable to increment or decrement the value based on the input */
    switch (ch)
    {
    case KEY_UP:
      highlight--;
      highlight = (highlight < 0) ? 2 : highlight;
      break;
    case KEY_DOWN:
      highlight++;
      highlight = (highlight > 2) ? 0 : highlight;
      break;
    }

    /* highlights the next item in the list */
    wattron(menu, A_STANDOUT);
    sprintf(letters, "%-9s", choices[highlight]);
    mvwprintw(menu, highlight + 1, 2, "%s", letters);
    wattroff(menu, A_STANDOUT);
  }

  delwin(menu);
  endwin();

  return 0;
}