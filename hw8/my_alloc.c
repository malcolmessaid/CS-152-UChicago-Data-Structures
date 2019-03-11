#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#include "memory.h"

/* Global variables
 * By declaring these outside of a function:
 *   Scope: Every function inside of this file may use them.
 *   		No functions in other files may use them.
 *   Lifetime: They exist for the entire program - they are created
 *		when the program begins and exist until the program
 *		ends.
 */

/* This is the tree that holds the available memory. */
bst *avail_mem = NULL;
//bst *address_sorted_mem = NULL;

/* This includes all of the functions for the memory allocator.
 * The last two functions (my_malloc and my_free) are public
 * functions with prototypes in the header function. The rest of the
 * functions are helper functions only called by my_malloc and
 * my_free. You must implement these helper functions. If you wish,
 * you may add helper functions we did not define.
 */




 bst* init_address_bst(){
	 bst* address_sorted_mem = bst_new(memory_addr_cmp);
	 void *item;
	 for(item = bst_iterate(avail_mem); item != NULL; item = bst_iterate(NULL)){
		 bst_insert(address_sorted_mem, item);
	 }
   return address_sorted_mem;
 }

/* compact_memory
 *
 * Search through all available memory and attempt to merge memory
 * that is stored next to each other.
 * This uses global variable avail_mem, so it does not need any
 * input parameters. Look at the bst functions and memory functions.
 */
void compact_memory()
{
	bst* add_bst = init_address_bst();

	void *item;
	for(item = bst_iterate(add_bst); item != NULL; item = bst_iterate(NULL)){
    // am i using the iterator correctly??
    void* next_item = bst_iterate(NULL);
    memory_print((memory*)next_item);
    void *item_two = merge_memory(item, next_item);


    // If there is a merge, then keep going through list until no merge is necesassy
    // This is so the following node is not skipped.
		while(item_two){
      item = bst_iterate(NULL);
      item_two = merge_memory(item, bst_iterate(NULL));
    }
	}
}

/* print_available_memory
 *
 * Print out all available memory in ascending order by size.
 */
void print_memory()
{

	void *item;
	for(item = bst_iterate(avail_mem); item != NULL; item = bst_iterate(NULL)) {
    memory_print((memory*)item);
	}
}

/* init_alloc
 *
 * Initializes the data structures. This initializes avail_mem so
 * that, instead of being a NULL pointer, it points to a valid bst
 * struct whose root pointer is NULL.
 */
void init_alloc()
{
	bst* new = bst_new(memory_size_cmp);

	avail_mem = new;

}

void* add_to_address_alloc(void *address, int x){

	char *pc = (char*)address;
	pc += x;
	return (void*)pc;
}


/* my_malloc
 *
 * function that finds a piece of available memory that is at least
 * num_bytes size. A pointer to the beginning of the usable piece of
 * that chunk is returned.
 */
void *my_malloc(int num_bytes)
{
	if ((num_bytes % 8) != 0) {
		num_bytes += (8 - (num_bytes % 8));
	}
	memory* new_mem = memory_new(NULL, num_bytes);
	memory* space = (memory*)bst_item_or_successor(avail_mem, new_mem);

  memory_print(space);
	if (space == NULL){

		// Save the size of each assinged memory chunk in a poitner with the add_to_address__alloc
		// eight fewer than the address of the memory chunk
		unsigned int* size_ptr;
		memory* empty;

		empty = allocate_memory_page();

	// If num bytes is greater than half of entire page then you need to give them
	// entire new block
		if (4088 >= num_bytes * 2){

			void* split = split_memory(empty, (unsigned int) num_bytes);
			size_ptr = add_to_address_alloc(split, -8);

			*size_ptr = num_bytes;

			bst_insert(avail_mem, empty);
			return split;
		}
		else {
      // How do you do this poropelry. Are you suppoed to free

			unsigned int* size_ptr;
			void* save = empty->addr;

      //memory_free(space);

			size_ptr = add_to_address_alloc(save, -8);

			*size_ptr = (unsigned int) num_bytes;
			// Why are you adding to space->addr. It should be in the right spot already
			return add_to_address_alloc(empty->addr, 8);
		}

	}

	else if (space->size >= num_bytes * 2){
		// use space
		unsigned int* size_ptr;
		// Split is the address of the usable data
		void* split = split_memory(space, num_bytes * 2);

		bst_delete(avail_mem, space);

		size_ptr = add_to_address_alloc(split, -8);
		// ABOVE LINE SHOULD SHOW THAT SPACE ADDRESS IS POINTING TO USABLE MEMORY
		*size_ptr = (unsigned int) num_bytes;

		bst_insert(avail_mem, space);

		return split;
	}
	else {

		// Allocating entire remaining chunk if less than 2*num_bytes
		unsigned int* size_ptr;
		void* save = space->addr;

		bst_delete(avail_mem, space);
		memory_free(space);

		size_ptr = add_to_address_alloc(save, -8);
		*size_ptr = (unsigned int) num_bytes;

		return add_to_address_alloc(space->addr, 8);
	}
	return NULL;
}

// Why are you adding to space->addr. It should be in the right spot already
// The whoole thing is broken. memory struct at the beginning cannot point to beginning and others point to usable part\
// there is no way of knowing how to return the usable spot in add_to_address_alloc

// The below is correct if space is the oringinal memory struct pointing to the
// the beginning of a page. But it is incorrect if it is one of the structs
// created by my_free becasue those address are said to be pointing to the
// usable data

/* my_free
 *
 * Function that returns the memory chunk whose usable piece starts
 * at that address back to the set of available memory so that it can
 * be reused in a subsequent free call
 */
void my_free(void *address)
{
	unsigned int* size;
	size = add_to_address_alloc(address, -8);
	// are we supposed to free the storage of the size here
	// If the info is being stored in the memory struct, why does it need
	// to be allocated anymore.

// BIG DECISION ABOUT ADDRESSES HERE
	// i guess you could make the address address -= 8. so that i had the data
	// all referenced by the memory struct
	memory* new = memory_new(add_to_address_alloc(address, -8), *size);
	// This means that memory struct has size stored too
	bst_insert(avail_mem, new);
	return;
}
