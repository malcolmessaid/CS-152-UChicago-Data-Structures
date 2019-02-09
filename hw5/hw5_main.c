#include <stdio.h>
#include <stdlib.h>
#include "hw5.h"

int main(int argc, char const *argv[]) {

  safe_string *strTest =  make_empty_string();

  printf("%s\n", strTest->str);
  printf("%u\n", strTest->allocated_length);


  safe_string *strTest1 = make_string("malcolm");

  printf("%s\n", strTest1->str);
  printf("%u\n", strTest1->allocated_length);

}
