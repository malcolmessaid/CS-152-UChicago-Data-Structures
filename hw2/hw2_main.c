#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw2.h"  // see how we're including the file again?
#include "mastermind.h" // another one!?! So that this code can be separate

void print_backwards_base_8_wrapper()
{
	unsigned int number;
        printf("What number would you like me to print? ");
        scanf("%u", &number);

        print_backwards_base_8(number);
}


// remember to create a test function for each function you
// are implementing. This test function will call the function
// and compare the result to the expected result.

unsigned int print_menu()
{
	unsigned int result;
	printf("\t0: Exit\n");
	printf("\t1: Mastermind\n");
	printf("\t2: 5 Questions\n");
	printf("\t3: Print Backwards in Base 8\n");
	printf("What would you like to play? ");
	scanf("%u", &result);

	return result;
}

int main()
{
    int choice = 0;

    do
    {
	choice = print_menu();

	switch (choice) {
	   case (1): play_mastermind(); break;
	   case (2): play_5_questions(); break;
	   case (3): print_backwards_base_8_wrapper(); break;
	   case (0): break;
	   default: printf("Invalid choice. Try again.\n");
	}

    } while (choice != 0);
}
