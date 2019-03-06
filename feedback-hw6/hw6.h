#ifndef HW6_H
#define HW6_H


typedef unsigned int uint;

enum Category { GROCERY=0, OFFICE, PHARMACY, HOBBY};
#define NUM_CATEGORIES 4

typedef struct {
 enum Category category;
 char name[40];
 uint productID;
 uint current_stock;
 uint min_for_restock;
 uint max_after_restock;
} product_info;

// for the linked list, we will use the following struct
typedef struct _node node;

struct _node{
 product_info *product;
 node *next;
};

extern char *category_strings[];


void print_product(product_info *g, FILE *fp);
void print_list(node *head, FILE *fp);



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
				uint current, uint mn, uint mx);


/* insert_head: inserts node at beginning of link list
	* input:
	*    node *head - pointer to head of list
	*    product_info *pinfo - info to place at begginning
	* output: node * - pointer modified list
*/
node* insert_head(node *head, product_info *pinfo);

/* find: finds a node in a link list given pID
	* input:
	*    node *head - pointer to head of list
	*    uint pID - pID to search for
	* output: node * - pointer to matching node
*/
product_info *find(node *head, uint pID);



/* record_restocked_single: replaces the current number of items with the max number
	* input:
	*    node *head - head of link list
	*    uint pID - pID of node to restock
	* output: void - restocks node
*/
void record_restocked_single(node *head, uint pID);



/* record_restocked_single: subtracts current stock by one
	* input:
	*    node *head - head of link list
	*    uint pID - pID of node to sell
	* output: node * - sells one item
*/
void product_sold(node *head, uint pID);

/* add_sorted_productID: inserts node in sorted spot based on productID
	* input:
	*    product_info *pinfo - product to insert
	*    node *head - head of link list to insert into
	* output: node * - modifed list
*/
node *add_sorted_productID(product_info *pinfo, node *head);


/* add_sorted_category_ID: inserts node in sorted spot based on productID and category
	* input:
	*    product_info *pinfo - product to insert, with details about ID and category
	*    node *head - head of link list to insert into
	* output: node * - modifed list
*/
node *add_sorted_category_ID(product_info *pinfo, node *head);


/* make_restock_list: creates link list of items that need to be restocked
	* input:
	*    node *head - link list of items
	* output: node * - new list of items to restock
*/
node *make_restock_list(node *head);



/* record_restocked_list: Restocks list of items that needs to be restocked
	* input:
	*    node *restocked_list - list that tells what needs to be restocked
	*    node *head - list that will be restocked
	* output: node * - new list of items to restock
*/
void record_restocked_list(node *restocked_list, node *head);





#endif
