#include <ncurses.h>

int main() {
    initscr(); //create the screen
    printw("Hello World!"); //print hello world
    refresh(); //print on to real screen
    getch(); //wait for user input
    endwin(); //end curses mode

    return 0;
}