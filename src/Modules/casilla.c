#include "../include/Modules/casilla.h"


void in_cell(tcell *c) { 

        c->type=CELL_VOID;
}

void show_cell(tcell c) { 

        switch (c.type) {

                case CELL_VOID: // cell is empty

                        c.value=CELL_VALUE_VOID;
                        printf_reset_color();
                        printf ("%c",c.value);
                        break;

                case CELL_WALL: // cell is part of the boards' wall

                        c.value=CELL_VALUE_WALL;
                        printf_reset_color();
                        printf ("%c",c.value);
                        break;

                case CELL_SNAKE: // cell is part of the snake

                        printf_color(BOLD_GREEN);
                        c.value=CELL_VALUE_SNAKE;
                        printf ("%c",c.value);
                        break;

                case CELL_FRUIT: // cell is the fruit

                        printf_color(BOLD_RED);
                        c.value= CELL_VALUE_FRUIT;
                        printf ("%c",c.value);
                        break;

                case CELL_CRASH: // cell is the snake colliding with the wall or itself 

                        printf_color(BOLD_YELLOW);
                        c.value=CELL_VALUE_CRASH;
                        printf ("%c",c.value);
                        break;
        }
}
