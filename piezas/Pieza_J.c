//
// Created by pruden on 26/06/25.
//

#include "Pieza_J.h"
#include <stdlib.h>
#include <string.h>
#include "../tablero/tablero.h"
#include "../metodos/piezas/pintar/pintar.h"
#include "../metodos/piezas/limpiar/limpiar.h"
#include "mover/bajar/bajar_3x2.h"
#include "mover/lados/lados_3x2.h"
#include "mover/rotar/rotar_especial.h"
#include "mover/rotar/rotar_normal.h"


#define NUM_PIEZA_J 5
#define CENTRO_J 58
#define COLOR_J 'J'
#define NUM_ROTACIONES_M_J 4
#define ANCHO_M_J 3
#define ALTO_M_J 3

static int forma_J[NUM_ROTACIONES_M_J][ANCHO_M_J][ALTO_M_J] = {
    {
        {NUM_PIEZA_J, BLANCO, BLANCO},
        {NUM_PIEZA_J, CENTRO_J, NUM_PIEZA_J},
        {BLANCO, BLANCO, BLANCO}
    },
    {
        {BLANCO, NUM_PIEZA_J, NUM_PIEZA_J},
        {BLANCO, CENTRO_J, BLANCO},
        {BLANCO, NUM_PIEZA_J, BLANCO}
    },
    {
        {BLANCO, BLANCO, BLANCO},
        {NUM_PIEZA_J, CENTRO_J, NUM_PIEZA_J},
        {BLANCO, BLANCO, NUM_PIEZA_J}
    },
    {
        {BLANCO, NUM_PIEZA_J, BLANCO},
        {BLANCO, CENTRO_J, BLANCO},
        {NUM_PIEZA_J, NUM_PIEZA_J, BLANCO}
    }
};

static void pintar_J(Pieza *pieza) {
    int fila_centro = -1, col_centro = -1;
    pintar(pieza, &fila_centro, &col_centro);

    pieza->fila_centro = fila_centro;
    pieza->columna_centro = col_centro;
}

static void limpiar_J(Pieza *pieza) {
    limpiar_pieza(pieza);
}

static bool rotar_J(Pieza *pieza) {
    return rotar_normal(pieza, 4);
}

static bool puede_rotar_J(Pieza *pieza, int nueva_orientacion) {
    pieza->condicion_especial = false;

    int cc = pieza->columna_centro;
    int fc = pieza->fila_centro;

    if (nueva_orientacion == 0) {
        if (cc != COLUMNAS - 1) {
            if (tablero[fc - 1][cc - 1] == BLANCO
                && tablero[fc][cc - 1] == BLANCO
                && tablero[fc][cc + 1] == BLANCO) {
                    return true;
                } else return condicion_rotar_especial(pieza,(int[]){-1, 0, 0},(int[]){-2, -2, -1}, true, -1, 3);
        } else return condicion_rotar_especial(pieza,(int[]){-1, 0, 0},(int[]){-2, -2, -1}, true, -1, 3);
    } else if (nueva_orientacion == 1) {
        if (fc != FILAS - 1) {
            if (tablero[fc - 1][cc] == BLANCO
            && tablero[fc + 1][cc] == BLANCO
            && tablero[fc - 1][cc + 1] == BLANCO) {
                return true;
            } else return condicion_rotar_especial(pieza,(int[]){-2, -1, -2},(int[]){0, 0, 1}, false, -1, 3);
        } else return condicion_rotar_especial(pieza,(int[]){-2, -1, -2},(int[]){0, 0, 1}, false, -1, 3);
    } else if (nueva_orientacion == 2) {
        if (cc != 0) {
            if (tablero[fc + 1][cc + 1] == BLANCO
                && tablero[fc][cc - 1] == BLANCO
                && tablero[fc][cc + 1] == BLANCO) {
                return true;
                } else return condicion_rotar_especial(pieza,(int[]){0, 0, 1},(int[]){1, 2, 2}, true, +1, 3);
        } else return condicion_rotar_especial(pieza,(int[]){0, 0, 1},(int[]){1, 2, 2}, true, +1, 3);
    } else {
        if (fc != 0) {
            if (tablero[fc + 1][cc - 1] == BLANCO
                && tablero[fc - 1][cc] == BLANCO
                && tablero[fc + 1][cc] == BLANCO) {
                return true;
                } else return condicion_rotar_especial(pieza,(int[]){2, 2, 1},(int[]){-1, 0, 0}, false, +1, 3);
        } else return condicion_rotar_especial(pieza,(int[]){2, 2, 1},(int[]){-1, 0, 0}, false, +1, 3);
    }
}

static bool bajar_J(Pieza *pieza) {
    int d[] = {1, 1, 1, 1, 1, 2, 2, 0, 2, 2};
    return bajar_3x2(pieza, d);
}

static void derecha_J(Pieza *pieza) {
    int d[] = {2, 0, 2, 2, 2, 1, 1, 1, 1, 1};
    lados_3x2(pieza, d, 1);
}

static void izquierda_J(Pieza *pieza) {
    int d[] = {-2, -2, -2, 0, -1, -1, -1, -1, -1, -2};
    lados_3x2(pieza, d, -1);
}

void free_J(Pieza *pieza) {
    for (int r = 0; r < NUM_ROTACIONES_M_J; r++) {
        for (int i = 0; i < ALTO_M_J; i++) {
            free(pieza->formas[r][i]);
        }
        free(pieza->formas[r]);
    }
    free(pieza->formas);
}

static const PiezaMetodos metodos_J = {
    .pintar = pintar_J,
    .rotar = rotar_J,
    .limpiar = limpiar_J,
    .bajar = bajar_J,
    .derecha = derecha_J,
    .izquierda = izquierda_J,
    .free = free_J,
    .puede_rotar = puede_rotar_J
};

Pieza_J *crear_pieza_J(int fila, int col) {
    Pieza_J *pieza_J = malloc(sizeof(Pieza_J));
    if (!pieza_J) return NULL;

    pieza_J->base.v_metodos = &metodos_J;
    pieza_J->base.fila = fila;
    pieza_J->base.col = col;
    pieza_J->base.orientacion = 0;
    pieza_J->base.condicion_especial = false;



    int ***formas = malloc(NUM_ROTACIONES_M_J * sizeof(int**));
    for (int r = 0; r < NUM_ROTACIONES_M_J; r++) {
        formas[r] = malloc(ALTO_M_J * sizeof(int*));
        for (int i = 0; i < ALTO_M_J; i++) {
            formas[r][i] = malloc(ANCHO_M_J * sizeof(int));
            for (int j = 0; j < ANCHO_M_J; j++) {
                formas[r][i][j] = forma_J[r][i][j];
            }
        }
    }

    pieza_J->base.formas = formas;

    pieza_J->base.fila_centro = fila;
    pieza_J->base.columna_centro = col + 1;

    // Constantes BASE
    pieza_J->base.n_rotaciones_m = NUM_ROTACIONES_M_J;
    pieza_J->base.ancho_m = ANCHO_M_J;
    pieza_J->base.alto_m = ALTO_M_J;
    pieza_J->base.num_pieza = NUM_PIEZA_J;
    pieza_J->base.num_centro = CENTRO_J;

    strcpy(pieza_J->base.nombre, "Pieza_J");
    return pieza_J;
}