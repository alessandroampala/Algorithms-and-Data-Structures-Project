#pragma once

typedef struct _Array Array;
typedef int (*ArrayCmp)(void*, void*) ;

Array* Array_new(void* array, int length, int elemSize);
void* Array_get(Array* a, int i);
void Array_set(Array* a, int i, void* elem);
void Array_free(Array* a);