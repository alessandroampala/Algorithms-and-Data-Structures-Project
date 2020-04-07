#include <stdlib.h>
#include <stdio.h>
#include "unity.h"
#include "array.h"
#include "sorting.h"

int compare_int(int* obj1, int* obj2)
{
  return *obj1 - *obj2;
}

Array* create_obj_empty()
{
  return Array_new(NULL, 0, sizeof(int));
}

Array* create_obj_lengthOne()
{
  int * a = malloc(sizeof(int));
  a[0] = 13;
  return Array_new(a, 1, sizeof(int));
}

Array* create_obj()
{
  int * array_test = malloc(sizeof(int) * 6);
  *(array_test) = 5;
  *(array_test + 1) = 11;
  *(array_test + 2) = 3;
  *(array_test + 3) = 18;
  *(array_test + 4) = 15;
  *(array_test + 5) = 0;  
  return Array_new(array_test, 6, sizeof(int)); 
}

void delete_test_obj(Array* a)
{
  Array_free(a);
}

void create_obj_test()
{
  Array* array_test = create_obj_empty();
  TEST_ASSERT_NULL((int*)Array_get(array_test, 0));
  
  delete_test_obj(array_test);

  array_test = create_obj();
  TEST_ASSERT_EQUAL_INT(5, *(int*)Array_get(array_test, 0));
  TEST_ASSERT_EQUAL_INT(11, *(int*)Array_get(array_test, 1));
  TEST_ASSERT_EQUAL_INT(3, *(int*)Array_get(array_test, 2));
  TEST_ASSERT_EQUAL_INT(18, *(int*)Array_get(array_test, 3));
  TEST_ASSERT_EQUAL_INT(15, *(int*)Array_get(array_test, 4));
  TEST_ASSERT_EQUAL_INT(0, *(int*)Array_get(array_test, 5));
  
  delete_test_obj(array_test);

  array_test = create_obj_lengthOne();
  TEST_ASSERT_EQUAL_INT(13, *(int*)Array_get(array_test, 0));
  delete_test_obj(array_test);
  
}

void swapping_test()
{
  Array* array_test = create_obj();
  
  Array_swap(array_test, 2, 4);

  TEST_ASSERT_EQUAL_INT(5, *(int*)Array_get(array_test, 0));
  TEST_ASSERT_EQUAL_INT(11, *(int*)Array_get(array_test, 1));
  TEST_ASSERT_EQUAL_INT(15, *(int*)Array_get(array_test, 2));
  TEST_ASSERT_EQUAL_INT(18, *(int*)Array_get(array_test, 3));
  TEST_ASSERT_EQUAL_INT(3, *(int*)Array_get(array_test, 4));
  TEST_ASSERT_EQUAL_INT(0, *(int*)Array_get(array_test, 5));
  
  delete_test_obj(array_test);  
  
}

void insertion_sort_test()
{
  Array* array_test = create_obj();
  
  insertion_sort(array_test, (compare_fun) compare_int);

  TEST_ASSERT_EQUAL_INT(0, *(int*)Array_get(array_test, 0));
  TEST_ASSERT_EQUAL_INT(3, *(int*)Array_get(array_test, 1));
  TEST_ASSERT_EQUAL_INT(5, *(int*)Array_get(array_test, 2));
  TEST_ASSERT_EQUAL_INT(11, *(int*)Array_get(array_test, 3));
  TEST_ASSERT_EQUAL_INT(15, *(int*)Array_get(array_test, 4));
  TEST_ASSERT_EQUAL_INT(18, *(int*)Array_get(array_test, 5));
  
  delete_test_obj(array_test);  
}

void quick_sort_test()
{
  Array* array_test = create_obj();
  
  quick_sort(array_test, (compare_fun) compare_int);

  TEST_ASSERT_EQUAL_INT(0, *(int*)Array_get(array_test, 0));
  TEST_ASSERT_EQUAL_INT(3, *(int*)Array_get(array_test, 1));
  TEST_ASSERT_EQUAL_INT(5, *(int*)Array_get(array_test, 2));
  TEST_ASSERT_EQUAL_INT(11, *(int*)Array_get(array_test, 3));
  TEST_ASSERT_EQUAL_INT(15, *(int*)Array_get(array_test, 4));
  TEST_ASSERT_EQUAL_INT(18, *(int*)Array_get(array_test, 5));
  
  delete_test_obj(array_test);  
}

int main()
{
  UNITY_BEGIN();

  RUN_TEST(create_obj_test);
  RUN_TEST(swapping_test);
  RUN_TEST(insertion_sort_test);
  RUN_TEST(quick_sort_test);

  UNITY_END();
  return 0;
}
