//
// Created by pruden on 23/06/25.
//

#include <stdio.h>

#include "tablero.h"
#include "../utils/constantes.h"

void cargar_tablero_principal() {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (i == FILAS - 1) {
                tablero[i][j] = SUELO;
            } else if (j == 0 || j == COLUMNAS - 1) {
                tablero[i][j] = 9; // Pared lateral
            } else {
                tablero[i][j] = 0;
            }
        }
    }
}


void imprimir_tablero() {
    for (int i = 0; i < FILAS; i++) {
        printf("\033[H\033[J");
    }

    printf("TABLERO DE LA HOSTIA\n");

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (tablero[i][j] == 9) {
                printf("\033[90m%d\033[0m ", tablero[i][j]);
            }else if (tablero[i][j] == 3) {
                printf("\033[95m%d\033[0m ", tablero[i][j]);
            }else {
                printf("%d ", tablero[i][j]);
            }
        }
        printf("\n");
    }
}