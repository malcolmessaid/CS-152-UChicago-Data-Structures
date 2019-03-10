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
void print_tree(bst* b){
    bst_inorder_traversal(b, memory_print);
}


void successor_test(bst *b, void *item) {
    printf("Successor Tests: \n");
    print_tree(b);
    memory* ret_val = (memory*)bst_item_or_successor(b, item);

    printf("Inputed Memory Struct: ");
    memory_print((memory*)item);
    printf("Chosen Memory Struct: ");
    memory_print(ret_val);
    printf("\n");
    //printf("Successor: %p\n", );

}


void delete_test(bst* b, memory* data){
  printf("deleted: ");
  memory_print(data);
  bst_delete(b, data);
  print_tree(b);
}



// need to test for throughly
void my_malloc_tester(bst *b, unsigned int bytes){
  printf("my_malloc TEST:\n");

  printf("Tree Before:\n");
  print_tree(b);




  my_malloc(bytes);

  printf("Size subtracted by %u\n", bytes);
  printf("Tree after Call\n");

  print_tree(b);
  printf("\n");

}


void free_test(bst *b, void *address, int size){
  printf("my_free Test:\n");
  printf("Tree Before\n");
  print_tree(b);

  my_free(address);
  // printf("%u\n", );

  printf("Should insert ");
  memory* expected = memory_new(address, size);
  memory_print(expected);

  printf("Tree after\n");
  print_tree(b);

}





bst* make_simple_bst(){
  bst* new = bst_new(memory_size_cmp);

// How do i know the address
// Or write as integer and cast as a void pointer
  bst_insert(new, memory_new(malloc(50) ,32));
  bst_insert(new, memory_new(malloc(50) ,16));
  bst_insert(new, memory_new(malloc(50) ,48));
  bst_insert(new, memory_new(malloc(50) ,24));
  bst_insert(new, memory_new(malloc(50) ,8));
  bst_insert(new, memory_new(malloc(50) ,40));

  return new;
}


int main() {

  bst* temp = make_simple_bst();

  //
  // successor_test(temp, memory_new(malloc(50) ,32));


  delete_test(temp, memory_new(malloc(50) ,48));
  delete_test(temp, memory_new(malloc(50) ,41324));

  // Free Tests
  init_alloc();
  // void * da = my_malloc(400);
  // my_free(da);
//  free_test(avail_mem, my_malloc(150), 150);


  // my_malloc_tester(avail_mem, 50);
  // my_malloc_tester(avail_mem, 150);
  // my_malloc_tester(avail_mem, 2000);

  return 0;
}
