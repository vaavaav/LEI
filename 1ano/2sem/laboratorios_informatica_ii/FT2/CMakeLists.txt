cmake_minimum_required(VERSION 3.13)
project(FT2 C)

set(CMAKE_C_STANDARD 99)

add_executable(imc main.c indicadores.c indicadores.h)
