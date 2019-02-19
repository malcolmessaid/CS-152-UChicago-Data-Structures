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

/* create_product
 *  Creates new product with given fields.
 * input:
 *    char *name - Name of product
 *    char *category - category of product
 *    uint id - Product ID of product
 *    uint current - current_stock of product
 *    uint mn - min_for_restock of product
 *    uint mx - max_after_restock of product
 * output: product_info * - pointer to new product
 */
product_info *create_product(char *name, char *category, uint id,
				uint current, uint mn, uint mx) {
					product_info *new;
					new = (product_info*)malloc(sizeof(product_info));


					int i;
					for (i = 0; i < 4; i++) {
						if (strcmp(category_strings[i], category) == 0){
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


/* insert_head: inserts node at beginning of link list
	* input:
	*    node *head - pointer to head of list
	*    product_info *pinfo - info to place at begginning
	* output: node * - pointer modified list
*/
node* insert_head(node *head, product_info *pinfo) {
	node *new = (node*)malloc(sizeof(node));

	new->product = pinfo;
	new->next = head;

	return new;
}



/* find: finds a node in a link list given pID
	* input:
	*    node *head - pointer to head of list
	*    uint pID - pID to search for
	* output: node * - pointer to matching node
*/
product_info *find(node *head, uint pID) {
	node *tmp;
	for (tmp = head; tmp != NULL ; tmp = tmp->next) {
		if (tmp->product->productID == pID) {
			return tmp->product;
		}
	}
	return NULL;
}




/* record_restocked_single: replaces the current number of items with the max number
	* input:
	*    node *head - head of link list
	*    uint pID - pID of node to restock
	* output: void - restocks node
*/
void record_restocked_single(node *head, uint pID) {
		if (find(head, pID) == NULL){
			printf("BROKE\n");
			return;
		}
		else {
			find(head, pID)->current_stock = find(head, pID)->max_after_restock;
		}
}

/* record_restocked_single: subtracts current stock by one
	* input:
	*    node *head - head of link list
	*    uint pID - pID of node to sell
	* output: node * - sells one item
*/
void product_sold(node *head, uint pID) {
	if (find(head, pID) == NULL){
		return;
	}
	else {
		find(head, pID)->current_stock--;;
	}
}


/* add_sorted_productID: inserts node in sorted spot based on productID
	* input:
	*    product_info *pinfo - product to insert
	*    node *head - head of link list to insert into
	* output: node * - modifed list
*/
node *add_sorted_productID(product_info *pinfo, node *head) {
	node *tmp;
	tmp = head;
	if (tmp->next->product->productID > pinfo->productID) {
		return insert_head(head, pinfo);
	}

	for (tmp = head; tmp->next != NULL; tmp = tmp->next) {
		if (tmp->next->product->productID > pinfo->productID) {
			node *insert = (node*)malloc(sizeof(node));
			insert->product = pinfo;
			insert->next = tmp->next;
			tmp->next = insert;
			return head;
		}
	}
		node *insert = (node*)malloc(sizeof(node));
		insert->product = pinfo;
		tmp->next = insert;
		return head;
}



/* add_sorted_category_ID: inserts node in sorted spot based on productID and category
	* input:
	*    product_info *pinfo - product to insert, with details about ID and category
	*    node *head - head of link list to insert into
	* output: node * - modifed list
*/
node *add_sorted_category_ID(product_info *pinfo, node *head) {
	node *tmp;
	printf("calling\n");
	tmp = head;
	if (tmp->next->product->productID > pinfo->productID &&
				(tmp->next->product->category  == pinfo->category)) {
		return insert_head(head, pinfo);
	}

	for (tmp = head; tmp->next != NULL ; tmp = tmp->next) {

		while (tmp->next->product->category  == pinfo->category) {
			if ((tmp->next->product->productID > pinfo->productID) &&
			(tmp->next->product->category  == pinfo->category)) {

				printf("hello1\n");
				node *insert = (node*)malloc(sizeof(node));
				insert->product = pinfo;
				insert->next = tmp->next;
				tmp->next = insert;
				return head;
			}
			else {
				break;
			}
		}
	}
	node *insert = (node*)malloc(sizeof(node));
	insert->product = pinfo;
	insert->next = tmp->next;
	tmp->next = insert;
	return head;
}


/* make_restock_list: creates link list of items that need to be restocked
	* input:
	*    node *head - link list of items
	* output: node * - new list of items to restock
*/
node *make_restock_list(node *head) {
	node *restock = (node*)malloc(sizeof(node));
	node *tmp;
	restock = NULL;
	for (tmp = head; tmp->next != NULL; tmp = tmp->next) {
		if (tmp->product->current_stock < tmp->product->min_for_restock) {
			restock = insert_head(restock, tmp->product);
		}
	}
	return restock;
}



/* record_restocked_list: Restocks list of items that needs to be restocked
	* input:
	*    node *restocked_list - list that tells what needs to be restocked
	*    node *head - list that will be restocked
	* output: node * - new list of items to restock
*/
void record_restocked_list(node *restocked_list, node *head){
	node *tmp = NULL;
	print_list(restocked_list, stdout);
	for (tmp = restocked_list; tmp != NULL; tmp = tmp->next) {
		record_restocked_single(head, tmp->product->productID);
	}
}
