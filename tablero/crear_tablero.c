//
// Created by pruden on 23/06/25.
//

#include <stdio.h>
#include <string.h>

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

void imprimir_siguientes_fila(int fila) {
    printf(" ");
    Pieza *siguientes[] = { pieza_siguiente_1, pieza_siguiente_2, pieza_siguiente_3 };
    for (int k = 0; k < 3; k++) {
        int limite = strcmp(siguientes[k]->nombre, "Pieza_I") == 0 ? 4 : 3;
        if (fila == 2 && strcmp(siguientes[k]->nombre, "Pieza_O") == 0) {
            printf("      ");
        } else {
            for (int j = 0; j < limite; j++) {
                imprimir_celda(siguientes[k]->formas[0][fila][j]);
            }
        }
        printf("    ");
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
            case FILAS - 20:
                printf("     Siguientes piezas");
                break;
            case FILAS - 18:
                imprimir_siguientes_fila(0);
                break;
            case FILAS - 17:
                imprimir_siguientes_fila(1);
                break;
            case FILAS - 16:
                imprimir_siguientes_fila(2);
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
        case 18:
            printf("\033[48;5;226m  \033[0m");
            break;
        case 2:
        case 28:
            printf("\033[48;5;51m  \033[0m");
            break;
        case 3:
        case 38:
            printf("\033[45m  \033[0m");
            break;
        case 4:
        case 48:
            printf("\033[44m  \033[0m");
            break;
        case 5:
        case 58:
            printf("\033[43m  \033[0m");
            break;
        case 6:
        case 68:
            printf("\033[48;5;10m  \033[0m");
            break;
        case 7:
        case 78:
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
