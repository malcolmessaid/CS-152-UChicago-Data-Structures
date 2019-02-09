#include <stdio.h>
#include <stdlib.h>
#include "warmup5.h"


int main(int argc, char const *argv[]) {

  // problem 1 tests
  char *str1;
  str1 = "malcolm";
  char *str2;
  str2 = "essaid";
  printf("%s\n", safe_str_concat(str1, str2));


  int_vector *vectorTest = make_init_array();
  printf("%d\n", vectorTest->allocated_size);


  write_value(vectorTest, 0, 1);
  write_value(vectorTest, 1, 2);
  write_value(vectorTest, 2, 3);
  write_value(vectorTest, 3, 4);
  printf("%d\n", vectorTest->allocated_size);

  int i;
  for (i = 0; i < vectorTest->allocated_size; i++) {
    printf("%d", vectorTest->array[i]);
  }
  printf("\n");

  printf("Should be 2: ");
  printf("%d\n", read_value(vectorTest, 1));
  printf("Should be 0: ");
  printf("%d\n", read_value(vectorTest, 10));





}
