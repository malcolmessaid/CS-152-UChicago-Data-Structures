#include <stdio.h>
#include <stdlib.h>
#include "hw4_provided.h"
#include "hw4.h"

int main() {
	unsigned int ref_r[ROWS][COLS];
	unsigned int ref_g[ROWS][COLS];
	unsigned int ref_b[ROWS][COLS];
	unsigned int hid_r[ROWS][COLS];
	unsigned int hid_g[ROWS][COLS];
	unsigned int hid_b[ROWS][COLS];
	unsigned int res_r[ROWS][COLS];
	unsigned int res_g[ROWS][COLS];
	unsigned int res_b[ROWS][COLS];
	
	hide_image(ref_r, ref_g, ref_b, hid_r, hid_g, hid_b, res_r, res_g, res_b,
		12, 12);

	provided_print_image_to_html("hide_image.html",res_r, res_g, res_b, 12,12);

	// Encode/Decode with happyface
	encode("uchicago.png", "happyface.png", "happyface_coded.png");
	decode("happyface_coded.png", "happyface_decoded.png");

	// Encode/Decode with happyface
	encode("happyface.png", "uchicago.png", "uchicago_coded.png");
	decode("uchicago_coded.png", "uchicago_decoded.png");
}
