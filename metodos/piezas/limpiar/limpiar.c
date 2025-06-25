//
// Created by pruden on 25/06/25.
//

#include "limpiar.h"

#include "Pieza.h"
#include "../tablero/tablero.h"
void limpiar_pieza(Pieza *pieza) {
    for (int i = 0; i < pieza->alto_m; i++) {
        for (int j = 0; j < pieza->ancho_m; j++) {
            if (tablero[i][j] == pieza->num_pieza || tablero[i][j] == pieza->num_centro) {
                tablero[pieza->fila + i][pieza->col + j] = BLANCO;
            }
        }
    }
}
