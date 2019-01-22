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


// Problem 1
int remove_max(int array[], unsigned int length) {
	
	if (length == 0) {
		return INT_MIN;
	}	

	int i, j;
	int max = array[0];	 
	int index = 0;
	for (i = 0; i < length; i++){
		if (array[i] == max) {
			max == array[i];
			index = i;
			for(i = index; i < (length - 1) ; i++){
                		array[i] = array[i + 1];
        		}
 
		}
		i--;
	}
		
	for(i = index; i < (length - 1) ; i++){
		array[i] = array[i + 1];
	}
	return max; 
}


//	fprintf(stderr, "error remove_max not yet implemented\n");
//	return 1;
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

	//  fprintf(stderr, "error place_piece not yet implemented\n");
//	return 1;
}


// Problem 4
void area_and_perimeter(double height, double length, double *area, double *perimeter);

// Problem 5
int remove_max_in_out(int array[], unsigned int *length);
