#include <stdio.h>
#include <stdlib.h>

/* surface_area: returns the surface area, as a double, of a cube given
 * given the side length
 * inputs:
 * 	double edge_length - double value for side length
 */
// CAN VALUE BE 0
double surface_area_cube(double edge_length) {
	
	if (edge_length < 0) {
		fprintf(stderr, "surface_area_cube:  edge_length must be not be negative");
		return -1;	
	}
	double result = 6 * (edge_length * edge_length); 
	return result;
}

double sides_to_area(unsigned int num_sides, double side_length) {
	
	if ((num_sides < 3) || (num_sides > 9) || (num_sides == 7)) {
		fprintf(stderr,  "error sides_to_area: Invalid num_sides. Shape must be either triangle, square, pentagon,  hexagon, octagon, and nonagon.");
		return -1;
	}
	if (side_length < 0) {
                fprintf(stderr, "error sides_to_area: side_length must be not be negative");
                return -1;
        }

	double result = side_length * num_sides;
	return result;

}

double surface_area_cylinder(double height, double radius) {
	fprintf(stderr,"surface_area_cylinder not yet implemented\n");
	return 0.0;
}

int main() {
	double dval, test1, test2;

	dval = surface_area_cylinder(2,1.5);
//	fprintf(stderr, surface_area_cube(3.0));
//	fprintf(stderr, sides_to_area(3,3.0));
}
