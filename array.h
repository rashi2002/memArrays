

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "memsys.h"

//structure declaration 

struct Array
{
	unsigned int width;
	unsigned int nel;
	unsigned int capacity;
	int data;
};

//function declarations- required functions 


struct Array *newArray(struct memsys *memsys, unsigned int width,unsigned int capacity);
void readItem(struct memsys *memsys,struct Array *array, unsigned int index, void *dest );
void writeItem(struct memsys *memsys, struct Array *array, unsigned int index, void *src);
void contract(struct memsys *memsys, struct Array *array);
void freeArray(struct memsys *memsys, struct Array *array );
void appendItem(struct memsys *memsys, struct Array *array, void *src);
void insertItem(struct memsys *memsys, struct Array *array, unsigned int index, void *src);
void prependItem(struct memsys *memsys, struct Array *array, void *src);
void deleteItem(struct memsys *memsys, struct Array *array, unsigned int index);

//function declarations - the last 2 functions

int findItem(struct memsys *memsys, struct Array *array, int (*compar)(const void*, const void*), void *target);
int searchItem(struct memsys *memsys, struct Array *array, int (*compar)(const void*, const void*), void *target);


//helper functions






















