#include <stdlib.h>
#include <stdio.h>
#include "unity.h"
#include "sorting.h"

int compare_int(int* obj1, int* obj2)
{
  return *obj1 - *obj2;
}

int getInt(void** obj, int pos)
{
  return *(int*)obj[pos];
}

void** create_obj_empty()
{
  void** obj = NULL;
  return obj; 
}

void** create_obj_length_one()
{
  int* element = malloc(sizeof(int));
  element[0] = 13;
  void** p = malloc(sizeof(void**));
  p[0] = &element[0];
  return p;
}

void** create_obj()
{
  int* a = malloc(sizeof(int) * 6);
  a[0] = 3;
  a[1] = 5;
  a[2] = 18;
  a[3] = 0;
  a[4] = 15;
  a[5] = 11;
  void ** p = malloc(sizeof(void*) *6);
  for(int i = 0; i < 6; i++)
  {
    p[i] = &a[i];
    //printf("%d\n", *((int*)p[i]));
  }
  return p;
}

void** create_obj_ordered_asc()
{
  int* a = malloc(sizeof(int) * 6);
  a[0] = 1;
  a[1] = 2;
  a[2] = 3;
  a[3] = 4;
  a[4] = 5;
  a[5] = 6;
  void ** p = malloc(sizeof(void*) *6);
  for(int i = 0; i < 6; i++)
  {
    p[i] = &a[i];
    //printf("%d\n", *((int*)p[i]));
  }
  return p;
}

void** create_obj_ordered_desc()
{
  int* a = malloc(sizeof(int) * 6);
  a[0] = 6;
  a[1] = 5;
  a[2] = 4;
  a[3] = 3;
  a[4] = 2;
  a[5] = 1;
  void ** p = malloc(sizeof(void*) *6);
  for(int i = 0; i < 6; i++)
  {
    p[i] = &a[i];
    //printf("%d\n", *((int*)p[i]));
  }
  return p;
}

void delete_test_obj(void** a)
{
  if(a!= NULL){
    free(*a);
  }
}

void insertion_sort_test()
{
  #define SORT(x) insertion_sort(x, 6, sizeof(int), (compare_fun) compare_int)
  void** a;
  
  // TEST NULL ARRAY
  a = create_obj_empty();
  SORT(a);
  TEST_ASSERT_NULL(a);
  delete_test_obj(a);
  /*
  // TEST ONE SIZED ARRAY
  a = create_obj_length_one();
  SORT(a);
  TEST_ASSERT_EQUAL_INT(13, getInt(a, 0));
  delete_test_obj(a);
  */
  // TEST ORDERED ASC
  a = create_obj_ordered_asc();
  SORT(a);
  TEST_ASSERT_EQUAL_INT(1, getInt(a, 0));
  TEST_ASSERT_EQUAL_INT(2, getInt(a, 1));
  TEST_ASSERT_EQUAL_INT(3, getInt(a, 2));
  TEST_ASSERT_EQUAL_INT(4, getInt(a, 3));
  TEST_ASSERT_EQUAL_INT(5, getInt(a, 4));
  TEST_ASSERT_EQUAL_INT(6, getInt(a, 5));
  delete_test_obj(a);

  // TEST ORDERED DESC
  a = create_obj_ordered_desc();
  SORT(a);
  TEST_ASSERT_EQUAL_INT(1, getInt(a, 0));
  TEST_ASSERT_EQUAL_INT(2, getInt(a, 1));
  TEST_ASSERT_EQUAL_INT(3, getInt(a, 2));
  TEST_ASSERT_EQUAL_INT(4, getInt(a, 3));
  TEST_ASSERT_EQUAL_INT(5, getInt(a, 4));
  TEST_ASSERT_EQUAL_INT(6, getInt(a, 5));
  delete_test_obj(a);

  // TEST NORMAL CASE
  a = create_obj();
  SORT(a);
  TEST_ASSERT_EQUAL_INT(0, getInt(a, 0));
  TEST_ASSERT_EQUAL_INT(3, getInt(a, 1));
  TEST_ASSERT_EQUAL_INT(5, getInt(a, 2));
  TEST_ASSERT_EQUAL_INT(11, getInt(a, 3));
  TEST_ASSERT_EQUAL_INT(15, getInt(a, 4));
  TEST_ASSERT_EQUAL_INT(18, getInt(a, 5));
  delete_test_obj(a);

  #undef SORT
}

void quick_sort_test()
{
  void** a;
  #define SORT(x) quick_sort(x, 6, sizeof(int), (compare_fun) compare_int)

  //TEST NULL ARRAY
  a = create_obj_empty();
  SORT(a);
  TEST_ASSERT_NULL(a);
  delete_test_obj(a);
  /*
  // TEST ONE SIZED ARRAY
  a = create_obj_length_one();
  SORT(a);
  TEST_ASSERT_EQUAL_INT(13, getInt(a, 0));
  delete_test_obj(a);
  */
  // TEST ORDERED ASC
  a = create_obj_ordered_asc();
  SORT(a);
  TEST_ASSERT_EQUAL_INT(1, getInt(a, 0));
  TEST_ASSERT_EQUAL_INT(2, getInt(a, 1));
  TEST_ASSERT_EQUAL_INT(3, getInt(a, 2));
  TEST_ASSERT_EQUAL_INT(4, getInt(a, 3));
  TEST_ASSERT_EQUAL_INT(5, getInt(a, 4));
  TEST_ASSERT_EQUAL_INT(6, getInt(a, 5));
  delete_test_obj(a);

  // TEST ORDERED DESC
  a = create_obj_ordered_desc();
  SORT(a);
  TEST_ASSERT_EQUAL_INT(1, getInt(a, 0));
  TEST_ASSERT_EQUAL_INT(2, getInt(a, 1));
  TEST_ASSERT_EQUAL_INT(3, getInt(a, 2));
  TEST_ASSERT_EQUAL_INT(4, getInt(a, 3));
  TEST_ASSERT_EQUAL_INT(5, getInt(a, 4));
  TEST_ASSERT_EQUAL_INT(6, getInt(a, 5));
  delete_test_obj(a);

  // TEST NORMAL CASE
  a = create_obj();
  SORT(a);
  TEST_ASSERT_EQUAL_INT(0, getInt(a, 0));
  TEST_ASSERT_EQUAL_INT(3, getInt(a, 1));
  TEST_ASSERT_EQUAL_INT(5, getInt(a, 2));
  TEST_ASSERT_EQUAL_INT(11, getInt(a, 3));
  TEST_ASSERT_EQUAL_INT(15, getInt(a, 4));
  TEST_ASSERT_EQUAL_INT(18, getInt(a, 5));
  delete_test_obj(a);
  
  #undef SORT
}

int main()
{
  UNITY_BEGIN();
  /*
  void** a = create_obj();
  printf("trova il problema %d\n", getInt(a,0));
  delete_test_obj(a);
  a = create_obj_ordered_asc();
  printf("trova il problema %d\n", getInt(a,0));
  delete_test_obj(a);
  a = create_obj_length_one();
  printf("trova il problema %d\n", getInt(a,0));
  delete_test_obj(a);
  */

  RUN_TEST(insertion_sort_test);
  RUN_TEST(quick_sort_test);

  UNITY_END();
  return 0;
}
