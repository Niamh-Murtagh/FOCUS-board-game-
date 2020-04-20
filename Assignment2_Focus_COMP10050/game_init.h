//
// Created by niamh on 27/03/2020.
//

#ifndef ASSIGNMENT2_FOCUS_COMP10050_GAME_INIT_H
#define ASSIGNMENT2_FOCUS_COMP10050_GAME_INIT_H

#include "Definations.h"

//colors that a piece can have RED 0 GREEN 1
typedef enum color {
    RED,
    GREEN
}color;

// Square types
//INVALID: squares that are on the sides and where no piece can be placed 1
//VALID: squares where it is possible to place a piece or a stack 1
typedef enum square_type {
    VALID,
    INVALID
}square_type;

//Player
typedef struct player{
    color player_color;  //the enum color
    char player_name[PLAYERS_NAME];
    int player_piece_captured;
    int player_piece_kept;

}player; //struct is called player so know u can just go player player_name Brad and it will make that

// A piece
typedef struct piece {
    //the color associated with a piece
    color p_color;
    // This is a pointer to the next pieces
    // to create a stack. For this lab you do not have to think too much about it.Week 10 lecture
    struct piece *next;

}piece;

// A Square of the board
typedef struct square {
    // type of the square (VALID/INVALID)
    square_type *type;
    //the piece or the top piece on the stack
    piece *stack;
    //number of pieces on the square
    int num_pieces;

}square;

//Function to create the players
void initialize_players(player players[PLAYERS_NUM]);

//Function to create the board
void initialize_board(square board[BOARD_SIZE][BOARD_SIZE]);


#endif //ASSIGNMENT2_FOCUS_COMP10050_GAME_INIT_H
