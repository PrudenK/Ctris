//
// Created by pruden on 26/06/25.
//

#ifndef PIEZA_S_H
#define PIEZA_S_H
#include "Pieza.h"
typedef struct {
    Pieza base;
} Pieza_S;

Pieza_S *crear_pieza_S(int fila, int col);
#endif //PIEZA_S_H
