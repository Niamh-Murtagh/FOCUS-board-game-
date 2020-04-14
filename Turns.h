//
// Created by niamh on 10/04/2020.
//
#include "game_init.h"
#include "Definations.h"


#ifndef ASSIGNMENT2_FOCUS_COMP10050_TURNS_H
#define ASSIGNMENT2_FOCUS_COMP10050_TURNS_H

int player_move(player curr_player, square board[BOARD_SIZE][BOARD_SIZE]);

int valid_colour(square * s, color player_color);
int valid_square(square * s);
#endif //ASSIGNMENT2_FOCUS_COMP10050_TURNS_H
