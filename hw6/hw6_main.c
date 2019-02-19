#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw6.h"

int main(int argc, char *argv[])
{
	// make sure there are two arguments - hw5 and filename
	if (argc < 2)
	{
		printf("Usage: ./hw6 filename. Missing filename\n");
		exit(1);
	}
	char *filename = argv[1];

	FILE *fpout = fopen("productLists", "w");
	// open file for reading
	FILE *fp = fopen(filename, "r");

	if (fp == NULL)
	{
		printf("Could not open file %s for reading\n",filename);
		exit(2);
	}

	// read in each record from the file
	char buffer[BUFSIZ];
	node *head= NULL;
	while (!feof(fp) && (fgets(buffer,500,fp) != NULL))
	{
		// parse the line to split up the fields
		char *category;
		char *name;
		uint pID;
		uint current_stock;
		uint min_stock;
		uint max_stock;
		char *tmp_s;

		// first field is category
		category = strtok(buffer," ,\n\r");
		// second field is name
		name = strtok(NULL," ,\n\r");
		// third is pID;
		tmp_s = strtok(NULL," ,\n\r");
		pID = atoi(tmp_s);
		// fourth is current
		tmp_s = strtok(NULL," ,\n\r");
		current_stock = atoi(tmp_s);
		// fifth is min
		tmp_s = strtok(NULL," ,\n\r");
		min_stock = atoi(tmp_s);
		// sixth is max
		tmp_s = strtok(NULL," ,\n\r");
		max_stock = atoi(tmp_s);

		printf("Read in record: %s, %s, %u, %u, %u, %u\n",
			category, name, pID, current_stock, min_stock,
			max_stock);

		// now you need to write the code to create a record
		// and put that record into the linked list

		product_info *testProduct = create_product(name, category, pID, current_stock,
			min_stock, max_stock);

		print_product(testProduct, fpout);

		head = insert_head(head, testProduct);

	}

	print_list(head, fpout);
	fclose(fpout);

	// here you can add stuff to test your other functions

 	// Testing for find
	printf("TESTING find Visually\n");
	printf("Print Butter given: 2956\n");
	print_product(find(head, 2956), stdout);
	printf("\n \n");
	printf("Print Stapler given: 3826\n");
	print_product(find(head, 3826), stdout);
	printf("\n \n");
	printf("Print BandAids given 8261: \n");
	print_product(find(head, 8261), stdout);
	printf("\n \n \n");



	// Test for record_restocked_single
	printf("TESTING record_restocked_single Visually\n");
	printf("Before: ");
	print_product(find(head, 2956), stdout);
	printf("\n");
	record_restocked_single(head, 2956);
	printf("Restocking Butter\n");
	printf("After: ");
	print_product(find(head, 2956), stdout);
	printf("\n \n");

	printf("Before: ");
	print_product(find(head, 380571), stdout);
	printf("\n");
	record_restocked_single(head, 380571);
	printf("Restocking LionStuffy\n");
	printf("After: ");
	print_product(find(head, 380571), stdout);
	printf("\n \n");

	printf("Before: ");
	print_product(find(head, 2653), stdout);
	printf("\n");
	record_restocked_single(head, 2653);
	printf("Restocking Bugspray\n");
	printf("After: ");
	print_product(find(head, 2653), stdout);
	printf("\n \n");

// test non existent products

	printf("TESTING product_sold Visually\n");
	printf("Before: ");
	print_product(find(head, 2956), stdout);
	printf("\n");
	product_sold(head, 2956);
	printf("Selling Butter\n");
	printf("After: ");
	print_product(find(head, 2956), stdout);
	printf("\n \n");

	printf("Before: ");
	print_product(find(head, 380571), stdout);
	printf("\n");
	product_sold(head, 380571);
	printf("Selling LionStuffy\n");
	printf("After: ");
	print_product(find(head, 380571), stdout);
	printf("\n \n");

	printf("Before: ");
	print_product(find(head, 2653), stdout);
	printf("\n");
	product_sold(head, 2653);
	printf("Selling Bugspray\n");
	printf("After: ");
	print_product(find(head, 2653), stdout);
	printf("\n \n");


	printf("\n \n \n");
	// WILL NOT CALL THE ONE THAT IS NOT BEING CALLED PROPERLY
//	Call with productsSorted.txt
	if (strcmp(filename,  "productsSorted.txt") == 0){
		printf("TESTING add_sorted_productID\n");
		product_info *test1 = create_product("airpod","Grocery", 222, 12, 10, 20);
		head = add_sorted_productID(test1, head);
		print_list(head, stdout);
		printf("\n");

		product_info *test2 = create_product("iphone","Office", 4000, 12, 10, 20);
		head = add_sorted_productID(test2, head);
		print_list(head, stdout);
		printf("\n");

		product_info *test3 = create_product("ipod","Hobby", 1000000, 12, 10, 20);
		head = add_sorted_productID(test3, head);
		print_list(head, stdout);
		printf("\n");
	}
	// To test add_sorted_category_ID call with productsSortedCat.txt
	else if (strcmp(filename,  "productsSortedCat.txt") == 0){
		printf("TESTING add_sorted_category_ID\n");
		product_info *test4 = create_product("apple","Grocery", 222, 12, 10, 20);
		head = add_sorted_category_ID(test4, head);
		print_list(head, stdout);
		printf("\n");

		product_info *test5 = create_product("iphone3","Office", 4000, 12, 10, 20);
		head = add_sorted_category_ID(test5, head);
		print_list(head, stdout);
		printf("\n");

		product_info *test6 = create_product("ipod","Hobby", 1000000, 12, 10, 20);
		head = add_sorted_category_ID(test6, head);
		print_list(head, stdout);
		printf("\n");
	}


// Above should be commented out when testing this.
// When testing call with productsSortedCat.txt

}
