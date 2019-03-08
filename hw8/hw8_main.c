#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "memory.h"
#include "my_alloc.h"
#include "llist.h"


extern bst* avail_mem;


/* print_tree: prints tree with data to insert if needed
	* input:
	*    bst* b - bst
  *    void*data - info to insert or delete
  *    int insert - if 1, insert data, if -1 delete. if 0 just print
	* output: node * - pointer modified list
*/
void print_tree(bst* b, void*data, int insert){
  if (data == NULL) {
    bst_inorder_traversal(b, memory_print);
    return;
  }
  else if (insert == 1){
    return;
  }
  else {
    printf("%d\n", ((memory*)data)->size);
    printf("Inserted: ");
    memory_print(data);
    bst_insert(b, data);
    bst_inorder_traversal(b, memory_print);
  }
}


void successor_test(bst *b, void *item) {
    printf("Item Memory: %u\n", ((memory*)item)->size);
    print_tree(b, NULL, 0);

    printf("%p", bst_item_or_successor(b, item));

  }


bst* make_simple_bst(){
  bst* new = bst_new(memory_size_cmp);

// How do i know the address
// Or write as integer and cast as a void pointer
  bst_insert(new, memory_new(malloc(40) ,32));
  bst_insert(new, memory_new(malloc(40) ,16));
  bst_insert(new, memory_new(malloc(40) ,48));
  bst_insert(new, memory_new(malloc(40) ,24));
  bst_insert(new, memory_new(malloc(40) ,8));
  bst_insert(new, memory_new(malloc(40) ,40));

  return new;
}


int main() {

  //bst* temp = make_simple_bst();

//  successor_test(temp, memory_new(allocate_memory_page() ,32));

  return 0;
}
