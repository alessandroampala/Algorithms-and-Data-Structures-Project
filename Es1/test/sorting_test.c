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

Array* create_obj_length_one()
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

Array* create_obj_ordered_asc()
{
  int* array_test = malloc(sizeof(int)*6);
  *(array_test) = 1;
  *(array_test + 1) = 2;
  *(array_test + 2) = 3;
  *(array_test + 3) = 4;
  *(array_test + 4) = 5;
  *(array_test + 5) = 6;
  return Array_new(array_test, 6, sizeof(int));
}

Array* create_obj_ordered_desc()
{
  int* array_test = malloc(sizeof(int)*6);
  *(array_test) = 6;
  *(array_test + 1) = 5;
  *(array_test + 2) = 4;
  *(array_test + 3) = 3;
  *(array_test + 4) = 2;
  *(array_test + 5) = 1;
  return Array_new(array_test, 6, sizeof(int));
}

void delete_test_obj(Array* a)
{
  Array_free(a);
}

void insertion_sort_test()
{
  #define SORT insertion_sort(a, (compare_fun) compare_int)
  Array* a;

  // TEST NULL ARRAY
  a = create_obj_empty();
  SORT;
  TEST_ASSERT_NULL(a);
  delete_test_obj(a);

  // TEST ONE SIZED ARRAY
  a = create_obj_length_one();
  SORT;
  TEST_ASSERT_EQUAL_INT(13, *(int*) Array_get(a, 0));
  delete_test_obj(a);

  // TEST ORDERED ASC
  a = create_obj_ordered_asc();
  SORT;
  TEST_ASSERT_EQUAL_INT(1, *(int*)Array_get(a, 0));
  TEST_ASSERT_EQUAL_INT(2, *(int*)Array_get(a, 1));
  TEST_ASSERT_EQUAL_INT(3, *(int*)Array_get(a, 2));
  TEST_ASSERT_EQUAL_INT(4, *(int*)Array_get(a, 3));
  TEST_ASSERT_EQUAL_INT(5, *(int*)Array_get(a, 4));
  TEST_ASSERT_EQUAL_INT(6, *(int*)Array_get(a, 5));
  delete_test_obj(a);

  // TEST ORDERED DESC
  a = create_obj_ordered_desc();
  SORT;
  TEST_ASSERT_EQUAL_INT(1, *(int*)Array_get(a, 0));
  TEST_ASSERT_EQUAL_INT(2, *(int*)Array_get(a, 1));
  TEST_ASSERT_EQUAL_INT(3, *(int*)Array_get(a, 2));
  TEST_ASSERT_EQUAL_INT(4, *(int*)Array_get(a, 3));
  TEST_ASSERT_EQUAL_INT(5, *(int*)Array_get(a, 4));
  TEST_ASSERT_EQUAL_INT(6, *(int*)Array_get(a, 5));
  delete_test_obj(a);

  // TEST NORMAL CASE
  a = create_obj();
  SORT;
  TEST_ASSERT_EQUAL_INT(0, *(int*)Array_get(a, 0));
  TEST_ASSERT_EQUAL_INT(3, *(int*)Array_get(a, 1));
  TEST_ASSERT_EQUAL_INT(5, *(int*)Array_get(a, 2));
  TEST_ASSERT_EQUAL_INT(11, *(int*)Array_get(a, 3));
  TEST_ASSERT_EQUAL_INT(15, *(int*)Array_get(a, 4));
  TEST_ASSERT_EQUAL_INT(18, *(int*)Array_get(a, 5));
  delete_test_obj(a);

  #undef SORT
}

void quick_sort_test()
{
  Array* a;
  #define SORT quick_sort(a, (compare_fun) compare_int)

// TEST NULL ARRAY
  a = create_obj_empty();
  SORT;
  TEST_ASSERT_NULL(a);
  delete_test_obj(a);

  // TEST ONE SIZED ARRAY
  a = create_obj_length_one();
  SORT;
  TEST_ASSERT_EQUAL_INT(13, *(int*) Array_get(a, 0));
  delete_test_obj(a);

  // TEST ORDERED ASC
  a = create_obj_ordered_asc();
  SORT;
  TEST_ASSERT_EQUAL_INT(1, *(int*)Array_get(a, 0));
  TEST_ASSERT_EQUAL_INT(2, *(int*)Array_get(a, 1));
  TEST_ASSERT_EQUAL_INT(3, *(int*)Array_get(a, 2));
  TEST_ASSERT_EQUAL_INT(4, *(int*)Array_get(a, 3));
  TEST_ASSERT_EQUAL_INT(5, *(int*)Array_get(a, 4));
  TEST_ASSERT_EQUAL_INT(6, *(int*)Array_get(a, 5));
  delete_test_obj(a);

  // TEST ORDERED DESC
  a = create_obj_ordered_desc();
  SORT;
  TEST_ASSERT_EQUAL_INT(1, *(int*)Array_get(a, 0));
  TEST_ASSERT_EQUAL_INT(2, *(int*)Array_get(a, 1));
  TEST_ASSERT_EQUAL_INT(3, *(int*)Array_get(a, 2));
  TEST_ASSERT_EQUAL_INT(4, *(int*)Array_get(a, 3));
  TEST_ASSERT_EQUAL_INT(5, *(int*)Array_get(a, 4));
  TEST_ASSERT_EQUAL_INT(6, *(int*)Array_get(a, 5));
  delete_test_obj(a);

  // TEST NORMAL CASE
  a = create_obj();
  SORT;
  TEST_ASSERT_EQUAL_INT(0, *(int*)Array_get(a, 0));
  TEST_ASSERT_EQUAL_INT(3, *(int*)Array_get(a, 1));
  TEST_ASSERT_EQUAL_INT(5, *(int*)Array_get(a, 2));
  TEST_ASSERT_EQUAL_INT(11, *(int*)Array_get(a, 3));
  TEST_ASSERT_EQUAL_INT(15, *(int*)Array_get(a, 4));
  TEST_ASSERT_EQUAL_INT(18, *(int*)Array_get(a, 5));
  delete_test_obj(a);

  #undef SORT
}

int main()
{
  UNITY_BEGIN();

  RUN_TEST(insertion_sort_test);
  RUN_TEST(quick_sort_test);

  UNITY_END();
  return 0;
}
