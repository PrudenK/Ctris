//
// Created by pruden on 23/06/25.
//

#include <stdio.h>

#include "tablero.h"
#include "../utils/constantes.h"


void imprimir_celda(int valor);


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

    printf("  TABLERO DE LA HOSTIA\n\n");


    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            imprimir_celda(tablero[i][j]);
        }
        printf("\n");
    }
}


void imprimir_celda(int valor) {
    switch (valor) {
        case 0:
            printf("  ");
            break;
        case 3:
            printf("\033[45m  \033[0m");
            break;
        case 5:
            printf("\033[43m  \033[0m");
            break;
            break;
        case 9:
            printf("\033[100m  \033[0m");
            break;
        default:
            printf("\033[41m??\033[0m");
            break;
    }
}
