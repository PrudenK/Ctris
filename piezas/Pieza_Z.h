//
// Created by pruden on 26/06/25.
//

#ifndef PIEZA_Z_H
#define PIEZA_Z_H
#include "Pieza.h"
typedef struct {
    Pieza base;
} Pieza_Z;

Pieza_Z *crear_pieza_Z(int fila, int col);
#endif //PIEZA_Z_H
