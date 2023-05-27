#ifndef TABLERO_H
#define TABLERO_H

// libraries
#include "../Utils/azar.h"
#include "../Utils/tamanyo_terminal.h"
#include "gusano.h"
#include "casilla.h"
#include <string.h>
// constants
#define CRASH                   120
#define FRUIT_SNAKE_OVERLAPPED  110
#define BOARD_MAXF		512
#define BOARD_MAXC		512

// type board
typedef struct {
	tcell c[BOARD_MAXF][BOARD_MAXC]; //cell matrix
	int numf, numc; //terminal size 
	tsnake s; 
	tcoord fruit, tail; //coords of the fruit and the snake tail
} tboard;


// functions
void in_board(tboard *t); //initialize the board to empty cells
int read_data_board(tboard t); //read if there has been a crash
void assign_wall_board(tboard *t); //assign the wall to the board
void move_snake_board(tboard *t); //move a coord all the coords of the snake
void assign_snake_board(tboard *t, int event); //assign the snake to the board
void assign_fruit_board(tboard *t); // assign the fruit to the board
void time_board (tsnake *s, unsigned wait); //update the clock
void show_board(tboard t); //prints the entire cell matrix to the screen

#endif
