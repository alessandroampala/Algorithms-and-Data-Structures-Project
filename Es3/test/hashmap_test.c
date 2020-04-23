#include <stdlib.h>
#include "unity.h"
#include "hashmap.h"

int hash(int* a)
{
  return *a;
}

int* new_int(int a)
{
  int* b = malloc(sizeof(int));
  *b = a;
  return b;
}

void empty_test()
{
  HashMap* map = HashMap_create(0, 0, sizeof(int), (hashing_fun) hash);
  TEST_ASSERT(HashMap_empty(map));
  TEST_ASSERT(HashMap_size(map) == 0);
  void* key = new_int(5);
  void* value = new_int(6);
  HashMap_insert(map, key, value);
  TEST_ASSERT(!HashMap_empty(map));
  HashMap_delete(map, key);
  TEST_ASSERT(HashMap_empty(map));

  HashMap_destroy(map);
  free(key);
  free(value);
}

void elements_number_test()
{
  HashMap* map = HashMap_create(0, 0, sizeof(int), (hashing_fun) hash);
  TEST_ASSERT_EQUAL_INT(0, HashMap_size(map));
  void* key = new_int(5);
  void* value = new_int(6);
  void* key2 = new_int(10);
  void* value2 = new_int(15);
  HashMap_insert(map, key, value);
  TEST_ASSERT_EQUAL_INT(1, HashMap_size(map));
  HashMap_insert(map, key2, value2);
  TEST_ASSERT_EQUAL_INT(2, HashMap_size(map));

  HashMap_destroy(map);
  free(key);
  free(value);
  free(key2);
  free(value2);
}

void key_exists_test()
{
  HashMap* map = HashMap_create(0, 0, sizeof(int), (hashing_fun) hash);
  void* key = new_int(5);
  void* value = new_int(6);
  void* key2 = new_int(10);
  void* value2 = new_int(15);
  HashMap_insert(map, key, value);
  TEST_ASSERT(HashMap_key_exists(map, key));
  HashMap_insert(map, key2, value2);
  TEST_ASSERT(HashMap_key_exists(map, key2));
  HashMap_delete(map, key);
  TEST_ASSERT(!HashMap_key_exists(map, key));
  HashMap_delete(map, key2);
  TEST_ASSERT(!HashMap_key_exists(map, key2));

  HashMap_destroy(map);
  free(key);
  free(value);
  free(key2);
  free(value2);
}

void delete_elements_test()
{
  HashMap* map = HashMap_create(0, 0, sizeof(int), (hashing_fun) hash);
  void* key = new_int(5);
  void* value = new_int(6);
  void* key2 = new_int(10);
  void* value2 = new_int(15);
  HashMap_insert(map, key, value);
  HashMap_insert(map, key2, value2);
  HashMap_delete_elements(map);
  TEST_ASSERT_EQUAL_INT(0, HashMap_size(map));

  HashMap_destroy(map);
  free(key);
  free(value);
  free(key2);
  free(value2);
}

void get_test()
{
  HashMap* map = HashMap_create(0, 0, sizeof(int), (hashing_fun) hash);
  void* key = new_int(5);
  void* value = new_int(6);
  void* key2 = new_int(10);
  void* value2 = new_int(15);
  HashMap_insert(map, key, value);
  HashMap_insert(map, key2, value2);

  TEST_ASSERT_EQUAL_INT(6, *(int*) HashMap_get(map, key));
  TEST_ASSERT_EQUAL_INT(15, *(int*) HashMap_get(map, key2));

  HashMap_destroy(map);
  free(key);
  free(value);
  free(key2);
  free(value2);
}

void key_set_test()
{
  HashMap* map = HashMap_create(0, 0, sizeof(int), (hashing_fun) hash);
  void* key = new_int(5);
  void* value = new_int(6);
  void* key2 = new_int(10);
  void* value2 = new_int(15);
  HashMap_insert(map, key, value);
  HashMap_insert(map, key2, value2);

  void** keys = HashMap_key_set(map);
  TEST_ASSERT(keys[0] == key);
  TEST_ASSERT(keys[1] == key2);

  free(keys);
  HashMap_destroy(map);
  free(key);
  free(value);
  free(key2);
  free(value2);
}

void insert_delete_test()
{
  HashMap* map = HashMap_create(0, 0, sizeof(int), (hashing_fun) hash);
  void* key = new_int(5);
  void* value = new_int(6);
  void* key2 = new_int(10);
  void* value2 = new_int(15);

  HashMap_insert(map, key, value);
  TEST_ASSERT_EQUAL_INT(1, HashMap_size(map));
  TEST_ASSERT_EQUAL_INT(6, *(int*) HashMap_get(map, key));
  HashMap_insert(map, key2, value2);
  TEST_ASSERT_EQUAL_INT(2, HashMap_size(map));
  TEST_ASSERT_EQUAL_INT(15, *(int*) HashMap_get(map, key2));
  HashMap_delete(map, key);
  TEST_ASSERT_EQUAL_INT(1, HashMap_size(map));
  TEST_ASSERT(NULL == HashMap_get(map, key));
  HashMap_delete(map, key2);
  TEST_ASSERT_EQUAL_INT(0, HashMap_size(map));
  TEST_ASSERT(NULL == HashMap_get(map, key2));

  HashMap_destroy(map);
  free(key);
  free(value);
  free(key2);
  free(value2);
}

int main()
{
  UNITY_BEGIN();

  RUN_TEST(empty_test);
  RUN_TEST(elements_number_test);
  RUN_TEST(key_exists_test);
  RUN_TEST(delete_elements_test);
  RUN_TEST(get_test);
  RUN_TEST(key_set_test);
  RUN_TEST(insert_delete_test);

  UNITY_END();
}