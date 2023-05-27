#ifndef GUSANO_H
#define GUSANO_H

// libraries
#include <string.h>
#include <time.h>

#include "coords.h"

// constants 
#define SNAKE_NAME_MAX		        32
#define SNAKE_START		        4

// direction of movement 
#define N	0       //North
#define S	1       //South
#define E	2       //East
#define O	3       //West

// snake type 
typedef struct {
	tcoords coords;
	char name[SNAKE_NAME_MAX];
	unsigned dir;
	unsigned m,s,aux,score;
	unsigned char stopped;
} tsnake ;

// functions
void in_snake(tsnake *s); // initialize snake
void move_snake(tsnake *s); // move snake on the board 
void grow_snake(tsnake *s); // snake's tail grows

#endif
