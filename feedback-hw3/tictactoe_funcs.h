#ifndef TICTACTOE_FUNCS_H
#define TICTACTOE_FUNCS_H


#include <stdio.h>
#include <stdlib.h>


void print_tic_tac_toe_board( char board[3][3] );

void init_board(char board[3][3]);

unsigned int place_piece(char board[3][3], char player, unsigned int row, unsigned int col);

int player_won(char board[3][3], char player, unsigned int row, unsigned int col);

int computer_move(char board[3][3], char player, unsigned int *row, unsigned int *col);

void play_tic_tac_toe();

#endif
