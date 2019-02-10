#include <stdio.h>
#include <stdlib.h>
#include "hw5.h"
#include <string.h>

int main(int argc, char const *argv[]) {

  safe_string *strTest =  make_empty_string();

  printf("%s\n", strTest->str);
  printf("%u\n", strTest->allocated_length);


  safe_string *strTest1 = make_string("malcolm");
  safe_string *strTest2 = make_string("ess");
  safe_string *strTest3 = make_string("mahmoud");
  safe_string *strTest4 = make_string("essaid");

  printf("%s\n", strTest1->str);
  printf("%u\n", strTest1->allocated_length);

  printf("copy\n");
  safe_str_cpy(strTest, strTest1);
  printf("%s\n", strTest->str);

  safe_str_cpy(strTest3, strTest2);
  printf("This is test3: %s\n", strTest3->str);


  safe_str_cat(strTest1, strTest4);
  printf("%s\n", strTest1->str);
  printf("%d\n", strTest1->allocated_length);

  safe_str_cat(strTest4, strTest3);
  printf("%s\n", strTest4->str);
  printf("%d\n", strTest4->allocated_length);
}
