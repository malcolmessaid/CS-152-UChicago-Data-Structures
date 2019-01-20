
#include <stdio.h>
#include <stdlib.h>
#include "mastermind.h"

/******* TODO: PUT YOUR MASTERMIND CODE FROM HW1 HERE ******/

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

	// TODO: Print out the guess number each time
	printf("Guess %d - ",guess_num);
	printf("Input your 4-digit guess: ");
	scanf("%u",&guess);

	// TODO: Get the feedback from the guess.

	printf("Feedback: %u correct placement, correct number,\n",
		feedback / 10);
	printf("%u incorrect placement, correct number\n",
		feedback % 10);


	// TODO: Detect whether guess was entirely correct:
	// if correct, print out congrats and return from this function.
	printf("Congratulations! Your guess of %u was correct!\n",
		guess);

	// TODO: if incorrect, print out number of guesses left
	// if incorrect
	printf("Not quite - you still have %u guesses left!\n",
		guess_num);


}
