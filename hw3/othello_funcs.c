#include <stdio.h>
#include <stdlib.h>
#include "othello_funcs.h"
#include <math.h>



/*  print_othello_board: Prints
 * inputs:
 * 	unsigned int num - value to be converted/reversed
 * outputs:
 *  nothing. Function prints the new value
 */
void print_othello_board( char board[8][8] )
{
  unsigned int i, j;
  for (i = 0; i < 8; i++)
  {
    for (j = 0;j < 8; j++)
    {
      printf("%c ",board[i][j]);
    }
    printf("\n");
  }
}



/*  init_board: Sets board up for beginning of game
 * inputs:
 * 	char board[8][8] - empty, but initalzied 8 by 8 array
 * outputs:
 *  nothing. just sets array
 */
void init_board(char board[8][8]) {
	int i, j;

  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      board[i][j] = '*';
    }
  }
  board[3][3] = 'W';
  board[4][4] = 'W';

  board[3][4] = 'B';
  board[4][3] = 'B';
}


	/*  switch_player: Returns opposite player of whose turn it is
	 * inputs:
	 *  char player -- whose move it is
	 * outputs:
	 *  char -- opposite player of input
	 */
	char switch_player(char player) {
		if (player == 'W'){
			return 'B';
		}
		else {
			return 'W';
		}
	}


/*  surroundings: Checks if placed stone is in the line of another stone of same color in a given direction
 * inputs:
 * 	char board[8][8] -- current board
 *  char player -- whose move it is
 * unsigned int row - row moved to
 * unsigned int col - col moved to
 *  int dirx - X direction looking
 *  int diry - Y direction looking
 * outputs:
 *  If in line, return 1. If not, return 0.
*/
unsigned int surroundings(char board[8][8], char player, unsigned int row, unsigned int col, int dirx, int diry){

  if ((row + diry) > 8 || ((row + diry) < 0) || ((col + dirx) > 8) || ((col + dirx) < 0)){
      return 0;
    })
  if (board[row + diry][col + dirx] == '*'){
    return 0;
  }
  else if (board[row + diry][col + dirx] == switch_player(player)) {
    surroundings(board, player, (row + diry), (col + dirx), dirx, diry);
  }
  else if (board[row + diry][col + dirx] == player) {
    return 1;
  }
}


/*  in_line: Checks if placed stone is in the line of another stone of same color
 * inputs:
 * 	char board[8][8] -- current board
 *  char player -- whose move it is
 * unsigned int row - row moved to
 * unsigned int col - col moved to
 *  int dirx - X direction looking
 *  int diry - Y direction looking
 * outputs:
 *  If in line, return 1. If not, return 0.
*/
unsigned int in_line(char board[8][8], char player, unsigned int row, unsigned int col){
  // East
  if (surroundings(board, player,row, col, 1, 0) == 1) {
    return 1;
  }
  // West
  else if (surroundings(board, player,row, col, -1, 0) == 1) {
      return 1;
  }
  // North
  else if (surroundings(board, player,row, col, 0, -1) == 1) {
    return 1;
  }
  // South
  else if (surroundings(board, player,row, col, 0, 1) == 1) {
    return 1;
  }
  // North - East
  else if (surroundings(board, player,row, col, 1, -1) == 1) {
    return 1;
  }
  // North - West
  else if (surroundings(board, player,row, col, -1, -1) == 1) {
    return 1;
  }
  // South - East
  else if (surroundings(board, player,row, col, 1, 1) == 1) {
    return 1;
  }
  // South - West
  else if (surroundings(board, player,row, col, -1, 1) == 1) {
    return 1;
  }
  else {
    return 0;
  }
}

/*  place_piece: Places piece on the board, if a valid move.
 * inputs:
 * 	char board[8][8] -- current board
 *  char player -- whose move it is
 * unsigned int row - row to move to
 * unsigned int col - col to move to
 * outputs:
 *  If move made, return 1. If not, return 0.
*/
unsigned int place_piece(char board[8][8], char player, unsigned int row, unsigned int col){
  if ((board[row][col] == 'W') || (board[row][col] == 'B')){
    return 0;
  }

  if (in_line(board, player, row, col) == 0){
    return 0;
  }
  // PLACE PIECE BEFORE THIS I THINK.
  // if (flip_pieces(board, row, col) == 0){
  //   // REMOVE THE PLACED PIECE BECASE NOTHIGN WAS FLIPPPED
  //   // RETURN 0
  // }
  else {
    // IDK WHAT YOU'LL DO. BUT IF IT REACHES HERE THEN ITS A VALID MOVE CAUSE
    // EVERYTHING ELSE PASSES AND IT FLIPS
  }
}


unsigned int flip_pieces(char board[8][8], unsigned int row, unsigned int col) {
  return 1;
}
