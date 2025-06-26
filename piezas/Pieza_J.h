//
// Created by pruden on 26/06/25.
//

#ifndef PIEZA_J_H
#define PIEZA_J_H
#include "Pieza.h"
typedef struct {
    Pieza base;
} Pieza_J;

Pieza_J *crear_pieza_J(int fila, int col);
#endif //PIEZA_J_H
