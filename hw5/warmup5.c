#include <stdio.h>
#include <stdlib.h>
#include "warmup5.h"
#include <math.h>


/* safe_str_concat
 *  allocates a brand new string that will hold both str1 and str2.
 * Then it copies both strings over, str1 at the front and str2 at the back.
 * input:
 *    char *str1 - string to concatanate
 *    char *str2 - string to concatanate
 * output: int - returns a pointer to that new string.
 */
char *safe_str_concat(char *str1, char *str2){
  char *newStr;
  int len1, len2, i;
  len1 = 0;
  len2 = 0;

  // Finding length of str1 and str2
  for (i = 0; str1[i] != '\0'; i++) {
    len1++;
  }
  for (i = 0; str2[i] != '\0'; i++) {
    len2++;
  }
  // Alloctating proper length
  newStr = (char*)malloc((sizeof(char) * len1) + (sizeof(char) * len2));

  // Copying strings
  for (i = 0; i < len1; i++) {
    newStr[i] = str1[i];
  }
  for (i = 0; i < len2; i++) {
    newStr[i + len1] = str2[i];
  }
  return newStr;
}

// typedef struct {
// 	unsigned int allocated_size;
// 	int *array;
// } int_vector;


 /* make_init_array
  *  allocates the int_vector and initializes the values for an array with 0 items
  * input: None
  * output: empty int_vector.
  */
int_vector* make_init_array() {
  // Initializes array
  // Mallocs Array
  int_vector *vector;
  vector = malloc(sizeof(int_vector));

  vector->allocated_size = 0;
  vector->array = (int*)malloc(sizeof(int) * vector->allocated_size);

  return vector;

}


/* write_value
 *  Assigns value at index in int _vector. If out of range. Allocates spaces
 * input:
 *    int_vector *vector -- int_vector assigned to
 *    unsigned int index - index where to assign
 *    int value -- value to assign
 * output: void - int_vector with given value at given index
 */
void write_value(int_vector *vector, unsigned int index, int value) {
  int i;

  // If Spaces needs to be allocated
  if (vector->allocated_size <= index) {
    int i;
    int orglen = vector->allocated_size;

    int *newArray;
    newArray = (int*)malloc(sizeof(int) * (index + 1));

    // Copying Array
    for (i = 0; i < orglen; i++) {
      newArray[i] = vector->array[i];
    }

    // Reallocating Space and Array
    free(vector->array);
    vector->allocated_size = (index + 1);
    vector->array = newArray;

    vector->array[index] = value;
  }
  else {
    vector->array[index] = value;
  }
}

/* read_value
 *  returns value at index in int _vector.
 * input:
 *    int_vector *vector -- int_vector to search
 *    unsigned int index - index of value to return
 * output: int - int at given index
 */
int read_value(int_vector *vector, unsigned int index){
  if (index >= vector->allocated_size){
    return 0;
  }
  else {
    return vector->array[index];
  }
}
