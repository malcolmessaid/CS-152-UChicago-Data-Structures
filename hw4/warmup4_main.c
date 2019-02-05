#include <stdio.h>
#include <stdlib.h>
#include "hw4_provided.h"
#include "warmup4.h"


/* count_vowels_test
 * Test for count_vowels
 * input: char *str - a string that is the input
 					int expected - expected value of test
 * output: 1 if passed. O if not.
 */
int count_vowels_test(char *input, int expected) {
	int result = count_vowels(input);

	if (expected == result){
		fprintf(stderr, "count_vowels Test Passed\n");
		return 1;
	}
	else {
		fprintf(stderr, "count_vowels Test Failed. Actual: %d,"
		"Expected: %d \n", result, expected);
		return 0;
	}
}

/* make_lowercase_test
 * Test for make_lowercase
 * input: char *input - a string that is input
 					char *expected - expected value of test
 * output: 1 if passed. O if not.
 */
int make_lowercase_test(char *input, char *expected) {
	make_lowercase(input);
	int i;
	for (i = 0; i < input[i] != '\0'; i++) {
		if (input[i] != expected[i]){
			fprintf(stderr, "make_lowercase Test Failed. Mismatched chars. Actual %c,"
			"Expected: %c \n",input[i], expected[i]);
			return 0;
		}
	}
	fprintf(stderr, "make_lowercase Test Passed\n");
	return 1;
}
int main()
{
	// declare variables
	unsigned int r[ROWS][COLS];
  unsigned int g[ROWS][COLS];
  unsigned int b[ROWS][COLS];

	char str1[] = {'H','o','w','d','y',' ','T','H','E','R','E','!','\0'};
	char str2[] = {'M','a','L','c','o','l','m','E','S','S','S','A','I', 'D', '\0'};
	char str3[] = {'b', 'c', 'd', 'f', 'g', '\0'};
	char str4[] = {'\0'};


	char str1test[] = {'h','o','w','d','y',' ','t','h','e','r','e','!','\0'};
	char str2test[] = {'m','a','l','c','o','l','m','e','s','s','s','a','i', 'd', '\0'};
	char str3test[] = {'b', 'c', 'd', 'f', 'g', '\0'};
	char str4test[] = {'\0'};

	// single call to each function.
	// you need to write more test cases
	// you need helper functions for exercises 1 and 2, not 3 and 4
	count_vowels_test(str1, 3);
	count_vowels_test(str2, 5);
	count_vowels_test(str3, 0);
	count_vowels_test(str4, 0);


// Tests for make_lowercase
	make_lowercase_test(str1, str1test);
	make_lowercase_test(str2, str2test);
	make_lowercase_test(str3, str3test);
	make_lowercase_test(str4, str4test);

/*
	// read in ppm file
	// note that r, g, b, width, length are all out parameters
	// that means we need to declare the variables here and send
	// the locations to the function, as seen below.

	// note that for the warmup, you do not need to read in a png.
	provided_read_png("sample.png",r,g,b,&width,&length);
*/


	// put in arrays
	make_horizontal_stripes(r, g, b, 1, 30, 144, 255, 12, 12);

	provided_print_image_to_html("my_horiz_stripes.html",r,g,b,12,12);

	make_horizontal_stripes(r, g, b, 1, 30, 144, 255, 3, 3);

	provided_print_image_to_html("my_horiz_stripes1.html",r,g,b,3,3);
// Error check
	make_horizontal_stripes(r, g, b, 1, 30, 144, 255, 55,55);

	// Tests for make_checker_board
	make_checker_board(r,g,b,4,30,144,255, 12, 12);

	provided_print_image_to_html("my_checkboard.html",r,g,b,12, 12);

	make_checker_board(r,g,b,1,30,144,255, 3, 3);

	provided_print_image_to_html("my_checkboard1.html",r,g,b,3, 3);

// Error check
	make_checker_board(r,g,b,4,30,144,255, 55, 12);


}
