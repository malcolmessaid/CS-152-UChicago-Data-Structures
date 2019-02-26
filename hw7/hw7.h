#ifndef HW6_H
#define HW6_H
#include "bst.h"
#include "memory.h"


bst* read_memory_blocks(char *filename,
  int (*cmp)(const void* x, const void* y));


#endif
