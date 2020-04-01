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
 * Returns a void* pointer to the element
 */
void* Array_get(Array* a, int i);

/**
 * Set the element in i position to the element
 * pointed to elem
 */
void Array_set(Array* a, int i, void* elem);

/**
 * Returns the length of the array
 */
int Array_length(Array* a);

/**
 * Free the allocated memory
 * (it does not free the memory of the objects
 *  in the array)
 */
void Array_free(Array* a);
