#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sorting.h"

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

int partition(void** a, int startIndex, int endIndex, size_t size, compare_fun compare)
{
  int i = startIndex + 1;
  int j = endIndex - 1;

  while(i <= j)
  {
    if(!(compare(a[i], a[startIndex]) > 0)) i++;
    else if(compare(a[j], a[startIndex]) > 0) j--;
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

// int compare_int(int* a, int* b)
// {
//   return *a-*b;
// }

// int main(int argc, char const *argv[])
// {
//   int* a = malloc(sizeof(int) * 4);
//   a[0] = 5;
//   a[1] = 4;
//   a[2] = 6;
//   a[3] = 1;

//   void** ap = malloc(sizeof(void*) * 4);

//   for(int i = 0; i < 4; i++)
//   {
//     ap[i] = &a[i];
//     printf("%d\n", a[i]);
//   }


//   quick_sort(ap, 4, sizeof(int), (compare_fun) compare_int);

//   for(int i = 0; i < 4; i++)
//   {
//     printf("%d\n", a[i]);
//   }
//   return 0;
// }