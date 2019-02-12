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


/* safe_str_cpy
 * Searches stycpy for safe_string. Allocates new memory if necessary, does
 * not if not not necessary
 * input:
 *    safe_string *dest - pointer to be copied into
 *    safe_string *src - string to be copied over
 * output: void
*/
void safe_str_cpy(safe_string *dest, safe_string *src);

/* safe_str_cat
 * Searches concatanates safe_string. Allocates new memory if necessary.
 * input:
 *    safe_string *dest - string to be copied to
 *    safe_string *src - string to be copied over
 * output: void
*/
void safe_str_cat(safe_string *dest, safe_string *src);


/* safe_strchr
 * Searches safe_string for char c.
 * input:
 *    safe_string *s -- String to be searched
 *    char c - char to look for
 * output: char* - Returns pointer to first instance of c. NULL if not in string
*/
char *safe_strchr(safe_string *s, char c);

/* safe_strcmp
 * Compares safestring s1 and s2. Compares alphabeticly, with A being smaller
 * a.
 * input:
 *    safe_string *s1  -- safe string 1
 *    safe_string *s2  -- safe string 2
 * output: int - Returns -1 if s1 is smaller, 0 if equal. 1 if s1 is greater.
*/
int safe_strcmp(safe_string *s1, safe_string *s2);








#endif
