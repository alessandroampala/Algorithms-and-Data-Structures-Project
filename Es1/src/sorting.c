#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sorting.h"


/**
 * Swap two elements
 */
void swap(void* a, void* b, size_t n)
{
  int* tmp = malloc(n);
  memcpy(tmp, a, n);
  memcpy(a, b, n);
  memcpy(b, tmp, n);
  free(tmp);
}

void insertion_sort(void** a, int length, size_t size, compare_fun compare)
{
  if(a != NULL)
  {
    for(int i = 1; i < length; i++)
    {
      int j = i;
      while(j >= 1 && compare(a[j-1], a[j]) > 0)
      {
        swap(a[j-1], a[j], size);
        j--;
      }
    }
  }
}

/**
 * Find the correct position of pivot.
 * @param al          An array of pointers
 * @param startIndex  First index of a and also the first position of pivot
 * @param endIndex    Last index of a
 * @param size        Size of each element pointed
 * @param compare     Function of type compare_fun
 * At the end:
 * - pivot is in a[j]
 * - all elements between a[startIndex] and a[j-1] are <= than pivot
 * - all elements between a[j+1] and a[endIndex] are >= than pivot
 */
int partition(void** a, int startIndex, int endIndex, size_t size, compare_fun compare)
{
  int i = startIndex + 1;
  int j = endIndex - 1;

  while(i <= j)
  {
    if(compare(a[i], a[startIndex]) < 0) i++; // a[i] < a[startIndex]
    else if(compare(a[j], a[startIndex]) > 0) j--; //a[j] > a[startIndex]
    else
    {
      swap(a[i], a[j], size);
      i++;
      j--;
    }
  }

  swap(a[startIndex], a[j], size);
  return j;
}


/*
 * Core method of Quick Sort
 */
void _quick_sort(void** a, int startIndex, int endIndex, size_t size, compare_fun compare)
{
  if(startIndex <= endIndex)
  {
    int p = partition(a, startIndex, endIndex, size, compare);
    if(p > 1 && startIndex < p) //if there are at least 2 elements before pivot
      _quick_sort(a, startIndex, p, size, compare);
    if(p < endIndex - 2) //if there are at least 2 elements after pivot
      _quick_sort(a, p + 1, endIndex, size, compare);
  }
}

void quick_sort(void** a, int length, size_t size, compare_fun compare)
{
  if(a != NULL)
    _quick_sort(a, 0, length, size, compare);
}