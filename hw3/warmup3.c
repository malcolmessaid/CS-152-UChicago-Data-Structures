#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "warmup3.h"
#include <limits.h>

void print_tic_tac_toe_board( char board[3][3] )
{
	unsigned int i, j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%c ",board[i][j]);
		}
		printf("\n");
	}
}


/*  remove_max: Removes max(es) from an array
 * inputs:
 * 	int array[] - array
 * unisgned int - length
 * outputs:
 *  int - maximum that was removed
 */
int remove_max(int array[], unsigned int length) {

	if (length == 0) {
		return INT_MIN;
	}

	int i, j;
	int max = array[0];
//	int index = 0;
	for (i = 0; i < length; i++){
		if (array[i] > max) {
			max = array[i];
		}
	}

	for(i = 0; i < (length - 1) ; i++){
		if (array[i] == max){
			for (j = i; j < length; j++) {
				array[j] = array[j+1];
			}
			i--;
		}
	}
	return max;
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
		for(j = 0; j < 3; j++){
			board[i][j] = '*';
		}
	}
}


/*  place_piece: Places piece on the board, if a valid move.
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


/*  area_and_perimeter: finds area and premieter given height and length
 * inputs:
 * 	double height - height
 *  double length - length
 * double *area - pointer to return area
* double *perimeter - pointer to return area perimeter
 * outputs:
 *  Void. POinters used to set area and perimeter
*/
void area_and_perimeter(double height, double length, double *area, double *perimeter){
	*area = height * length;
	*perimeter = (2 * height) + (2 * length);
}

/*  remove_max_in_out: takes in array, removes max and changes length
 * inputs:
 * 	int array[] -- array to be removed from
 *  unsigned int *length --- lengh pointer to change
 * double *area - pointer to return area
* double *perimeter - pointer to return area perimeter
 * outputs:
 *  Max. change array and length
*/

int remove_max_in_out(int array[], unsigned int *length){

		if (*length == 0) {
			return INT_MIN;
		}
		int i, j;
		int max = array[0];
		int len = *length;
		for (i = 0; i < len; i++){
			if (array[i] > max) {
				max = array[i];
			}
		}

		for(i = 0; i < (len - 1) ; i++){
			if (array[i] == max){
				for (j = i; j < len; j++) {
					array[j] = array[j+1];
				}
				i--;
				(*length)--;
			}
		}
		return max;
}
