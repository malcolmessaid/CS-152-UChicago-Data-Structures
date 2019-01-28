#include <stdio.h>
#include <stdlib.h>
#include "tictactoe_funcs.h"
#include <math.h>




/*  print_tic_tac_toe_board: prints the current boad
 * inputs:
 * 	char board[3][3] - current state of board
 * outputs:
 *  nothing
 */

void print_tic_tac_toe_board( char board[3][3] )
{
	unsigned int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%c ",board[i][j]);
		}
		printf("\n");
	}
}

/*  init_board: Fills a tictactoe board with asteriks
 * inputs:
 * 	char board[3][3] - initlized 3 by 3 array.
 * outputs:
 *  nothing
 */

void init_board(char board[3][3]) {
	int i, j;
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			board[i][j] = '*';
		}
	}
}

/*  place_piece: Places piece on the board.
 * inputs:
 * 	char board[3][3] -- current board
 *  char player -- whose move it is
 * unsigned int row - row to move to
 * unsigned int col - col to move to
 * outputs:
 *  If move made, return 1. If not, return 0.


unsigned int place_piece(char board[3][3], char player, unsigned int row, unsigned int col){
	if ((row > 2) || (col > 2)){
		return 0;
	}
	else if ((board[row][col] == 'X') || (board[row][col] == 'O')) {
		return 0;
	}
	else {
		board[row][col] = player;
		return 1;
	}
}


/*  player_won: In this function, player has just placed its piece in location row, col.
		Checks to see if this makes player win the game.
 * inputs:
 * 	char board[3][3] -- current board
 *  char player -- whose move it is
 * unsigned int row - location of move
 * unsigned int col - location of move
 * outputs:
 *  If the player has won, return 1. If not, return 0.
 */
int player_won(char board[3][3], char player, unsigned int row, unsigned int col) {

	// Horizantal check
	if ((board[row][0] == player) && (board[row][1] == player) && (board[row][2] == player)) {
		return 1;
	}

	// Vertical Check
	else if ((board[0][col] == player) && (board[1][col] == player) && (board[2][col] == player)) {
		return 1;
	}

	// Diagonal Check
	else if (col == row){
		if ((board[0][0] == player) && (board[1][1] == player) && (board[2][2] == player)) {
			return 1;
		}
	}

	return 0;
}


/*  computer_move: Chooses optimal move given board and player turn. Returns move
 * inputs:
 * 	char board[3][3] -- current board
 *  char player -- whose move it is
 * unsigned int *row - pointer to be used to return move row
 * unsigned int *col - pointer to be used to return move col
 * outputs:
 *  If move made, return 1. If not, return 0.
 */
int computer_move(char board[3][3], char player, unsigned int *row, unsigned int *col) {
		// Determing whose turn it is
		char opp;
		if (player == 'X'){
			opp = 'O';
		}
		else {
			opp = 'X';
		}


		int i, j, a, b;
		char temp[3][3];
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				temp[i][j] = board[i][j];
			}
		}

		// Win or prevent from winning
		for (i = 0; i < 3; i++) {

			// Sets temp
			for (a = 0; a < 3; a++) {
				for (b = 0; b < 3; b++) {
					temp[i][j] = board[i][j];
				}
			}

			for (j = 0; j < 3; j++) {
				if (player_won(board, player, i, j) == 1){
					*row = i;
					*col = j;
					return 1;
				}
				place_piece(temp, opp, i, j);
				if (player_won( temp, opp , i , j) == 1){
					*row = i;
					*col = j;
					return 1;
				}
			}
		}

		// Move to center if open
		if (board[1][1] == '*'){
			*row = 1;
			*col = 1;
			return 1;
		}

		// Move to an open diagonal
		for (i = 0; i < 3; i+=2) {
			for (j = 0; j < 3; j+=2) {
				if (board[i][j] == '*'){
					*row = i;
					*col = j;
					return 1;
				}
			}
		}

		// Everything else exhausted. Just move anywhere open
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				if (board[i][j] == '*'){
					*row = i;
					*col = j;
					return 1;
				}
			}
		}

	 	return 0;


	}



	/*  switch_player: Returns opposite player of whose turn it is
	 * inputs:
	 *  char player -- whose move it is
	 * outputs:
	 *  char -- opposite player of input
	 */
	char switch_player(char player) {
		if (player == 'X'){
			return 'O';
		}
		else {
			return 'X';
		}
	}



	/*  play_tic_tac_toe: Game loop which implements above functions for 2 players to
	 * play tictactoe
	 * inputs:
	 *   none - Info gathered through scan
	 * outputs:
	 *  None. all print statements
	 */

 void play_tic_tac_toe() {

	 unsigned int row = 0;
	 unsigned int col = 0;
	 unsigned int *r, *c;
	 r = &row;
	 c = &col;


	 char player = 'X';



	 char board[3][3];
	 init_board(board);


	 while (computer_move(board, player, r, c) != 0){
		 // Define row
		 printf("Player %c, in what row (0-2) will you place your next piece? \n", player);
		 scanf("%u", &row);

		 while ((row > 2)) {
		 	printf("Player %c, that is not a valid row. Try again. \n", player); // ask for row again
			printf("Player %c, in what row (0-2) will you place your next piece? ", player);
			scanf("%u",&row);
		 }

		 // Define col
		 printf("Player %c, in what column (0-2) will you place your next piece? \n", player);
		 scanf("%u",&col);

		 while ((col > 2)) {
	 	 	printf("Player %c, that is not a valid column. Try again. \n", player); // ask for column again
			printf("Player %c, in what column (0-2) will you place your next piece? ", player);
			scanf("%u",&col);
		 }


		 // Move the piece
		 if (place_piece(board, player, row, col) == 0){
			 	printf("That is not a valid move. Try again. \n");
				print_tic_tac_toe_board(board);
		 }
		 else if (player_won(board, player, row, col) == 1){
			 	printf("Congratulations! Player %c won! \n", player);
				print_tic_tac_toe_board(board);
			 	return;
		 }
		 else {
				print_tic_tac_toe_board(board);
				player = switch_player(player);
		 }
	 }

	 	printf("Tie game!\n");

 }
