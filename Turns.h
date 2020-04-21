//
// Created by niamh on 10/04/2020.
//
#include "game_init.h"
#include "Definations.h"


#ifndef ASSIGNMENT2_FOCUS_COMP10050_TURNS_H
#define ASSIGNMENT2_FOCUS_COMP10050_TURNS_H

int player_move(player *curr_player, square board[BOARD_SIZE][BOARD_SIZE]);
int valid_colour(square * s, color player_color);
int valid_square(square * s);
void adding_piece(square * s, player *curr_player);
void move_piece(square * s, player *curr_player, square *dest);
//void adding_piece(square * s, player *curr_player);


#endif //ASSIGNMENT2_FOCUS_COMP10050_TURNS_H
