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





#endif
