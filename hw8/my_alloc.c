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

/* This includes all of the functions for the memory allocator.
 * The last two functions (my_malloc and my_free) are public
 * functions with prototypes in the header function. The rest of the
 * functions are helper functions only called by my_malloc and
 * my_free. You must implement these helper functions. If you wish,
 * you may add helper functions we did not define.
 */

/* compact_memory
 *
 * Search through all available memory and attempt to merge memory
 * that is stored next to each other.
 * This uses global variable avail_mem, so it does not need any
 * input parameters. Look at the bst functions and memory functions.
 */
void compact_memory()
{
	fprintf(stderr,"compact_memory not implemented yet\n");
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
//fprintf(stderr,"print_memory not implemented yet\n");
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

	// 1. Bst successor to find a piece of memory that is equal to or larger
			// bst_item_or_successor
	// 2. Use split memory if chunk of memory is more than twice the size
	memory* new_mem = memory_new(NULL, num_bytes);
	//printf("%p\n", bst_item_or_successor(avail_mem, new_mem));
	memory* space = (memory*)bst_item_or_successor(avail_mem, new_mem);


	if (space == NULL){
		printf("%u\n", num_bytes);
		printf("ONE\n");
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

			unsigned int* size_ptr;
			void* save = space->addr;

			bst_delete(avail_mem, space);
			memory_free(space);

			size_ptr = add_to_address_alloc(save, -8);
			*size_ptr = (unsigned int) num_bytes;
			// Why are you adding to space->addr. It should be in the right spot already
			return add_to_address_alloc(space->addr, 8);
		}

	}

	else if (space->size >= num_bytes * 2){
		// use space
				printf("%u\n", num_bytes);
		printf("TWO\n");
		unsigned int* size_ptr;
		void* split = split_memory(space, num_bytes * 2);

		bst_delete(avail_mem, space);

		size_ptr = add_to_address_alloc(split, -8);
		*size_ptr = (unsigned int) num_bytes;

		bst_insert(avail_mem, space);

		return split;
	}
	else {
		printf("THREE\n");
				printf("%u\n", num_bytes);
		// Allocating entire remaining chunk if less than 2*num_bytes
		unsigned int* size_ptr;
		void* save = space->addr;

		bst_delete(avail_mem, space);
		memory_free(space);

		size_ptr = add_to_address_alloc(save, -8);
		*size_ptr = (unsigned int) num_bytes;
		// Why are you adding to space->addr. It should be in the right spot already
		return add_to_address_alloc(space->addr, 8);
	}
	return NULL;
}

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
	memory* new = memory_new(address, *size);
	bst_insert(avail_mem, new);
	return;
}
