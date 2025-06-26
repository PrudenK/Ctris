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
#include "mover/bajar/bajar_3x2.h"
#include "mover/lados/lados_3x2.h"
#include "mover/rotar/rotar_especial.h"
#include "mover/rotar/rotar_normal.h"


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

   pieza->fila_centro = fila_centro;
   pieza->columna_centro = col_centro;
}

static void limpiar_T(Pieza *pieza) {
    limpiar_pieza(pieza);
}

static bool rotar_T(Pieza *pieza) {
    return rotar_normal(pieza, 4);
}

static bool puede_rotar_T(Pieza *pieza, int nueva_orientacion) {
    pieza->condicion_especial = false;

    int cc = pieza->columna_centro;
    int fc = pieza->fila_centro;

    if (nueva_orientacion == 0) {
        if (cc != COLUMNAS -1) {
            if (tablero[fc][cc+1] == BLANCO) {
                return true;
            }else return condicion_rotar_especial(pieza, (int[]){ -1, 0 }, (int[]){ -1, -2 }, true, -1, 2);
        }else return condicion_rotar_especial(pieza,(int[]){-1, 0},(int[]){-1, -2}, true, -1, 2);
    }else if (nueva_orientacion == 1) {
        if (fc != FILAS - 1) {
            if (tablero[fc+1][cc] == BLANCO) {
                return true;
            }else return condicion_rotar_especial(pieza,(int[]){-2, -1},(int[]){0, 1}, false, -1, 2);
        }else return condicion_rotar_especial(pieza,(int[]){-2, -1},(int[]){0, 1}, false, -1, 2);
    }else if (nueva_orientacion == 2) {
        if (cc != 0) {
            if (tablero[fc][cc -1] == BLANCO) {
                return true;
            }else return condicion_rotar_especial(pieza,(int[]){1, 0},(int[]){1, 2}, true, +1, 2);
        }else return condicion_rotar_especial(pieza,(int[]){1, 0},(int[]){1, 2}, true, +1, 2);
    }else {
        if (fc != 0) {
            if (tablero[fc -1][cc] == BLANCO) {
                return true;
            }else return condicion_rotar_especial(pieza,(int[]){1, 2},(int[]){-1, 0}, false, +1, 2);
        }else return condicion_rotar_especial(pieza,(int[]){1, 2},(int[]){-1, 0}, false, +1, 2);
    }
}

static bool bajar_T(Pieza *pieza) {
    int d[] = {1, 1, 1, 1, 2, 1, 2, 1, 2, 1};
    return bajar_3x2(pieza, d);
}

static void derecha_T(Pieza *pieza) {
    int d[] = {2, 1, 2, 1, 1, 2, 1, 1, 1, 1};
    lados_3x2(pieza, d, 1);
}

static void izquierda_T(Pieza *pieza) {
    int d[] = {-2, -1, -2, -1, -1, -1, -1, -1, -2, -1};
    lados_3x2(pieza, d, -1);
}

void free_T(Pieza *pieza) {
    for (int r = 0; r < NUM_ROTACIONES_M_T; r++) {
        for (int i = 0; i < ALTO_M_T; i++) {
            free(pieza->formas[r][i]);
        }
        free(pieza->formas[r]);
    }
    free(pieza->formas);
}

static const PiezaMetodos metodos_T = {
    .pintar = pintar_T,
    .rotar = rotar_T,
    .limpiar = limpiar_T,
    .bajar = bajar_T,
    .derecha = derecha_T,
    .izquierda = izquierda_T,
    .free = free_T,
    .puede_rotar = puede_rotar_T
};

Pieza_T *crear_pieza_T(int fila, int col) {
    Pieza_T *pieza_T = malloc(sizeof(Pieza_T));
    if (!pieza_T) return NULL;

    pieza_T->base.v_metodos = &metodos_T;
    pieza_T->base.fila = fila;
    pieza_T->base.col = col;
    pieza_T->base.orientacion = 0;
    pieza_T->base.condicion_especial = false;



    int ***formas = malloc(NUM_ROTACIONES_M_T * sizeof(int**));
    for (int r = 0; r < NUM_ROTACIONES_M_T; r++) {
        formas[r] = malloc(ALTO_M_T * sizeof(int*));
        for (int i = 0; i < ALTO_M_T; i++) {
            formas[r][i] = malloc(ANCHO_M_T * sizeof(int));
            for (int j = 0; j < ANCHO_M_T; j++) {
                formas[r][i][j] = forma_T[r][i][j];
            }
        }
    }

    pieza_T->base.formas = formas;

    pieza_T->base.fila_centro = fila;
    pieza_T->base.columna_centro = col + 1;

    // Constantes BASE
    pieza_T->base.n_rotaciones_m = NUM_ROTACIONES_M_T;
    pieza_T->base.ancho_m = ANCHO_M_T;
    pieza_T->base.alto_m = ALTO_M_T;
    pieza_T->base.num_pieza = NUM_PIEZA_T;
    pieza_T->base.num_centro = CENTRO_T;

    strcpy(pieza_T->base.nombre, "Pieza_T");
    return pieza_T;
}