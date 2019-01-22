#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "warmup2.h"  // note this new include file!!!


/* Principle 2: Design a good set of test cases
 * they check the base case (0), right above the base case (1), well
 * above the base case (5, 8), and error conditions (-1, -5).
 * -1, 0, 1 are the boundary test cases - base, base+1, base-1.
 */


// Test Functions:


int main()
{

	// Tests for print_asterisk_letter
	printf("Tests for print_asterisk_letter\n");
	print_asterisk_letter('N');
	printf("\n");

	// Tests for draw_sideways_wedge_rec
	printf("Tests for draw_sideways_wedge_rec\n");
	draw_sideways_wedge_rec(3, 1);
	printf("\n");
	draw_sideways_wedge_rec(3, 2);
	printf("\n");
	draw_sideways_wedge_rec(3, 10);
	printf("\n");


	// Tests for draw_sideways_wedge_iter
	printf("Tests for draw_sideways_wedge_iter\n");
	draw_sideways_wedge_iter(3, 10);
	printf("\n");
	draw_sideways_wedge_iter(3, 11);
	printf("\n");
	draw_sideways_wedge_iter(3, 1);
	printf("\n");
	draw_sideways_wedge_iter(3, 2);
	draw_sideways_wedge_iter(0, 0);
	printf("\n");



// Tests for draw_halves_down
	printf("Tests for draw_halves_down\n");
	printf("\n");
	printf("Amount of asterisks: %d\n",draw_halves_down(1));
	printf("\n");
	printf("Amount of asterisks: %d\n",draw_halves_down(2));
	printf("\n");
	printf("Amount of asterisks: %d\n",draw_halves_down(20));
	printf("\n");




//	Tests for draw_halves_up
	printf("Tests for draw_halves_up\n");
	printf("\n");
	printf("Amount of asterisks: %d\n",draw_halves_up(1));
	printf("\n");
	printf("Amount of asterisks: %d\n",draw_halves_up(2));
	printf("\n");
	printf("Amount of asterisks: %d\n",draw_halves_up(20));
	printf("\n");

}
