#include <stdio.h>
#include <stdlib.h>
#include "hw2.h"
#include <math.h>

void play_5_qs_instructions()
{
	printf("Choose one of the following items to think about:\n");
	printf("duck-billed platypus, camel, pat of butter, squirrel, \n");
	printf("oven, pet gerbil, tetherball, jellyfish, pincushion, see-saw\n");

	printf("I will ask 5 questions and then guess which one you chose.\n");
	printf("Type 1 for yes and 0 for no for each question\n");


}

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


/*  base_converter_8: Takes in a number in base 10. Switchs to base 8
 *
 * inputs:
 * 	unsigned int num - value to be converted/reversed
 * outputs:
 *  unsigned int - input value in base 8
 */
unsigned int base_converter_8(unsigned int num){
	printf("%u ppoo\n", num /8);
	if ((num / 8) < 1) {
		return num;
	}
	else {
		return ((num % 8) + base_converter_8((int)floor(num / 8)));
	}

    // [(< (/ n 25) 1) (cons n '())]
    // [else (cons (remainder n 25) (base-converter (floor (/ n 25))))]))
}

/*  num_string: Takes in a number. Returns string version of it.
 * inputs:
 * 	unsigned int num - value to be converted
 * outputs:
 *  string - string value
 */

// string num_string(unsigned int num){
// 	if (num == 0){
// 		return "0";
// 	}
// 	if (num == 1){
// 		return "1";
// 	}
// 	if (num == 2){
// 		return "2";
// 	}
// 	if (num == 3){
// 		return "3";
// 	}
// 	if (num == 4){
// 		return "4";
// 	}
// 	if (num == 5){
// 		return "5";
// 	}
// 	if (num == 6){
// 		return "6";
// 	}
// 	if (num == 7){
// 		return "7";
// 	}
// }


/*  reverse: Takes in a number. Reverses it
 * inputs:
 * 	unsigned int num - value to be reversed
 * outputs:
 *  unsigned int - Reversed value
 */
 unsigned int reverse(unsigned int num) {
	 printf("%u\n", num);
	 if (num < 10){
		 return num;
	 }
	 else {
		 unsigned int last_digit = (num % 10);
		 printf("%u\n", last_digit);
		 return (reverse( num / 10 ) + last_digit));
	 }
 }


 /*  print_backwards_base_8: Takes in a number in base 10. Switchs to base 8
  * then it reverses it
  * inputs:
  * 	unsigned int num - value to be converted/reversed
  * outputs:
  *  nothing. Function prints the new value
  */
 void print_backwards_base_8(unsigned int num) {
	 reverse(num);
 	//	printf("%u\n", reverse(num));
//	 printf("%u\n", base_converter_8(num));
	 //printf("%u\n", reverse(base_converter_8(num)));
 }
