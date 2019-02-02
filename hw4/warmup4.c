#include <stdio.h>
#include <stdlib.h>
#include "warmup4.h"
#include "hw4_provided.h"

/* count_vowels
 * search through str and count the number of vowels.
 * input: char *str - a string
 * output: int - the number of vowels in the string str
 */
int count_vowels(char *str)
{
	// length of string
int i,count;
	count = 0;
	for (i = 0; str[i] != '\0'; i++) {
		if ((str[i] == 'a') || (str[i] == 'u') || (str[i] == 'o') || (str[i] == 'i') || (str[i] == 'e')
				|| (str[i] == 'A') || (str[i] == 'U') || (str[i] == 'O') || (str[i] == 'I') || (str[i] == 'E')){
			count++;
		}
	}
	return count;
}

/* make_lowercase
 * modify str such that all alphabetic characters are lower case
 * input: char *str - a string
 * output: no return value - str is out parameter
 */
void make_lowercase(char *str)
{
	int i;
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] < 91 && str[i] > 64){
			str[i] = (str[i] + 32);
		}
	}
}

/* fill_color
 * Fills color arrays with one color
 * input: unsigned int pixels[ROWS][COLS]- an array of a given color to be filled
 *        unsigned int color - color to fill with
 * output: no return value - str is out parameter
 */
void fill_color(unsigned int pixels[ROWS][COLS], unsigned int color) {
	int i,j;
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLS; j++) {
		 	pixels[i][j] = color;
		}
	}
}
/* make_horizontal_stripes
 *   This produces an image stored in the red, green, and blue 2-d arrays.
 *   The image contains black and colored stripes. All stripes are
 *   stripe_height. The stripe colors are indicated by stripe_color.
 *   The top stripe is colored. The image is heightxwidth.
 * inputs:
 *   unsigned int red[ROWS][COLS],  - red component of resulting image pixels
 *   unsigned int green[ROWS][COLS], - green component of resulting image pixels
 *   unsigned int blue[ROWS][COLS],  - blue component of resulting image pixels
 *   unsigned int stripe_height,  - height of a single stripe
 *   unsigned int stripe_red,  - red component of stripe pixel
 *   unsigned int stripe_green,  - green component of stripe pixel
 *   unsigned int stripe_blue,  - blue component of stripe pixel
 *   unsigned int width,  - width of resulting image
 *   unsigned int height); - height of resulting image
 *
 */
void make_horizontal_stripes(
	unsigned int red[ROWS][COLS],
	unsigned int green[ROWS][COLS],
	unsigned int blue[ROWS][COLS],
	unsigned int stripe_height,
	unsigned int stripe_red,
	unsigned int stripe_green,
	unsigned int stripe_blue,
	unsigned int width,
	unsigned int height)
{

	if (width > COLS){
			fprintf(stderr, "error make_horizontal_stripes: width cannot be larger
			than cols");
	}
	if (height > ROWS){
		fprintf(stderr, "error make_horizontal_stripes: height cannot be larger
		than rows");
	}
	int i,j,count, black;

	// Fill color arrays
	fill_color(red, stripe_red);
	fill_color(green, stripe_green);
	fill_color(blue, stripe_blue);
	count = 1;
	black = 1;
	for (i = 0; i < ROWS; i++) {
		if ((count % stripe_height) == 0){
			black++;
		}
		for (j = 0; j < COLS; j++) {
			if ((black % 2) == 1){
				red[i][j] = 0;
				green[i][j] = 0;
				blue [i][j] = 0;
			}
		}
		count++;
	}

	provided_write_png("horiz_stripes.png", red, green, blue, width, height);
}

/* make_checker_board
 *   This produces an image stored in the red, green, and blue 2-d arrays.
 *   The image contains white and colored squares. All squares are
 *   square_width x square_width. The square colors are indicated by
 *   square_color. The image is heightxwidth. The top-left square is colored.
 * inputs:
 *   unsigned int red[ROWS][COLS],  - red component of resulting image pixels
 *   unsigned int green[ROWS][COLS], - green component of resulting image pixels
 *   unsigned int blue[ROWS][COLS],  - blue component of resulting image pixels
 *   unsigned int square_height,  - height of a single square
 *   unsigned int square_red,  - red component of square pixel
 *   unsigned int square_green,  - green component of square pixel
 *   unsigned int square_blue,  - blue component of square pixel
 *   unsigned int width,  - width of resulting image
 *   unsigned int height); - height of resulting image
 *
 */
void make_checker_board(
        unsigned int red[ROWS][COLS],
        unsigned int green[ROWS][COLS],
        unsigned int blue[ROWS][COLS],
        unsigned int square_width,
        unsigned int square_red,
        unsigned int square_green,
        unsigned int square_blue,
        unsigned int width,
        unsigned int height)
{
	fill_color(red, stripe_red);
	fill_color(green, stripe_green);
	fill_color(blue, stripe_blue);

	provided_write_png("my_checkboard.png", red, green, blue, width, height);
}
