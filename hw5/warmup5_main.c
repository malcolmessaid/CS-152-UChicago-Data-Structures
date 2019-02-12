#include <stdio.h>
#include <stdlib.h>
#include "warmup5_provided.h"
#include "warmup5.h"


int main(int argc, char const *argv[]) {

  if( atoi(argv[1]) == 1 ) {

     char *str1;
     char *str2;
     char *str3;
     char *str5;
     str1 = "malcolm";
     str2 = "essaid";
     str3 = "";
     str5 = "world";

     printf("safe_str_concat: should be malcolmessaid: %s\n",
     safe_str_concat(str1, str2));
     printf("safe_str_concat: should be malcolm: %s\n",
     safe_str_concat(str1, str3));
     printf("safe_str_concat: should be world: %s\n",
     safe_str_concat(str3, str5));

  }
  else if( atoi(argv[1]) == 2 ) {
    printf("Tests for make_and_init_array, write_value and read_value\n");
    int_vector *vectorTest = make_init_array();
    printf("make_init_array: should be 0%d\n", vectorTest->allocated_size);



    write_value(vectorTest, 0, 1);
    printf("write_value: Should be 1: %d\n", vectorTest->allocated_size);
    printf("read_value/write_value: Should be 1: %d\n", read_value(vectorTest, 0));
    write_value(vectorTest, 1, 2);
    printf("write_value: Should be 2: %d\n", vectorTest->allocated_size);
    printf("read_value/write_value: Should be2: %d\n", read_value(vectorTest, 1));
    write_value(vectorTest, 2, 3);
    printf("write_value: Should be 3: %d\n", vectorTest->allocated_size);
    printf("read_value/write_value: Should be 3: %d\n", read_value(vectorTest, 2));
    write_value(vectorTest, 3, 4);
    printf("write_value: Should be 4: %d\n", vectorTest->allocated_size);
    printf("read_value/write_value: Should be 4: %d\n", read_value(vectorTest, 3));
    printf("\n");

    printf("read_value: should be 0: %d\n", read_value(vectorTest, 10));
  }
  else if( atoi(argv[1]) == 3 ) {
    pixel blue;
    blue.red = atoi(argv[2]);
    blue.blue = atoi(argv[3]);
    blue.green = atoi(argv[4]);

    pixel **bluearray = make_and_init_image(atoi(argv[5]), atoi(argv[5]), blue);
    provided_write_png_struct("ex3.png", bluearray, atoi(argv[5]), atoi(argv[5]));

    pixel multi;

    multi.red = atoi(argv[6]);
    multi.blue = atoi(argv[7]);
    multi.green = atoi(argv[8]);

    pixel **multiarray = make_and_init_image(atoi(argv[5]), atoi(argv[5]), multi);
    provided_write_png_struct("multi.png", multiarray, atoi(argv[5]), atoi(argv[5]));

  }












}
