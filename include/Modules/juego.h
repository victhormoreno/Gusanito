#ifndef JUEGO_H
#define JUEGO_H

#include <string.h>

// Utils and modules
#include "../Utils/tamanyo_terminal.h"
#include "../Utils/azar.h"
#include "../Utils/teclas_tictac.h"
#include "tablero.h"


// constants
#define DEFAULT_TIMEOUT	1000000	// 1 second

// game type 
typedef struct {
	tboard t; // board type
	unsigned wait; // wait time
	int event; // last returned event
} tgame;

// functions
void in_game(tgame *j); // start the game
void run_game(tgame *j); // run and show the game
void end_game(tgame j); // game over

#endif
