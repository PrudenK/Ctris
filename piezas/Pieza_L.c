//
// Created by pruden on 26/06/25.
//

#include "Pieza_L.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../tablero/tablero.h"
#include "../metodos/piezas/pintar/pintar.h"
#include "../metodos/piezas/limpiar/limpiar.h"
#include "mover/bajar/bajar_3x2.h"
#include "mover/lados/lados_3x2.h"
#include "mover/rotar/rotar_especial.h"
#include "mover/rotar/rotar_normal.h"


#define NUM_PIEZA_L 4
#define CENTRO_L 48
#define COLOR_L 'T'
#define NUM_ROTACIONES_M_L 4
#define ANCHO_M_L 3
#define ALTO_M_L 3

static int forma_L[NUM_ROTACIONES_M_L][ANCHO_M_L][ALTO_M_L] = {
    {
        {BLANCO, BLANCO, NUM_PIEZA_L},
        {NUM_PIEZA_L, CENTRO_L, NUM_PIEZA_L},
        {BLANCO, BLANCO, BLANCO}
    },
    {
        {BLANCO, NUM_PIEZA_L, BLANCO},
        {BLANCO, CENTRO_L, BLANCO},
        {BLANCO, NUM_PIEZA_L, NUM_PIEZA_L}
    },
    {
        {BLANCO, BLANCO, BLANCO},
        {NUM_PIEZA_L, CENTRO_L, NUM_PIEZA_L},
        {NUM_PIEZA_L, BLANCO, BLANCO}
    },
    {
        {NUM_PIEZA_L, NUM_PIEZA_L, BLANCO},
        {BLANCO, CENTRO_L, BLANCO},
        {BLANCO, NUM_PIEZA_L, BLANCO}
    }
};

static void pintar_L(Pieza *pieza) {
    int fila_centro = -1, col_centro = -1;
    pintar(pieza, &fila_centro, &col_centro);

   pieza->fila_centro = fila_centro;
   pieza->columna_centro = col_centro;
}

static void limpiar_L(Pieza *pieza) {
    limpiar_pieza(pieza);
}

static bool rotar_L(Pieza *pieza) {
    return rotar_normal(pieza, 4);
}

static bool puede_rotar_L(Pieza *pieza, int nueva_orientacion) {
    pieza->condicion_especial = false;

    int cc = pieza->columna_centro;
    int fc = pieza->fila_centro;

    if (nueva_orientacion == 0) {
        if (cc != COLUMNAS - 1) {
            if (tablero[fc - 1][cc + 1] == BLANCO
                && tablero[fc][cc - 1] == BLANCO
                && tablero[fc][cc + 1] == BLANCO) {
                return true;
                } else return condicion_rotar_especial(pieza,(int[]){0, 0},(int[]){-1, -2}, true, -1, 2);
        } else return condicion_rotar_especial(pieza,(int[]){0, 0},(int[]){-1, -2}, true, -1, 2);
    } else if (nueva_orientacion == 1) {
        if (fc != FILAS - 1) {
            if (tablero[fc - 1][cc] == BLANCO
                && tablero[fc + 1][cc] == BLANCO
                && tablero[fc + 1][cc + 1] == BLANCO
            ) {
                return true;
            } else return condicion_rotar_especial(pieza,(int[]){-2, -1},(int[]){0, 0}, false, -1, 2);
        } else return condicion_rotar_especial(pieza,(int[]){-2, -1},(int[]){0, 0}, false, -1, 2);
    } else if (nueva_orientacion == 2) {
        if (cc != 0) {
            if (tablero[fc + 1][cc - 1] == BLANCO
                && tablero[fc][cc - 1] == BLANCO
                && tablero[fc][cc + 1] == BLANCO
            ) {
                return true;
            } else return condicion_rotar_especial(pieza,(int[]){0, 0},(int[]){1, 2}, true, +1, 2);
        }else return condicion_rotar_especial(pieza,(int[]){0, 0},(int[]){1, 2}, true, +1, 2);
    } else {
        if (fc != 0) {
            if (tablero[fc - 1][cc - 1] == BLANCO
                && tablero[fc - 1][cc] == BLANCO
                && tablero[fc + 1][cc] == BLANCO) {
                return true;
            } else return condicion_rotar_especial(pieza,(int[]){1, 2},(int[]){0, 0}, false, +1, 2);
        } else return condicion_rotar_especial(pieza,(int[]){1, 2},(int[]){0, 0}, false, +1, 2);
    }
}

static bool bajar_L(Pieza *pieza) {
    int d[] = {1, 1, 1, 2, 1, 1, 2, 2, 2, 0};
    return bajar_3x2(pieza, d);
}

static void derecha_L(Pieza *pieza) {
    int d[] = {2, 2, 2, 0, 1, 1, 2, 1, 1, 1};
    lados_3x2(pieza, d, 1);
}

static void izquierda_L(Pieza *pieza) {
    int d[] = {-2, 0, -2, -2, -1, -1, -1, -2, -1, -1};
    lados_3x2(pieza, d, -1);
}

void free_L(Pieza *pieza) {
    for (int r = 0; r < NUM_ROTACIONES_M_L; r++) {
        for (int i = 0; i < ALTO_M_L; i++) {
            free(pieza->formas[r][i]);
        }
        free(pieza->formas[r]);
    }
    free(pieza->formas);
}

static const PiezaMetodos metodos_L = {
    .pintar = pintar_L,
    .rotar = rotar_L,
    .limpiar = limpiar_L,
    .bajar = bajar_L,
    .derecha = derecha_L,
    .izquierda = izquierda_L,
    .free = free_L,
    .puede_rotar = puede_rotar_L
};

Pieza_L *crear_pieza_L(int fila, int col) {
    Pieza_L *pieza_L = malloc(sizeof(Pieza_L));
    if (!pieza_L) return NULL;

    pieza_L->base.v_metodos = &metodos_L;
    pieza_L->base.fila = fila;
    pieza_L->base.col = col;
    pieza_L->base.orientacion = 0;
    pieza_L->base.condicion_especial = false;



    int ***formas = malloc(NUM_ROTACIONES_M_L * sizeof(int**));
    for (int r = 0; r < NUM_ROTACIONES_M_L; r++) {
        formas[r] = malloc(ALTO_M_L * sizeof(int*));
        for (int i = 0; i < ALTO_M_L; i++) {
            formas[r][i] = malloc(ANCHO_M_L * sizeof(int));
            for (int j = 0; j < ANCHO_M_L; j++) {
                formas[r][i][j] = forma_L[r][i][j];
            }
        }
    }

    pieza_L->base.formas = formas;

    pieza_L->base.fila_centro = fila;
    pieza_L->base.columna_centro = col + 1;

    // Constantes BASE
    pieza_L->base.n_rotaciones_m = NUM_ROTACIONES_M_L;
    pieza_L->base.ancho_m = ANCHO_M_L;
    pieza_L->base.alto_m = ALTO_M_L;
    pieza_L->base.num_pieza = NUM_PIEZA_L;
    pieza_L->base.num_centro = CENTRO_L;

    strcpy(pieza_L->base.nombre, "Pieza_L");
    return pieza_L;
}