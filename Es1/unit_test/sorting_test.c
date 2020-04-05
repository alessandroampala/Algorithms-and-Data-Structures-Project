#include <stdlib.h>
#include "unity.h"
#include "array.h"
#include "sorting.h"

static int compare_int(int* obj1, int* obj2)
{
  if(*obj1 > *obj2)
		return 1;
	else if(*obj1 == *obj2)
		return 0;
	else
		return -1;
}

static Array* create_test_obj_empty()
{
	int* a = NULL;
	return Array_new(a, 0, sizeof(int));
}

static Array* create_test_obj_lengthOne()
{
	int a[] = {13};
	return Array_new(a, 1, sizeof(int));
}

static Array* create_test_obj()
{
	int a[] = {11, 2, 5, 3, 0};
	return Array_new(a, 5, sizeof(int));
}

static void delete_test_obj(Array* a);

static void swapping_test();

static void insertion_sort_test();

static void quick_sort_test();

int main()
{
    UNITY_BEGIN();

    UNITY_END();
	return 0;
}
