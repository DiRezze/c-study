cmake_minimum_required(VERSION 4.2)
project(TAD_Pilha C)

set(CMAKE_C_STANDARD 99)

add_executable(TAD_Pilha main.c
        Stack.c
        Stack.h)
