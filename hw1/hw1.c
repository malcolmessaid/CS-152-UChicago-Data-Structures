#include <stdio.h>
#include <stdlib.h>


// EXERCISE 1

/* surface_area: returns the surface area, as a double, of a cube given
 * given the side length
 * inputs:
 * 	double edge_length - double value for side length
 */
// CAN VALUE BE 0
double surface_area_cube(double edge_length) {

	if (edge_length <= 0) {
		fprintf(stderr, "error surface_area_cube:  edge_length must be not be negative");
		return -1.0;
	}
	double result = 6.0 * (edge_length * edge_length);
	return result;
}

/* test_surface_area: this function tests surface_area_cube. Prints a
 * a statement indicating if the test passed. Takes in an input for
 * surface_area_cube, an expected ouput, and an a value to determine
 * how accurate output must be.
 */
unsigned int test_surface_area(double edge_length, double expected, double accuracy) {
	// Surface Area
	double sa;
	sa = surface_area_cube(edge_length);

	if ((sa >= expected - accuracy) && (sa <= expected + accuracy)) {
		printf("Test passed: Test Edge Length: %lf, Expected Value: %lf, Calculated Value: %lf  \n", edge_length, expected, sa);
		return 1;
	}

//	if ((sa <  expected - accuracy) || (sa > expected + accuracy))
	else {
  	printf("FAILED TEST: Test Edge Length: %lf, Expected Value: %lf, Calculated Value: %lf \n", edge_length, expected, sa);
  	return 0;
	}
}

double sides_to_area(unsigned int num_sides, double side_length) {

	if ((num_sides < 3) || (num_sides > 9) || (num_sides == 7)) {
		fprintf(stderr,  "error sides_to_area: Invalid num_sides. Shape must be either triangle, square, pentagon,  hexagon, octagon, and nonagon.");
		return -1.0;
	}
	if (side_length < 0) {
    fprintf(stderr, "error sides_to_area: side_length must be not be negative");
    return -1.0;
  }

	double result = side_length * num_sides;
	return result;
}


unsigned int test_sides_to_area(unsigned int num_sides, double side_length, double expected, double accuracy) {
	double area;
	area = sides_to_area(num_sides, side_length);

	if ((area >= expected - accuracy) && (area <= expected + accuracy)) {
		printf("Test passed: Test Num sides: %d, Side Length:"
		"%lf, Expected Value: %lf, Calculated Value: %lf  \n",
		num_sides, side_length, expected, area);
		return 1;
	}

	// if ((area <  expected - accuracy) || (area > expected + accuracy))
	else {
		printf("Failed test: Test Num sides: %d, Side Length:"
		 "%lf, Expected Value: %lf, Calculated Value: %lf  \n",
		num_sides, side_length, expected, area);
		return 0;
	}
}

double surface_area_cylinder(double height, double radius) {
	fprintf(stderr,"surface_area_cylinder not yet implemented\n");
	return 0.0;
}

// ----------

// EXERCISE 2


void print_number_grid(int start_num) {

	if (start_num > 999999) {
		fprintf(stderr, "error print_number_grid:  start_num must less than 999999");
	}
	if (start_num < -999999) {
		fprintf(stderr, "error print_number_grid:  start_num must greater than -999999");
	}


	int temp;
	if ((start_num % 10) == 0){
		temp = start_num;
	}
	else {
		temp = start_num - (abs(start_num) % 10);
	}
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			int count = 0;
			int n = abs(temp);
			while(n != 0){
        n /= 10;
        count++;
    	}
			if (temp <= 0) count++;

			for (int k = 0; k < (6 - count); k++) {
				printf(" ");
			}

			printf("%d", temp);
			temp++;
		}
		printf("\n");
	}
}



int main() {
//	double dval;

//	dval = surface_area_cylinder(2,1.5);
//	fprintf(stderr, surface_area_cube(3.0));
//	fprintf(stderr, sides_to_area(3,3.0));

// Tests for surface_area_cube
	test_surface_area(3.0, 54.0, 0.1);
	test_surface_area(2.3, 31.74, 0.1);
	test_surface_area(5.8, 201.84, 0.1);
//	test_surface_area(0.0, -1.0, 0.1);


// Tests for print_number_grid
	printf("print_number_grid Input: 13 \n");
	print_number_grid(13);
	printf("print_number_grid Input: -15 \n");
	print_number_grid(-15);

}
