#include <stdio.h>
#include <stdlib.h>
#include "hw4.h"
#include "hw4_provided.h"
#include <math.h>

/* is_odd - Returns 1 if value is odd. 0 if even
 * inputs :
 *   int val - value to be checked
 * outputs:
 *   Returns 1 if value is odd. 0 if even
 */
int is_odd(int val){
  if ((val % 2) == 1){
    return 1;
  }
  else {
    return 0;
  }
}

/* hide_image
 * Hides the one image in another given image, resulting in a final image.
 * inputs:
 *  unsigned int ref_r[ROWS][COLS],- 2-d array of red pixels of reference img
 *	unsigned int ref_g[ROWS][COLS],- 2-d array of green pixels of reference img
 *	unsigned int ref_b[ROWS][COLS],- 2-d array of blue pixels of reference img
 *	unsigned int hid_r[ROWS][COLS],- 2-d array of red pixels of hidden img
 *	unsigned int hid_g[ROWS][COLS],- 2-d array of green pixels of hidden img
 *	unsigned int hid_b[ROWS][COLS],- 2-d array of blue pixels of hidden img
 *	unsigned int res_r[ROWS][COLS],- 2-d array of red pixels of resulting img
 *	unsigned int res_g[ROWS][COLS],- 2-d array of green pixels of resulting img
 *	unsigned int res_b[ROWS][COLS],- 2-d array of blue pixels of resulting img
 * 	unsigned int height - height of images, which is all the same
 * unsigned int width - height of images, which is all the same
 * output:
  void -- but res arrays are out parameters, holding infromation of image
          hidden in reference image
 */
void hide_image(
	unsigned int ref_r[ROWS][COLS],
	unsigned int ref_g[ROWS][COLS],
	unsigned int ref_b[ROWS][COLS],
	unsigned int hid_r[ROWS][COLS],
	unsigned int hid_g[ROWS][COLS],
	unsigned int hid_b[ROWS][COLS],
	unsigned int res_r[ROWS][COLS],
	unsigned int res_g[ROWS][COLS],
	unsigned int res_b[ROWS][COLS],
	unsigned int height, unsigned int width) {

    if (width > COLS){
        fprintf(stderr, "error make_checker_board: width cannot be larger"
        "than cols");
    }
    if (height > ROWS){
      fprintf(stderr, "error make_checker_board: height cannot be larger"
      "than rows");
    }


    int i, j;
    for (i = 0; i < height; i++) {
      for (j = 0; j < width; j++) {
        // Making changes to Red Results Array
        if (hid_r[i][j] >= 128) {
          if (is_odd(ref_r[i][j]) == 0) {
            res_r[i][j] = ref_r[i][j] + 1;
          }
          else {
            res_r[i][j] = ref_r[i][j];
          }
        }
        else {
          if (is_odd(ref_r[i][j]) == 1) {
            res_r[i][j] = ref_r[i][j] + 1;
          }
          else {
            res_r[i][j] = ref_r[i][j];
          }
        }

        // Making changes to Green Results Array
        if (hid_g[i][j] >= 128) {
          if (is_odd(ref_g[i][j]) == 0) {
            res_g[i][j] = ref_g[i][j] - 1;
          }
          else {
            res_g[i][j] = ref_g[i][j];
          }
        }
        else {
          if (is_odd(ref_g[i][j]) == 1) {
            res_g[i][j] = ref_g[i][j] + 1;
          }
          else {
            res_g[i][j] = ref_g[i][j];
          }
        }

        // Making changes to Blue Results Array
        if (hid_b[i][j] >= 128) {
          if (is_odd(ref_b[i][j]) == 0) {
            res_b[i][j] = ref_b[i][j] + 1;
          }
          else {
            res_b[i][j] = ref_b[i][j];
          }
        }
        else {
          if (is_odd(ref_b[i][j]) == 1) {
            res_b[i][j] = ref_b[i][j] + 1;
          }
          else {
            res_b[i][j] = ref_b[i][j];
          }
        }
      }
    }

  //  	provided_write_png("hidden_image.png", res_r, res_g, res_b, width, height);
  }

  /* white_or_black - Returns 255 or 0 based on if value is even or odd
   * inputs :
   *   int val - value to be checked
   * outputs:
   *   Returns 255 if value is odd. 0 if even
   */
  int white_or_black(int val){
    if ((val % 2) == 1){
      return 255;
    }
    else {
      return 0;
    }
  }

  /* extract_image
     *  Takes in encoded and extracts image
     * inputs:
     *	unsigned int res_r[ROWS][COLS],- 2-d array of red pixels of resulting img
     *	unsigned int res_g[ROWS][COLS],- 2-d array of green pixels of resulting img
     *	unsigned int res_b[ROWS][COLS],- 2-d array of blue pixels of resulting img
     *	unsigned int hid_r[ROWS][COLS],- 2-d array of red pixels of hidden img
     *	unsigned int hid_g[ROWS][COLS],- 2-d array of green pixels of hidden img
     *	unsigned int hid_b[ROWS][COLS],- 2-d array of blue pixels of hidden img
     * 	unsigned int height - height of images, which is all the same
     * unsigned int width - height of images, which is all the same
     * output:
      void -- a decoded version of hidden image
   */
void extract_image(
  unsigned int res_r[ROWS][COLS],
  unsigned int res_g[ROWS][COLS],
  unsigned int res_b[ROWS][COLS],
  unsigned int hid_r[ROWS][COLS],
  unsigned int hid_g[ROWS][COLS],
  unsigned int hid_b[ROWS][COLS],
  unsigned int height, unsigned int width){
    int i,j;
    for (i = 0; i < height; i++) {
      for (j = 0; j < width; j++) {
        hid_r[i][j] = white_or_black(res_r[i][j]);
        hid_g[i][j] = white_or_black(res_g[i][j]);
        hid_b[i][j] = white_or_black(res_b[i][j]);
      }
    }
  }


  /* encode
     *  Performs actions of hide image, but takes files and returns a file
     *   instead of arrays.
     * inputs:
     *   char *ref_filename - Oringal file that hidden gets hidden in.
     *   char *hid_filename - File to be hidden in.
     *   char *enc_filename - Encoded file
     * output:
      void -- a decoded version of hidden image
   */
void encode(char *ref_filename, char *hid_filename, char *enc_filename) {

  unsigned int ref_r[ROWS][COLS];
  unsigned int ref_g[ROWS][COLS];
  unsigned int ref_b[ROWS][COLS];
  unsigned int hid_r[ROWS][COLS];
  unsigned int hid_g[ROWS][COLS];
  unsigned int hid_b[ROWS][COLS];
  unsigned int enc_r[ROWS][COLS];
  unsigned int enc_g[ROWS][COLS];
  unsigned int enc_b[ROWS][COLS];

  unsigned int height = ROWS;
  unsigned int width = COLS;

  unsigned int *heightP = &height;
  unsigned int *widthP = &width;
//sdf
  provided_read_png(ref_filename, ref_r, ref_g, ref_b, heightP, widthP);
  provided_read_png(hid_filename, hid_r, hid_g, hid_b, heightP, widthP);

  hide_image(ref_r, ref_g, ref_b, hid_r, hid_g, hid_b, enc_r, enc_g, enc_b,
  height, width);

  provided_write_png(enc_filename, enc_r, enc_g, enc_b, height, width);

}
