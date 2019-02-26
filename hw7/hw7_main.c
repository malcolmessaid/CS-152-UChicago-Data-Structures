#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "memory.h"
#include "hw7.h"

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
/* search_test: tests the search functions
	* input:
	*    bst* b - bst
  *    void*data - info to search for
	* output: node * - pointer modified list
*/
int search_test(bst* b, memory* data, void* expected){
  memory* temp = (memory*)bst_search(b, data);
  if (temp == NULL && expected == NULL){
    printf("search_test passed: bst_search and node_search work\n");
    return 1;
  }
  if (b->cmp(temp, expected) == 0){
    printf("search_test passed: bst_search and node_search work\n");
    return 1;
  }
  else {
    fprintf(stderr, "search_test failed: incorrect data type failed\n");
    return 0;
  }
}


void delete_test(bst* b, memory* data){
  printf("deleted: ");
  memory_print(data);
  bst_delete(b, data);
  print_tree(b, NULL, 0);
}


int main() {
  bst* test1 = bst_new(memory_addr_cmp);
  bst* test2 = bst_new(memory_addr_cmp);
  bst* test3 = bst_new(memory_addr_cmp);

  // Tests for read memory blocks and bst_inorder_traversal
  test1 = read_memory_blocks("testmemory1.txt", memory_addr_cmp);
  test2 = read_memory_blocks("testmemory2.txt", memory_size_cmp);


  printf("\nTests for read_memory_blocks and bst_inorder_traversal\n");

  printf("Prints testmemory1:\n");
  bst_inorder_traversal(test1, memory_print);

  printf("\nPrints testmemory2:\n");
  bst_inorder_traversal(test2, memory_print);

  printf("\nPrints an empty BST should not be able to read:\n");
  test3 = read_memory_blocks(NULL, memory_addr_cmp);
  bst_inorder_traversal(test3, memory_print);



  //print_tree(test1, test5, 0);


  // Tests for Search
  search_test(test1, memory_new(2, 50), (memory_new(2, 50)));
  search_test(test1, memory_new(4, 100), (memory_new(4, 100)));
  search_test(test2, memory_new(4, 111), (memory_new(4, 111)));

  // Tests for Delete
  //memory* test7 = memory_new(6, 175);
///  bst_insert(test1, test7);
  delete_test(test1, memory_new(2, 50));




  return 0;
}
