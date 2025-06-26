//
// Created by pruden on 26/06/25.
//

#include "rotar_especial.h"

#include <stdbool.h>
#include <stddef.h>

#include "Pieza.h"
#include "tablero.h"

bool condicion_rotar_especial(
    Pieza *pieza,
    const int *d_filas,
    const int *d_columnas,
    bool columna_b,
    int movimiento,
    size_t tama
) {
    bool condicion = true;

    for (int i = 0; i < tama; i++) {
        if (tablero[pieza->fila_centro + d_filas[i]][pieza->columna_centro + d_columnas[i]] != BLANCO) {
            condicion = false;
            break;
        }
    }
    if (condicion) {
        pieza->v_metodos->limpiar(pieza);
        if (columna_b) {
            pieza->col += movimiento;
        }else {
            pieza->fila += movimiento;
        }
        pieza->condicion_especial = true;
        return true;
    }
    return false;
}
