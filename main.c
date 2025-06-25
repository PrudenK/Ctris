#include "tablero/crear_tablero.h"
#include "piezas/Pieza.h"
#include "piezas/Pieza_T.h"
#include "teclado/teclado.h"
#include "utils/constantes.h"

#define INTERVALO 2000 // en ms

int tablero[FILAS][COLUMNAS] = {0};

void main() {
    configurar_terminal_sin_buffer();
    cargar_tablero_principal();

    Pieza *pieza = (Pieza *)crear_pieza_T(-1, 4);
    long ultimo_tick = get_time_millis();

    imprimir_tablero();

    while (1) {
        long ahora = get_time_millis();

        if (ahora - ultimo_tick >= INTERVALO) {
            if (pieza->v_metodos->bajar(pieza)) {
                imprimir_tablero();
            }
            ultimo_tick = ahora;
        }

        manejar_input(pieza);
    }
}
