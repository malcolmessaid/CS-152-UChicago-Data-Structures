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

	// open file for reading
	FILE *fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Could not open file %s for reading\n",filename);
		exit(2);
	}

	// read in each record from the file
	char buffer[BUFSIZ];
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

	}

	// here you can add stuff to test your other functions



}
