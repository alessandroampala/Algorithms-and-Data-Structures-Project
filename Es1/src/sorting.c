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
      void* tmp = Array_get(a, i);
      Array_set(a, i, Array_get(a, j));
      Array_set(a, j, tmp);
      i++;
      j--;
    }
  }

  void* tmp = Array_get(a, startIndex);
  Array_set(a, startIndex, Array_get(a, j));
  Array_set(a, j, tmp);
  return j;
}

Array* quick_sort(Array* a, int startIndex, int endIndex, compare_fun compare)
{
  if(startIndex <= endIndex)
  {
    int p = partition(a, startIndex, endIndex, compare);
    if(p > 1 && startIndex < p) //if there are at least 2 elements before pivot
      quick_sort(a, startIndex, p, compare);
    if(p < endIndex - 2) //if there are at least 2 elements after pivot
      quick_sort(a, p + 1, endIndex, compare);
  }

  return a;
}