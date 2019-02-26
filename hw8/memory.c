#include<stdio.h>
#include<stdlib.h>
#include "memory.h"

/* memory_new
 * create a new memory struct, initialze its address and size
 */
memory* memory_new(void *addr, unsigned int size);
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
 // Pay attention to bugs here
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

	char *pc = (char*)v;
	pc += x;
  pc += 8
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

  void *memory = malloc(4096);

  memory* new_mem =  memory_new(add_to_address(memory, 8) , 4088);

  return new_mem;

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
// Update the size
  return add_to_address(data->addr, data->size + 8);

}
