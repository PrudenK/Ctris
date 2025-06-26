//
// Created by pruden on 26/06/25.
//

#include "Pieza_I.h"


#include "Pieza_I.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "bajar_4x1.h"
#include "../tablero/tablero.h"
#include "../metodos/piezas/pintar/pintar.h"
#include "../metodos/piezas/limpiar/limpiar.h"
#include "mover/bajar/bajar_3x2.h"
#include "mover/lados/lados_3x2.h"
#include "mover/lados/lados_4x1.h"
#include "mover/rotar/rotar_especial.h"
#include "mover/rotar/rotar_normal.h"


#define NUM_PIEZA_I 2
#define CENTRO_I 28
#define NUM_ROTACIONES_M_I 4
#define ANCHO_M_I 4
#define ALTO_M_I 4

static int forma_I[NUM_ROTACIONES_M_I][ANCHO_M_I][ALTO_M_I] = {
    {
        {BLANCO, BLANCO, BLANCO, BLANCO},
        {NUM_PIEZA_I, CENTRO_I, NUM_PIEZA_I, NUM_PIEZA_I},
        {BLANCO, BLANCO, BLANCO, BLANCO},
        {BLANCO, BLANCO, BLANCO, BLANCO}
    },
    {
        {BLANCO, BLANCO, NUM_PIEZA_I, BLANCO},
        {BLANCO, BLANCO, CENTRO_I, BLANCO},
        {BLANCO, BLANCO, NUM_PIEZA_I, BLANCO},
        {BLANCO, BLANCO, NUM_PIEZA_I, BLANCO}
    },
    {
        {BLANCO, BLANCO, BLANCO, BLANCO},
        {BLANCO, BLANCO, BLANCO, BLANCO},
        {NUM_PIEZA_I, NUM_PIEZA_I, CENTRO_I, NUM_PIEZA_I},
        {BLANCO, BLANCO, BLANCO, BLANCO}
    },
    {
        {BLANCO, NUM_PIEZA_I, BLANCO, BLANCO},
        {BLANCO, NUM_PIEZA_I, BLANCO, BLANCO},
        {BLANCO, CENTRO_I, BLANCO, BLANCO},
        {BLANCO, NUM_PIEZA_I, BLANCO, BLANCO}
    }
};

static void pintar_I(Pieza *pieza) {
    int fila_centro = -1, col_centro = -1;
    pintar(pieza, &fila_centro, &col_centro);

   pieza->fila_centro = fila_centro;
   pieza->columna_centro = col_centro;
}

static void limpiar_I(Pieza *pieza) {
    limpiar_pieza(pieza);
}

static bool rotar_I(Pieza *pieza) {
    return rotar_normal(pieza, 4);
}

static bool puede_rotar_I(Pieza *pieza, int nueva_orientacion) {
    pieza->condicion_especial = false;

    int cc = pieza->columna_centro;
    int fc = pieza->fila_centro;

    if (nueva_orientacion == 0) {
        if (cc <= COLUMNAS - 3 && cc != 0) {
            if (tablero[fc - 1][cc - 1] == BLANCO
                && tablero[fc - 1][cc + 1] == BLANCO
                && tablero[fc - 1][cc + 2] == BLANCO) {
                    return true;
            } else {
                if (tablero[fc - 1][cc + 1] != BLANCO) { // para el caso R0-2
                    return condicion_rotar_especial(pieza,(int[]){-1, -1, -1},(int[]){-1, -2, -3}, true, -2, 3);
                } else if (tablero[fc - 1][cc + 2] != 0) { // para el caso R0-1
                    return condicion_rotar_especial(pieza,(int[]){-1, -1, -1},(int[]){1, -1, -2}, true, -1, 3);
                }
                return condicion_rotar_especial(pieza,(int[]){-1, -1, -1},(int[]){1, 2, 3}, true, +1, 3);
            }
        } else {
            if (cc == COLUMNAS - 2) {
                if (tablero[fc - 1][cc + 1] != BLANCO) {
                    return condicion_rotar_especial(pieza,(int[]){-1, -1, -1},(int[]){-1, -2, -3}, true, -2, 3);
                } else return condicion_rotar_especial(pieza,(int[]){-1, -1, -1},(int[]){-1, -2, 1}, true, -1, 3);
            } else if (cc == COLUMNAS - 1) {
                return condicion_rotar_especial(pieza,(int[]){-1, -1, -1},(int[]){-1, -2, -3}, true, -2, 3);
            } else return condicion_rotar_especial(pieza,(int[]){-1, -1, -1},(int[]){1, 2, 3}, true, +1, 3);
        }
    } else if (nueva_orientacion == 1) {
        if (fc <= FILAS - 3 && fc != 0) {
            if (tablero[fc - 1][cc + 1] == BLANCO
                && tablero[fc + 1][cc + 1] == BLANCO
                && tablero[fc + 2][cc + 1] == BLANCO) {
                return true;
            } else {
                if (tablero[fc + 1][cc + 1] != BLANCO) { // R1-2
                    return condicion_rotar_especial(pieza,(int[]){-1, -2, -3},(int[]){1, 1, 1}, false, -2, 3);
                } else if (tablero[fc + 2][cc + 1] != BLANCO) { // Para R1-1
                    return condicion_rotar_especial(pieza,(int[]){1, -1, -2},(int[]){1, 1, 1}, false, -1, 3);
                } else return condicion_rotar_especial(pieza,(int[]){1, 2, 3},(int[]){1, 1, 1},  false, +1, 3); // R1+1 (punto conflictivo (-1,1))
            }
        } else {
            if (fc == FILAS - 2) {
                if (tablero[fc + 1][cc + 1] != BLANCO) { // R1-2
                    return condicion_rotar_especial(pieza,(int[]){-1, -2, -3},(int[]){1, 1, 1}, false, -2, 3);
                } else return condicion_rotar_especial(pieza,(int[]){1, -1, -2},(int[]){1, 1, 1}, false, -1, 3);
            } else if (fc == FILAS - 1) {
                return condicion_rotar_especial(pieza,(int[]){-1, -2, -3},(int[]){1, 1, 1}, false, -2, 3);
            } else return condicion_rotar_especial(pieza,(int[]){-1, 1, 2},(int[]){1, 1, 1}, false, +1, 3);
        }
    } else if (nueva_orientacion == 2) {
        if (cc >= 2 && cc != COLUMNAS - 1) {
            if (tablero[fc + 1][cc - 2] == BLANCO
                && tablero[fc + 1][cc - 1] == BLANCO
                && tablero[fc + 1][cc + 1] == BLANCO) {
                return true;
            } else {
                if (tablero[fc + 1][cc - 1] != BLANCO) { // R2+2
                    return condicion_rotar_especial(pieza,(int[]){1, 1, 1},(int[]){1, 2, 3}, true, +2, 3);
                } else if (tablero[fc + 1][cc - 2] != 0) { // R2+1
                    return condicion_rotar_especial(pieza,(int[]){1, 1, 1},(int[]){-1, 1, 2}, true, +1, 3);
                } else return condicion_rotar_especial(pieza,(int[]){1, 1, 1},(int[]){-1, -2, -3}, true, -1, 3);
            }
        } else {
            if (cc == 0) {
                return condicion_rotar_especial(pieza,(int[]){1, 1, 1},(int[]){1, 2, 3}, true, +2, 3);
            } else if (cc == 1) {
                if (tablero[fc + 1][cc - 1] != BLANCO) { // R2+2
                    return condicion_rotar_especial(pieza,(int[]){1, 1, 1},(int[]){1, 2, 3}, true, +2, 3);
                } else return condicion_rotar_especial(pieza,(int[]){1, 1, 1},(int[]){-1, 1, 2}, true, +1, 3);
            } else return condicion_rotar_especial(pieza,(int[]){1, 1, 1},(int[]){-1, -2, -3}, true, -1, 3);
        }
    } else {
        if (fc >= 2 && fc != FILAS - 1) {
            if (tablero[fc + 1][cc - 1] == BLANCO
                && tablero[fc - 1][cc - 1] == BLANCO
                && tablero[fc - 2][cc - 1] == BLANCO) {
                return true;
            } else {
                if (tablero[fc - 1][cc - 1] != BLANCO) {
                    return condicion_rotar_especial(pieza,(int[]){1, 2, 3},(int[]){-1, -1, -1}, false, +2, 3);
                } else if (tablero[fc - 2][cc - 1] != BLANCO) {
                    return condicion_rotar_especial(pieza,(int[]){-1, 1, 2},(int[]){-1, -1, -1}, false, +1, 3);
                } else return condicion_rotar_especial(pieza,(int[]){-1, -2, -3},(int[]){-1, -1, -1}, false, -1, 3);
            }
        } else {
            if (fc == 0) { //Aquí omito una situación ilógica q en las otras si que tengo en cuenta
                return condicion_rotar_especial(pieza,(int[]){1, 2, 3},(int[]){-1, -1, -1}, false, +2, 3);
            } else if (fc == 1) {
                return condicion_rotar_especial(pieza,(int[]){-1, 1, 2},(int[]){-1, -1, -1}, false, +1, 3);
            } else return condicion_rotar_especial(pieza,(int[]){-1, -2, -3},(int[]){-1, -1, -1}, false, -1, 3);
        }
    }
}

static bool bajar_I(Pieza *pieza) {
    return bajar_4x1(pieza);
}

static void derecha_I(Pieza *pieza) {
    derecha_4x1(pieza);
}

static void izquierda_I(Pieza *pieza) {
    izquierda_4x1(pieza);
}

void free_I(Pieza *pieza) {
    for (int r = 0; r < NUM_ROTACIONES_M_I; r++) {
        for (int i = 0; i < ALTO_M_I; i++) {
            free(pieza->formas[r][i]);
        }
        free(pieza->formas[r]);
    }
    free(pieza->formas);
}

static const PiezaMetodos metodos_I = {
    .pintar = pintar_I,
    .rotar = rotar_I,
    .limpiar = limpiar_I,
    .bajar = bajar_I,
    .derecha = derecha_I,
    .izquierda = izquierda_I,
    .free = free_I,
    .puede_rotar = puede_rotar_I
};

Pieza_I *crear_pieza_I(int fila, int col) {
    Pieza_I *pieza_I = malloc(sizeof(Pieza_I));
    if (!pieza_I) return NULL;

    pieza_I->base.v_metodos = &metodos_I;
    pieza_I->base.fila = fila;
    pieza_I->base.col = col;
    pieza_I->base.orientacion = 0;
    pieza_I->base.condicion_especial = false;



    int ***formas = malloc(NUM_ROTACIONES_M_I * sizeof(int**));
    for (int r = 0; r < NUM_ROTACIONES_M_I; r++) {
        formas[r] = malloc(ALTO_M_I * sizeof(int*));
        for (int i = 0; i < ALTO_M_I; i++) {
            formas[r][i] = malloc(ANCHO_M_I * sizeof(int));
            for (int j = 0; j < ANCHO_M_I; j++) {
                formas[r][i][j] = forma_I[r][i][j];
            }
        }
    }

    pieza_I->base.formas = formas;

    pieza_I->base.fila_centro = fila;
    pieza_I->base.columna_centro = col + 1;

    // Constantes BASE
    pieza_I->base.n_rotaciones_m = NUM_ROTACIONES_M_I;
    pieza_I->base.ancho_m = ANCHO_M_I;
    pieza_I->base.alto_m = ALTO_M_I;
    pieza_I->base.num_pieza = NUM_PIEZA_I;
    pieza_I->base.num_centro = CENTRO_I;

    strcpy(pieza_I->base.nombre, "Pieza_I");
    return pieza_I;
}