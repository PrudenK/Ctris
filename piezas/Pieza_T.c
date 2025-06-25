//
// Created by pruden on 23/06/25.
//
#include "Pieza_T.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#define NUM_PIEZA_T 3
#define CENTRO_T 38
#define COLOR_T 'T'
#define BLANCO 0

static int forma_T[4][3][3] = {
    {
        {BLANCO, NUM_PIEZA_T, BLANCO},
        {NUM_PIEZA_T, CENTRO_T, NUM_PIEZA_T},
        {BLANCO, BLANCO, BLANCO}
    },
    {
        {BLANCO, NUM_PIEZA_T, BLANCO},
        {BLANCO, CENTRO_T, NUM_PIEZA_T},
        {BLANCO, NUM_PIEZA_T, BLANCO}
    },
    {
        {BLANCO, BLANCO, BLANCO},
        {NUM_PIEZA_T, CENTRO_T, NUM_PIEZA_T},
        {BLANCO, NUM_PIEZA_T, BLANCO}
    },
    {
        {BLANCO, NUM_PIEZA_T, BLANCO},
        {NUM_PIEZA_T, CENTRO_T, BLANCO},
        {BLANCO, NUM_PIEZA_T, BLANCO}
    }
};

static void pintar_T(Pieza *pieza) {
    Pieza_T *self = (Pieza_T *)pieza;
    printf("Pintando Pieza_T en (%d, %d) orientación %d\n",
           pieza->fila, pieza->col, pieza->orientacion);
    self->filaCentro = pieza->fila;
    self->columnaCentro = pieza->col + 1;
}

static bool rotar_T(Pieza *pieza) {
    pieza->orientacion = (pieza->orientacion + 1) % 4;
    return true;
}

static void limpiar_T(Pieza *pieza) {
    printf("Limpiando Pieza_T\n");
}

// VTable específica
static const PiezaMetodos metodos_T = {
    .pintar = pintar_T,
    .rotar = rotar_T,
    .limpiar = limpiar_T
};

// Constructor
Pieza_T *crear_pieza_T(int fila, int col) {
    Pieza_T *pieza_T = malloc(sizeof(Pieza_T));
    if (!pieza_T) return NULL;

    pieza_T->base.v_metodos = &metodos_T;
    pieza_T->base.fila = fila;
    pieza_T->base.col = col;
    pieza_T->base.orientacion = 0;
    pieza_T->base.condicion_especial = false;
    pieza_T->base.formas = (int ***)forma_T;
    pieza_T->base.num_pieza = NUM_PIEZA_T;
    pieza_T->base.num_centro = CENTRO_T;

    pieza_T->filaCentro = fila;
    pieza_T->columnaCentro = col + 1;

    strcpy(pieza_T->base.nombre, "Pieza_T");
    return pieza_T;
}
