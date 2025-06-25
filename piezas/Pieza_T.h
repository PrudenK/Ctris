//
// Created by pruden on 25/06/25.
//

#ifndef PIEZA_T_H
#define PIEZA_T_H
#include "Pieza.h"
typedef struct {
    Pieza base;
    int filaCentro;
    int columnaCentro;
} Pieza_T;

Pieza_T *crear_pieza_T(int fila, int col);
#endif //PIEZA_T_H
