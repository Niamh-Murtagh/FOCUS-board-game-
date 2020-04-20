//
// Created by niamh on 13/04/2020.
//
#include "game_init.h"
#include <stdio.h>
#include <stdlib.h>
#include "Definations.h"
#include "input_output.h"

int valid_colour(square * s, color player_color)
{

    //check if colour matches
    if(s->stack!=NULL) {
        if (s->stack->p_color != player_color) {
            printf("Invalid colour ");
            return (1);
        }
    }
    else
        {   printf("Empty Square ");
            return(1);
        }

    return 0;
}//end valid colour
int valid_square(square board[BOARD_SIZE][BOARD_SIZE], int r, int c)
{
    if(r > BOARD_SIZE|| c> BOARD_SIZE){
        printf("\n Outside board limits");
        return(1);
    }
        if(board[r][c].type != VALID) {
        printf("Invalid square ");
        return(1);
    }//end if

   return 0;
}//end valid square
void move_piece(square * s, player *curr_player, square *dest)
{
    //s->stack->p_color = curr_player.player_color;
    piece *head;
    head = s->stack; //head  is the top fo the stack ie the last thing implemented doesnt move
    s->stack = NULL;
    s->num_pieces = 0;
    piece *current;
    current = head; //both pointing to the same thing

    //actually moving the stack - filter down through stack one
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = dest->stack; //moves the bottom piece of s to top of dest
    dest->stack = head; //top piece of old stack

    current = dest->stack;
    //removing pieces
    int counter =1;
    piece *last = NULL;  //last will not be > 5

    //checks <5 the number allowed in the stack
    while(current != NULL){
        if(counter <5){
            current = current->next;
            counter++;
        }//end if
        else{
            last = current;
            break;
        }
    }//end while

    //declaring the piece that we need to get rid of
    piece *toRemove;
    int i=0; // I will check the to remove pieces
    if(last != NULL){
        current = current->next;
        while(current != NULL){
            toRemove = current;
            //checking the colour of the pieces and deciding if they are kept or captured
            if(toRemove->p_color == curr_player->player_color){
                curr_player->player_piece_kept++;
                printf("\n turns piece kept %d",curr_player->player_piece_kept );
            }
            else{
                curr_player->player_piece_captured++;
                printf("\n turns piece captured %d",curr_player->player_piece_captured);
            }
            current = current->next;
            free(toRemove);
            i++;
//            printf("\n 2nd piece captured %d",curr_player.player_piece_captured);
//            printf("\n 2 nd piece kept %d",curr_player.player_piece_kept );

        }//end while
        last->next =NULL;
    }//end if

    //Updating the Numbers
    current = head;
    dest->num_pieces = 1;
    while(current->next != NULL){
        dest->num_pieces++;
        current = current->next;
    }

}//end move piece
void adding_piece(square *s, player *curr_player){
    //creating a new piece with the players colour
    piece *New_piece = (piece *) malloc (sizeof(piece));
    New_piece->p_color = curr_player->player_color;
    piece *curr_piece = NULL;
    if(s->stack != NULL){
        //piece on square that has a stack
        curr_piece = s->stack;
    }
    //top
    New_piece->next = curr_piece;
    s->stack =New_piece;
    //changing the numbers
    s->num_pieces++;
    curr_player->player_piece_kept--;

}//end adding piece


int player_move(player *curr_player, square board[BOARD_SIZE][BOARD_SIZE]){
    int row=0,col=0; //piece to be moved
    int newrow=0,newcol=0; //moved to


    //check valid square
    int ret_square = 1;
     int ret_colour = 1;
    int check=0;

    //error colours or square dont match or add new piece

    if(curr_player->player_piece_kept > 0) {
        printf("Do you want to move a piece or  use a reserve piece?\n"
               "Please pick 0 for move or 1 to use a reserve piece:");
        scanf("%d", &check);

    }

    if(check == 0){
    while((ret_colour != 0 ) || ( ret_square != 0)) {
       //checking reserve pieces

               printf("\n%s please pick a %s square:", &curr_player->player_name[0], enum_desc(1,curr_player->player_color));
               scanf("%d%d", &row, &col);

               ret_square = valid_square(board, row, col);
               if(ret_square == 0) {
                   ret_colour = valid_colour(&board[row][col], curr_player->player_color);
               }

    }//end while
    }//end check if

    int ret2 = 1;

        while(ret2 != 0){

            printf("\n %s please enter your destination square: ",&curr_player->player_name[0]);
            scanf("%d%d", &newrow, &newcol);
            ret2 = valid_square(board, newrow, newcol);

            //check again
            if(ret2 == 0) {
                //This is creating the new piece
                if(check ==0){

                    //check rows UP DOWN LEFT RIGHT
                    if (newrow > (row + board[row][col].num_pieces) || newrow < (row - board[row][col].num_pieces)) {
                        printf("!! you can only move the number of rows in stack!!\n");
                        ret2 = 1;
                    }
                    //check cols
                    if (newcol > (col + board[row][col].num_pieces) || newcol < (col - board[row][col].num_pieces)) {
                        printf("!! you can only move amount of columns in stack!!\n");
                        ret2 = 1;
                    }

                }//end if check
            }//end ret2 check
        }//end while

    if(check ==1){

        adding_piece(&board[newrow][newcol], curr_player);
    }//ends check if
    else {
        //actually MOVING
        move_piece(&board[row][col], curr_player, &board[newrow][newcol]);
    }
    return 0;
}//end player move




