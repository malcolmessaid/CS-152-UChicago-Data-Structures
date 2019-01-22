#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "warmup3.h"




int main() {
  // Problem 1
  int board1[3];
  remove_max(board1, 3);

  // Problem 2
  char board2[3][3];
  init_board(board2);


  // Problem 3
  char board3[3][3];
  place_piece(board3,'A', 1, 1);


// Intrsuctions were confusing. Not sure if we're supposed to call these
  //
  // // Problem 4
  // void area_and_perimeter(double height, double length, double *area, double *perimeter);
  //
  // // Problem 5
  // int remove_max_in_out(int array[], unsigned int *length);
  return 0;
}
