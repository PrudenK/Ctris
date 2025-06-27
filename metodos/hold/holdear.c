//
// Created by pruden on 26/06/25.
//

#include "holdear.h"

#include <stddef.h>
#include <string.h>

#include "bolsa_piezas.h"
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
        copia_pieza_hold = clonar_por_nombre(pieza->nombre);
        nueva_pieza(); // Genera una nueva desde bolsa
    } else {
        Pieza *tmp = pieza;
        pieza->v_metodos->free(pieza);
        pieza = clonar_por_nombre(pieza_hold->nombre);

        copia_pieza_hold = clonar_por_nombre(tmp->nombre);


        pieza_hold = tmp;
    }

    pieza->v_metodos->pintar(pieza);
    imprimir_tablero();
    puedes_holdear = false;
}
