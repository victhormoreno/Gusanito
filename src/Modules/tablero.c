#include "../include/Modules/tablero.h"
#include "../include/Utils/tamanyo_terminal.h"


void in_board (tboard *t){
        
        int i,j;

        //numf and numc are assigned the value of the terminal
        obtener_tamanyo_terminal(&t->numf, &t->numc);

        //initialize the board empty
        for (i=0;i<t->numf;i++) {
                for (j=0;j<t->numc;j++)
                        t->c[i][j].type=CELL_VOID;
                
        }

        //initialize the snake coords
        in_snake(&t->s);
}

int read_data_board(tboard t) {

        int res=0, i;
        //check if there's a WALL-SNAKE crash
        if (t.s.coords.coord[0].col==0 || t.s.coords.coord[0].row==1 || t.s.coords.coord[0].col==t.numc-1 || t.s.coords.coord[0].row==t.numf-2)
                res=CRASH;
                

        //check if there's a SNAKE-SNAKE crash
        for(i=1;i<t.s.coords.ncoords;i++){
                if(t.s.coords.coord[0].row==t.s.coords.coord[i].row && t.s.coords.coord[0].col==t.s.coords.coord[i].col )
                        res=CRASH;
        }

        //check if there's a SNAKE-FRUIT overlapping
        for (i=0;i<t.s.coords.ncoords;i++){
                if (t.fruit.row==t.s.coords.coord[i].row && t.fruit.col== t.s.coords.coord[i].col)
                        res=FRUIT_SNAKE_OVERLAPPED;
        }
        
        return res;
}


void assign_wall_board(tboard *t) {

        int i;

        //frist row
        for (i=0;i<t->numc;i++)
                t->c[1][i].type=CELL_WALL;
        
        //last row
        for (i=0;i<t->numc;i++)
                t->c[t->numf-2][i].type=CELL_WALL;
        
        //left column
        for (i=2;i<t->numf-1;i++)
                t->c[i][0].type=CELL_WALL;
        
        //right column
        for (i=2;i<t->numf-2;i++)
                t->c[i][t->numc-1].type=CELL_WALL;
}

void assign_snake_board(tboard *t, int event) {

        int i;

        //if there has not been a CRASH assign the new snake coordinates to the board
        if (event!=CRASH){
                for (i=0;i<t->s.coords.ncoords;i++)
                        t->c[t->s.coords.coord[i].row][t->s.coords.coord[i].col].type=CELL_SNAKE;
                t->c[t->tail.row][t->tail.col].type=CELL_VOID;
                in_cell(&t->c[t->tail.row][t->tail.col]);
        }

        //if there has been CRASH change the value of the snake's head cell
        if (event == CRASH)
                t->c[t->s.coords.coord[1].row][t->s.coords.coord[1].col].type=CELL_CRASH;
}

void assign_fruit_board(tboard *t) {

        //initialize the fruit to a coord
        in_coord(&t->fruit);
        t->c[t->fruit.row][t->fruit.col].type=CELL_FRUIT;

}
void move_snake_board(tboard *t) {
        
        //the last position of the worm is saved
        t->tail.row=t->s.coords.coord[t->s.coords.ncoords-1].row;
        t->tail.col=t->s.coords.coord[t->s.coords.ncoords-1].col;

        //the snake coords are moved
        move_snake(&t->s);
}

void time_board (tsnake *s, unsigned wait) {
        
        s->aux++;

        //if a second has passed add a second
        if (s->aux==wait){
                s->aux=0;
                s->s++;

                //if 60 second has passed add a minute
                if (s->s==60){
                        s->s=0;
                        s->m++;
                }
        }

}

void show_board(tboard t) {
        
        //clean the screen
	clear_screen();

	int i,j;

        //print the scoreboard
        printf_color(BOLD_GREEN);
        printf ("Jugador: ");
        printf ("%s\t\t",t.s.name);
        printf ("Puntos: %u\t\tTiempo: %02u m %02u s\n",t.s.score,t.s.m,t.s.s);

        //print the cell matrix
        for (i=1;i<t.numf;i++) {
                for (j=0;j<t.numc;j++)
                        show_cell (t.c[i][j]);
        }
}
