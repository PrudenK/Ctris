#ifndef PIEZA_H
#define PIEZA_H

#include <stdbool.h>

typedef struct Pieza Pieza;

typedef struct {
    void (*pintar)(Pieza *self);
    bool (*rotar)(Pieza *self);
    void (*limpiar)(Pieza *self);
    bool (*bajar)(Pieza *self);
    void (*derecha)(Pieza *self);
    void (*izquierda)(Pieza *self);
    void (*free)(Pieza *self);
} PiezaMetodos;

struct Pieza {
    const PiezaMetodos *v_metodos;
    char nombre[50];
    int num_pieza, num_centro;
    int fila, col;
    int orientacion;
    int ***formas;
    int ancho_m, alto_m, n_rotaciones_m;
    bool condicion_especial;
};

Pieza *crear_pieza_base(int fila, int col);

#endif
