#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "warmup3.h"

/*  remove_max_test: tests remove_max
 * inputs:
 * 	int array[] - array
 * unisgned int - length
 * int expected - expected value
 * outputs:
 *  1 if passed. 0 if Failed.
 */
unsigned int remove_max_test(int array[], unsigned int length, int expected) {
  int temp = remove_max(array, length);
  if (temp == expected){
    printf("Test Passed\n");
    return 1;
  }
  else {
    printf("Test Failed\n");
    return 0;
  }
}


/*  init_board_test: tests init_board
 * inputs:
 * 	char board[3][3] - initlized 3 by 3 array.
 * outputs:
 *  nothing
 */
unsigned int init_board_test(char board[3][3], char expected[3][3]){
  int i,j;

  for ( i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (board[i][j] != expected[i][j]){
        printf("Test Failed\n");
        return 0;
      }
    }
  }
  printf("Test Passed\n");
  return 1;
}

int main() {
  // Problem 1
  int board1[] = {1, 3, 6, 5, 6, 2, 3};
  int board3[] = {1, 5, 9, 1, 123, 4, 2};
  int board4[] = {1, 3, 6, 5, 6, 2, 3};
  int board5[] = {1};
  printf("Problem 1 Test\n");
  printf("%d\n", remove_max(board1, 7));
  remove_max_test(board3, 7, 123);
  remove_max_test(board5, 1, 1);
  printf("\n");

  // Problem 2
  char board2[3][3];
  char board10[3][3] = {{'*', '*', '*'},
                        {'*', '*', '*'},
                        {'*', '*', '*'}};
  printf("Problem 2 Test\n");
  init_board(board2);
  init_board_test(board2, board10);



  // Problem 3
  char board6[3][3];
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
