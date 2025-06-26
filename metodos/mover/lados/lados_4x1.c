//
// Created by pruden on 26/06/25.
//

#include "lados_4x1.h"

#include "Pieza.h"
#include "tablero.h"

void izquierda_4x1(Pieza *pieza) {
    bool puede_moverse = true;

    int orientacion = pieza->orientacion;

    int fc = pieza->fila_centro;
    int cc = pieza->columna_centro;

    switch (orientacion) {
        case 0:
            puede_moverse = tablero[fc][cc-2] == 0;
            break;
        case 1:
            for (int i = -1; i < 3; i++) {
                if (tablero[fc+i][cc-1] != 0) {
                    puede_moverse = false;
                    break;
                }
            }
            break;
        case 2:
            puede_moverse = tablero[fc][cc-3] == 0;
            break;
        case 3:
            for (int i = -2; i < 2; i++) {
                if (tablero[fc+i][cc-1] != 0) {
                    puede_moverse = false;
                    break;
                }
            }
            break;
        default:
            puede_moverse = false;
            break;
    }

    if (puede_moverse) {
        pieza->v_metodos->limpiar(pieza);
        pieza->col -= 1;
        pieza->v_metodos->pintar(pieza);
    }
}

void derecha_4x1(Pieza *pieza) {
    bool puede_moverse = true;

    int orientacion = pieza->orientacion;

    int fc = pieza->fila_centro;
    int cc = pieza->columna_centro;

    switch (orientacion) {
        case 0:
            puede_moverse = tablero[fc][cc+3] == 0;
            break;
        case 1:
            for (int i = -1; i < 3; i++) {
                if (tablero[fc+i][cc+1] != 0) {
                    puede_moverse = false;
                    break;
                }
            }
            break;
        case 2:
            puede_moverse = tablero[fc][cc+2] == 0;
            break;
        case 3:
            for (int i = -2; i < 2; i++) {
                if (tablero[fc+i][cc+1] != 0) {
                    puede_moverse = false;
                    break;
                }
            }
            break;
        default:
            puede_moverse = false;
            break;
    }

    if (puede_moverse) {
        pieza->v_metodos->limpiar(pieza);
        pieza->col += 1;
        pieza->v_metodos->pintar(pieza);
    }
}