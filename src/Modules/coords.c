#include "../include/Modules/coords.h"
#include "../include/Utils/azar.h"
#include "../include/Utils/tamanyo_terminal.h"

// in_coord (initializes any object to a coord)
void in_coord(tcoord *c) {

        int maxc,maxf;

        obtener_tamanyo_terminal(&maxf,&maxc); //maxf and maxc are assigned the value of the terminal

        inicializar_azar(); //random library is started

        //the loop is repeated if the fruit appears on the wall
        do{
                c->row=numero_al_azar (maxf-1);
                c->col=numero_al_azar (maxc);
        }while (c->col==maxc-1 || c->col==00 || c->row==0 ||c->row==1 ||        c->row==maxf-2 || c->row==maxf-1);
}

void in_coords(tcoords *cs) {

        int i,maxc,maxf;
        obtener_tamanyo_terminal(&maxf,&maxc); //maxf and maxc are assigned the value of the terminal

        //the snake is initialized in the center of the terminal
        for (i=0;i<cs->ncoords;i++){
                cs->coord[i].col=maxc/2-i;
                cs->coord[i].row=maxf/2;
        }
}

void insert_pos(tcoords *cs) {

        cs->ncoords++; //the size of the snake is increased

        //depending on the coords of the penultimate and antepenultimate part of the snake, the last part of the snake is initialized at specific coord
        if(cs->coord[cs->ncoords-2].row>cs->coord[cs->ncoords-3].row){
                cs->coord[cs->ncoords-1].row=cs->coord[cs->ncoords-2].row+1;
                cs->coord[cs->ncoords-1].col=cs->coord[cs->ncoords-2].col;
        }

        else if (cs->coord[cs->ncoords-2].row<cs->coord[cs->ncoords-3].row){
                cs->coord[cs->ncoords-1].row=cs->coord[cs->ncoords-2].row-1;
                cs->coord[cs->ncoords-1].col=cs->coord[cs->ncoords-2].col;
        }

        else if(cs->coord[cs->ncoords-2].col>cs->coord[cs->ncoords-3].col){
                cs->coord[cs->ncoords-1].col=cs->coord[cs->ncoords-2].col-1;
                cs->coord[cs->ncoords-1].row=cs->coord[cs->ncoords-2].row;
        }

        else if (cs->coord[cs->ncoords-2].col<cs->coord[cs->ncoords-3].col){
                cs->coord[cs->ncoords-1].col=cs->coord[cs->ncoords-2].col+1;
                cs->coord[cs->ncoords-1].row=cs->coord[cs->ncoords-2].row;
        }
}