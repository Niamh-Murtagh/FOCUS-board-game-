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

bool win_condition(player curr_player, square board[BOARD_SIZE][BOARD_SIZE]){
    bool win = false;
    printf("In win condition\n");
    if(curr_player.player_piece_captured == 18) {
        win = true;
        return(win);
    }

  // printf(" empty %d",board[0][2].stack->p_color);
    //return(win);

    for(int i=0; i< BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j].stack != NULL) {
                if (board[i][j].type != VALID || board[i][j].stack->p_color != curr_player.player_color) {
                    break;
                }
                printf("%s WINNER ", curr_player.player_name);
                win = true;
                return (win);
            }//end stack if
            else{
                win = false;
                return(win);
            }
        }//end j loop
    }//end i loop

    return(win);
}//end win condition
