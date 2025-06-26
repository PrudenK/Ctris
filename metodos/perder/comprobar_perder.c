//
// Created by pruden on 26/06/25.
//

#include "comprobar_perder.h"
#include <stdbool.h>
#include "constantes.h"
#include "tablero.h"

static bool verificar_perder();

bool comprobar_perder() {
    if (verificar_perder()) {
        has_perdido = true;
        return true;
    }
    return false;
}

static bool verificar_perder() {
    for (int c = 1; c < COLUMNAS-1; c++) {
        if (tablero[0][c] != BLANCO) {
            return true;
        }
    }

    return false;
}