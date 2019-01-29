#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "othello_funcs.h"



int main() {
  char board1[8][8];
  init_board(board1);
  char first = 'B';

  print_othello_board(board1);
  printf("\n");
  place_piece(board1, first, 2, 3);
  printf("\n");
  print_othello_board(board1);
  //play_othello();

  return 0;
}
