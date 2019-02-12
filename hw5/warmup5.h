#ifndef WARMUP5_H
#define WARMUP5_H


// Structs
typedef struct {
	unsigned int allocated_size;
	int *array;
} int_vector;





 /* safe_str_concat
  *  allocates a brand new string that will hold both str1 and str2.
  * Then it copies both strings over, str1 at the front and str2 at the back.
  * input:
  *    char *str1 - string to concatanate
  *    char *str2 - string to concatanate
  * output: int - returns a pointer to that new string.
  */
char *safe_str_concat(char *str1, char *str2);






 /* make_init_array
  *  allocates the int_vector and initializes the values for an array with 0 items
  * input: None
  * output: empty int_vector.
  */
int_vector* make_init_array();


/* write_value
 *  Assigns value at index in int _vector. If out of range. Allocates spaces
 * input:
 *    int_vector *vector -- int_vector assigned to
 *    unsigned int index - index where to assign
 *    int value -- value to assign
 * output: void - int_vector with given value at given index
 */
void write_value(int_vector *vector, unsigned int index, int value);

/* read_value
 *  returns value at index in int _vector.
 * input:
 *    int_vector *vector -- int_vector to search
 *    unsigned int index - index of value to return
 * output: int - int at given index
 */
int read_value(int_vector *vector, unsigned int index);



/* make_and_init_image
 *  Creates a double array of pixels of a given color.
* input:
 *    int height  -- Height of array
 *    int width  -- Width of array
 *    pixel color - color of pixels
 * output: int - double 2-d array of pixel color
 */
pixel** make_and_init_image(int height, int width, pixel color);


#endif
