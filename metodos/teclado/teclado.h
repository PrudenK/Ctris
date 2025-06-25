//
// Created by pruden on 25/06/25.
//

#ifndef TECLADO_H
#define TECLADO_H
#include "Pieza.h"

void configurar_terminal_sin_buffer();
void restaurar_terminal();
long get_time_millis();
void manejar_input(Pieza *pieza);

void nueva_pieza(void);
#endif //TECLADO_H
