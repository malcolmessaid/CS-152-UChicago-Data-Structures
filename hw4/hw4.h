#ifndef HW4_H
#define HW4_H

#define ROWS 50
#define COLS 50

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
	unsigned int height, unsigned int width);

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
	unsigned int height, unsigned int width);


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
  void encode(char *ref_filename, char *hid_filename, char *enc_filename);


  void decode(char *enc_filename, char *hid_filename);


#endif
