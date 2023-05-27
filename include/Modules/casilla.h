#ifndef CASILLA_H
#define CASILLA_H

// libraries
#include <stdio.h>
#include "../Utils/colores.h"

// cell types 
#define CELL_VOID               0
#define CELL_WALL	  	1
#define CELL_SNAKE		2
#define CELL_FRUIT		3
#define CELL_TEXT		4
#define CELL_CRASH		5

// default values 
#define CELL_VALUE_VOID         ' ' //Empty
#define CELL_VALUE_WALL         '#' //Wall
#define CELL_VALUE_SNAKE        '@' //Snake
#define CELL_VALUE_FRUIT	'$' //Fruit
#define CELL_VALUE_CRASH	'X' //Snake crash



// cell struct
typedef struct {
	char type, value;
} tcell ;

// functions
void in_cell(tcell *c); // initialize an empty cell
void show_cell(tcell c) ; // it prints the content of a cell

#endif

