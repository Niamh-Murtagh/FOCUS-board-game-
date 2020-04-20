#include <stdio.h>

#include "input_output.h"
#include "game_init.h"
#include "Definations.h"
#include "Turns.h"
#include "CheckWin.h"
#include <stdbool.h>


int main() {

    // declaration of the players and the board
    player players[PLAYERS_NUM];
    square board[BOARD_SIZE][BOARD_SIZE];

    initialize_players(players);
    initialize_board(board);

    print_board(board);

     bool win = false;
       while(false == win){
           //Player 1 moves
           player_move(&players[0], board);
           print_board(board);
           print_player_info(players);
            //check if they have won
            win = win_condition(players[0], board);

            //if haven't won move to player 2
            if(win == false){
                player_move(&players[1], board);
                print_board(board);
                print_player_info(players);
                //check again
                win = win_condition(players[1], board);
            }
        }//end while
        print_player_info(players);

    return 0;
}
