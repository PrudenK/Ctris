//
// Created by pruden on 25/06/25.
//

#ifndef BOLSA_PIEZAS_H
#define BOLSA_PIEZAS_H
#include "Pieza.h"
#define NUM_TIPOS_PIEZA 7
extern Pieza *bolsa[NUM_TIPOS_PIEZA];
extern int bolsa_size;
extern Pieza *pieza_siguiente_1;
extern Pieza *pieza_siguiente_2;
extern Pieza *pieza_siguiente_3;
Pieza *devolver_pieza_aleatoria();
Pieza *clonar_por_nombre(const char *nombre);
#endif //BOLSA_PIEZAS_H
