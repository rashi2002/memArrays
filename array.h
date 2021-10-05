

#include <stdio.h>
#include <stdlib.g>
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
void readItem(structmemsys *memsys,struct Array *array, unsigned int index, void *dest );
void writeItem(structmemsys *memsys, struct Array *array, unsigned int index, void *src);
void contract(structmemsys *memsys, struct Array *array);
void freeArray(structmemsys *memsys, struct Array *array );
void appendItem(structmemsys *memsys, struct Array *array, void *src);
void insertItem(structmemsys *memsys, structArray *array, unsigned int index, void *src);
void prependItem(structmemsys *memsys, struct Array *array, void *src);
void deleteItem(structmemsys *memsys, struct Array *array, unsigned int index);

//function declarations - the last 2 functions

int findItem(struct memsys *memsys, struct Aray *array, int (*compar)(const void*, const void*), void *target);
int searchItem(struct memsys *memsys, struct Array *array, int (*compar)(const void*, const void*), void *target);


//helper functions






















