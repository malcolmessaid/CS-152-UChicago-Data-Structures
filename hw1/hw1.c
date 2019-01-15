#include <stdio.h>
#include <stdlib.h>
#include <math.h>




// EXERCISE 1

/* surface_area: returns the surface area, as a double, of a cube given
 * given the side length
 * inputs:
 * 	double edge_length - double value for side length
 * outputs:
 *  double - surface area of cube with given dimensions
 */
double surface_area_cube(double edge_length) {

	if (edge_length <= 0) {
		fprintf(stderr, "error surface_area_cube:  edge_length must be not be negative");
		return -1.0;
	}
	double result = 6.0 * (edge_length * edge_length);
	return result;
}

/* test_surface_area: Helper functio to tests surface_area
 * inputs:
 * 	double edge_length - double value for side length. To be input of
 *   surface area
 *  double expected - expected value of test
 *  double accuracy - used becase doubles are inaccurate. Necessary accuration of
     test
 * outputs:
 *  0 if incorrect, 1 if correct.  Prints results of tests.
 */
unsigned int test_surface_area(double edge_length, double expected, double accuracy) {
	// Surface Area
	double sa;
	sa = surface_area_cube(edge_length);

	if ((sa >= expected - accuracy) && (sa <= expected + accuracy)) {
		printf("Test passed: Test Edge Length: %lf, Expected Value:"
		 "%lf, Calculated Value: %lf  \n", edge_length, expected, sa);
		return 1;
	}

	else {
  	printf("FAILED TEST: Test Edge Length: %lf, Expected Value:"
		 "%lf, Calculated Value: %lf \n", edge_length, expected, sa);
  	return 0;
	}
}


/* sides_to_area: returns the area, as a double, of a shape given
 * given the side length and nubmer of sides
 * inputs:
 * 	double side_length - double value for side length
 *  unsigned int num_sides - number of sides of shape. Determines shape type
 * outputs:
 *  double - area of the shape given the params
*/
double sides_to_area(unsigned int num_sides, double side_length) {

	if ((num_sides < 3) || (num_sides > 9) || (num_sides == 7)) {
		fprintf(stderr,  "error sides_to_area: Invalid num_sides. Shape must be either triangle,"
		"square, pentagon,  hexagon, octagon, and nonagon.");
		return -1.0;
	}
	if (side_length < 0) {
    fprintf(stderr, "error sides_to_area: side_length must be not be negative");
    return -1.0;
  }

	double result = side_length * num_sides;
	return result;
}

/* test_sides_to_area: Helper functio to tests test_sides_to_area
 * inputs:
 * 	double side_length - double value for side length
 *  unsigned int num_sides - number of sides of shape. Determines shape type.
 *  double expected - expected value of test
 *  double accuracy - used becase doubles are inaccurate. Necessary accuration of
     test
 * outputs:
 *  0 if incorrect, 1 if correct.  Prints results of tests.
 */
unsigned int test_sides_to_area(unsigned int num_sides, double side_length, double expected, double accuracy) {
	double area;
	area = sides_to_area(num_sides, side_length);

	if ((area >= expected - accuracy) && (area <= expected + accuracy)) {
		printf("Test passed: Test Num sides: %d, Side Length:"
		"%lf, Expected Value: %lf, Calculated Value: %lf  \n",
		num_sides, side_length, expected, area);
		return 1;
	}

	else {
		printf("Failed test: Test Num sides: %d, Side Length:"
		 "%lf, Expected Value: %lf, Calculated Value: %lf  \n",
		num_sides, side_length, expected, area);
		return 0;
	}
}



// ----------

// EXERCISE 2

/* test_sides_to_area: print out a number grid, starting with the 10's of the
 * input number and going on for 100 numbers. Every column lines up
 * and the numbers within the column are right justified.
 * inputs:
 * 	int start num - number that the first line will include.
 * outputs:
 *  prints the grid. Does not return anything
 */
void print_number_grid(int start_num) {

	if (start_num > 999999) {
		fprintf(stderr, "error print_number_grid:  start_num must less than 999999");
	}
	if (start_num < -999999) {
		fprintf(stderr, "error print_number_grid:  start_num must greater than -999999");
	}


	int temp;
	if ((start_num % 10) == 0){
		temp = start_num;
	}
	else {
		temp = start_num - (abs(start_num) % 10);
	}
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			// Determining number of spaces
			int count = 0;
			int n = abs(temp);
			while(n != 0){
        n /= 10;
        count++;
    	}
			if (temp <= 0) count++;

			for (int k = 0; k < (6 - count); k++) {
				printf(" ");
			}

			printf("%d", temp);
			temp++;
		}
		printf("\n");
	}
}

// ----------------------

// EXERCISE 3


/* extract_digit: Takes in a 4-digit pattern and returns the value at the given digit.
 * 0 is right most spot.
 * inputs:
 * 	unsigned int pattern - the pattern to be parsed
 *  unsigned int digit - the spot of the value to be returned
 * outputs:
 *  returns an unsigned int at the spot indicated
*/
unsigned int extract_digit(unsigned int pattern, unsigned int digit) {
	unsigned int temp = pattern;
	temp /= pow(10, digit);
	return (temp % 10);
}


/* test_extract_digit: Helper that tests extract_digit
 * inputs:
 * 	unsigned int pattern - the pattern to be parsed
 *  unsigned int digit - the spot of the value to be returned
 *  unsigned int expected - expected value of test
 * outputs:
 *  returns a 1 if correct 0 if not. Prints results of tests.
 */
unsigned int test_extract_digits(unsigned int pattern, unsigned int digit, unsigned int expected){
	unsigned int temp = extract_digit(pattern, digit);
	if (temp == expected) {
		printf("Test passed: Test Pattern: %d, Digit:"
		"%d, Expected Value: %d, Calculated Value: %d  \n",
		pattern, digit, expected, temp);
		return 1;
	}
	else {
		printf("Test failed: Test Pattern: %d, Digit:"
		"%d, Expected Value: %d, Calculated Value: %d  \n",
		pattern, digit, expected, temp);
		return 0;
	}
}

//

/* extract_digit: Takes in a 4-digit pattern and a color. Returns amount of instances
 * of the given color in the pattern.
 * inputs:
 * 	unsigned int pattern - the pattern to be parsed
 *  unsigned int color - the color to search for
 * outputs:
 *  returns an unsigned int indicating amount of instances
 */
unsigned int num_of_color(unsigned int pattern, unsigned int color){
	unsigned int temp = pattern;
	unsigned int count = 0;
	while (temp != 0) {
		if ((temp % 10) == color){
			count++;
		}
		temp /= 10;
	}
	return count;
}

/* test_num_of_color: Helper that tests num_of_color
 * inputs:
 * 	unsigned int pattern - the pattern to be parsed
 *  unsigned int color - the color to search for
 *  unsigned int expected - expected value of test
 * outputs:
 *  returns a 1 if correct 0 if not. Prints results of tests.
 */
unsigned int test_num_of_color(unsigned int pattern, unsigned int color, unsigned int expected){
	unsigned int temp = num_of_color(pattern, color);
	if (temp == expected) {
		printf("Test passed: Test Pattern: %d, Color:"
		"%d, Expected Value: %d, Calculated Value: %d  \n",
		pattern, color, expected, temp);
		return 1;
	}
	else {
		printf("Test failed: Test Pattern: %d, Color:"
		"%d, Expected Value: %d, Calculated Value: %d  \n",
		pattern, color, expected, temp);
		return 0;
	}
}


/* test_count_exact_matches: Counts the number of exact matches between
 * a given guess and solution
 * inputs:
 * 	unsigned int guess - the guess pattern to compare
 *  unsigned int solution - the solution pattern to compate
 * outputs:
 *  unsigned int - number instances of exact matches
 */

unsigned int count_exact_matches(unsigned int guess, unsigned int solution){
	unsigned int count = 0;
	for (int i = 0; i < 4; i++) {
		if (extract_digit(guess, i) == extract_digit(solution, i)){
			count++;
		}
	}
	return count;
}


/* test_count_exact_matches: Helper that tests count_exact_matches
 * inputs:
 * 	unsigned int guess - the guess pattern to compare
 *  unsigned int solution - the solution pattern to compate
 *  unsigned int expected - expected value of test
 * outputs:
 *  returns a 1 if correct 0 if not. Prints results of tests.
 */

unsigned int test_count_exact_matches(unsigned int guess, unsigned int solution, unsigned int expected){
	unsigned int temp = count_exact_matches(guess, solution);
	if (temp == expected) {
		printf("Test passed: Test Guess: %d, Solution:"
		"%d, Expected Value: %d, Calculated Value: %d  \n",
		guess, solution, expected, temp);
		return 1;
	}
	else {
		printf("Test failed: Test Guess: %d, Solution:"
		"%d, Expected Value: %d, Calculated Value: %d  \n",
		guess, solution, expected, temp);
		return 0;
	}
}

/* count_color_matches: Counts the number of color matches between
 * a given guess and solution
 * inputs:
 * 	unsigned int guess - the guess pattern to compare
 *  unsigned int solution - the solution pattern to compate
 * outputs:
 *  unsigned int - number instances of color matches
 */
unsigned int count_color_matches(unsigned int guess, unsigned int solution){
	unsigned int count = 0;
	for (int i = 0; i < 4; i++) {
		unsigned int temp = extract_digit(solution, i);
		for (int j = 0; j < 4; j++) {
		//	printf("%d\n", temp);
			if (temp == extract_digit(guess, j)){
				count++;
				break;
			}
		}
	}
	return count;
}

/* test_count_color_matches: Helper that tests count_color_matches
 * inputs:
 * 	unsigned int guess - the guess pattern to compare
 *  unsigned int solution - the solution pattern to compate
 *  unsigned int expected - expected value of test
 * outputs:
 *  returns a 1 if correct 0 if not. Prints results of tests.
 */

unsigned int test_count_color_matches(unsigned int guess, unsigned int solution, unsigned int expected){
	unsigned int temp = count_color_matches(guess, solution);
	if (temp == expected) {
		printf("Test passed: Test Pattern: %d, Color:"
		"%d, Expected Value: %d, Calculated Value: %d  \n",
		guess, solution, expected, temp);
		return 1;
	}
	else {
		printf("Test failed: Test Pattern: %d, Color:"
		"%d, Expected Value: %d, Calculated Value: %d  \n",
		guess, solution, expected, temp);
		return 0;
	}
}

/* get_guess_feedback: Returns feedback for guess. 10s place represents
 * number of exact matches. 1s represents remaining color matches
 * inputs:
 * 	unsigned int guess - the guess pattern to compare
 *  unsigned int solution - the solution pattern to compate
 * outputs:
 *  unsigned int as a Feedback number.
 */
unsigned int get_guess_feedback(unsigned int guess, unsigned int solution){
	unsigned int exact = count_exact_matches(guess, solution);
	unsigned int inexact = count_color_matches(guess, solution);

	// Checking if patterns have 4 digits
	if ((guess > 6666) || (guess < 1000) || (solution > 6666) || (solution < 1000)){
		fprintf(stderr, "error get_guess_feedback: patterns must be 4 digits");
		return 0;
	}

	// Checking if patterns are digited correctly.
	for (int i = 0; i < 4; i++) {
		if ((extract_digit(guess, i) > 6) || (extract_digit(solution, i) > 6) ||
				(extract_digit(guess, i) < 1) || (extract_digit(solution, i) < 1)) {
			fprintf(stderr, "error get_guess_feedback: patterns must be digited with values between 1 and 6");
		}
	}

	return ((10 * exact) + (inexact - exact));
}

/* test_get_guess_feedback: Helper function that tests get_guess_feedback
 * inputs:
 * 	unsigned int guess - the guess pattern to compare
 *  unsigned int solution - the solution pattern to compate
 *  unsigned int expected - expected value of the test
 * outputs:
 *  unsigned int as a Feedback number.
 */
unsigned int test_get_guess_feedback(unsigned int guess, unsigned int solution, unsigned int expected){
	unsigned int temp = get_guess_feedback(guess, solution);
	if (temp == expected) {
		printf("Test passed: Test Pattern: %d, Color:"
		"%d, Expected Value: %d, Calculated Value: %d  \n",
		guess, solution, expected, temp);
		return 1;
	}
	else {
		printf("Test failed: Test Pattern: %d, Color:"
		"%d, Expected Value: %d, Calculated Value: %d  \n",
		guess, solution, expected, temp);
		return 0;
	}
}



int main() {
// Tests for surface_area_cube
	printf("\n");
	printf("Tests for surface_area_cube\n");
	test_surface_area(3.0, 54.0, 0.1);
	test_surface_area(2.3, 31.74, 0.1);
	test_surface_area(5.8, 201.84, 0.1);
	printf("\n");

// Checking errors
	printf("Should return error: edge_length must be not be negative \n");
	test_surface_area(0.0, -1.0, 0.1);
	printf("\n", );


	printf("Tests for sides_to_area\n");
	test_sides_to_area(3, 3.0, 9.0, .1);
	test_sides_to_area(4, 3.0, 12.0, .1);
	test_sides_to_area(6, 3.0, 18.0, .1);

// Checking errors
	printf("Should return error: Invalid num_sides. Shape must be either triangle, square,"
	 "pentagon,  hexagon, octagon, and nonagon. \n");
	sides_to_area(7, 3.0, 0.1);
	printf("\n");


// Tests for print_number_grid
	printf("Tests for print_number_grid\n");
	printf("print_number_grid Input: 13 \n");
	print_number_grid(13);
	printf("\n");
	printf("print_number_grid Input: -15 \n");
	print_number_grid(-15);
	printf("\n");


// Test for Mastermind
	printf("Tests for Mastermind\n");

	printf("Tests for extract_digits\n");
	test_extract_digits(1234, 2, 2);
	test_extract_digits(1234, 0, 4);
	test_extract_digits(1234, 3, 1);
	printf("\n");

	printf("Tests for num_of_color\n");
	test_num_of_color(3333, 3, 4);
	test_num_of_color(3333, 4, 0);
	test_num_of_color(1235, 5, 1);
	test_num_of_color(2332, 2, 2);
	printf("\n");

	printf("Tests for count_exact_matches\n");
	test_count_exact_matches(1111, 1111, 4);
	test_count_exact_matches(1325, 1532, 1);
	test_count_exact_matches(4325, 6260, 0);
	test_count_exact_matches(4561, 3521, 2);
	printf("\n");

	printf("Tests for count_color_matches\n");
	test_count_color_matches(1111, 1111, 4);
	test_count_color_matches(1325, 1532, 4);
	test_count_color_matches(4325, 6260, 1);
	test_count_color_matches(4561, 3521, 2);
	test_count_color_matches(4461, 3521, 1);
	printf("\n");


	printf("get_guess_feedback\n");
	test_get_guess_feedback(1111, 1111, 40);
	test_get_guess_feedback(1325, 1532, 13);
	test_get_guess_feedback(4325, 6261, 1);
	test_get_guess_feedback(4563, 3523, 20);
	test_get_guess_feedback(4262, 3542, 11);
	printf("\n");

	// Checking errors working properly
	printf("Should return error: patterns must be 4 digits \n");
	get_guess_feedback(11111, 2343);
	printf("\n");
	printf("Should return error:  patterns must be digited with values between 1 and 6 \n");
	get_guess_feedback(1119, 2343);
	printf("\n");




}
