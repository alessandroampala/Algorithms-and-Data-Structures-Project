#include <stdlib.h>
#include "array.h"
#include "sorting.h"

int partition(Array* a, int startIndex, int endIndex, compare_fun compare)
{
  int i = startIndex + 1;
  int j = endIndex - 1;

  while(i <= j)
  {
    if(!(compare(Array_get(a, i), Array_get(a, startIndex)) > 0)) i++;
    else if(compare(Array_get(a, j), Array_get(a, startIndex)) > 0) j--;
    else
    {
      Array_swap(a, i, j);
      i++;
      j--;
    }
  }

  Array_swap(a, startIndex, j);
  return j;
}

Array* _quick_sort(Array* a, int startIndex, int endIndex, compare_fun compare)
{
  if(startIndex <= endIndex)
  {
    int p = partition(a, startIndex, endIndex, compare);
    if(p > 1 && startIndex < p) //if there are at least 2 elements before pivot
      _quick_sort(a, startIndex, p, compare);
    if(p < endIndex - 2) //if there are at least 2 elements after pivot
      _quick_sort(a, p + 1, endIndex, compare);
  }

  return a;
}

Array* quick_sort(Array* a, compare_fun compare)
{
  if(a == NULL) return NULL;
  return _quick_sort(a, 0, Array_length(a), compare);
}

Array* insertion_sort(Array* a, compare_fun compare)
{
  if(a != NULL)
  {
    int ln = Array_length(a);

    for(int i = 1; i < ln; i++)
    {
      int j = i;
      while(j >= 1 && compare(Array_get(a, j-1), Array_get(a, j)) > 0){
        Array_swap(a, j-1, j);
        j--;
      }
    }
  }
  return a;
}
