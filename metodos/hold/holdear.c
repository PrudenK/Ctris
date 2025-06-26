//
// Created by pruden on 26/06/25.
//

#include "holdear.h"

#include <stddef.h>
#include <string.h>

#include "constantes.h"
#include "crear_tablero.h"
#include "Pieza_I.h"
#include "Pieza_J.h"
#include "Pieza_L.h"
#include "Pieza_O.h"
#include "Pieza_S.h"
#include "Pieza_T.h"
#include "Pieza_Z.h"
#include "teclado.h"

void holdear() {
    if (!puedes_holdear) return;

    pieza->v_metodos->limpiar(pieza);

    if (pieza_hold == NULL) {
        pieza_hold = pieza;
        nueva_pieza(); // Genera una nueva desde bolsa
    } else {
        Pieza *tmp = pieza;
        pieza->v_metodos->free(pieza);

        if (strcmp(pieza_hold->nombre, "Pieza_I") == 0) {
            pieza = (Pieza *)crear_pieza_I(-1, COLUMNAS / 2);
        } else if (strcmp(pieza_hold->nombre, "Pieza_O") == 0) {
            pieza = (Pieza *)crear_pieza_O(-1, COLUMNAS / 2);
        } else if (strcmp(pieza_hold->nombre, "Pieza_T") == 0) {
            pieza = (Pieza *)crear_pieza_T(-1, COLUMNAS / 2);
        } else if (strcmp(pieza_hold->nombre, "Pieza_S") == 0) {
            pieza = (Pieza *)crear_pieza_S(-1, COLUMNAS / 2);
        } else if (strcmp(pieza_hold->nombre, "Pieza_Z") == 0) {
            pieza = (Pieza *)crear_pieza_Z(-1, COLUMNAS / 2);
        } else if (strcmp(pieza_hold->nombre, "Pieza_L") == 0) {
            pieza = (Pieza *)crear_pieza_L(-1, COLUMNAS / 2);
        } else if (strcmp(pieza_hold->nombre, "Pieza_J") == 0) {
            pieza = (Pieza *)crear_pieza_J(-1, COLUMNAS / 2);
        }

        pieza_hold = tmp;
    }

    pieza->v_metodos->pintar(pieza);
    imprimir_tablero();
    puedes_holdear = false;
}
