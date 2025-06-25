#include <stdio.h>

#include "tablero/crear_tablero.h"
#include <unistd.h>

#include "piezas/Pieza.h"
#include "piezas/Pieza_T.h"
#include "utils/constantes.h"

int tablero[FILAS][COLUMNAS] = {0};


int main() {

    cargar_tablero_principal();

    Pieza *pieza = (Pieza *)crear_pieza_T(0, 4);


    for (int i = 0; i< 5; i++) {

        pieza->v_metodos->pintar(pieza);
        imprimir_tablero();
        usleep(1500000);
        pieza->v_metodos->limpiar(pieza);
        pieza->fila +=1;
    }

    pieza->v_metodos->free(pieza);


    return 0;
}