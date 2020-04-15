#pragma once

/**
 * The library assumes
 *    that the function returns a value less than 0 if the first 
 *    object is smaller than the second, returns 0
 *    if they are equal, and it returns a value larger than 0 
 *    if the first object is larger than the second.
 */
typedef int (*compare_fun)(void*, void*);

/**
 * Sort an Array using Quicksort algotithm.
 * 
 * @param a       An array of pointers to the elemets to sort
 * @param length  Length of the array
 * @param size    Size of each element pointed
 * @param compare Function of type compare_fun
 */
void quick_sort(void** a, int length, size_t size, compare_fun compare);

/**
 * Sort an Array using InserionSort algorithm.
 * 
 * @param a       An array of pointers to the elemets to sort
 * @param length  Length of the array
 * @param size    Size of each element pointed
 * @param compare Function of type compare_fun
 */
void insertion_sort(void** a, int length, size_t size, compare_fun compare);