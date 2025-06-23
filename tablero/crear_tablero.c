//
// Created by pruden on 23/06/25.
//

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