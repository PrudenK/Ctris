//
// Created by pruden on 25/06/25.
//

#include "bolsa_piezas.h"

#include <stdlib.h>

#include "constantes.h"
#include "Pieza.h"
#include "Pieza_J.h"
#include "Pieza_L.h"
#include "Pieza_O.h"
#include "Pieza_S.h"
#include "Pieza_T.h"
#include "Pieza_Z.h"

#define NUM_TIPOS_PIEZA 6
Pieza *bolsa[NUM_TIPOS_PIEZA];
int bolsa_size = 0;

void cargar_bolsa();


Pieza *devolver_pieza_aleatoria() {
    if (bolsa_size == 0) {
        cargar_bolsa();
    }

    return bolsa[--bolsa_size];
}


void cargar_bolsa() {
    int columnaInicial = COLUMNAS / 2;
    //bolsa[0] = (Pieza *)crear_pieza_I(0, columnaInicial);
    bolsa[5] = (Pieza *)crear_pieza_O(-1, columnaInicial);
    bolsa[0] = (Pieza *)crear_pieza_T(-1, columnaInicial);
    bolsa[3] = (Pieza *)crear_pieza_S(-1, columnaInicial);
    bolsa[4] = (Pieza *)crear_pieza_Z(-1, columnaInicial);
    bolsa[2] = (Pieza *)crear_pieza_L(-1, columnaInicial);
    bolsa[1] = (Pieza *)crear_pieza_J(-1, columnaInicial);

    bolsa_size = NUM_TIPOS_PIEZA;


    // Mezclar (Fisher-Yates)

    for (int i = NUM_TIPOS_PIEZA - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Pieza *tmp = bolsa[i];
        bolsa[i] = bolsa[j];
        bolsa[j] = tmp;
    }
}