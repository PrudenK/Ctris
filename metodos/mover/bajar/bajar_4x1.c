//
// Created by pruden on 26/06/25.
//

#include "bajar_4x1.h"

#include "Pieza.h"
#include "tablero.h"
#include "completar_linea/completar_linea.h"

bool bajar_4x1(Pieza *pieza) {
    bool puede_bajar = true;

    int orientacion = pieza->orientacion;

    int fc = pieza->fila_centro;
    int cc = pieza->columna_centro;

    switch (orientacion) {
        case 0:
            for (int i = -1; i<3; i++) {
                if (tablero[fc +1][cc +i] != 0) {
                    puede_bajar = false;
                    break;
                }
            }
            break;
        case 1:
            puede_bajar = tablero[fc +3][cc] == 0;
            break;
        case 2:
            for (int i = -2; i<2; i++) {
                if (tablero[fc +1][cc +i] != 0) {
                    puede_bajar = false;
                    break;
                }
            }
            break;
        case 3:
            puede_bajar = tablero[fc +2][cc] == 0;
            break;
        default:
            puede_bajar = false;
            break;
    }

    if (puede_bajar) {
        pieza->v_metodos->limpiar(pieza);
        pieza->fila += 1;
        pieza->v_metodos->pintar(pieza);
        return true;
    }else {
        borrar_linea();
    }
    return false;
}
