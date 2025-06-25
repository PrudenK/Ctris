//
// Created by pruden on 25/06/25.
//

#include "limpiar.h"

#include <stdio.h>

#include "tablero.h"

void limpiar_pieza(Pieza *pieza) {
    int **forma = pieza->formas[pieza->orientacion];
    for (int i = 0; i < pieza->alto_m; i++) {
        for (int j = 0; j < pieza->ancho_m; j++) {
            if (forma[i][j] == pieza->num_pieza || forma[i][j] == pieza->num_centro) {
                tablero[pieza->fila + i][pieza->col + j] = BLANCO;
            }
        }
    }
}
