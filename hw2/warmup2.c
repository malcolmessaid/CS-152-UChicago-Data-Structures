#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "warmup2.h"

/* print_asterisk_letter
 * input: char letter - the letter to print out
 * output: nothing returned, just printed to the screen.
 * Given a character, print the corresponding upper-case letter of the
 * alphabet using asterisks. The letter can be anything from 'N' to 'R'.
 */
void print_asterisk_letter(char letter)
{
	if (letter == 'N'){
		printf("*   *\n");
		printf("**  *\n");
		printf("* * *\n");
		printf("*  **\n");
		printf("*   *\n");
		return;
	}
	else if (letter == 'O'){
		printf(" *** \n");
		printf("*   *\n");
		printf("*   *\n");
		printf("*   *\n");
		printf(" *** \n");
		return;
	}
	else if (letter == 'P'){
		printf("**** \n");
		printf("*   *\n");
		printf("**** \n");
		printf("*    \n");
		printf("*    \n");
		return;
	}
	else if (letter == 'R'){
		printf("**** \n");
		printf("*   *\n");
		printf("**** \n");
		printf("*  * \n");
		printf("*   *\n");
		return;
	}
	else {
		fprintf(stderr,"error print_asterisk_letter: Letter must be N, O, P, or R\n");
		return;
	}

}

/* print_n_times
 * prints n asterisks on a line. implemented recursively.
 * inputs:
 *   uint width - number of asterisks to print
 * outputs:
 *   nothing returned, just printed to the screen
 */
void print_n_times(unsigned int width){
	if (width == 0){
		printf("\n");
		return;
	}
	else {
		printf("*");
		print_n_times(--width);
	}
}



/* recursive_sideways_helper
 * Helper for draw_sideways_wedge_rec. Parameters are different.
 draws a sideways wedge with asterisks. implemented recursively.
 * inputs:
 *   uint width - the  minimum width of the wedge
 *   uint height - the number of rows to print of the wedge
 *   uint max - Initial height. Stays constant.
 * outputs:
 *   nothing returned, just printed to the screen
 */

void recursive_sideway_helper(unsigned int width, unsigned int height, unsigned int max, unsigned int original_width){

	if (height == 1){
	//	printf("here base\n");
    print_n_times(original_width);
  }

	else if (height == (max/2)){
	//	printf("here 2\n");
		width--;
		print_n_times(width);
		recursive_sideway_helper((width - 1), --height, max, original_width);
	}

	else if (height < (max/2)){
	//	printf("here 3\n");
		print_n_times(width);
		recursive_sideway_helper(--width, --height, max, original_width);
	}

	else {
    print_n_times(width);
		recursive_sideway_helper(++width, --height, max, original_width);
  }

}

/* draw_sideways_wedge_rec
 * draws a sideways wedge with asterisks. implemented recursively. Calls recursive_sideway_helper
 * to do the recursion.
 * inputs:
 *   uint width - the  minimum width of the wedge
 *   uint height - the number of rows to print of the wedge
 * outputs:
 *   nothing returned, just printed to the screen
 */

void draw_sideways_wedge_rec(unsigned int width, unsigned int height)
{
	recursive_sideway_helper(width, height, height, width);

}



/* draw_sideways_wedge_iter
 * draws a sideways wedge with asterisks. Implemented iteratively.
 * inputs:
 *   uint width - the minimum width of the wedge
 *   uint height - the number of rows to print of the wedge
 * outputs:
 *   nothing returned, just printed to the screen
 */

void draw_sideways_wedge_iter(unsigned int width, unsigned int height)
{
	unsigned int i,j;
	for (i = 0; i < (height / 2); i++) {
		for (j = 0; j < width; j++) {
			printf("*");
		}
		printf("\n");
		printf("\n");
		width++;
	}
	if ((height % 2) == 0) {
		width--;
	}
	for (i = i; i < height ; i++) {
		for (j = width; j > 0; j--) {
			printf("*");
		}
		printf("\n");
		printf("\n");
		width--;
	}
}

/* draw_halves_down
 * Draws a set of rows of asterisks, each with half as many asterisks as
 * the previous one. It stops after a row with 1 asterisk in it. It returns
 * the number of rows of asterisks printed out.
 * inputs:
 *    uint start - number of asterisks in the first row
 * outputs:
 *    uint - number of rows of asterisks draw
 */
unsigned int draw_halves_down(unsigned int width) {
	if (width == 1) {
		printf("*\n");
		return 1;
	}
	else {
		print_n_times(width);
		return (width + draw_halves_down(width/2));
	}
}



/* draw_halves_up
 * Draws a set of rows of asterisks, each with half as many asterisks as
 * the following one. It begins with a row with 1 asterisk in it. It returns
 * the number of rows of asterisks printed out.
 * inputs:
 *    uint start - number of asterisks in the last row
 * outputs:
 *    uint - number of rows of asterisks draw
 */
unsigned int draw_halves_up(unsigned int width)
{
	if (width == 1) {
		printf("*\n");
		return 1;
	}
	else {
		unsigned int temp = draw_halves_up(width/2);
		print_n_times(width);
		return (width + temp);
	}
}
