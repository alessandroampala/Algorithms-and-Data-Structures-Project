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
 * Sort an Array using Quicksort algotithm.
 * 
 * @param  a       A pointer to the Array to sort
 * @param  compare Function of type compare_fun
 * @return         Returns the sorted Array
 */
Array* quick_sort(Array* a, compare_fun compare);

/**
 * Sort an Array using InserionSort algorithm.
 * @param  a       A pointer to the Array to sort
 * @param  compare Function of type compare_fun
 * @return         Returns the sorted Array
 */
Array* insertion_sort(Array* a, compare_fun compare);