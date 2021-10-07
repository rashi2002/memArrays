
#include "array.h"


struct Array *newArray(struct memsys *memsys, unsigned int width,unsigned int capacity)
{
	struct Array *arr;
	arr = (struct Array*)malloc(sizeof(struct Array));
	arr->width = width;
	arr->capacity = capacity;
	arr->nel = 0;
	arr->data = memmalloc(memsys, width*capacity);
	if(arr->data==-1){
		fprintf(stderr,"ERROR: memory allocation failed, memsys may be full");
		exit(0);
	}
	return arr;
}


void readItem(struct memsys *memsys,struct Array *array, unsigned int index, void *dest )
{
	if (index >= array->nel){
		fprintf(stderr, "ERROR: index greater than the number of elements");
		exit(0);               
	}
	getval(memsys, dest, array->width, array->data + (index*(array->width)));
}

void writeItem(struct memsys *memsys, struct Array *array, unsigned int index, void *src)
{
	if ((index > array->nel) || (index>= array->capacity)){
		fprintf(stderr, "ERROR: index greater than the number of elements or greater than/equal to the capacity");		
		exit(0);               
	}

	if(array->nel == index){

		array->nel++;
	}
	

	setval(memsys, src, array->width , array->data + (index*(array->width)));

}

void contract(struct memsys *memsys, struct Array *array)
{
	if (array->nel==0){
		fprintf(stderr, "ERROR: No elements in the array\n" );
	}
	array->nel--;
}

void freeArray(struct memsys *memsys, struct Array *array )
{
	memfree(memsys, array->data);
	free(array);
	/*for(int i=(array->nel-1), i>=0;i-- ){
		free(array[i]);	
	}*/
}

void appendItem(struct memsys *memsys, struct Array *array, void *src)
{
	writeItem(memsys, array, array->nel,src);

}

void insertItem(struct memsys *memsys, struct Array *array, unsigned int index, void *src)
{
	appendItem(memsys,array, &array[array->nel]);
	struct Array temp;
	void* dest = malloc(sizeof (struct Array));
	temp.width = array[array->nel].width;
	temp.nel = array[array->nel].nel;
	temp.capacity = array[array->nel].capacity;
	temp.data = array[array->nel].data;
	for (int i=array->nel; i>index; i-- ){
		readItem(memsys, array, i-1, dest);
		writeItem(memsys, array, i, dest);
	}
	writeItem(memsys, array, index, src);
	
}








