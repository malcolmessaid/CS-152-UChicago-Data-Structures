#include<stdio.h>
#include<stdlib.h>
#include "memory.h"
#include "my_alloc.h"

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
  // This might be wrong. Could it be at the beginning
  newmem =  memory_new(mem , 4088);

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
  return add_to_address(data->addr, data->size + 16);

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
  // This can only be done properly if I understand where things are pointing to.
  void* f_add = first->address;
  void* s_add= second->address;

  unsigned int* f_size;
  unsigned int* s_size;
  f_size = add_to_address(f_add, -8);
  s_size = add_to_address(s_add, -8);

// Todo: figure out way to free s_size.
  if (memory_addr_cmp(add_to_address(f_add, 8 + first->size),s_add) == 0){
    memory* new = memory_new(f_add, 8 + first->size + second->size);
    *f_size = 8 + first->size + second->size;

    bst_delete(avail_mem, first);
    bst_delete(avail_mem, second);

    bst_insert(new);
    return new;
  }
  //FREE THE OLD STRUCTS IN HEREE
  else {
    return NULL;
  }
}
