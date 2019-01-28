#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tictactoe_funcs.h"





int main(){
  char board2[3][3];
  init_board(board2);

  char board3[3][3];
//  printf("Problem 3 Test\n");
  place_piece(board3,'A', 1, 1);

  printf("hello\n");

  player_won(board3,'A', 1, 1);

  unsigned int *r, *c;
  unsigned int row, col;
  row = 0;
  col = 0;
  r = &row;
  c = &col;

  computer_move(board3, 'A', r, c);

  play_tic_tac_toe();
}
