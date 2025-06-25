//
// Created by pruden on 25/06/25.
//

#include "lados_3x2.h"

#include "Pieza.h"
#include "tablero.h"


// d -> desplazamientos
// fc -> fila centro
// cc -> columna centro

void mover_derecha_3x2(Pieza *pieza,  const int *d, int sentido) { // -1 izq
    bool puede_moverse = false;

    int orientacion = pieza->orientacion;
    int fc = pieza->fila_centro;
    int cc = pieza->columna_centro;

    switch (orientacion) {
        case 0:
            puede_moverse =tablero[fc][cc+d[0]] == BLANCO
                        && tablero[fc-1][cc+d[1]] == BLANCO;
            break;
        case 1:
            puede_moverse =tablero[fc - 1][cc+d[4]] == BLANCO
                           && tablero[fc][cc+d[5]] == BLANCO
                           && tablero[fc + 1][cc+d[6]] == BLANCO;
            break;
        case 2:
            puede_moverse =tablero[fc][cc+d[2]] == BLANCO
                        && tablero[fc + 1][cc+d[3]] == BLANCO;
            break;
        case 3:
            puede_moverse =tablero[fc - 1][cc+d[7]] == BLANCO
                        && tablero[fc][cc+d[8]] == BLANCO
                        && tablero[fc + 1][cc+d[9]] == BLANCO;
            break;
        default:
            puede_moverse = false;
            break;
    }

    if (puede_moverse) {
        pieza->v_metodos->limpiar(pieza);
        pieza->col += sentido;
        pieza->v_metodos->pintar(pieza);
    }
}