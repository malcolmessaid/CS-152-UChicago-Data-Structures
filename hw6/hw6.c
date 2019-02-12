#include <stdio.h>
#include <stdlib.h>
#include "hw6.h"
#include <math.h>
#include <string.h>




char *category_strings[] = { "Grocery", "Office", "Pharmacy", "Hobby"};

void print_product(product_info *p, FILE *fp) {
	fprintf(fp,"%s (%u) %s:",p->name, p->productID,
		category_strings[p->category]);
	fprintf(fp, "current: %u, min: %u, max: %u",
		p->current_stock, p->min_for_restock, p->max_after_restock);
}

void print_list(node *head, FILE *fp) {
	node *tmp;
	printf("Product Status:\n");
	for(tmp = head; tmp != NULL; tmp = tmp->next)
	{
		print_product(tmp->product,fp);
		printf("\n");
	}
}


product_info *create_product(char *name, char *category, uint id,
				uint current, uint mn, uint mx) {
					product_info *new;
					new = (product_info*)malloc(sizeof(product_info));


					int i;
					for (i = 0; i < 4; i++) {
						if (strcmp(category_strings[i], category)){
							new->category = i;
						}
					}
					for (i = 0; i < 40; i++) {
						new->name[i] = name[i];
					}
					new->productID = id;
					new->current_stock = current;
					new->min_for_restock = mn;
					new->max_after_restock = mx;

					return new;
				}


node* insert_head(node *head, product_info *pinfo) {
	node *new = (node*)malloc(sizeof(node));

	new->product = pinfo;
	new->next = head;

	return new;
}




product_info *find(node *head, uint pID) {
	node *tmp = (node*)malloc(sizeof(node));
	for (tmp = head; tmp->next ; tmp = tmp->next) {
		if (tmp->product->productID == pID) {
			return tmp->product;
		}
	}
	return NULL;
}
