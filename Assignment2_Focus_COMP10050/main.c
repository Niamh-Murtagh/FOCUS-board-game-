#include <stdio.h>

#include "input_output.h"
#include "game_init.h"
#include "Definations.h"


int main() {

    // declaration of the players and the board
    player players[PLAYERS_NUM];
    square board[BOARD_SIZE][BOARD_SIZE];

    initialize_players(players);

    initialize_board(board);

    print_board(board);
    return 0;
}
