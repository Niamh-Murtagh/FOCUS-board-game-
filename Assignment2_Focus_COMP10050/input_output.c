//
// Created by niamh on 27/03/2020.
//

#include <stdio.h>
#include "input_output.h"
#include "Definations.h"

/* FUnction to print the board:
 * Invalid Squares are printed as | - |
 * Valid empty squares are printed as |   |
 * Valid squares with a GREEN piece are printed as | G |
 * Valid squares with a RED piece are printed as | R | */

void print_board(square board[BOARD_SIZE][BOARD_SIZE]){
    printf("\n****** The Board ******\n");
    for(int i = 0; i < BOARD_SIZE; i ++){
        for (int j = 0; j < BOARD_SIZE; j++){
            if(board[i][j].type == VALID) {
                if(board[i][j].stack == NULL)
                    printf("|   ");
                else{
                    if (board[i][j].stack->p_color == GREEN) //checks the colour of the piece
                        printf("| G ");
                    else{

                        printf("| R ");
                        //printf("\033[0m");
                    }
                    }
                }
            else
                printf("| - ");
        }//end j for
        printf("|\n");

    }//end i for

}//end print board

void print_player_info(player players[PLAYERS_NUM]){
    printf("%s info: \t \t  %s info:\n "
           "Player colour: %s \t \t Player colour: %s\n "
           "Pieces captured: %d\t \t Pieces captured: %d\n "
           "Pieces reserved: %d\t \t Pieces reserved: %d",
           players[0].player_name, players[1].player_name,
           enum_desc(1,players[0].player_color), enum_desc(1,players[1].player_color) ,
           players[0].player_piece_captured, players[1].player_piece_captured,
           players[0].player_piece_kept,  players[1].player_piece_kept);

    printf("\n");

}//end print player info

char* enum_desc(int enum_type, int enum_val){

    if(enum_type == 1){
        switch(enum_val) {
            case 0 :
                return "RED";
            case 1:
                return "GREEN";
        }
    }//end enum type 1
    else{
        switch(enum_val) {
            case 0 :
                return "VALID";
            case 1:
                return "INVALID";
        }
    }//end enum type 2

}//end enum_desc

