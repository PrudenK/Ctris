//
// Created by pruden on 26/06/25.
//

#ifndef PIEZA_O_H
#define PIEZA_O_H
#include "Pieza.h"
typedef struct {
    Pieza base;
} Pieza_O;

Pieza_O *crear_pieza_O(int fila, int col);
#endif //PIEZA_O_H
