//
// Created by pruden on 26/06/25.
//

#include "completar_linea.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#include "constantes.h"
#include "tablero.h"

typedef struct {
    int *filas;
    size_t size;
} LineasABorrar;

static LineasABorrar filas_que_hay_que_borrar();
static void actualizar_puntuacion_al_completar_linea(int num_lineas);
int lineas_borradas = 0;

void borrar_linea() {
    LineasABorrar lineas_que_borrar = filas_que_hay_que_borrar();
    lineas_borradas += lineas_que_borrar.size;

    if (lineas_borradas > 0) {
        lineas += (int)lineas_que_borrar.size;
        actualizar_puntuacion_al_completar_linea(lineas_que_borrar.size);

        for (size_t i = 0; i < lineas_que_borrar.size; i++) {
            int fila = lineas_que_borrar.filas[i];
            for (int j = fila; j > 0; j--) {
                for (int col = 0; col < COLUMNAS; col++) {
                    tablero[j][col] = tablero[j - 1][col];
                }
            }

            for (int col = 0; col < COLUMNAS; col++) {
                if (col == 0 || col == COLUMNAS - 1) {
                    tablero[0][col] = SUELO;
                }else {
                    tablero[0][col] = BLANCO;
                }
            }
        }
    }

    free(lineas_que_borrar.filas);
}

void reiniciar_lineas_borradas() {
    lineas_borradas = 0;
}

static LineasABorrar filas_que_hay_que_borrar() {
    LineasABorrar resultado;
    resultado.filas = malloc(FILAS * sizeof(int));
    resultado.size = 0;

    for (int i = 0; i < FILAS - 1; i++) { // -1 y me salto la última
        bool llena = true;
        for (int j = 0; j < COLUMNAS; j++) {
            if (tablero[i][j] == BLANCO) {
                llena = false;
                break;
            }
        }
        if (llena) {
            resultado.filas[resultado.size++] = i;
        }
    }

    return resultado;
}

static void actualizar_puntuacion_al_completar_linea(int num_lineas) {
    switch (num_lineas) {
        case 1: puntuacion+= 100; break;
        case 2: puntuacion+= 300; break;
        case 3: puntuacion+= 500; break;
        case 4: puntuacion+= 800; break;
        default:
    }
}