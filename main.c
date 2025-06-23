#include <stdio.h>

#include "utils/constantes.h"
#include "tablero/crear_tablero.h"

int main() {
    int tablero[FILAS][COLUMNAS] = {0};

    cargar_tablero_principal(tablero);

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%d ", tablero[i][j]);
        }
        printf("\n");
    }

    return 0;
}
