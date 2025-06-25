#include <stddef.h>

#include "bolsa_piezas.h"
#include "tablero/crear_tablero.h"
#include "piezas/Pieza.h"
#include "teclado/teclado.h"
#include "utils/constantes.h"

#define INTERVALO 2000 // en ms

int tablero[FILAS][COLUMNAS] = {0};
Pieza *pieza = NULL;

void nueva_pieza() {
    pieza = devolver_pieza_aleatoria();
    pieza->v_metodos->pintar(pieza);
    imprimir_tablero();
}

void main() {
    configurar_terminal_sin_buffer();
    cargar_tablero_principal();

    nueva_pieza();

    long ultimo_tick = get_time_millis();

    while (1) {
        long ahora = get_time_millis();

        if (ahora - ultimo_tick >= INTERVALO) {
            if (pieza->v_metodos->bajar(pieza)) {
                imprimir_tablero();
            }else {
                nueva_pieza();
            }
            ultimo_tick = ahora;
        }

        manejar_input(pieza);
    }
}
