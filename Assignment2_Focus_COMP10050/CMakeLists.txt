cmake_minimum_required(VERSION 3.15)
project(Assignment2_Focus_COMP10050 C)
include_directories(..)
set(CMAKE_C_STANDARD 11)

add_executable(Assignment2_Focus_COMP10050 main.c game_init.c game_init.h input_output.c input_output.h Definations.c Definations.h Turns.h Turns.c CheckWin.c CheckWin.h )