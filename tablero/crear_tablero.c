//
// Created by pruden on 23/06/25.
//

#include <stdio.h>
#include "../utils/constantes.h"


void cargar_tablero_principal(int tablero[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (i == FILAS -1) {
                tablero[i][j] = SUELO;
            }else {
                tablero[i][j] = 0;
            }
        }
    }
}

void imprimir_tablero(int tablero[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        printf("\033[H\033[J");
    }


    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%d ", tablero[i][j]);
        }
        printf("\n");
    }
}