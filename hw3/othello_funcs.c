#include <stdio.h>
#include <stdlib.h>
#include "othello_funcs.h"
#include <math.h>




void print_othello_board( char board[8][8] )
{
        unsigned int i, j;
        for(i=0;i<8;i++)
        {
                for(j=0;j<8;j++)
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
	// for (i = 0; i < length; i++) {
	// 	printf("%d\n", array[i]);
	// }

	return max;
}


// Problem 2
void init_board(char board[3][3]) {
	int i, j;
	for (i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			board[i][j] = '*';
		}
	}

//  fprintf(stderr, "error init_board not yet implemented\n");
//	return;
}


// Problem 3
unsigned int place_piece(char board[3][3], char player, unsigned int row, unsigned int col){
	if ((row >= 3) || (col >= 3)){
		return 0;
	}
	else {
		board[row][col] = player;
		return 1;
	}
}


// Problem 4
void area_and_perimeter(double height, double length, double *area, double *perimeter){
	*area = height * length;
	*perimeter = (2 * height) + (2 * length);
}

// Problem 5
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
