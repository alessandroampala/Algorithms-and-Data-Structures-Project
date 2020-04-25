#include <stdio.h>
#include <stdlib.h>
#include "hashmap.h"

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

HashMap* load_data(char const* filename, Record** elements)
{
  int key, value;
  int lineno = 0;
  int size = 7000000;
  HashMap* map;

  FILE* file = fopen(filename, "r");
  if(file == NULL)
  {
    fprintf(stderr, "Error while opening file, terminating\n");
    exit(EXIT_FAILURE);
  }

  map = HashMap_create(0, 0, (hashing_fun) hash, (compare_fun) compare_ints);
  *elements = malloc(sizeof(Record) * size);

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

    if(lineno == size)
    {
      size *= 2;
      *elements = realloc(*elements, sizeof(Record) * size);
    }

    (*elements)[lineno - 1].key = key;
    (*elements)[lineno - 1].value = value;
    HashMap_insert(map, &((*elements)[lineno - 1].key), &((*elements)[lineno - 1].value));
  }

  fclose(file);
  return map;
}

int main(int argc, char const *argv[])
{
  HashMap* map;
  Record* elements = NULL;

  if(argc != 2)
    printf("Argument error\n");
  map = load_data(argv[1], &elements);
  free(elements);
  HashMap_destroy(map);
}