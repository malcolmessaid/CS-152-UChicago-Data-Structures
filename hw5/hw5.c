#include <stdio.h>
#include <stdlib.h>
#include "hw5.h"
#include <string.h>


// typedef struct {
// 	char *str;
// 	uint allocated_length;
// } safe_string;


/* make_empty_string
 * The first one creates an empty string.
 * output: int - safe_string reprsenting empty string
 */


safe_string* make_empty_string() {
  safe_string *newstr;
  newstr = (safe_string*)malloc(sizeof(safe_string));

  char *empty;
  empty = (char*)malloc(sizeof(char) * 1);
  *empty = '\0';

  newstr->str = empty;
  newstr->allocated_length = 1;

  return newstr;
}

/* make_string
 * Makes string struct with string of input
 * input: char *str - a string to be assigned
 * output: int - safe_string with str as string field
 */
safe_string* make_string(char *str){
  if (str == NULL) {
    return make_empty_string();
  }

  safe_string *new_safe = make_empty_string();
  int i, len;
  len = 0;
  for (i = 0; str[i] != '\0'; i++) {
    len++;
  }

  free(new_safe->str);
  new_safe->str = (char*)malloc(sizeof(char) * (1 + len));

  for (i = 0; i < len; i++) {
    (new_safe->str)[i] = str[i];
  }

  (new_safe->str)[len] = '\0';
  new_safe->allocated_length = (1 + len);

  return new_safe;
}



void safe_str_cpy(safe_string *dest, safe_string *src){
  int len_src, len_dest, i;
  len_src = src->allocated_length;
  len_dest = dest->allocated_length;


  if (len_src > len_dest) {
    free(dest->str);

    dest->allocated_length = src->allocated_length;

    dest->str = (char*)malloc(sizeof(char) * len_src);

    for (i = 0; i < len_src; i++) {
      (dest->str)[i] = src->str[i];
    }
  }
  // I do not understand how this works
  else {
    for (i = 0; i < len_src; i++) {
      (dest->str)[i] = src->str[i];
    }

    dest->allocated_length = src->allocated_length;
  }
}

// Needs to be tested for else statement
void safe_str_cat(safe_string *dest, safe_string *src){
  int len_src, len_dest, i, total_len;
  len_dest = 0;
  len_src = 0;

  for (i = 0; dest->str[i] != '\0'; i++) {
    len_dest++;
  }
  for (i = 0; src->str[i] != '\0'; i++) {
    len_src++;
  }
  total_len = len_src + len_dest;

  if (total_len > dest->allocated_length) {
    printf("here\n");
    char *new_str = (char*)malloc(sizeof(char) *
                    (dest->allocated_length + src->allocated_length));

    for (i = 0; i < len_dest; i++) {
      new_str[i] = (dest->str)[i];
    }
    for (i = len_dest; i < total_len; i++) {
      new_str[i] =  src->str[i - len_dest];
    }

    free(dest->str);
    dest->str = new_str;
    dest->allocated_length = dest->allocated_length + src->allocated_length - 1;
  }
  else {
    for (i = len_dest; i < total_len; i++) {
      (dest->str)[i] = src->str[i - len_dest];
    }
  }
}
