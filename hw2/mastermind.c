
#include <stdio.h>
#include <stdlib.h>
#include "mastermind.h"
#include <math.h>

/******* TODO: PUT YOUR MASTERMIND CODE FROM HW1 HERE ******/


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
	int i;
	for (i = 0; i < 4; i++) {
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
	int i, j;
	for (i = 0; i < 4; i++) {
		unsigned int temp = extract_digit(solution, i);
		for (j = 0; j < 4; j++) {
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
 *  unsigned int solution - the solution pattern to compare
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




/******* TODO: Reimplement your mastermind code with loops ******/


void print_mastermind_instructions()
{
	printf("Welcome to mastermind. I am thinking of a 4-number\n");
	printf("sequence. All four numbers are between 1 and 6.\n");
	printf("You have 12 guesses to guess it correctly.\n");
	printf("Each time you guess, I'll tell two things.\n");
	printf("1. How many numbers are correct and in the correct position.\n");
	printf("2. How many other numbers are correct but in the wrong position.\n");
	printf("Let's get started!!!\n");
}

/* get_new_code
 * Generates a 4-digit number, with each digit a number from 1 to 6, inclusive.
 * inputs:
 *   none
 * outputs:
 *   unsigned int - 4-digit number with each digit from 1 to 6
 */
unsigned int get_new_code()
{
	int i;
	int result = 0;
	for (i = 0; i < 4; i++)
	{
		result = result * 10;
		result = result + ((rand() % 6) + 1);
	}
	return result;
}

/* play_mastermind
 * Executes the game. Prompts player to guess, give feedback accordingly. Ends game
     when appropriate.
 * inputs:
 *   none
 * outputs:
 *  none
 */

void play_mastermind()
{

	unsigned int guess_num = 0;
	unsigned int solution = 0;
	unsigned int guess = 0;
	unsigned int feedback = 0;

	print_mastermind_instructions();
	solution = get_new_code();
	printf("solution: %u\n",solution);

	// TODO: Limit number of guesses to 12 guesses
	while (guess_num < 12){

		// TODO: Print out the guess number each time
		printf("Guess %d - ",guess_num);
		printf("Input your 4-digit guess: ");
		scanf("%u",&guess);

		// TODO: Get the feedback from the guess.
		feedback = get_guess_feedback(guess, solution);
		printf("%u\n", feedback);
		printf("ex\n");
		printf("%u\n", count_exact_matches(guess, solution));
		printf("%u\n", count_color_matches(guess, solution));
		printf("Feedback: %u correct placement, correct number,\n",
			feedback / 10);
		printf("%u incorrect placement, correct number\n",
			feedback % 10);


		// TODO: Detect whether guess was entirely correct:
		if ((feedback / 10) == 4) {
			// if correct, print out congrats and return from this function.
			printf("Congratulations! Your guess of %u was correct!\n",
				guess);
				return;
		}
		else {
			// TODO: if incorrect, print out number of guesses left
			// if incorrect
			guess_num = guess_num + 1;
			printf("Not quite - you still have %u guesses left!\n",
				(12 - guess_num));
		}
	}
	printf("You lost. You ran out of guesses\n");



}
