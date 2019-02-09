#ifndef HW5_H
#define HW5_H


typedef unsigned int uint;

typedef struct {
	char *str;
	uint allocated_length;
} safe_string;


/* make_empty_string
 * The first one creates an empty string.
 * output: int - safe_string reprsenting empty string
 */
safe_string* make_empty_string();

/* make_string
 * Makes string struct with string of input
 * input: char *str - a string to be assigned
 * output: int - safe_string with str as string field
 */
safe_string* make_string(char *str);


void safe_str_cpy(safe_string *dest, safe_string *src);
void safe_str_cat(safe_string *dest, safe_string *src);





#endif
