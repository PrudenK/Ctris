#include "utils/constantes.h"
#include "tablero/crear_tablero.h"
#include <unistd.h>

int main() {
    int tablero[FILAS][COLUMNAS] = {0};

    cargar_tablero_principal(tablero);



    for (int i = 0; i< 5; i++) {
        imprimir_tablero(tablero);
        usleep(1500000);
    }


    return 0;
}
