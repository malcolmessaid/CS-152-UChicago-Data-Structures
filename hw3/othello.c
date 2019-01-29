#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "othello_funcs.h"



int main() {
  char board1[8][8];
  init_board(board1);
  char first = 'B';

  //print_othello_board(board1);
  // printf("\n");
  // printf("%u\n", place_piece(board1, first, 2, 3));
  // printf("\n");
  // print_othello_board(board1);
//  printf("%u\n", surroundings(board1, 'B', 2, 3, 0, 1)); // THIS WORKS
  play_othello();


//  printf("%u\n", in_line(board1, 'B', 2, 3));
//  printf("%u\n", flip_pieces(board1, 2, 3));

  return 0;
}
