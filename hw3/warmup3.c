#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "warmup3.h"

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
	fprintf(stderr, "error remove_max not yet implemented\n");
	return 1;
}

// Problem 2
void init_board(char board[3][3]) {
  fprintf(stderr, "error init_board not yet implemented\n");
	return;
}


// Problem 3
unsigned int place_piece(char board[3][3], char player, unsigned int row, unsigned int col){
  fprintf(stderr, "error place_piece not yet implemented\n");
	return 1;
}


// Problem 4
void area_and_perimeter(double height, double length, double *area, double *perimeter);

// Problem 5
int remove_max_in_out(int array[], unsigned int *length);
