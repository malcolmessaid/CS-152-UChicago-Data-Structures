#include <stdio.h>
#include <stdlib.h>
#include "hw2.h"

void play_5_qs_instructions()
{
	printf("Choose one of the following items to think about:\n");
	printf("duck-billed platypus, camel, pat of butter, squirrel, \n");
	printf("oven, pet gerbil, tetherball, jellyfish, pincushion, see-saw\n");

	printf("I will ask 5 questions and then guess which one you chose.\n");
	printf("Type 1 for yes and 0 for no for each question\n");


}

// printf("It is a jellyfish!\n");
// printf("It is a duck-billed platypus!\n");
// printf("It is a camel!\n");
// printf("It is a pet gerbil!\n");
// printf("It is a squirrel!\n");
// printf("It is a pat of butter!\n");
// printf("It is an oven!\n");
// printf("It is a pincushion!\n");
// printf("It is a see-saw!\n");
// printf("It is a tetherball!\n");

void determine_answer(unsigned int n[]){
	// If object is alive/an animal
	if (n[1] == 1){
		//Does it live in water
		if (n[4] == 1){
			// Is it bigger than a breadbox
		 	if (n[0] == 1){
				printf("It is a duck-billed platypus!\n");
			}
			else {
				printf("It is a jellyfish!\n");
			}
		}
		else {
			// Is it indoors
			if (n[2] == 1){
				printf("It is a pet gerbil!\n");
			}
			// Is it bigger than a bread box
			else if (n[0] == 1){
				printf("It is a camel!\n");
			}
			else {
				printf("It is a squirrel!\n");
			}
		}
	}
	else {
		// Is it found in a kitchen
		if (n[3] == 1){
			// Is it bigger than a bread box
			if (n[0] == 1){
				printf("It is an oven!\n");
			}
			else {
				printf("It is a pat of butter!\n");
			}
		}
		// Is it found indoors
		else if (n[2] == 1) {
			printf("It is a pincushion!\n");
		}
		else {
			if (n[0] == 1){
				printf("It is a see-saw!\n");
			}
			else {
				printf("It is a tetherball!\n");
			}
		}
	}
}



void play_5_questions()
{
	unsigned int response;
	unsigned int responses[5];

	play_5_qs_instructions();

	// TODO: Store the responses somehow

	printf("Is it bigger than a breadbox? ");
	scanf("%u", &response);

	if (response > 1) {
		fprintf(stderr, "error play_5_questions:  response be 1 or 0\n");
		return;
	}

	responses[0] = response;

	printf("Is it alive? ");
	scanf("%u", &response);
	responses[1] = response;

	printf("Is it found indoors? ");
	scanf("%u", &response);

	if (response > 1) {
		fprintf(stderr, "error play_5_questions:  response be 1 or 0\n");
		return;
	}

	responses[2] = response;

	printf("Is it found in the kitchen? ");
	scanf("%u", &response);

	if (response > 1) {
		fprintf(stderr, "error play_5_questions:  response be 1 or 0\n");
		return;
	}

	responses[3] = response;

	printf("Does it live in water? ");
	scanf("%u", &response);

	if (response > 1) {
		fprintf(stderr, "error play_5_questions:  response be 1 or 0\n");
		return;
	}

	responses[4] = response;



//	Only print out the correct message
	determine_answer(responses);
}



/*  print_backwards_base_8: Takes in a number in base 10. Switchs to base 8
 * then it reverses it
 * inputs:
 * 	unsigned int num - value to be converted/reversed
 * outputs:
 *  nothing. Function prints the new value
 */
void print_backwards_base_8(unsigned int num)
{
	

	fprintf(stderr,"error: print_backwards_base_8 - not implemented yet\n");
	return;

}
