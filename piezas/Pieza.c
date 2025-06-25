//
// Created by pruden on 23/06/25.
//

#include <stdbool.h>
#include <stdlib.h>
#include "Pieza.h"
#include <stdio.h>


void pintar_generico(Pieza *self) {
    printf("Pintando pieza en (%d, %d), orientación %d\n", self->fila, self->col, self->orientacion);
}

bool rotar_generico(Pieza *self) {
    printf("Rotando pieza en (%d, %d)\n", self->fila, self->col);
    return true;
}

void limpiar_generico(Pieza *self) {
    printf("Limpiando pieza en (%d, %d)\n", self->fila, self->col);
}

bool bajar_generico(Pieza *self) {
    printf("Bajar");
    return true;
}

void derecha_generico(Pieza *self) {
    printf("Derecha");
}

void izquierda_generico(Pieza *self) {
    printf("izquierda");
}

void free_generico(Pieza *self) {
    printf("Liberar memoria");
}

const PiezaMetodos metodos_base = {
    .pintar = pintar_generico,
    .rotar = rotar_generico,
    .limpiar = limpiar_generico,
    .bajar = bajar_generico,
    .derecha = derecha_generico,
    .izquierda = izquierda_generico,
    .free = free_generico
};

Pieza *crear_pieza_base(int fila, int col) {
    Pieza *p = malloc(sizeof(Pieza));
    if (!p) return NULL;

    p->v_metodos = &metodos_base;
    p->fila = fila;
    p->col = col;
    p->orientacion = 0;
    p->condicion_especial = false;

    return p;
}
