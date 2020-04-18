//
// Created by niamh on 13/04/2020.
//
#include "game_init.h"
#include <stdio.h>
#include <stdlib.h>
#include "Definations.h"

int valid_colour(square * s, color player_color)
{
    //check if colour matches
    if(s->stack->p_color != player_color){
        printf("NOT YOUR COLOUR");
        return(1);
    }
    return 0;

}
int valid_square(square * s)
{
    if(s->type != VALID) {
        printf("INVALID SQAURE");
        return(1);
    }
   return 0;
}
void move_piece(square * s, player curr_player, square *dest)
{
    s->stack->p_color = curr_player.player_color;
    piece *head= s->stack; //head  is the top fo the stack ie the last thing implemented doesnt move
    s->stack = NULL;
    s->num_pieces = 0;
    piece *current = head;

    //actually moving the stack - filter down through stack one
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = dest->stack; //moves the bottom piece of s to top of dest
    dest->stack = head;

    //removing pieces
    int counter =1;
    piece *last = NULL;  //last will noe be > 5

    //checks <5 the number allowed in the stack
    while(current != NULL){
        if(counter <5){
            current = current->next;
            counter++;
        }//end if
        else{
            last = current;
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
            if(toRemove->p_color == curr_player.player_color){
                curr_player.player_piece_kept++;
            }
            else{
                curr_player.player_piece_captured++;
            }
            current = current->next;
            free(toRemove);
            i++;
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
    printf("num pieces in dest %d ", dest->num_pieces);

}//end move piece
int player_move(player curr_player, square board[BOARD_SIZE][BOARD_SIZE]){
    int row,col; //piece to be moved
    int newrow,newcol; //moved to

    printf("%s indicate which piece you'd like to move by indicating the row and column", &curr_player.player_name[0]);
    scanf("%d%d", &row, &col);

        //check valid square
    int ret = valid_square(&board[row][col]);
    //check players colour match
    if( ret == 0) {
      ret = valid_colour(&board[row][col], curr_player.player_color);
    }
    //error
   if(ret != 0) {
        return (ret);
    }
    printf("Where do u want to move this to");
    scanf("%d%d", &newrow, &newcol);

    int ret2 = valid_square(&board[newrow][newcol]);
    if (ret2 != 0) {
                return (1);
    }//end if
    else { //square is valid

        //check rows UP DOWN LEFT RIGHT
        if (newrow > (row + board[row][col].num_pieces) || newrow < (row - board[row][col].num_pieces)) {
            printf("can only move the number of rows in stack");
            return (1);
        }
        //check cols
        if (newcol > (col + board[row][col].num_pieces) || newcol < (col - board[row][col].num_pieces)) {
            printf("can only move amount of col in stack");
            return (1); //maybe fix these returns
        }
        //actually MOVING
        move_piece(&board[row][col], curr_player, &board[newrow][newcol]);

    }//end else
    return 0;
}//end player move