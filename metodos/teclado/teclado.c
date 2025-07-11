//
// Created by pruden on 25/06/25.
//

#include "teclado.h"
#include <termios.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#include "crear_tablero.h"
#include "Pieza.h"
#include "tablero.h"
#include "completar_linea/completar_linea.h"
#include "hold/holdear.h"

void configurar_terminal_sin_buffer() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void restaurar_terminal() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

long get_time_millis() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

void manejar_input(Pieza *pieza) {
    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(STDIN_FILENO, &read_fds);

    struct timeval timeout;
    timeout.tv_sec = 0;
    timeout.tv_usec = 1000;

    if (select(STDIN_FILENO + 1, &read_fds, NULL, NULL, &timeout) > 0) {
        if (!has_perdido) {
            char c = getchar();

            // Si es una secuencia de escape (flechas)
            if (c == '\033') {
                getchar(); // omite [
                c = getchar(); // lee 'A', 'B', 'C' o 'D'
            }

            switch (c) {
                case 'A':
                    pieza->v_metodos->rotar(pieza);
                    imprimir_tablero();
                    break;
                case 'B':
                    if (pieza->v_metodos->bajar(pieza)) {
                        puntuacion += 2;
                        imprimir_tablero();
                    } else {
                        puedes_holdear = true;
                        nueva_pieza();
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
                case ' ':
                    while (pieza->v_metodos->bajar(pieza)) {
                        puntuacion += 4;
                    }
                    puedes_holdear = true;
                    imprimir_tablero();
                    nueva_pieza();
                    break;

                case 'h':
                    holdear();
                    break;
                case 'q':
                    printf("Saliendo...\n");
                    restaurar_terminal();
                    pieza->v_metodos->free(pieza);
                    exit(0);
                    break;
            }

        }
    }
}
