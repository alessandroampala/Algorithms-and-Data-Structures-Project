#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hashmap.h"
#include "sorting.h"

#define SIZE 6321078

typedef struct Record{
  int key;
  int value;
} Record;

int hash(int* a)
{
  return *a;
}

int compare_ints(const void* a, const void* b)
{
  return *(int*) a - *(int*) b;
}

HashMap* load_data_HashMap(char const* filename, Record** elements)
{
  int key, value;
  int lineno = 0;
  HashMap* map;

  FILE* file = fopen(filename, "r");
  if(file == NULL)
  {
    fprintf(stderr, "Error while opening file, terminating\n");
    exit(EXIT_FAILURE);
  }

  map = HashMap_create(0, 0, (hashing_fun) hash, (compare_fun) compare_ints);
  *elements = malloc(sizeof(Record) * SIZE);

  while(!feof(file))
  {
    int n = fscanf(file, "%d,%d\n", &key, &value);
    lineno++;

    if(n != 2)
    {
      if(feof(file))
        continue;
      printf("Error while reading file at line: %d\n", lineno);
      exit(EXIT_FAILURE);
    }

    (*elements)[lineno - 1].key = key;
    (*elements)[lineno - 1].value = value;
    HashMap_insert(map, &((*elements)[lineno - 1].key), &((*elements)[lineno - 1].value));
  }

  fclose(file);
  return map;
}

Record* load_data_array(char const* filename, Record elements[])
{
  int key, value;
  int lineno = 0;

  FILE* file = fopen(filename, "r");
  if(file == NULL)
  {
    fprintf(stderr, "Error while opening file, terminating\n");
    exit(EXIT_FAILURE);
  }

  while(!feof(file))
  {
    int n = fscanf(file, "%d,%d\n", &key, &value);
    lineno++;

    if(n != 2)
    {
      if(feof(file))
        continue;
      printf("Error while reading file at line: %d\n", lineno);
      exit(EXIT_FAILURE);
    }

    elements[lineno - 1].key = key;
    elements[lineno - 1].value = value;
  }

  fclose(file);
  return elements;
}

struct timespec diff(struct timespec start, struct timespec end)
{
  struct timespec temp;
  if ((end.tv_nsec-start.tv_nsec)<0) {
    temp.tv_sec = end.tv_sec-start.tv_sec-1;
    temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
  } else {
    temp.tv_sec = end.tv_sec-start.tv_sec;
    temp.tv_nsec = end.tv_nsec-start.tv_nsec;
  }
  return temp;
}

Record array[SIZE];
int keys[10000000];

int main(int argc, char const *argv[])
{
  HashMap* map;
  Record* map_elements = NULL;
  struct timespec start, end;

  if(argc != 2)
  {
    printf("Argument error\n");
    exit(EXIT_FAILURE);
  }
  
  //LOAD HASHMAP
  clock_gettime(CLOCK_MONOTONIC_RAW, &start);
  map = load_data_HashMap(argv[1], &map_elements);
  clock_gettime(CLOCK_MONOTONIC_RAW, &end);
  start = diff(start, end);
  printf("HashMap loaded in %ld.%ld seconds\n", start.tv_sec, start.tv_nsec / 10000000);

  //LOAD SORTED ARRAY
  clock_gettime(CLOCK_MONOTONIC_RAW, &start);
  load_data_array(argv[1], array);
  void** ap = malloc(sizeof(void*) * SIZE);
  for(int i = 0; i < SIZE; i++)
  {
    ap[i] = &(array[i]);
  }
  quick_sort(ap, SIZE, sizeof(Record), (compare_fun) compare_ints);
  clock_gettime(CLOCK_MONOTONIC_RAW, &end);
  start = diff(start, end);
  printf("array loaded and sorted in %ld.%ld seconds\n", start.tv_sec, start.tv_nsec / 10000000);
  free(ap);

  //PICK RANDOM KEYS
  srand(time(0));
  for (int i = 0; i < 10000000; ++i)
    keys[i] = rand() % 10000000;

  //RETRIEVE KEYS FROM HASHMAP
  int retrieved_keys_hashmap = 0;
  clock_gettime(CLOCK_MONOTONIC_RAW, &start);
  for (int i = 0; i < 10000000; ++i)
  {
    if(HashMap_get(map, &(keys[i])) != NULL)
      retrieved_keys_hashmap++;
  }
  clock_gettime(CLOCK_MONOTONIC_RAW, &end);
  start = diff(start, end);
  printf("%d keys retrieved from HashMap in %ld.%ld seconds\n", retrieved_keys_hashmap, start.tv_sec, start.tv_nsec / 10000000);

  //RETRIEVE KEYS FROM SORTED ARRAY
  int retrieved_keys_array = 0;
  clock_gettime(CLOCK_MONOTONIC_RAW, &start);
  for (int i = 0; i < 10000000; ++i)
  {
    if(bsearch(&keys[i], array, SIZE, sizeof(Record), compare_ints) != NULL)
      retrieved_keys_array++;
  }
  clock_gettime(CLOCK_MONOTONIC_RAW, &end);
  start = diff(start, end);
  printf("%d keys retrieved from array in %ld.%ld seconds\n", retrieved_keys_array, start.tv_sec, start.tv_nsec / 10000000);

  if(retrieved_keys_hashmap == retrieved_keys_array)
    printf("Number of retrieved keys is the same!\n");
  else
    printf("ERROR: Number of retrieved keys is NOT the same\n");

  free(map_elements);
  HashMap_destroy(map);
}