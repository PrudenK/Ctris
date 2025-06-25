//
// Created by pruden on 25/06/25.
//

#include "pintar.h"

#include "constantes.h"
#include "tablero.h"

void pintar(Pieza *pieza, int *fila_centro, int *col_centro) {
    int **forma = pieza->formas[pieza->orientacion];

    for (int i = 0; i < pieza->alto_m; i++) {
        for (int j = 0; j < pieza->ancho_m; j++) {
            if (forma[i][j] != BLANCO) {
                if (forma[i][j] == pieza->num_centro) {
                    tablero[pieza->fila + i][pieza->col + j] = pieza->num_pieza; // ANTES ERA CENTRO
                    if (fila_centro) *fila_centro = pieza->fila + i;
                    if (col_centro) *col_centro = pieza->col + j;
                }else {
                    tablero[pieza->fila + i][pieza->col + j] = pieza->num_pieza;
                }
            }
        }
    }
}