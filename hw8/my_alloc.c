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
	fprintf(stderr,"print_memory not implemented yet\n");
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

/* my_malloc
 *
 * function that finds a piece of available memory that is at least
 * num_bytes size. A pointer to the beginning of the usable piece of
 * that chunk is returned.
 */
void *my_malloc(int num_bytes)
{
	if ((num_bytes % 8) != 0) {
		num_bytes += (num_bytes % 8);
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
	fprintf(stderr,"my_free not implemented yet\n");
}
