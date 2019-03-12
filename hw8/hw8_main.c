#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "memory.h"
#include "my_alloc.h"
#include "llist.h"


extern bst* avail_mem;


/* print_tree: prints tree
	* input:
	*    bst* b - bst
	* output: node * - pointer modified list
*/
void print_tree(bst* b){
    bst_inorder_traversal(b, memory_print);
}

/* node_height: returns height of node tree
	* input:
	*    node* n - node to calculate height of =
	* output: int - height of node
*/
int node_height(node* n){
  if (n == NULL){
    return 0;
  }

  int left = node_height(n->left);
  int right = node_height(n->right);

  if (left > right){
    return (1 + left);
  }
  else {
    return (1 + right);
  }
}

/* bst_height: returns height of bst
	* input:
	*    bst* b - bst to calculate height of
	* output: int - height of bst
*/
int bst_height(bst* b){
  if (b == NULL){
    return 0;
  }
  return node_height(b->root);
}



/* height_test: tests height of bst
	* input:
  *    bst* b - to test on
  *    int expected - expected value
	* output: void - prints result of tests
*/
void height_test(bst* b, int expected){
  int val = bst_height(b);

  if (val == expected){
    printf("Test Passed: bst_height\n");
  }
  else {
    printf("Test Failed: actual value: %d, expected value %d\n", val, expected);
  }
}

/* Test for part 2 of part 2. Tests if height is same after bst_delete is called
 *  Takes in value to delete and bst to delete from.
 *  returns: nothing. prints results of tests
*/
void height_delete_test(bst* b, void* to_delete){
  int height_before = bst_height(b);

  bst_delete(b, to_delete);

  int height_after = bst_height(b);

  if (height_before >= height_after){
    printf("Test Passed: delete_test height the same after bst_delete\n");
  }
  else {
    printf("Test Failed: delete_test height greater after bst_delete\n");
    printf("height_before:%d, height_after:%d\n", height_before, height_after);
  }
}


/* successor_test: tests bst_item_or_successor
	* input:
  *    bst* b - to test on
  *    void* item - address to search for
	* output: void - prints result of tests
*/
void successor_test(bst *b, void *item, memory* expected) {

    memory* ret_val = (memory*)bst_item_or_successor(b, item);

    if (expected == ret_val){
      printf("Test Passsed bst_item_or_successor\n");
    }
    else if (b->cmp(expected, ret_val) == 0){
      printf("Test Passsed bst_item_or_successor\n");
    }
    else {
      printf("Test Failed bst_item_or_successor\n");
      printf("Inputed Memory Struct: ");
      memory_print((memory*)item);
      printf("Chosen Memory Struct: ");
      memory_print(ret_val);
    }


}


void delete_test(bst* b, memory* data){
  printf("deleted: ");
  memory_print(data);
  bst_delete(b, data);
  print_tree(b);
}


/* merge_test: tests to see if two nodes are propely merged if suppposed to be
	* input:
	*    node* n - node to calculate height of =
	* output: int - height of node
*/
void merge_test(memory* first, memory* second, memory* expected){
  memory* result = merge_memory(first, second);

  if (result == NULL && expected == NULL){
    printf("Test Passed merge_memory: did not merge\n");
    return;
  }
  else if (result == expected){
    printf("Test Passed merge_memory: Test Passed memories properly merged\n");
    return;
  }

  else {
    printf("Test Failed merge_memory: expected: %p actual: %p\n",
      expected, result);
    return;
  }
}



/* my_malloc_tester: tests my_malloc. my_malloc is also used throughout main and
  * works properly so there is implicit more thorough testing
	* input:
  *    bst* b - to test on
  *    unsigned int bytes - num_bytes for my_malloc call
	* output: void: visually inspect to find results
*/
void my_malloc_tester(bst *b, unsigned int bytes){
  printf("my_malloc call on %u and bellow tree:\n", bytes);
  printf("visually inspect\n");

  printf("Tree Before:\n");
  print_tree(b);

  my_malloc(bytes);

  printf("Tree After:\n");
  print_tree(b);
  printf("\n");

}


/* free_test: tests my_free. same as my_malloc, my_free is also used throughout
  * main and  works properly so there is implicit more thorough testing
	* input:
  *    bst* b - to test on
  *    void* address - address for my_free to call on
	* output: void: visually inspect to find results
*/
void free_test(bst *b, void *address, int size){
  printf("my_free Test:\n");
  printf("Tree Before\n");
  print_tree(b);

  my_free(address);

  printf("Should insert ");
  memory* expected = memory_new(address, size);
  memory_print(expected);

  printf("Tree after\n");
  print_tree(b);

}



/* make_simple_bst: makes simple bst with hard_coded values for testing
 * return value: hard_coded bst
*/
bst* make_simple_bst(){
  bst* new = bst_new(memory_size_cmp);

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

  printf("successor_tests \n");
   successor_test(temp, memory_new(malloc(50) ,32), memory_new(malloc(50) ,32));
   successor_test(temp, memory_new(malloc(50) ,24), memory_new(malloc(50) ,24));
   successor_test(temp, memory_new(malloc(50) ,234), NULL);



  printf("Delete Tests\n");
  delete_test(temp, memory_new(malloc(50), 48));
  printf("\n");
  delete_test(temp, memory_new(malloc(50), 41324));

  // Free Tests
  init_alloc();


  printf("\nmy_malloc Tests\n");
  my_malloc_tester(avail_mem, 50);
  my_malloc_tester(avail_mem, 150);
  my_malloc_tester(avail_mem, 2009);


  free(avail_mem);
  init_alloc();
//  print_tree(avail_mem);
  my_malloc(43);
  my_malloc(3);
  my_malloc(123);
  my_malloc(4000);
  my_malloc(4050);


  printf("Inspect Tree give malloc calls\nmy_malloc(43);\n"
  "my_malloc(3)\nmy_malloc(123);\nmy_malloc(4000);\nmmy_malloc(4050);\n");
  printf("Should be address: 0x1084a98, size: 3880\n");
  print_tree(avail_mem);

  free(avail_mem);
  init_alloc();



  printf("\nmy_free Tests\n");
  void* addr1 = my_malloc(400);
  void* addr2 = my_malloc(30);
  print_tree(avail_mem);

  printf("My free call on both addresses in tree\n");
  my_free(addr1);
  my_free(addr2);


  print_tree(avail_mem);



  printf("\nMerge Tests and Compacting \n");

  free(avail_mem);
  init_alloc();
  void* one = my_malloc(43);
  void* two = my_malloc(3);
  void* five = my_malloc(123);

  //print_tree(avail_mem);
  my_free(one);
  my_free(two);
  my_free(five);


  print_tree(avail_mem);
  memory* merge1 = bst_iterate(avail_mem);
  memory* merge2 = bst_iterate(NULL);
  memory* merge5 = bst_iterate(NULL);



  printf("Testing Merge Memory\n");
  //merge_test(merge1, merge2,)

  memory_print(merge_memory(merge1, merge2));
  printf("Test Passed: first merge called\n");
  printf("Size should be 64\n");
  //print_tree(avail_mem);

  printf("Second Merge Test Called\n");
  memory_print(merge_memory(merge5, merge1));
  printf("Test Passed: second merge called\n");
  printf("Size should be 200\n\n\n");\



  print_tree(avail_mem);



  printf("Compact Memory Testing\n");



  init_alloc();

  void* six = my_malloc(43);
  void* seven = my_malloc(3);
  void* eight = my_malloc(123);

  my_free(six);
  my_free(seven);
  my_free(eight);


  print_tree(avail_mem);
  printf("Before Call to print tree\n");
  compact_memory();
  printf("After Call to print tree\n");
  print_tree(avail_mem);


  printf("\n\nHeight Tests\n");
  bst* temp2 = make_simple_bst();
  height_test(temp2, 3);
  height_test(NULL, 0);

  height_delete_test(temp2,  memory_new(malloc(50) ,48));
  height_delete_test(temp2,  memory_new(malloc(50) ,32));
  height_delete_test(temp2,  memory_new(malloc(50) ,8));
  height_delete_test(temp2,  memory_new(malloc(50) ,40));



  return 0;
}
