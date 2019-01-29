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


char player_won(char board[8][8]);

int computer_move(char board[8][8], char player, unsigned int *row, unsigned int *col);


void play_othello();
#endif


// // East
// if (surroundings(board, player,row, col, 1, 0) == 1) {
//   return 1;
// }
// // West
// else if (surroundings(board, player,row, col, -1, 0) == 1) {
//     return 1;
// }
// // North
// else if (surroundings(board, player,row, col, 0, -1) == 1) {
//   return 1;
// }
// // South
// else if (surroundings(board, player,row, col, 0, 1) == 1) {
//   return 1;
// }
// // North - East
// else if (surroundings(board, player,row, col, 1, -1) == 1) {
//   return 1;
// }
// // North - West
// else if (surroundings(board, player,row, col, -1, -1) == 1) {
//   return 1;
// }
// // South - East
// else if (surroundings(board, player,row, col, 1, 1) == 1) {
//   return 1;
// }
// // South - West
// else if (surroundings(board, player,row, col, -1, 1) == 1) {
//   return 1;
// }
// else {
//   return 0;
// }
