//
// Created by niamh on 27/03/2020.
//

#include "game_init.h"
#include <stdio.h>
#include <stdlib.h>
#include "Definations.h"

void initialize_players(player players[PLAYERS_NUM]){

    //int clr;
    printf("Enter the name for player 1:\t");
    //should scan the users string into the struct player as thr players name
    scanf("%s", &players[0].player_name[0]);

    //choosing colour
    unsigned int c;
    printf("\nChoose your colour - 0 for RED 1 for GREEN:\t");
    scanf("%u", &c);
    players[0].player_color = c;

     //Player 2
    printf("\nEnter the name for player 2:\t");
    scanf("%s", &players[1].player_name[0]);

    printf("\n%s has chosen : " , &players[0].player_name[0]);
    if (c == 0) {
        printf("Red\n");
        printf("%s must use  : ", &players[1].player_name[0] );
        printf("Green\n\n");
        players[1].player_color = GREEN;
        }
    else {
        printf("Green\n");
        printf("%s must use  : " ,&players[1].player_name[1] );
        printf("Red\n\n");
        players[1].player_color = RED;
    }
    //Initalising the numbers to zero for print players

    players[0].player_piece_captured =0;
    players[1].player_piece_captured =0;
    players[0].player_piece_kept =0;
    players[1].player_piece_kept=0;

}//end initalised

//Set Invalid Squares (where it is not possible to place stacks)
void set_invalid(square * s){
s->type = (square_type *) INVALID;
s->stack = NULL;
s->num_pieces = 0;
}

//Set Empty Squares (with no pieces/stacks)
void set_empty(square * s){
s->type = VALID;
s->stack = NULL;
s->num_pieces = 0;
}

//Set squares  with a GREEN piece
void set_green(square * s){
s->type = VALID;
s->stack = (piece *) malloc (sizeof(piece));
s->stack->p_color = GREEN;
s->stack->next = NULL;
s->num_pieces = 1;
}

//Set squares with a RED piece
void set_red(square * s){
s->type = VALID;
s->stack = (piece *) malloc (sizeof(piece));
s->stack->p_color = RED;
s->stack->next = NULL;
s->num_pieces = 1;
}

//initializes the board
void initialize_board(square board [BOARD_SIZE][BOARD_SIZE]){

    for(int i=0; i< BOARD_SIZE; i++){
        for(int j=0; j< BOARD_SIZE; j++){
            //invalid squares
            if((i==0 && (j==0 || j==1 || j==6 || j==7)) ||
               (i==1 && (j==0 || j==7)) ||
               (i==6 && (j==0 || j==7)) ||
               (i==7 && (j==0 || j==1 || j==6 || j==7)))
                set_invalid(&board[i][j]);

            else{
                //squares with no pieces
                if(i==0 || i ==7 || j==0 || j == 7)
                    set_empty(&board[i][j]);
                else{
                    //squares with red pieces
                    if((i%2 == 1 && (j < 3 || j> 4)) ||
                       (i%2 == 0 && (j == 3 || j==4)))
                        set_red(&board[i][j]);
                        //green squares
                    else set_green(&board[i][j]);
                }
            }
        }
    }
}


