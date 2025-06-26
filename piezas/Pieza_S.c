//
// Created by pruden on 26/06/25.
//

#include "Pieza_S.h"
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


#define NUM_PIEZA_S 6
#define CENTRO_S 68
#define COLOR_S 'T'
#define NUM_ROTACIONES_M_S 4
#define ANCHO_M_S 3
#define ALTO_M_S 3

static int forma_S[NUM_ROTACIONES_M_S][ANCHO_M_S][ALTO_M_S] = {
    {
        {BLANCO, NUM_PIEZA_S, NUM_PIEZA_S},
        {NUM_PIEZA_S, CENTRO_S, BLANCO},
        {BLANCO, BLANCO, BLANCO}
    },
    {
        {BLANCO, NUM_PIEZA_S, BLANCO},
        {BLANCO, CENTRO_S, NUM_PIEZA_S},
        {BLANCO, BLANCO, NUM_PIEZA_S}
    },
    {
        {BLANCO, BLANCO, BLANCO},
        {BLANCO, CENTRO_S, NUM_PIEZA_S},
        {NUM_PIEZA_S, NUM_PIEZA_S, BLANCO}
    },
    {
        {NUM_PIEZA_S, BLANCO, BLANCO},
        {NUM_PIEZA_S, CENTRO_S, BLANCO},
        {BLANCO, NUM_PIEZA_S, BLANCO}
    }
};

static void pintar_S(Pieza *pieza) {
    int fila_centro = -1, col_centro = -1;
    pintar(pieza, &fila_centro, &col_centro);

   pieza->fila_centro = fila_centro;
   pieza->columna_centro = col_centro;
}

static void limpiar_S(Pieza *pieza) {
    limpiar_pieza(pieza);
}

static bool rotar_S(Pieza *pieza) {
    return rotar_normal(pieza, 4);
}

static bool puede_rotar_S(Pieza *pieza, int nueva_orientacion) {
    pieza->condicion_especial = false;

    int cc = pieza->columna_centro;
    int fc = pieza->fila_centro;

    if (nueva_orientacion == 0) {
        if (cc != COLUMNAS - 1) {
            if (tablero[fc - 1][cc] == BLANCO
                && tablero[fc - 1][cc + 1] == BLANCO) {
                return true;
                } else return condicion_rotar_especial(pieza,(int[]){0, -1},(int[]){-2, 0}, true, -1, 2);
        } else return condicion_rotar_especial(pieza,(int[]){0, -1},(int[]){-2, 0}, true, -1, 2);
    } else if (nueva_orientacion == 1) {
        if (fc != FILAS - 1) {
            if (tablero[fc][cc + 1] == BLANCO
                && tablero[fc + 1][cc + 1] == BLANCO) {
                return true;
            } else return condicion_rotar_especial(pieza,(int[]){-2, 0},(int[]){0, 1}, false, -1, 2);
        } else return condicion_rotar_especial(pieza,(int[]){-2, 0},(int[]){0, 1}, false, -1, 2);
    } else if (nueva_orientacion == 2) {
        if (cc != 0) {
            if (tablero[fc + 1][cc] == BLANCO
                && tablero[fc + 1][cc - 1] == BLANCO) {
                return true;
            } else return condicion_rotar_especial(pieza,(int[]){1, 0},(int[]){0, 2}, true, +1, 2);
        } else return condicion_rotar_especial(pieza,(int[]){1, 0},(int[]){0, 2}, true, +1, 2);
    } else {
        if (fc != 0) {
            if (tablero[fc][cc - 1] == BLANCO
                && tablero[fc - 1][cc - 1] == BLANCO) {
                return true;
            } else return condicion_rotar_especial(pieza,(int[]){0, 2},(int[]){-1, 0}, false, +1, 2);
        } else return condicion_rotar_especial(pieza,(int[]){0, 2},(int[]){-1, 0}, false, +1, 2);
    }
}

static bool bajar_S(Pieza *pieza) {
    int d[] = {1, 1, 0, 2, 2, 1, 1, 2, 2, 1};
    return bajar_3x2(pieza, d);
}

static void derecha_S(Pieza *pieza) {
    int d[] = {1, 2, 2, 1, 1, 2, 2, 0, 1, 1};
    lados_3x2(pieza, d, 1);
}

static void izquierda_S(Pieza *pieza) {
    int d[] = {-2, -1, -1, -2, -1, -1, 0, -2, -2, -1};
    lados_3x2(pieza, d, -1);
}

void free_S(Pieza *pieza) {
    for (int r = 0; r < NUM_ROTACIONES_M_S; r++) {
        for (int i = 0; i < ALTO_M_S; i++) {
            free(pieza->formas[r][i]);
        }
        free(pieza->formas[r]);
    }
    free(pieza->formas);
}

static const PiezaMetodos metodos_S = {
    .pintar = pintar_S,
    .rotar = rotar_S,
    .limpiar = limpiar_S,
    .bajar = bajar_S,
    .derecha = derecha_S,
    .izquierda = izquierda_S,
    .free = free_S,
    .puede_rotar = puede_rotar_S
};

Pieza_S *crear_pieza_S(int fila, int col) {
    Pieza_S *pieza_S = malloc(sizeof(Pieza_S));
    if (!pieza_S) return NULL;

    pieza_S->base.v_metodos = &metodos_S;
    pieza_S->base.fila = fila;
    pieza_S->base.col = col;
    pieza_S->base.orientacion = 0;
    pieza_S->base.condicion_especial = false;



    int ***formas = malloc(NUM_ROTACIONES_M_S * sizeof(int**));
    for (int r = 0; r < NUM_ROTACIONES_M_S; r++) {
        formas[r] = malloc(ALTO_M_S * sizeof(int*));
        for (int i = 0; i < ALTO_M_S; i++) {
            formas[r][i] = malloc(ANCHO_M_S * sizeof(int));
            for (int j = 0; j < ANCHO_M_S; j++) {
                formas[r][i][j] = forma_S[r][i][j];
            }
        }
    }

    pieza_S->base.formas = formas;

    pieza_S->base.fila_centro = fila;
    pieza_S->base.columna_centro = col + 1;

    // Constantes BASE
    pieza_S->base.n_rotaciones_m = NUM_ROTACIONES_M_S;
    pieza_S->base.ancho_m = ANCHO_M_S;
    pieza_S->base.alto_m = ALTO_M_S;
    pieza_S->base.num_pieza = NUM_PIEZA_S;
    pieza_S->base.num_centro = CENTRO_S;

    strcpy(pieza_S->base.nombre, "Pieza_S");
    return pieza_S;
}