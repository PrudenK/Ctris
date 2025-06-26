//
// Created by pruden on 26/06/25.
//

#ifndef ROTAR_ESPECIAL_H
#define ROTAR_ESPECIAL_H
#include <stdbool.h>
#include <stddef.h>

#include "Pieza.h"

bool condicion_rotar_especial(
    Pieza *pieza,
    const int *d_filas,
    const int *d_columnas,
    bool columna_b,
    int movimiento,
    size_t tama
);

#endif //ROTAR_ESPECIAL_H
