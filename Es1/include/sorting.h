#pragma once
/**
 * The library assumes
 *    that the function returns a value less than 0 if the first 
 *    object is smaller than the second, returns 0
 *    if they are equal, and it returns a value larger than 0 
 *    if the first object is larger than the second.
 */
typedef int (*compare_fun)(void*, void*) ;

/**
 * Sort an array using Quicksort algotithm.
 * NOTE: The returned Array* is malloc'ed,
 * 		 an Array_free(Array*) may be useful.
 * 
 * @param  array    A pointer to the array to sort
 * @param  length   The length of array
 * @param  elemSize The size of each element
 * @param  compare  A compare_fun function that compares two elemetns of the array
 * @return          Returns the sorted Array
 */
Array* quick_sort(void* array, int length, int elemSize, compare_fun compare);
Array* insertion_sort(Array* a, int ln, compare_fun compare);
