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

  if ((row + diry) > 8 || ((col + dirx) > 8)){
      return 0;
    }
  if (board[row + diry][col + dirx] == '*'){
    return 0;
  }
  else if (board[row + diry][col + dirx] == switch_player(player)) {
    // printf("add stuff in surr\n");
    // printf("dir y %u\n", (row + diry));
    // printf("dir x%u\n", (col + dirx));
    // printf("surr %u\n", surroundings(board, player, (row + diry), (col + dirx), dirx, diry));
    return surroundings(board, player, (row + diry), (col + dirx), dirx, diry);
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
  int i,j;
  for ( i = -1; i < 2; i++) {
    for ( j = -1; j < 2; j++) {
      if (i != 0 || j != 0){
        if (surroundings(board, player, row, col, i, j) == 1){
          return 1;
        }
      }
    }
  }
  return 0;
}


/*  flip_pieces: flips stones that should be flipped. Returns amount flipped
 * inputs:
 * 	char board[8][8] -- current board
 * unsigned int row - row to move to
 * unsigned int col - col to move to
 * outputs:
 *  Amount of stones flipped
*/
unsigned int flip_pieces(char board[8][8], unsigned int row, unsigned int col) {
  int i, j, count;
  char player = board[row][col];
  count = 0;
  for ( i = -1; i < 2; i++) {
    for ( j = -1; j < 2; j++) {
      if (i != 0 || j != 0){
        // printf("surr in flip %u \n", surroundings(board, player, row, col, i,j));
        // if (surroundings(board, player, row, col, i,j))
        // printf("surr in flip dirx %d", i);
        // printf("surr in flip diry %d\n", j);
        if (surroundings(board, player, row, col, i, j) == 1){
          // printf("added stuff in flip\n");
          // printf("row %u\n", row);
          // printf("col %u\n", col);
          // printf("i %u\n", i);
          // printf("j %u\n", j);
          // printf("stone %c\n", board[row + j][col + i]);
          // printf("hell0s\n");
          while (board[row + j][col + i] == switch_player(player)){
            count++;
            board[row + j][col + i] = player;
            row += j;
            col += i;
          }
        }
      }
    }
  }
  return count;
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
    printf("1\n");
    return 0;
  }

  if (in_line(board, player, row, col) == 0){
    printf("2\n");
    return 0;
  }
  board[row][col] = player;
  print_othello_board(board);
  unsigned int flipped = flip_pieces(board, row, col);
  if (flipped == 0){
    board[row][col] = '*';
    printf("3\n");
    return 0;
  }
  else {
    return (flipped + 1);
  }
}



/*  player: determines winner from board of finished game
 * inputs:
 * 	char board[8][8] -- current board
 * outputs:
 *  char -- char of winner. '*' if a tie
*/
char player_won(char board[8][8]) {
  int i,j, black, white;
  white = 0;
  black = 0;
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      if (board[i][j] == 'B'){
        black++;
      }
      else {
        white++; // Grader: What about when board[i][j] == *
      }
    }
  }
  if (black < white){ // Grader: The winner should have more pieces, not fewer
    return 'B';
  }
  else if (white > black){
    return 'W';
  }
  else {
    return '*';
  }
}


/*  computer_move: Chooses valid move given board and player turn. Returns move
 * inputs:
 * 	char board[8][8] -- current board
 *  char player -- whose move it is
 * unsigned int *row - pointer to be used to return move row
 * unsigned int *col - pointer to be used to return move col
 * outputs:
 *  If move made, return 1. If not possible, return 0.
 */
int computer_move(char board[8][8], char player, unsigned int *row, unsigned int *col) {
  int i,j;

  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      if (place_piece(board, player, i, j) == 1){
        // Grader: What if place_piece returns something greater than 1?
        *row = i;
        *col = j;
        return 1;
      }
    }
  }
  return 0;
}




/*  play_othello: Game loop which implements above functions for 2 players to
 * play othello
 * inputs:
 *   none - Info gathered through scan
 * outputs:
 *  None. all print statements
 */

void play_othello() {

	char player[2] = {'W','B'};
	int num_tiles[2] = {2,2};
	unsigned int cur_play = 1;
	char board[8][8];
	unsigned int move_num = 0;

	unsigned int num_invalid_moves = 0;
	unsigned int num_valid_moves = 0; // number invalid moves in a row for one player
	unsigned int num_invalid_player = 0; // number of players with invalid moves in a row


	// initialize the game board
	init_board(board);

	// play one move of the game
	do {
		unsigned int row, col;
		unsigned int valid_move;

		print_othello_board(board);

		// get the row input
		do {
			printf("Player %c, in what row (0-7) will you place your next piece? ",
					player[cur_play]);
			scanf("%u",&row);

			// if it is an invalid row
			if (row >= 8)
			{
				printf("Player %c, that is not a valid row. Try again.\n",
					player[cur_play]);
			}
		} while ( row >= 8 );

		// get the col input
		do {
			printf("Player %c, in what column (0-7) will you place your next piece? ",
					player[cur_play]);
			scanf("%u",&col);

			// if it is an invalid column
			if (col >= 8)
			{
				printf("Player %c, that is not a valid col. Try again.\n",
					player[cur_play]);
			}
		} while ( col >= 8 );

		valid_move = place_piece(board, player[cur_play], row, col);

		// if it is not a valid move
		if (valid_move == 0)
		{
			// if they already had an invalid move, switch players
			if (num_invalid_moves > 0)
			{
				num_invalid_moves = 0;
				num_invalid_player++;
			}
			else
			{
				// try again!
				printf("That is not a valid move. Try again.\n");
				num_invalid_moves++;
			}

		}
		// flip the tiles
		else
		{
			// add one tile for the tile being placed
			num_tiles[cur_play] += valid_move;

			// switch player
			cur_play = (cur_play + 1)%2;
			num_invalid_moves = 0;
			num_invalid_player = 0;
			num_valid_moves++;
			// subtract flipped tiles from this player's total
			num_tiles[cur_play] -= (valid_move-1);

			// report progress
			printf("White: %u tiles, Black: %u tiles\n", num_tiles[0], num_tiles[1]);
		}

	// exit while there is still space on the board and we haven't had two players with invalid
	// plays in a row
	} while ((num_valid_moves < 64) && (num_invalid_player < 2));

	char winner = player_won(board);
			// check for winning
	if (winner == '*')
	{
		printf("Tie game!\n");
	}
	else
	{
		printf("Congratulations! Player %c won!\n",winner);
	}

}
