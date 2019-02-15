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



// struct _node{
//  product_info *product;
//  node *next;
// };

void record_restocked_single(node *head, uint pID) {
		if (find(head, pId) == NULL){
			return;
		}
		else {for
			find(head, pID)->product->current_stock = max_after_restock;
		}
}


void product_sold(node *head, uint pID) {
	if (find(head, pId) == NULL){
		return;
	}
	else {for
		find(head, pID)->product->current_stock--;;
	}
}



node *add_sorted_productID(product_info *pinfo, node *head) {
	node *tmp;
	for (tmp = head; tmp->next ; tmp = tmp->next) {
		if (temp->product->productID < pinfo->productID) {
			node *insert = (node*)malloc(sizeof(node));
			insert->product = pinfo;
			insert->next = temp->next;
			return head;
		}
	}

	node *insert = (node*)malloc(sizeof(node));
	insert->product = pinfo;
	tmp->next = insert;
	return head;
}



//
// node *add_sorted_category_ID(product_info *pinfo, node *head) {
// 	node *tmp;
// 	int i;
// 	for (size_t i = 0; i < count; i++) {
// 		for (tmp = head; tmp->next ; tmp = tmp->next) {
// 			if (temp->product->productID < pinfo->productID) {
// 				node *insert = (node*)malloc(sizeof(node));
// 				insert->product = pinfo;
// 				insert->next = temp->next;
// 				return head;
// 			}
// 		}
// 	}
//
//
// 	node *insert = (node*)malloc(sizeof(node));
// 	insert->product = pinfo;
// 	tmp->next = insert;
// 	return head;
// }


//
// typedef struct {
//  enum Category category;
//  char name[40];
//  uint productID;
//  uint current_stock;
//  uint min_for_restock;
//  uint max_after_restock;
// } product_info;


// I THINK THE REST OF THIS CAN BE DONE ON MONDAY NIGHT, RIGHT?
node *make_restock_list(node *head) {
	node *restock = (node*)malloc(sizeof(node));
	node *tmp;
	for (tmp = head; tmp->next ; tmp = tmp->next) {
		if (temp->product->current_stock < temp->product->current_stock) {
			node *new_restock = (node*)malloc(sizeof(node));
			new_restock->product = tmp;
			new_restock->next = NULL;
			return head;
		}
	}
}
