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
