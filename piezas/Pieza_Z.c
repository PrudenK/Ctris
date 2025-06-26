//
// Created by pruden on 26/06/25.
//

#include "Pieza_Z.h"
#include <stdlib.h>
#include <string.h>
#include "../tablero/tablero.h"
#include "../metodos/piezas/pintar/pintar.h"
#include "../metodos/piezas/limpiar/limpiar.h"
#include "mover/bajar/bajar_3x2.h"
#include "mover/lados/lados_3x2.h"
#include "mover/rotar/rotar_especial.h"
#include "mover/rotar/rotar_normal.h"


#define NUM_PIEZA_Z 7
#define CENTRO_Z 78
#define NUM_ROTACIONES_M_Z 4
#define ANCHO_M_Z 3
#define ALTO_M_Z 3

static int forma_Z[NUM_ROTACIONES_M_Z][ANCHO_M_Z][ALTO_M_Z] = {
    {
        {NUM_PIEZA_Z, NUM_PIEZA_Z, BLANCO},
        {BLANCO, CENTRO_Z, NUM_PIEZA_Z},
        {BLANCO, BLANCO, BLANCO}
    },
    {
        {BLANCO, BLANCO, NUM_PIEZA_Z},
        {BLANCO, CENTRO_Z, NUM_PIEZA_Z},
        {BLANCO, NUM_PIEZA_Z, BLANCO}
    },
    {
        {BLANCO, BLANCO, BLANCO},
        {NUM_PIEZA_Z, CENTRO_Z, BLANCO},
        {BLANCO, NUM_PIEZA_Z, NUM_PIEZA_Z}
    },
    {
        {BLANCO, NUM_PIEZA_Z, BLANCO},
        {NUM_PIEZA_Z, CENTRO_Z, BLANCO},
        {NUM_PIEZA_Z, BLANCO, BLANCO}
    }
};

static void pintar_Z(Pieza *pieza) {
    int fila_centro = -1, col_centro = -1;
    pintar(pieza, &fila_centro, &col_centro);

   pieza->fila_centro = fila_centro;
   pieza->columna_centro = col_centro;
}

static void limpiar_Z(Pieza *pieza) {
    limpiar_pieza(pieza);
}

static bool rotar_Z(Pieza *pieza) {
    return rotar_normal(pieza, 4);
}

static bool puede_rotar_Z(Pieza *pieza, int nueva_orientacion) {
    pieza->condicion_especial = false;

    int cc = pieza->columna_centro;
    int fc = pieza->fila_centro;

    if (nueva_orientacion == 0) {
        if (cc != COLUMNAS - 1) {
            if (tablero[fc - 1][cc - 1] == BLANCO
                && tablero[fc][cc + 1] == BLANCO) {
                return true;
            } else return condicion_rotar_especial(pieza,(int[]){-1, -1},(int[]){-2, -1}, true, -1, 2);
        } else return condicion_rotar_especial(pieza,(int[]){-1, -1},(int[]){-2, -1}, true, -1, 2);
    } else if (nueva_orientacion == 1) {
        if (fc != FILAS - 1) {
            if (tablero[fc - 1][cc + 1] == BLANCO
                && tablero[fc + 1][cc] == BLANCO) {
                return true;
            } else return condicion_rotar_especial(pieza,(int[]){-1, -2},(int[]){1, 1}, false, -1, 2);
        } else return condicion_rotar_especial(pieza,(int[]){-1, -2},(int[]){1, 1}, false, -1, 2);
    } else if (nueva_orientacion == 2) {
        if (cc != 0) {
            if (tablero[fc][cc - 1] == BLANCO
                && tablero[fc + 1][cc + 1] == BLANCO) {
                return true;
            } else return condicion_rotar_especial(pieza,(int[]){1, 1},(int[]){1, 2}, true, +1, 2);
        } else return condicion_rotar_especial(pieza,(int[]){1, 1},(int[]){1, 2}, true, +1, 2);
    } else {
        if (fc != 0) {
            if (tablero[fc - 1][cc] == BLANCO
                && tablero[fc + 1][cc - 1] == BLANCO) {
                return true;
            } else return condicion_rotar_especial(pieza,(int[]){1, 2},(int[]){-1, -1}, false, +1, 2);
        } else return condicion_rotar_especial(pieza,(int[]){1, 2},(int[]){-1, -1}, false, +1, 2);
    }
}

static bool bajar_Z(Pieza *pieza) {
    int d[] = {0, 1, 1, 1, 2, 2, 2, 1, 1, 2};
    return bajar_3x2(pieza, d);
}

static void derecha_Z(Pieza *pieza) {
    int d[] = {2, 1, 1, 2, 2, 2, 1, 1, 1, 0};
    lados_3x2(pieza, d, 1);
}

static void izquierda_Z(Pieza *pieza) {
    int d[] = {-1, -2, -2, -1, 0, -1, -1, -1, -2, -2};
    lados_3x2(pieza, d, -1);
}

void free_Z(Pieza *pieza) {
    for (int r = 0; r < NUM_ROTACIONES_M_Z; r++) {
        for (int i = 0; i < ALTO_M_Z; i++) {
            free(pieza->formas[r][i]);
        }
        free(pieza->formas[r]);
    }
    free(pieza->formas);
}

static const PiezaMetodos metodos_Z = {
    .pintar = pintar_Z,
    .rotar = rotar_Z,
    .limpiar = limpiar_Z,
    .bajar = bajar_Z,
    .derecha = derecha_Z,
    .izquierda = izquierda_Z,
    .free = free_Z,
    .puede_rotar = puede_rotar_Z
};

Pieza_Z *crear_pieza_Z(int fila, int col) {
    Pieza_Z *pieza_Z = malloc(sizeof(Pieza_Z));
    if (!pieza_Z) return NULL;

    pieza_Z->base.v_metodos = &metodos_Z;
    pieza_Z->base.fila = fila;
    pieza_Z->base.col = col;
    pieza_Z->base.orientacion = 0;
    pieza_Z->base.condicion_especial = false;



    int ***formas = malloc(NUM_ROTACIONES_M_Z * sizeof(int**));
    for (int r = 0; r < NUM_ROTACIONES_M_Z; r++) {
        formas[r] = malloc(ALTO_M_Z * sizeof(int*));
        for (int i = 0; i < ALTO_M_Z; i++) {
            formas[r][i] = malloc(ANCHO_M_Z * sizeof(int));
            for (int j = 0; j < ANCHO_M_Z; j++) {
                formas[r][i][j] = forma_Z[r][i][j];
            }
        }
    }

    pieza_Z->base.formas = formas;

    pieza_Z->base.fila_centro = fila;
    pieza_Z->base.columna_centro = col + 1;

    // Constantes BASE
    pieza_Z->base.n_rotaciones_m = NUM_ROTACIONES_M_Z;
    pieza_Z->base.ancho_m = ANCHO_M_Z;
    pieza_Z->base.alto_m = ALTO_M_Z;
    pieza_Z->base.num_pieza = NUM_PIEZA_Z;
    pieza_Z->base.num_centro = CENTRO_Z;

    strcpy(pieza_Z->base.nombre, "Pieza_Z");
    return pieza_Z;
}