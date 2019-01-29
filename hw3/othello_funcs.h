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


/*  flip_pieces: flips stones that should be flipped. Returns amount flipped
 * inputs:
 * 	char board[8][8] -- current board
 * unsigned int row - row to move to
 * unsigned int col - col to move to
 * outputs:
 *  Amount of stones flipped
*/

unsigned int flip_pieces(char board[8][8], unsigned int row, unsigned int col);


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



/*  player: determines winner from board of finished game
 * inputs:
 * 	char board[8][8] -- current board
 * outputs:
 *  char -- char of winner. '*' if a tie
*/
char player_won(char board[8][8]);



/*  computer_move: Chooses valid move given board and player turn. Returns move
 * inputs:
 * 	char board[8][8] -- current board
 *  char player -- whose move it is
 * unsigned int *row - pointer to be used to return move row
 * unsigned int *col - pointer to be used to return move col
 * outputs:
 *  If move made, return 1. If not possible, return 0.
 */
int computer_move(char board[8][8], char player, unsigned int *row, unsigned int *col);


/*  play_othello: Game loop which implements above functions for 2 players to
 * play othello
 * inputs:
 *   none - Info gathered through scan
 * outputs:
 *  None. all print statements
 */
void play_othello();

#endif
