#include "tablero/crear_tablero.h"
#include <unistd.h>

#include "utils/constantes.h"

int tablero[FILAS][COLUMNAS] = {0};


int main() {
    cargar_tablero_principal();



    for (int i = 0; i< 5; i++) {
        imprimir_tablero();
        usleep(1500000);
    }


    return 0;
}