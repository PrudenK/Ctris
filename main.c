#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "bolsa_piezas.h"
#include "perder/comprobar_perder.h"
#include "tablero/crear_tablero.h"
#include "piezas/Pieza.h"
#include "teclado/teclado.h"
#include "utils/constantes.h"


int tablero[FILAS][COLUMNAS] = {0};
int nivel = 1;
int lineas = 0;
int puntuacion = 0;
int TIEMPO_CAIDA = 2000;
bool has_perdido = false;
bool puedes_holdear = true;
Pieza *pieza = NULL;
Pieza *pieza_hold = NULL;
Pieza *copia_pieza_hold = NULL;


void nueva_pieza() {
    if (pieza != NULL) {
        pieza->v_metodos->free(pieza);
    }

    pieza = pieza_siguiente_1;
    pieza_siguiente_1 = pieza_siguiente_2;
    pieza_siguiente_2 = pieza_siguiente_3;
    pieza_siguiente_3 = devolver_pieza_aleatoria();

    pieza->v_metodos->pintar(pieza);
    imprimir_tablero();
}

void main() {
    srand(time(NULL));

    configurar_terminal_sin_buffer();
    cargar_tablero_principal();

    pieza_siguiente_1 = devolver_pieza_aleatoria();
    pieza_siguiente_2 = devolver_pieza_aleatoria();
    pieza_siguiente_3 = devolver_pieza_aleatoria();

    nueva_pieza();

    long ultimo_tick = get_time_millis();

    while (1) {
        long ahora = get_time_millis();

        if (!has_perdido) {
            if (ahora - ultimo_tick >= TIEMPO_CAIDA) {
                if (pieza->v_metodos->bajar(pieza)) {
                    imprimir_tablero();
                }else {
                    if (!comprobar_perder()) {
                        nueva_pieza();
                    }
                }
                ultimo_tick = ahora;
            }
        }else {
            printf("\nHas perdido. Pulsa 'r' para reiniciar o 'q' para salir.\n");
            while (1) {
                char c = getchar();
                if (c == 'q') {
                    restaurar_terminal();
                    pieza->v_metodos->free(pieza);
                    exit(0);
                } else if (c == 'r') {
                    TIEMPO_CAIDA = 2000;
                    nivel = 1;
                    puntuacion = 0;
                    lineas = 0;
                    cargar_tablero_principal();
                    nueva_pieza();
                    has_perdido = false;
                    puedes_holdear = true;
                    ultimo_tick = get_time_millis();
                    imprimir_tablero();
                    break;  // salimos del bucle y el juego continúa
                }
                usleep(100000);  // para evitar 100% uso de CPU
            }
        }


        manejar_input(pieza);
    }
}
