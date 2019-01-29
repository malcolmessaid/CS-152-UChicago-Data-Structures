#ifndef OTHELLO_FUNCS_H
#define OTHELLO_FUNCS_H


#include <stdio.h>
#include <stdlib.h>


/*  init_board: Sets board up for beginning of game
 * inputs:
 * 	char board[8][8] - empty, but initalzied 8 by 8 array
 * outputs:
 *  nothing. just sets array
 */
void init_board(char board[8][8]);


/*  print_othello_board: Prints
 * inputs:
 * 	unsigned int num - value to be converted/reversed
 * outputs:
 *  nothing. Function prints the new value
 */

void print_othello_board( char board[8][8] );


/*  place_piece: Places piece on the board, if a valid move.
 * inputs:
 * 	char board[8][8] -- current board
 *  char player -- whose move it is
 * unsigned int row - row to move to
 * unsigned int col - col to move to
 * outputs:
 *  If move made, return 1. If not, return 0.
*/
unsigned int place_piece(char board[8][8], char player, unsigned int row, unsigned int col);



#endif
