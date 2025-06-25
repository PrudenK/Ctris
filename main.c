#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/select.h>
#include <sys/time.h>

#include "tablero/crear_tablero.h"
#include "piezas/Pieza.h"
#include "piezas/Pieza_T.h"
#include "utils/constantes.h"

int tablero[FILAS][COLUMNAS] = {0};

// Configura el terminal para entrada sin buffer ni eco
void configurar_terminal_sin_buffer() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

// Restaura el modo normal del terminal
void restaurar_terminal() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

// Lee el tiempo actual en milisegundos
long get_time_millis() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

int main() {
    configurar_terminal_sin_buffer();
    cargar_tablero_principal();

    Pieza *pieza = (Pieza *)crear_pieza_T(0, 4);
    long ultimo_tick = get_time_millis();
    const long intervalo = 15000; // milisegundos por tick

    imprimir_tablero();

    while (1) {
        long ahora = get_time_millis();

        // ⏬ Baja automática cada intervalo
        if (ahora - ultimo_tick >= intervalo) {
            if (pieza->v_metodos->bajar(pieza)) {
                imprimir_tablero();
            }
            ultimo_tick = ahora;
        }

        // 🎧 Escucha teclas sin bloquear
        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(STDIN_FILENO, &read_fds);

        struct timeval timeout;
        timeout.tv_sec = 0;
        timeout.tv_usec = 1000; // 1ms espera

        if (select(STDIN_FILENO + 1, &read_fds, NULL, NULL, &timeout) > 0) {
            char c = getchar();
            if (c == '\033') {
                getchar(); // omite [
                switch (getchar()) {
                    case 'A': break; // rotar (a implementar)
                    case 'B':
                        if (pieza->v_metodos->bajar(pieza)) {
                            imprimir_tablero();
                        }
                        break;
                    case 'C':
                        pieza->v_metodos->derecha(pieza);
                        imprimir_tablero();
                        break;
                    case 'D':
                        pieza->v_metodos->izquierda(pieza);
                        imprimir_tablero();
                        break;
                }
            } else if (c == 'q') {
                printf("Saliendo...\n");
                break;
            }
        }
    }

    restaurar_terminal();
    pieza->v_metodos->free(pieza);
    return 0;
}
