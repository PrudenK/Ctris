#include "bolsa_piezas.h"

#include <stdlib.h>
#include <string.h>
#include "constantes.h"
#include "Pieza.h"
#include "Pieza_I.h"
#include "Pieza_J.h"
#include "Pieza_L.h"
#include "Pieza_O.h"
#include "Pieza_S.h"
#include "Pieza_T.h"
#include "Pieza_Z.h"

Pieza *bolsa[NUM_TIPOS_PIEZA];
int bolsa_size = 0;
Pieza *pieza_siguiente_1 = NULL;
Pieza *pieza_siguiente_2 = NULL;
Pieza *pieza_siguiente_3 = NULL;

void cargar_bolsa();

Pieza *sacar_de_bolsa() {
    if (bolsa_size == 0) {
        cargar_bolsa();
    }
    return bolsa[--bolsa_size];
}

void actualizar_siguientes() {
    if (pieza_siguiente_1 == NULL) pieza_siguiente_1 = sacar_de_bolsa();
    if (pieza_siguiente_2 == NULL) pieza_siguiente_2 = sacar_de_bolsa();
    if (pieza_siguiente_3 == NULL) pieza_siguiente_3 = sacar_de_bolsa();
}

Pieza *obtener_siguiente_pieza() {
    actualizar_siguientes();

    Pieza *siguiente = pieza_siguiente_1;
    pieza_siguiente_1 = pieza_siguiente_2;
    pieza_siguiente_2 = pieza_siguiente_3;
    pieza_siguiente_3 = sacar_de_bolsa();

    return siguiente;
}

void cargar_bolsa() {
    int columnaInicial = COLUMNAS / 2;
    Pieza *nuevas[NUM_TIPOS_PIEZA];

    nuevas[0] = crear_pieza_I(-1, columnaInicial);
    nuevas[1] = crear_pieza_O(-1, columnaInicial);
    nuevas[2] = crear_pieza_T(-1, columnaInicial);
    nuevas[3] = crear_pieza_S(-1, columnaInicial);
    nuevas[4] = crear_pieza_Z(-1, columnaInicial);
    nuevas[5] = crear_pieza_L(-1, columnaInicial);
    nuevas[6] = crear_pieza_J(-1, columnaInicial);

    for (int i = 0; i < NUM_TIPOS_PIEZA; i++) {
        bolsa[i] = nuevas[i];
    }

    bolsa_size = NUM_TIPOS_PIEZA;

    for (int i = bolsa_size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Pieza *tmp = bolsa[i];
        bolsa[i] = bolsa[j];
        bolsa[j] = tmp;
    }
}

Pieza *clonar_por_nombre(const char *nombre) {
    int fila = -1;
    int col = COLUMNAS / 2;

    if (strcmp(nombre, "Pieza_I") == 0) return crear_pieza_I(fila, col);
    if (strcmp(nombre, "Pieza_O") == 0) return crear_pieza_O(fila, col);
    if (strcmp(nombre, "Pieza_T") == 0) return crear_pieza_T(fila, col);
    if (strcmp(nombre, "Pieza_S") == 0) return crear_pieza_S(fila, col);
    if (strcmp(nombre, "Pieza_Z") == 0) return crear_pieza_Z(fila, col);
    if (strcmp(nombre, "Pieza_L") == 0) return crear_pieza_L(fila, col);
    if (strcmp(nombre, "Pieza_J") == 0) return crear_pieza_J(fila, col);

    return NULL;
}
