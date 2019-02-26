#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "hw7.h"
#include "bst.h"
#include "memory.h"



bst* read_memory_blocks(char *filename,
  int (*cmp)(const void* x, const void* y)) {
    FILE *fp;
    char buf[BUFSIZ] = "Garbage";
    int i;
    bst* new = bst_new(cmp);

    // attempt to open the file, then check whether that worked.
    if ((fp = fopen(filename, "r")) == NULL)
    {
      fprintf(stderr,"Could not open file %s\n",filename);
      return NULL;
    }

    // for each line of the file, read it in and then print it out
    char *tokenPtr;

    i = 0;
    while (fgets(buf, sizeof(buf), fp) != NULL)
    {
	    tokenPtr = strtok(buf, ",\n");
      int address = atoi(tokenPtr);
      tokenPtr = strtok(NULL, ",\n");
      int size = atoi(tokenPtr);

  //    memory* temp = ;

      bst_insert(new, (void*)memory_new(address, size));

      i++;
    }

    fclose(fp);
    return new;
  }

// void display_file(char *filename)
// {
//   FILE *fp;
//   char buf[BUFSIZ] = "Garbage";
//   int i;
//
//   // attempt to open the file, then check whether that worked.
//   if ((fp = fopen(filename, "r")) == NULL)
//   {
//     fprintf(stderr,"Could not open file %s\n",filename);
//     return (1);
//   }
//
//   // for each line of the file, read it in and then print it out
//   i = 0;
//   while (fgets(buf, sizeof(buf), fp) != NULL)
//   {
//     printf ("Line %4d: %s", i, buf);
//     i++;
//   }
//
//   fclose(fp);
// }
