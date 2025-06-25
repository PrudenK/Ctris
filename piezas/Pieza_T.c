//
// Created by pruden on 23/06/25.
//
#include "Pieza_T.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../tablero/tablero.h"
#include "../metodos/piezas/pintar/pintar.h"
#include "../metodos/piezas/limpiar/limpiar.h"


#define NUM_PIEZA_T 3
#define CENTRO_T 38
#define COLOR_T 'T'
#define BLANCO 0
#define NUM_ROTACIONES_M_T 4
#define ANCHO_M_T 3
#define ALTO_M_T 3

static int forma_T[NUM_ROTACIONES_M_T][ANCHO_M_T][ALTO_M_T] = {
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
    int fila_centro = -1, col_centro = -1;
    pintar(pieza, &fila_centro, &col_centro);

    ((Pieza_T *)pieza)->fila_centro = fila_centro;
    ((Pieza_T *)pieza)->columna_centro = col_centro;
}

static bool rotar_T(Pieza *pieza) {
    pieza->orientacion = (pieza->orientacion + 1) % 4;
    return true;
}

static void limpiar_T(Pieza *pieza) {
    limpiar_pieza(pieza);
}

static bool bajar_T(Pieza *pieza) {
    Pieza_T *self = (Pieza_T *)pieza;
    return true;
}

static void derecha_T(Pieza *pieza) {
    Pieza_T *self = (Pieza_T *)pieza;
}

static void izquierda_T(Pieza *pieza) {
    Pieza_T *self = (Pieza_T *)pieza;
}

static const PiezaMetodos metodos_T = {
    .pintar = pintar_T,
    .rotar = rotar_T,
    .limpiar = limpiar_T,
    .bajar = bajar_T,
    .derecha = derecha_T,
    .izquierda = izquierda_T
};

Pieza_T *crear_pieza_T(int fila, int col) {
    Pieza_T *pieza_T = malloc(sizeof(Pieza_T));
    if (!pieza_T) return NULL;

    pieza_T->base.v_metodos = &metodos_T;
    pieza_T->base.fila = fila;
    pieza_T->base.col = col;
    pieza_T->base.orientacion = 0;
    pieza_T->base.condicion_especial = false;
    pieza_T->base.formas = (int ***)forma_T;

    pieza_T->fila_centro = fila;
    pieza_T->columna_centro = col + 1;

    // Constantes BASE
    pieza_T->base.n_rotaciones_m = NUM_ROTACIONES_M_T;
    pieza_T->base.ancho_m = ANCHO_M_T;
    pieza_T->base.alto_m = ALTO_M_T;
    pieza_T->base.num_pieza = NUM_PIEZA_T;
    pieza_T->base.num_centro = CENTRO_T;

    strcpy(pieza_T->base.nombre, "Pieza_T");
    return pieza_T;
}
