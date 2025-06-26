//
// Created by pruden on 26/06/25.
//

#ifndef PIEZA_L_H
#define PIEZA_L_H
#include "Pieza.h"
typedef struct {
    Pieza base;
} Pieza_L;

Pieza_L *crear_pieza_L(int fila, int col);
#endif //PIEZA_L_H
