//
// Created by niamh on 18/04/2020.
//

#include "CheckWin.h"
#include "input_output.h"
#include "game_init.h"
#include "Definations.h"
#include "Turns.h"
#include <stdbool.h>
#include <stdio.h>

bool win_condition(player curr_player, square board[BOARD_SIZE][BOARD_SIZE], int other_players_pieces){
    bool win = false;

    if(curr_player.player_piece_captured == 18) { //all players pieces are captured ie cant move
        win = true;
        return(win);
    }

    //loop through the entire board ie checking each square
    for(int i=0; i< BOARD_SIZE; i++) {
        for (int j=0; j < BOARD_SIZE; j++){

            if(board[i][j].stack != NULL) {
                //the board still contains both colours red and green or the square is invalid you keep playing
                if ((board[i][j].type != VALID) || ( board[i][j].stack->p_color != curr_player.player_color)) {
                    win = false;
                    return(win);
                }
            }//end stack if
        }//end j loop
    }//end i loop

    if((win = true) && (other_players_pieces >0)){
        win = false;
        return(win);
    }
    //the board is just your colour
    win = true;

    printf("\n\n *****%s IS A WINNER*****\n *****CONGRATZ*****\n ", curr_player.player_name);

    return(win);
}//end win condition
