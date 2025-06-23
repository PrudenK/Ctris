#include <stdio.h>

#include "utils/constantes.h"
#include "tablero/crear_tablero.h"

int main() {
    int tablero[FILAS][COLUMNAS] = {0};

    cargar_tablero_principal(tablero);

    imprimir_tablero(tablero);

    return 0;
}
