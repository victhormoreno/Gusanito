#include "../include/Modules/juego.h"
#include <string.h>
#define UNDERLINE   "\e[4m"
#define REVERSE   "\e[7m"

void in_game(tgame *j) {

        clear_screen();

        printf_reset_color();
        printf_color(BOLD_BLUE);
        printf (REVERSE "FO-QT21-Bienvenido al Proyecto Gusanito!\n\n");
        printf_reset_color();
        printf (UNDERLINE "Este proyecto ha sido creado a manos de:\n" );
        printf_reset_color();
        printf ("\tNatalia Abellán (Secretaria del Grupo)\n");
        printf ("\tPol Buitrago\n");
        printf ("\tVíctor Moreno\n\n");
        printf_reset_color();
        printf ("\t-Flecha arriba (o tecla 'a')\n");
        printf ("\t-Flecha abajo (o tecla 'z')\n");
        printf ("\t-Flecha izquierda (o tecla 'o')\n");
        printf ("\t-Flecha derecha (o tecla 'p')\n");
        printf ("\t-Tecla 'q' (para cancelar)\n\n");
        printf ("Introduce la velocidad en pasos/seg [0: defecto 3 p/s N: <0 p/s]: ");
        scanf ("%u", &j->wait);
        printf ("Introduce el nombre del jugador: ");
        scanf ("%*c%31[^\n]%*c", &*j->t.s.name);
        

        //When the value entered is 0, by default it is equal to three
        if (j->wait==0)
                j->wait=3; 

}


void run_game(tgame *j) {

        in_board (&j->t); //initialize all board values
        assign_wall_board (&j->t);
        assign_fruit_board (&j->t);

        init_tecla_o_tictac(); //initialize the library tecla_o_tictac

        do {
                j->event = lee_tecla_o_tictac(DEFAULT_TIMEOUT/j->wait);
                //the function is passed the wait value entered by the player

                if (j->event==TIC_TAC) {

                        move_snake_board(&j->t);
                        j->event=read_data_board(j->t);
                        //the board is read in case there has been a crash

                        assign_snake_board(&j->t,j->event);
                        show_board (j->t);

                        time_board (&j->t.s,j->wait);
                }

                if (j->event==UP1 || j->event==UP2) {
                        if (j->t.s.dir!=S && j->t.s.dir!=N) {
                                //change the direction of the snake
                                j->t.s.dir=N;
                                move_snake_board(&j->t);
                                j->event=read_data_board(j->t);


                                assign_snake_board(&j->t,j->event);
                                show_board (j->t);
                        }
                }

                else if (j->event==DOWN1 || j->event==DOWN2 ) {
                        if (j->t.s.dir!=N && j->t.s.dir!=S) {
                                //change the direction of the snake
                                j->t.s.dir=S;
                                move_snake_board(&j->t);
                                j->event=read_data_board(j->t);

                                assign_snake_board(&j->t,j->event);
                                show_board (j->t);
                  }
                }

                else if (j->event==RIGHT1 || j->event==RIGHT2 ) {
                        if (j->t.s.dir!=O && j->t.s.dir!=E) {
                              //change the direction of the snake
                              j->t.s.dir=E;
                              move_snake_board(&j->t);
                              j->event=read_data_board(j->t);

                              assign_snake_board(&j->t,j->event);
                              show_board (j->t);
                  }
                }

                else if (j->event==LEFT1 || j->event==LEFT2) {
                        if (j->t.s.dir!=E && j->t.s.dir!=O) {
                              //change the direction of the snake
                              j->t.s.dir=O;
                              move_snake_board(&j->t);
                              j->event=read_data_board(j->t);

                              assign_snake_board(&j->t,j->event);
                              show_board (j->t);
                        }
                }

                if (j->t.s.coords.coord[0].row==j->t.fruit.row && j->t.s.coords.coord[0].col==j->t.fruit.col){

                        grow_snake(&j->t.s); //if the coordinates of the fruit and the worm are the same then
                        do{
                                assign_fruit_board (&j->t);
                                j->event=read_data_board(j->t);
                        } while (j->event==FRUIT_SNAKE_OVERLAPPED);
                }
        } while (j->event!=CANCEL && j->event!=CRASH);
        //CANCEL == 'q'
        
        //the function stops reading keys by the keyboard
        end_tecla_o_tictac();
}


void end_game(tgame j) {

        if (j.event==CRASH){
                printf("\n\nEl juego se ha acabado por 'CHOQUE' con los siguientes datos:\n");
        }

        if (j.event==CANCEL){
                printf("\n\nEl juego se ha acabado por 'CANCELACION' con los siguientes datos:\n");
        }

        printf ("\t\t-Nombre del jugador:     %s ", j.t.s.name);
        printf ("\n\t\t-Puntos obtenidos:       %u",j.t.s.score);
        printf ("\n\t\t-Tiempo de juego:        %02u mins %02u segs",j.t.s.m,j.t.s.s);
        printf ("\n\t\t-Tamanyo tablero:        %d filas x %d columnas",j.t.numf,j.t.numc);
        printf ("\n\t\t-Longitud gusano:        %u",j.t.s.coords.ncoords);
        printf ("\n\t\t-Velocidad del gusano:   %u pasos/seg\n\n", j.wait);
}
