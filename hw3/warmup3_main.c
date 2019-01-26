#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "warmup3.h"




int main() {
  // Problem 1
  int board1[] = {1, 3, 6, 5, 6, 2, 3};
  printf("Problem 1 Test\n");
  printf("%d\n\n", remove_max(board1, 7));

  // Problem 2
  char board2[3][3];
  printf("Problem 2 Test\n");
  init_board(board2);


  // Problem 3
  char board3[3][3];
  printf("Problem 3 Test\n");
  place_piece(board3,'A', 1, 1);

 // Problem 4
 double *a, *p;
 double area, permi;
 area = 0.0;
 permi = 0.0;
 a = &area;
 p = &permi;
 area_and_perimeter(3, 4, a, p);
 // How do you print a pointer
 printf("Problem 4 Test\n");
 printf("%f\n", area);
 printf("%f\n\n", permi);

  // Problem 5
  int test5[] = {1, 3, 6, 5, 6, 2, 3};
  unsigned int *len;
  unsigned int length5 = 7;
  len = &length5;
  printf("Problem 5 Test\n");
  printf("%d\n",remove_max_in_out(test5, len));
  printf("%d\n\n", length5);


  return 0;
}
