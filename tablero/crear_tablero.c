//
// Created by pruden on 23/06/25.
//

#include <stdio.h>

#include "bolsa_piezas.h"
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
    printf("\033[H\033[J");  // Limpia pantalla
    printf("  TABLERO DE LA HOSTIA\n\n");

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            imprimir_celda(tablero[i][j]);
        }

        printf("    ");

        switch (i) {
            case 7:
                printf("Siguiente pieza: %s", pieza_siguiente->nombre);
                break;
            case FILAS -5:
                printf("Nivel: %d", nivel);
                break;
            case FILAS -3:
                printf("Líneas: %d", lineas);
                break;
            case FILAS -1:
                printf("Puntuación: %d", puntuacion);
                break;
            default:
                break;
        }

        printf("\n");
    }
}



void imprimir_celda(int valor) {
    switch (valor) {
        case 0:
            printf("  ");
            break;
        case 1:
            printf("\033[48;5;226m  \033[0m");
            break;
        case 2:
            printf("\033[48;5;51m  \033[0m");
            break;
        case 3:
            printf("\033[45m  \033[0m");
            break;
        case 4:
            printf("\033[44m  \033[0m");
            break;
        case 5:
            printf("\033[43m  \033[0m");
            break;
        case 6:
            printf("\033[48;5;10m  \033[0m");
            break;
        case 7:
            printf("\033[41m  \033[0m");
            break;
        case 9:
            printf("\033[100m  \033[0m");
            break;
        default:
            printf("\033[41m??\033[0m");
            break;
    }
}
