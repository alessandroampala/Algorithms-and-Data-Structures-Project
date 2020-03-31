#include <stdlib.h>
#include "array.h"

struct _Array
{
	void** array;
	int length;
	int elemSize;
};

Array* Array_new(void* array, int length, int elemSize)
{
	Array* a = malloc(sizeof(Array));
	a->array = malloc(sizeof(void*) * length);
	for(int i = 0; i < length; i++)
	{
		a->array[i] = array + i * elemSize;
	}
	a->length = length;
	a->elemSize = elemSize;
	a->compare = compare;
}

void* Array_get(Array* a, int i)
{
	return a->array[i];
}

void Array_set(Array* a, int i, void* elem)
{
	a->array[i] = elem;
}

void Array_free(Array* a)
{
	free(a->array);
	free(a);
}