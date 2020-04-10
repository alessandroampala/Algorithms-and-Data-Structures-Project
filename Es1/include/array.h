#pragma once

typedef struct _Array Array;

/**
 * Create a new Array.
 * 
 * @param void* array   A pointer to the array
 * @param int length    The length of array
 * @param int elemSize  The size of each element
 *                      of array in bytes
 * @return Array*       A pointer to the new Array created
 */
Array* Array_new(void* array, int length, int elemSize);

/**
 * Returns a void* pointer to the element.
 * If i >= Array_length(a), NULL is returned.
 */
void* Array_get(Array* a, int i);

/**
 * Set the element in i position to the element
 * pointed to elem.
 * If i >= Array_length(a), nothing will happen.
 */
void Array_set(Array* a, int i, void* elem);

/**
 * Returns the length of the array
 */
int Array_length(Array* a);

/**
 * Swap two elements in the array.
 * If indexes are >= Array_length(a), nothing will happen.
 */
void Array_swap(Array* a, int i, int j);

/**
 * Free the allocated memory
 * (it does not free the memory of the objects
 *  in the array)
 */
void Array_free(Array* a);
