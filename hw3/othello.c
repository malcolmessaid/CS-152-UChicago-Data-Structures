#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "othello_funcs.h"



int main() {
  char board1[8][8];
  init_board(board1);

  print_othello_board(board1);

  return 0;
}
