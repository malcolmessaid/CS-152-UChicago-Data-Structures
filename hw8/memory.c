#include<stdio.h>
#include<stdlib.h>
#include "memory.h"
#include "my_alloc.h"
// Ask if you can do this
#include "bst.h"

extern bst* avail_mem;

/* memory_new
 * create a new memory struct, initialze its address and size
 */
memory* memory_new(void *addr, unsigned int size){
  memory* m = (memory*)malloc(sizeof(memory));
  m->addr = addr;
  m->size = size;
  return m;
}

/* free the dynamically allocated memory struct
 */
void memory_free(void* p){
  memory* m = (memory*)p;
  free(m);
}

/* compare two memory variables x and y by address
 * if x is less than y, return -1
 * if x is greater than y, return 1
 * if they are equal, return 0
 */
 // How do you compare addresses if they are void pointers
int memory_addr_cmp(const void* x, const void* y){
  //TODO
  memory *mem1 = (memory*)x;
  memory *mem2 = (memory*)y;

  if (mem1->addr == mem2->addr){
    return 0;
  }
  else if (mem1->addr < mem2->addr) {
    return -1;
  }
  else {
    return 1;
  }

}

/* compare two memory variables x and y by size
 * if x is less than y, return -1
 * if x is greater than y, return 1
 * if they are equal, return 0
 */
 // Pay attention to bugs here
int memory_size_cmp(const void* x, const void* y){
  memory *mem1 = (memory*)x;
  memory *mem2 = (memory*)y;

  if (mem1->size == mem2->size){
    return 0;
  }
  else if (mem1->size < mem2->size) {
    return -1;
  }
  else {
    return 1;
  }

  return 0;
}

/* print the memory address and size
 */
void memory_print(void* data){
  if (data == NULL) return;
  memory* m = (memory*)data;
  printf("address: %p, size: %u\n", m->addr, m->size);
}



void* add_to_address(void *address, int x){

	char *pc = (char*)address;
	pc += x;
	return (void*)pc;
}

/* allocate_memory_page
 *
 * Call malloc to request a page of data - 4096 bytes. Create
 * a memory struct and initialize it to store the resulting
 * large chunk of data that was allocated. Return a pointer
 * to the memory struct.
 */
memory *allocate_memory_page() {

  void *mem = malloc(4096);
  memory* newmem;
  newmem =  memory_new(add_to_address(mem, 8), 4088);

  return newmem;

}



/* split_memory
 *
 * Given a memory struct and a desired size of memory,
 * perform the operations necessary to remove the desired
 * size of memory from the end of the chunk and record
 * the new information for the smaller chunk. Return a
 * pointer to the beginning of the chunk you are handing out.
 */
void *split_memory(memory* data, unsigned int size_desired) {


  data->size = data->size - size_desired - 8;
  // THis might be plus 16


  // Points to the beginning of the usable chunk
  return add_to_address(data->addr, data->size + 8);

}

/* merge_memory
 *
 * Given two memory structs, check to see if the two can be
 * merged. They can be merged if the two are next to each other
 * in memory with no break in between. If they can be merged,
 * return a memory struct pointer to a struct containing the information
 * for a single memory chunk containing the old two chunks.
 * If they cannot be merged (there is space between them), then
 * return NULL;
 *
 * Make sure that you free any memory structs that you need to.
 */
memory *merge_memory(memory *first, memory *second) {
  void* f_add = first->addr;
  void* s_add= second->addr;

  unsigned int* f_size;
  unsigned int* s_size;
  f_size = add_to_address(f_add, -8);
  s_size = add_to_address(s_add, -8);
  // printf("%d\n", first->size);
  // printf("%d\n", second->size);
  //
  // printf("%ld\n", f_add - s_add);
  //
  // printf("merge 5 plus 120 %p\n", add_to_address(s_add, 120));
  // printf("merge 5 plus 128 %p\n", add_to_address(s_add, 128));
  // printf("merge 5 plus 136 %p\n", add_to_address(s_add, 136));

  //
  // printf(" %d\n", 48 + 16);
  // printf("second size %d\n", second->size);
  //   printf("first size %d\n", first->size);
  // printf("Second Address Plus Size %p\n", add_to_address(s_add, 8 + second->size));
  // printf("First address %p\n", f_add);
  //
  // printf("First Address Plus Size %p\n", add_to_address(f_add, 8 + first->size));
  // printf("Second address %p\n", add_to_address(s_add , 8));


  if ((add_to_address(f_add, 8 + first->size) == s_add) ||
      add_to_address(s_add, 8 + second->size) == f_add){

  //  printf("%s\n", );
  // printf("second size %d\n", second->size);
  //   printf("first size %d\n", first->size);
    first->size = (8 + first->size + second->size);
    *f_size = first->size;

// Delete this based on decison
// Please Note: In the directions it says to free uneeded structs here. But
// from Piazza and what I think make more sense, I will free the structs in
// compact_memory instead;


// You need to delete based on address not size
    bst_delete(avail_mem, second);

    free(second);

    return first;
  }
  else {
    return NULL;
  }
}
