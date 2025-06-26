//
// Created by pruden on 26/06/25.
//

#ifndef PIEZA_I_H
#define PIEZA_I_H
#include "Pieza.h"
typedef struct {
    Pieza base;
} Pieza_I;

Pieza_I *crear_pieza_I(int fila, int col);
#endif //PIEZA_I_H
