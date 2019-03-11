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



void successor_test(bst *b, void *item) {
    printf("Successor Test: \n");
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



/* make_simple_bst: makes simple bst with hard_coded values for testing
 * return value: hard_coded bst
*/
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
//  print_tree(temp);
  printf("Delete Tests\n");
  delete_test(temp, memory_new(malloc(50), 48));
  printf("\n");
  delete_test(temp, memory_new(malloc(50), 41324));

  // Free Tests
  init_alloc();
  // void * da = my_malloc(400);
  // my_free(da);
//  free_test(avail_mem, my_malloc(150), 150);


  printf("my_malloc Tests\n");

  my_malloc_tester(avail_mem, 50);
  my_malloc_tester(avail_mem, 150);

//ADDRESS HOW THIS BREAKS THIS FUNCTIONS. SHOULD IT? WHAT ELSE SHOULD IT DO
//  my_malloc_tester(avail_mem, 2000);


  printf("my_free Tests\n");
  void* addr1 = my_malloc(400);
  void* addr2 = my_malloc(30);
  print_tree(avail_mem);

  my_free(addr1);
  my_free(addr2);

  printf("My free call\n");
  print_tree(avail_mem);



  printf("\nMerge Tests and Compacting \n");
  // memory* merge1 = bst_iterate(avail_mem);
  // memory* merge2 = bst_iterate(NULL);
  // memory* merge3 = bst_iterate(NULL);
  // print_memory();

  free(avail_mem);
  init_alloc();
  printf("hemm\n");
  print_tree(avail_mem);
  printf("he\n");
  void* one = my_malloc(48);
  void* two = my_malloc(1);
  void* third = my_malloc(4000);
  void* four = my_malloc(4050);
  print_tree(avail_mem);
  printf("hetwo\n");
  my_free(one);
  my_free(two);
  my_free(third);
  my_free(four);
  // merge_test(merge2, merge1,
  //   memory_new(merge1->addr, merge1->size + merge2->size + 8));
  // //merge_test(merge1, merge2, )

  print_tree(avail_mem);
  memory* merge1 = bst_iterate(avail_mem);
  memory* merge2 = bst_iterate(NULL);
  memory* merge3 = bst_iterate(NULL);

  printf("memt test\n");
  memory_print(merge_memory(merge1, merge2));
  //memory_print(merge_memory(me, third));
  //memory_print(merge_memory(one, two));

  printf("Height Tests\n");
  bst* temp2 = make_simple_bst();
  height_test(temp2, 3);
  height_test(NULL, 0);

  height_delete_test(temp2,  memory_new(malloc(50) ,48));
  height_delete_test(temp2,  memory_new(malloc(50) ,32));
  height_delete_test(temp2,  memory_new(malloc(50) ,8));
  height_delete_test(temp2,  memory_new(malloc(50) ,40));



  return 0;
}
