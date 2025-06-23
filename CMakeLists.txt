cmake_minimum_required(VERSION 3.31)
project(Ctris C)

set(CMAKE_C_STANDARD 11)

add_library(Ctris STATIC
        piezas/Pieza.c
        piezas/Pieza.h
        main.c)
