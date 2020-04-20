//
// Created by niamh on 27/03/2020.
//

#ifndef ASSIGNMENT2_FOCUS_COMP10050_INPUT_OUTPUT_H
#define ASSIGNMENT2_FOCUS_COMP10050_INPUT_OUTPUT_H
#include "game_init.h"
#include "Definations.h"

//Function to print the board
void print_board(square board[BOARD_SIZE][BOARD_SIZE]);
void print_player_info(player players[PLAYERS_NUM]);
char* enum_desc(int enum_type, int enum_val);


#endif //ASSIGNMENT2_FOCUS_COMP10050_INPUT_OUTPUT_H
