/*      PROYECTO GUSANITO
        
        Creado por:
         -Natalia Abellán
         -Pol Buitrago
         -Víctor Moreno
        
        Fecha entrega 30/12/2020
*/

#include <stdio.h>
#include "../include/Modules/juego.h"


int main () {

        tgame j;

        in_game (&j);
        run_game(&j);
        end_game(j);

}