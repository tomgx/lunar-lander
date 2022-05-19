#include "menu.h"

void titleLogo()
{
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_BLUE, COLOR_BLACK);
  init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(4, COLOR_GREEN, COLOR_BLACK);
  init_pair(5, COLOR_CYAN, COLOR_BLACK);

  mvprintw(6, 35, "  MM         MM    MM   MMMM  MM       M       MMMMMMM     ");
  mvprintw(7, 35, "  88         88    88   88 MM 88      AVV      88   98     ");
  mvprintw(8, 35, "  88         88    88   88  MW88     AV VA     88MMM68     ");
  mvprintw(9, 35, "  88         88    88   88   Mw8    AVAVAVA    88  VKA     ");
  mvprintw(10, 35, "  88888888    Xx88xX    88    W8   AV     VA   88   VAA   ");

  mvprintw(12, 43, "  M      AA   NN  N  MAAD.  MMMN  9MM6    ");
  mvprintw(13, 43, "  M     A==A  N M N  M   D  M##   M++W    ");
  mvprintw(14, 43, "  MWWW  W  W  N  NN  MMMD`  MWWN  M ^Kn   ");
};

void titleControls()
{
  mvprintw(16, 44, "---------------------------------------");
  mvprintw(17, 54, "            [^]                        ");
  mvprintw(18, 54, "CONTROLS: [<] [>]                      ");
}

void titleRules()
{
  attron(A_UNDERLINE);
  mvprintw(20, 57, "HOW TO PLAY");
  attroff(A_UNDERLINE);
  attron(A_BOLD);
  mvprintw(21, 16, "| Land on landing pad with a Vertical velocity of less than or equal to 3 to gain points and fuel |");
  mvprintw(22, 35, "| Crashing removes 20 units of fuel from the lander |");
  attroff(A_BOLD);
  mvprintw(22, 35, "| Crashing removes 20 units of fuel from the lander |");
  attron(A_UNDERLINE);
  mvprintw(24, 33, "DIFFICULTY RATING DETERMINES HOW MUCH FUEL YOU START WITH");
  attroff(A_UNDERLINE);
  attron(A_STANDOUT);
  mvprintw(26, 55, " SELECT 1 - 4 ");
  attroff(A_STANDOUT);

  mvprintw(27, 46, "(1)");
  attron(COLOR_PAIR(4));
  mvprintw(27, 56, "(2)");
  attroff(COLOR_PAIR(4));
  attron(COLOR_PAIR(3));
  mvprintw(27, 66, "(3)");
  attroff(COLOR_PAIR(3));
  attron(COLOR_PAIR(1));
  mvprintw(27, 76, "(4)");
  attroff(COLOR_PAIR(1));

  mvprintw(28, 43, "100 FUEL   80 FUEL   60 FUEL   40 FUEL");
}

void titleMoon()
{
  mvprintw(5, 3, "          ___---___.            ");
  mvprintw(6, 3, "       ..--        *--..        ");
  mvprintw(7, 3, "     ./   ()       .-.  \\.     ");
  mvprintw(8, 3, "     /   o    .   (   )   \\    ");
  mvprintw(9, 3, "    / .            '-'     \\   ");
  mvprintw(10, 3, "   | O         .      .     |  ");
  mvprintw(11, 3, "  |                .    o   |  ");
  mvprintw(12, 3, "  |    o        .*--.     . |  ");
  mvprintw(13, 3, "  | .          |    |       |  ");
  mvprintw(14, 3, "   \\          `.__.'   .    / ");
  mvprintw(15, 3, "    \\               o      /  ");
  mvprintw(16, 3, "     `\\  o    ()         /'   ");
  mvprintw(17, 3, "        `--___   ___--'        ");
  mvprintw(18, 3, "              ---              ");
}