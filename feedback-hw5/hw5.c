#include <stdio.h>
#include <stdlib.h>
#include "hw5.h"
#include <string.h>
#include <math.h>


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


/* safe_str_cpy
 * Searches stycpy for safe_string. Allocates new memory if necessary, does
 * not if not not necessary
 * input:
 *    safe_string *dest - pointer to be copied into
 *    safe_string *src - string to be copied over
 * output: void
*/
void safe_str_cpy(safe_string *dest, safe_string *src){
  if (dest == NULL || src == NULL){
      fprintf(stderr, "error safe_str_cpy: pointers must be declared to values"
      "\n");
      return;
  }

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
  else {
    for (i = 0; i < len_src; i++) {
      (dest->str)[i] = src->str[i];
    }

    dest->allocated_length = src->allocated_length;
  }
}

/* safe_str_cat
 * Searches concatanates safe_string. Allocates new memory if necessary.
 * input:
 *    safe_string *dest - string to be copied to
 *    safe_string *src - string to be copied over
 * output: void
*/
void safe_str_cat(safe_string *dest, safe_string *src){

  if (dest == NULL || src == NULL){
      fprintf(stderr, "error safe_str_cats: pointers must be declared to values"
      "\n");
      return;
  }

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

/* safe_strchr
 * Searches safe_string for char c.
 * input:
 *    safe_string *s -- String to be searched
 *    char c - char to look for
 * output: char* - Returns pointer to first instance of c. NULL if not in string
*/
char *safe_strchr(safe_string *s, char c) {
  int i;
  for (i = 0; (i < s->allocated_length) || (s->str[i] != '\0') ; i++) {
    if (s->str[i] == c) {
      char *new_str = (char*)malloc(sizeof(char));
      new_str = &(s->str[i]);
      return new_str;
    }
  }
  return NULL;
}


/* safe_strcmp
 * Compares safestring s1 and s2. Compares alphabeticly, with A being smaller
 * a.
 * input:
 *    safe_string *s1  -- safe string 1
 *    safe_string *s2  -- safe string 2
 * output: int - Returns -1 if s1 is smaller, 0 if equal. 1 if s1 is greater.
*/
// Empty string check
int safe_strcmp(safe_string *s1, safe_string *s2) {
  int i;

  for (i = 0; i < s1->allocated_length; i++) {
    if ((s1->str[i] < s2->str[i]) && (abs(s1->str[i] - s2->str[i]) != 32)) {
      return -1;
    }
    else if (s1->str[i] < s2->str[i] ) {
      return -1;
    }
    if ((s1->str[i] > s2->str[i]) && abs(s1->str[i] - s2->str[i]) != 32){
      return 1;
    }
    else if (s1->str[i] > s2->str[i] ) {
      return 1;
    }
  }
  return 0;
}
