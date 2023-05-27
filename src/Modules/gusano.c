#include "../include/Modules/gusano.h"


void in_snake(tsnake *s) {

        s->dir=E; //first direction EST
        s->score=0; //point value at the start of the game
        
        //time is initialized to 0
        s->m=0; 
        s->s=0;
        s->aux=0;

        //the snake in the middle of the board is initialized
        s->coords.ncoords=SNAKE_START;
        in_coords(&s->coords);
}



void move_snake(tsnake *s) {

        //move the snake according to its direction

        int i;

        if (s->dir==E){
                for (i=s->coords.ncoords-1;i>=1;i--){
                        s->coords.coord[i].col=s->coords.coord[i-1].col;
                        s->coords.coord[i].row=s->coords.coord[i-1].row;
                }
                s->coords.coord[0].col++;
        }

        else if (s->dir==S){
                for (i=s->coords.ncoords-1;i>=1;i--){
                        s->coords.coord[i].col=s->coords.coord[i-1].col;
                        s->coords.coord[i].row=s->coords.coord[i-1].row;
                }
                s->coords.coord[0].row++;
        }

        else if (s->dir==N) {

                for (i=s->coords.ncoords-1;i>=1;i--){
                        s->coords.coord[i].col=s->coords.coord[i-1].col;
                        s->coords.coord[i].row=s->coords.coord[i-1].row;
                }
                s->coords.coord[0].row--;
        }

        else if (s->dir==O) {
                for (i=s->coords.ncoords-1;i>=1;i--){
                        s->coords.coord[i].col=s->coords.coord[i-1].col;
                        s->coords.coord[i].row=s->coords.coord[i-1].row;
                }
                s->coords.coord[0].col--;
        }

}

void grow_snake(tsnake *s) {
        s->score++; //add a point to the score
        insert_pos (&s->coords); //add a coord to the snake tail
}
