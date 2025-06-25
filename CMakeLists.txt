cmake_minimum_required(VERSION 3.31)
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
)

include_directories(utils, tablero, piezas)
