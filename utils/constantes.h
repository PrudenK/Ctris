//
// Created by pruden on 23/06/25.
//

#ifndef CONSTANTES_H
#define CONSTANTES_H

#include "../piezas/Pieza.h"

#define FILAS 20
#define COLUMNAS 12
#define SUELO 9
#define BLANCO 0
#define LINEAS_X_NIVEL 10
#define SALTO_TEIMPO_X_NIVEL 200


extern int TIEMPO_CAIDA;
extern Pieza *pieza;
extern Pieza *pieza_hold;
extern bool puedes_holdear;
extern Pieza *copia_pieza_hold;
#endif //CONSTANTES_H
