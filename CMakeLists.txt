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
)

include_directories(
        utils
        tablero
        piezas
        metodos
        metodos/piezas
        metodos/piezas/pintar
        metodos/piezas/limpiar
)