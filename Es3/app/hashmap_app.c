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

int compare_ints(int* a, int* b)
{
  return *a - *b;
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



void update_time(time_t* rawtime, struct tm ** timeinfo)
{
  time(rawtime);
  *timeinfo = localtime(rawtime);
}

Record array[SIZE];
int keys[10000000];

int main(int argc, char const *argv[])
{
  HashMap* map;
  Record* map_elements = NULL;
  time_t rawtime_before, rawtime_after;

  if(argc != 2)
  {
    printf("Argument error\n");
    exit(EXIT_FAILURE);
  }
  
  //LOAD HASHMAP
  time(&rawtime_before);
  map = load_data_HashMap(argv[1], &map_elements);
  time(&rawtime_after);
  printf("map loaded in %d seconds\n", (int) difftime(rawtime_after, rawtime_before));

  //LOAD SORTED ARRAY
  time(&rawtime_before);
  load_data_array(argv[1], array);
  void** ap = malloc(sizeof(void*) * SIZE);
  for(int i = 0; i < SIZE; i++)
  {
    ap[i] = &(array[i]);
  }
  quick_sort(ap, SIZE, sizeof(Record), (compare_fun) compare_ints);
  time(&rawtime_after);
  printf("array loaded and sorted in %d seconds\n", (int) difftime(rawtime_after, rawtime_before));

  srand(time(0));
  for (int i = 0; i < 10000000; ++i)
    keys[i] = rand() % 10000000;

  //PICK RANDOM KEYS FROM HASHMAP
  int picked_keys_hashmap = 0;
  time(&rawtime_before);
  for (int i = 0; i < 10000000; ++i)
  {
    if(HashMap_get(map, &(keys[i])) == NULL)
      picked_keys_hashmap++;
  }
  time(&rawtime_after);
  printf("%d keys picked from HashMap in %d seconds\n", picked_keys_hashmap, (int) difftime(rawtime_after, rawtime_before));





  free(map_elements);
  HashMap_destroy(map);
}