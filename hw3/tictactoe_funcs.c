#include <stdio.h>
#include <stdlib.h>
#include "tictactoe_funcs.h"
#include <math.h>



void print_tic_tac_toe_board( char board[3][3] )
{
	unsigned int i, j;
	for (i = 0;i<3;i++)
	{
		for (j = 0;j < 3; j++)
		{
			printf("%c ",board[i][j]);
		}
		printf("\n");
	}
}


/*  print_backwards_base_8: Takes in a number in base 10. Switchs to base 8
 * then it reverses it
 * inputs:
 * 	unsigned int num - value to be converted/reversed
 * outputs:
 *  nothing. Function prints the new value
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
 */
unsigned int place_piece(char board[3][3], char player, unsigned int row, unsigned int col){
	if ((row >= 3) || (col >= 3)){
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


		int i, j;
//		char temp[3][3];
	//	temp = board;
		// Win or prevent from winning
		for (i = 0; i < 3; i++) {
		//	temp = board;
			for (j = 0; j < 3; j++) {
				if (player_won(board, player, i, j) == 1){
					*row = i;
					*col = j;
					return 1;
				}
				// else if (player_won( , opp , i , j) == 1){
				// 	*row = i;
				// 	*col = j;
				// 	return 1;
				// }
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



	// printf("Player %c, in what column (0-2) will you place your next piece? ",...);
	// scanf("%u",...);
	// printf("Player %c, that is not a valid column. Try again. "...); // ask for column again
	// printf("That is not a valid move. Try again. "...); // go back and ask for row again
	// printf("Congratulations! Player %c won!",...);
	// printf("Tie game!",...);
	//

 void play_tic_tac_toe() {
	 int row = 0;
	 int col = 0;
	 char player = 'X';
	 char board[3][3];


	 while (player_won(board, player, row, col) != 1){
		 // Define row
		 printf("Player %c, in what row (0-2) will you place your next piece? \n", player);
		 scanf("%u", &row);

		 while ((row < 0) || (row >2)) {
		 	printf("Player %c, that is not a valid row. Try again. \n", player); // ask for row again
			printf("Player %c, in what row (0-2) will you place your next piece? ", player);
			scanf("%u",&row);
		 }

		 // Define col
		 printf("Player %c, in what column (0-2) will you place your next piece? ", player);
		 scanf("%u",&col);

		 while ((col < 0) || (col > 2)) {
			printf("Player %c, that is not a valid row. Try again. ", player); // ask for row again
			scanf("%u",&col);
		 }


		 // Move the piece
		 if (place_piece(board, player, row, col) == 0){
			 	printf("That is not a valid move. Try again. ");
		 }
		 else {
			 	print_tic_tac_toe_board(board);
		 }

		 if (player_won(board, player, row, col) == 1){
			 printf("Congratulations! Player %c won!", player);
			 return;
		 }
		 else {

		 }

		 // CHECK IF ITS A TIE, PRINT PROPERLY, CHANGE PLAYERS
	 }














	 // fprintf(stderr, "error play_tic_tac_toe not yet implemented\n");
   // return;
 }
