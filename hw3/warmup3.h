#ifndef WARMUP3_H
#define WARMUP3_H


#include <stdio.h>
#include <stdlib.h>




void print_tic_tac_toe_board( char board[3][3] );


// Problem 1
int remove_max(int array[], unsigned int length);

// Problem 2
void init_board(char board[3][3]);


// Problem 3
unsigned int place_piece(char board[3][3], char player, unsigned int row, unsigned int col);


// Problem 4
void area_and_perimeter(double height, double length, double *area, double *perimeter);


int remove_max_in_out(int array[], unsigned int *length);

#endif
