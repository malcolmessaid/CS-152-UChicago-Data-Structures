#include <stdio.h>
#include <stdlib.h>
#include "hw5.h"
#include <string.h>

int main(int argc, char const *argv[]) {
  printf("HW5 Testing\n");
  if( atoi(argv[1]) == 1 ) {
    printf("TESTS FOR make_empty_string\n");
    safe_string *strTest =  make_empty_string();

    printf("make_empty_string: should be empty: %s\n", strTest->str);
    printf("make_empty_string: should be 1: %u\n", strTest->allocated_length);


  }

  else if (atoi(argv[1]) == 2) {
    printf("TESTS FOR make_string safe_str_cpy and safe_str_cat\n");
    safe_string *strTest =  make_empty_string();
    safe_string *strTest1 = make_string("malcolm");
    safe_string *strTest2 = make_string("ess");
    safe_string *strTest3 = make_string("mahmoud");
    safe_string *strTest4 = make_string("essaid");
    safe_string *strTest5 =  make_empty_string();
    safe_string *strTest6 = make_string("string");

    printf("make_string: %s\n", strTest1->str);
    printf("make_string: %s\n", strTest2->str);
    printf("make_string: %s\n", strTest3->str);

    safe_str_cpy(strTest, strTest1);
    safe_str_cpy(strTest3, strTest2);
    printf("safe_str_cpy: should be ess: %s\n", strTest3->str);
    safe_str_cpy(strTest6, strTest5);
    printf("safe_str_cpy: should be empty: %s\n", strTest6->str);



    safe_str_cat(strTest1, strTest4);
    safe_str_cat(strTest4, strTest3);
    printf("safe_str_cat: Should be essaidess: %s\n", strTest4->str);
    printf("safe_str_cat: Length of above %d\n", strTest4->allocated_length);
    safe_str_cat(strTest4, strTest5);
    printf("safe_str_cat: Should be essaidess, same as above: %s\n", strTest4->str);
    printf("safe_str_cat: Length of above, same as above %d\n", strTest4->allocated_length);


    printf("safe_str_cat: Should be malcolmessaid: %s\n", strTest1->str);
    printf("safe_str_cat: Length of above: %d\n", strTest1->allocated_length);

  }

  else if (atoi(argv[1]) == 3) {
    printf("TESTS FOR safe_strchr\n");
    safe_string *strTest2 = make_string("ess");
    safe_string *strTest3 = make_string("mahmoud");
    safe_string *strTest4 = make_string("essaid");

    char* searchtest1 = safe_strchr(strTest3, 'o');
    char* searchtest2 = safe_strchr(strTest2, 'o');
    char* searchtest3 = safe_strchr(strTest4, 'e');
    printf("strchr1: should be oud: %s\n", searchtest1);
    printf("strchr2: should be NULL: %s\n", searchtest2);
    printf("strchr3: should be essaid: %s\n", searchtest3);
  }
  else if (atoi(argv[1]) == 4) {
    safe_string *strTest11 = make_string("aaab");
    safe_string *strTest22 = make_string("Adfa");
    safe_string *strTest33 = make_string("mahmoud");
    safe_string *strTest44 = make_string("Essaid");
    safe_string *strTest66 = make_string("");
    safe_string *strTest77 = make_string("mahmoud");

    printf("Shuld be 1: %d\n", safe_strcmp(strTest11, strTest22));
    printf("Should be -1: %d\n", safe_strcmp(strTest22, strTest11));
    printf("Should be -1: %d\n", safe_strcmp(strTest44, strTest33));
    printf("Should be 0: %d\n", safe_strcmp(strTest77, strTest33));
    printf("Empty test: %d\n", safe_strcmp(strTest66, strTest11));
    }

  }
