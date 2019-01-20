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

void play_5_questions()
{
	unsigned int response;

	play_5_qs_instructions();

	// TODO: Store the responses somehow

	printf("Is it bigger than a breadbox? ");
	scanf("%u", &response);
	printf("Is it alive? ");
	scanf("%u", &response);
	printf("Is it found indoors? ");
	scanf("%u", &response);
	printf("Is it found in the kitchen? ");
	scanf("%u", &response);
	printf("Does it live in water? ");
	scanf("%u", &response);

	// TODO: Only print out the correct message

	printf("It is a pat of butter!\n");
	printf("It is an oven!\n");
	printf("It is a pincushion!\n");
	printf("It is a squirrel!\n");
	printf("It is a see-saw!\n");
	printf("It is a jellyfish!\n");
	printf("It is a duck-billed platypus!\n");
	printf("It is a camel!\n");
	printf("It is a pet gerbil!\n");
	printf("It is a tetherball!\n");

}




void print_backwards_base_8(unsigned int num)
{

	fprintf(stderr,"error: print_backwards_base_8 - not implemented yet\n");
	return;

}
