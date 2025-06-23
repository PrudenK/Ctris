cmake_minimum_required(VERSION 3.31)
project(Ctris C)

set(CMAKE_C_STANDARD 11)


add_executable(Ctris
        main.c
        piezas/Pieza.c
        tablero/crear_tablero.c
)

include_directories(utils, tablero, piezas)

