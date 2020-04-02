#pragma once
/**
 * The library assumes
 *    that the function returns a value less than 0 if the first 
 *    object is smaller than the second, returns 0
 *    if they are equal, and it returns a value larger than 0 
 *    if the first object is larger than the second.
 */
typedef int (*compare_fun)(void*, void*) ;

Array* quick_sort(Array* a, int startIndex, int endIndex, compare_fun compare);