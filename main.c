#include <stdio.h>

#include "input_output.h"
#include "game_init.h"
#include "Definations.h"
#include "Turns.h"


int main() {

    // declaration of the players and the board
    player players[PLAYERS_NUM];
    square board[BOARD_SIZE][BOARD_SIZE];

    initialize_players(players);

    initialize_board(board);

    print_board(board);
    player_move(players[0],board);


    return 0;
}
