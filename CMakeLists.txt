cmake_minimum_required(VERSION 3.16)
project(Ctris C)

set(CMAKE_C_STANDARD 11)


add_executable(Ctris
        main.c
        piezas/Pieza.c
        tablero/crear_tablero.c
        piezas/Pieza_T.c
        piezas/Pieza_T.h
        tablero/tablero.h
        metodos/piezas/pintar/pintar.c
        metodos/piezas/pintar/pintar.h
        metodos/piezas/limpiar/limpiar.c
        metodos/piezas/limpiar/limpiar.h
        metodos/mover/bajar/bajar_3x2.c
        metodos/mover/bajar/bajar_3x2.h
        metodos/teclado/teclado.c
        metodos/teclado/teclado.h
        metodos/bolsa_piezas/bolsa_piezas.c
        metodos/bolsa_piezas/bolsa_piezas.h
        metodos/mover/lados/lados_3x2.c
        metodos/mover/lados/lados_3x2.h
        metodos/mover/rotar/rotar_normal.c
        metodos/mover/rotar/rotar_normal.h
        metodos/mover/rotar/rotar_especial.c
        metodos/mover/rotar/rotar_especial.h
        piezas/Pieza_J.c
        piezas/Pieza_J.h
        piezas/Pieza_L.c
        piezas/Pieza_L.h
        piezas/Pieza_S.c
        piezas/Pieza_S.h
        piezas/Pieza_Z.c
        piezas/Pieza_Z.h
        piezas/Pieza_O.c
        piezas/Pieza_O.h
        metodos/mover/bajar/bajar_2x2.c
        metodos/mover/bajar/bajar_2x2.h
        piezas/Pieza_I.c
        piezas/Pieza_I.h
        metodos/mover/bajar/bajar_4x1.c
        metodos/mover/bajar/bajar_4x1.h
        metodos/mover/lados/lados_4x1.c
        metodos/mover/lados/lados_4x1.h
        metodos/completar_linea/completar_linea.c
        metodos/completar_linea/completar_linea.h
        metodos/perder/comprobar_perder.c
        metodos/perder/comprobar_perder.h
        metodos/hold/holdear.c
        metodos/hold/holdear.h
)

include_directories(
        utils
        tablero
        piezas
        metodos
        metodos/piezas
        metodos/piezas/pintar
        metodos/piezas/limpiar
        metodos/mover/bajar
        metodos/teclado
        metodos/bolsa_piezas
)