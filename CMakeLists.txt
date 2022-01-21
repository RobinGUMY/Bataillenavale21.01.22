cmake_minimum_required(VERSION 3.20)
project(tableau C)

set(CMAKE_C_STANDARD 99)

add_executable(tableau main.c Aides.c Aides.h Scores.c Scores.h)
