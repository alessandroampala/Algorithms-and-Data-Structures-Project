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
  if(array == NULL || !length) return NULL;
  Array* a = malloc(sizeof(Array));
  a->array = malloc(sizeof(void*) * length);
  for(int i = 0; i < length; i++)
  {
    a->array[i] = array + i * elemSize;
  }
  a->length = length;
  a->elemSize = elemSize;

  return a;
}

void* Array_get(Array* a, int i)
{
  if(a == NULL || i < 0 || i >= length) return NULL;
  return a->array[i];
}

void Array_set(Array* a, int i, void* elem)
{
  if(a != NULL || i < 0 || i >= length)
    a->array[i] = elem;
}

int Array_length(Array* a)
{
  if(a == NULL) return -1;
  return a->length;
}

void Array_swap(Array* a, int i, int j)
{
  if(a == NULL || i >= a->length || j >= a->length) return;
  void* tmp = Array_get(a, i);
  Array_set(a, i, Array_get(a, j));
  Array_set(a, j, tmp);
}

void Array_free(Array* a)
{
  if(a == NULL) return;
  if(Array_length(a) > 0)
    free(a->array);
  free(a);
}