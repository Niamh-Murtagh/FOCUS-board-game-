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
void move_piece(square * s, player curr_player )
{
    s->num_pieces +=1;
    s->stack->p_color = curr_player.player_color;

    s->stack->next = NULL;
}
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
    if(ret2 == 0) {
            //check rows
            if(newrow >= (row + board[row][col].num_pieces) || newrow <=( row - board[row][col].num_pieces)){
                printf("can only move the number of rows in stack");
                return (1);
            }
            //check cols
            if(newcol >= (col + board[row][col].num_pieces) || newcol <=( col - board[row][col].num_pieces)){
                printf("can only move amount of col in stack");
            }
            return (1);
        }//end if

    else if(ret2 == 1){
        return(1);
    }

    //actually MOVING
    &board[newrow][newcol].num_pieces + 1;
    return 0;
}//end player move