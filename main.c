#include "main.h"


int main() {
    
    initscr();                              /* create the screen */
    raw();				                    /* Line buffering disabled	*/
    attron(A_UNDERLINE);
    printw("Welcome to Lunar Lander\n");    /* print hello world */
    attroff(A_UNDERLINE);
    attron(A_STANDOUT);
    printw("PLAY\n");
    attroff(A_STANDOUT);
    printw("EXIT\n");
    noecho();			    /* Don't echo() while we do getch */
    raw();				    /* Line buffering disabled	*/
	keypad(stdscr, TRUE);	/* We get F1, F2 etc..		*/
	noecho();			    /* Don't echo() while we do getch */
	ch = getch();


        switch (ch) {
          case KEY_UP:       /* user presses UP arrow key */ 
            printw("UP arrow is pressed\n");
            break;
          case KEY_DOWN:     /* user presses DOWN arrow key */
            printw("DOWN arrow is pressed\n");
            break;
          case KEY_LEFT:     /* user presses LEFT arrow key */
            printw("LEFT arrow is pressed\n");
            break;
          case KEY_RIGHT:    /* user presses RIGHT arrow key */
            printw("RIGHT arrow is pressed\n");
            break;
     }

    refresh();  /* Print it on to the real screen */
    getch();    /* wait for user input before exiting */
    endwin();   /* end curses mode */

    return 0;
}
