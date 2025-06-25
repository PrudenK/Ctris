//
// Created by pruden on 25/06/25.
//

#include "bajar_3x2.h"

#include <stdbool.h>
#include <stdio.h>

#include "Pieza.h"
#include "tablero.h"


// d -> desplazamientos
// fc -> fila centro
// cc -> columna centro

bool bajar_3x2(Pieza *pieza, const int *d) {
    bool puede_bajar = true;

    int orientacion = pieza->orientacion;

    int fc = pieza->fila_centro;
    int cc = pieza->columna_centro;

    switch (orientacion) {
        case 0:
            puede_bajar =   tablero[fc+d[0]][cc - 1] == BLANCO
                        && tablero[fc+d[1]][cc] == BLANCO
                        && tablero[fc+d[2]][cc + 1] == BLANCO;
            break;
        case 1:
            puede_bajar =  tablero[fc+d[6]][cc - 1] == BLANCO
                           && tablero[fc+d[7]][cc + 1] == BLANCO;
            break;
        case 2:
            puede_bajar =   tablero[fc+d[3]][cc - 1] == BLANCO
                        && tablero[fc+d[4]][cc] == BLANCO
                        && tablero[fc+d[5]][cc + 1] == BLANCO;
            break;
        case 3:
            puede_bajar =  tablero[fc+d[6]][cc - 1] == BLANCO
                        && tablero[fc+d[7]][cc + 1] == BLANCO;
            break;
        default:
            puede_bajar = false;
            break;
    }

    if (puede_bajar) {
        pieza->v_metodos->limpiar(pieza);
        pieza->fila += 1;
        pieza->v_metodos->pintar(pieza);
        return true;
    }else {
        // TODO borrar línea
    }
    return false;

}
