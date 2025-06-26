//
// Created by pruden on 26/06/25.
//

#include "Pieza_O.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "bajar_2x2.h"
#include "../tablero/tablero.h"
#include "../metodos/piezas/pintar/pintar.h"
#include "../metodos/piezas/limpiar/limpiar.h"
#include "mover/bajar/bajar_3x2.h"
#include "mover/lados/lados_3x2.h"
#include "mover/rotar/rotar_especial.h"
#include "mover/rotar/rotar_normal.h"


#define NUM_PIEZA_O 1
#define CENTRO_O 18
#define NUM_ROTACIONES_M_O 1
#define ANCHO_M_O 2
#define ALTO_M_O 2

static int forma_O[NUM_ROTACIONES_M_O][ANCHO_M_O][ALTO_M_O] = {
    {   // Centro
        {CENTRO_O, NUM_PIEZA_O},
        {NUM_PIEZA_O, NUM_PIEZA_O},
    }
};

static void pintar_O(Pieza *pieza) {
    int fila_centro = -1, col_centro = -1;
    pintar(pieza, &fila_centro, &col_centro);

   pieza->fila_centro = fila_centro;
   pieza->columna_centro = col_centro;
}

static void limpiar_O(Pieza *pieza) {
    limpiar_pieza(pieza);
}

static bool rotar_O(Pieza *pieza) {
    return true;
}

static bool puede_rotar_O(Pieza *pieza, int nueva_orientacion) {
    return true;
}

static bool bajar_O(Pieza *pieza) {
    int d[] = {2,2};
    return bajar_2x2(pieza, d);
}

static void derecha_O(Pieza *pieza) {
    if (pieza->col != COLUMNAS - 2) {
        if (!(tablero[pieza->fila][pieza->col + 2] != 0 || tablero[pieza->fila + 1][pieza->col + 2] != 0)) {
            pieza->v_metodos->limpiar(pieza);
            pieza->col += 1;
            pieza->v_metodos->pintar(pieza);
        }
    }
}

static void izquierda_O(Pieza *pieza) {
    if (pieza->col > 0) {
        if (!(tablero[pieza->fila][pieza->col - 1] != 0 || tablero[pieza->fila + 1][pieza->col - 1] != 0)) {
            pieza->v_metodos->limpiar(pieza);
            pieza->col -= 1;
            pieza->v_metodos->pintar(pieza);
        }
    }
}

void free_O(Pieza *pieza) {
    for (int r = 0; r < NUM_ROTACIONES_M_O; r++) {
        for (int i = 0; i < ALTO_M_O; i++) {
            free(pieza->formas[r][i]);
        }
        free(pieza->formas[r]);
    }
    free(pieza->formas);
}

static const PiezaMetodos metodos_O = {
    .pintar = pintar_O,
    .rotar = rotar_O,
    .limpiar = limpiar_O,
    .bajar = bajar_O,
    .derecha = derecha_O,
    .izquierda = izquierda_O,
    .free = free_O,
    .puede_rotar = puede_rotar_O
};

Pieza_O *crear_pieza_O(int fila, int col) {
    Pieza_O *pieza_O = malloc(sizeof(Pieza_O));
    if (!pieza_O) return NULL;

    pieza_O->base.v_metodos = &metodos_O;
    pieza_O->base.fila = fila;
    pieza_O->base.col = col;
    pieza_O->base.orientacion = 0;
    pieza_O->base.condicion_especial = false;



    int ***formas = malloc(NUM_ROTACIONES_M_O * sizeof(int**));
    for (int r = 0; r < NUM_ROTACIONES_M_O; r++) {
        formas[r] = malloc(ALTO_M_O * sizeof(int*));
        for (int i = 0; i < ALTO_M_O; i++) {
            formas[r][i] = malloc(ANCHO_M_O * sizeof(int));
            for (int j = 0; j < ANCHO_M_O; j++) {
                formas[r][i][j] = forma_O[r][i][j];
            }
        }
    }

    pieza_O->base.formas = formas;

    pieza_O->base.fila_centro = fila;
    pieza_O->base.columna_centro = col + 1;

    // Constantes BASE
    pieza_O->base.n_rotaciones_m = NUM_ROTACIONES_M_O;
    pieza_O->base.ancho_m = ANCHO_M_O;
    pieza_O->base.alto_m = ALTO_M_O;
    pieza_O->base.num_pieza = NUM_PIEZA_O;
    pieza_O->base.num_centro = CENTRO_O;

    strcpy(pieza_O->base.nombre, "Pieza_O");
    return pieza_O;
}