//
// Created by pruden on 26/06/25.
//

#include "rotar_normal.h"

#include "Pieza.h"

bool rotar_normal(Pieza *pieza, int mod) {
    int nueva_orientacion = (pieza->orientacion + 1) % mod;

    if (pieza->v_metodos->puede_rotar(pieza, nueva_orientacion)) {
        if (!pieza->condicion_especial) {
            pieza->v_metodos->limpiar(pieza);
        }
        pieza->orientacion = nueva_orientacion;
        pieza->v_metodos->pintar(pieza);
        return true;
    }
    return false;
}
