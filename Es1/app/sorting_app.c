#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "array.h"
#include "sorting.h"

typedef struct Record{
  int id;
  char* field1;
  int field2;
  float field3;
} Record;

typedef struct RecordArray{
  Record* array;
  int length;
} RecordArray;

RecordArray load_data(char const* filename)
{
  FILE* file = fopen(filename, "r");

  #define MAX_BUF_LEN 1024
  int id;
  char field1[MAX_BUF_LEN];
  int field2;
  float field3;

  int size = 100;
  Record* records = malloc(sizeof(Record) * size);

  int lineno = 0;
  while(!feof(file))
  {

    int n = fscanf(file, "%d,%1024[^,],%d,%f\n", &id, field1, &field2, &field3);
    lineno++;

    if(n != 4)
    {
        if(feof(file))
            continue;
        printf("Error while reading file at line: %d\n", lineno);
        exit(EXIT_FAILURE);
    }

    if(lineno == size)
    {
      size *= 2;
      records = realloc(records, sizeof(Record) * size);
    }

    records[lineno - 1].id = id;
    records[lineno - 1].field1 = strndup(field1, MAX_BUF_LEN);
    records[lineno - 1].field2 = field2;
    records[lineno - 1].field3 = field3;
  }

  RecordArray ra;
  ra.array = records;
  ra.length = lineno;

  return ra;
}

int compare_field3(Record* obj1, Record* obj2)
{
  if(obj1->field3 > obj2->field3)
    return 1;
  else if(obj1->field3 == obj2->field3)
    return 0;
  else
    return -1;
}

int compare_field2(Record* obj1, Record* obj2)
{
  return obj1->field2 - obj2->field2;
}

int compare_field1(Record* obj1, Record* obj2)
{
  return strcmp(obj1->field1, obj2->field1);
}

void print_usage()
{
  fprintf(stderr, "Unrecognized option\n");
}

void wrong_options()
{
  print_usage();
  exit(EXIT_FAILURE);
}

void get_options(int argc, char* const *argv, char* algorithm, int* field)
{
  switch(*algorithm = getopt(argc, argv, "qi"))
  {
    case 'q':
    case 'i':
    printf("%c\n", *algorithm);
      break;
    case '?':
      fprintf(stderr, "Unrecognized option\n");
      wrong_options();
      break;
  }

  switch(*field = getopt(argc, argv, "123") - '0')
  {
    case 1:
    case 2:
    case 3:
    printf("%d\n", *field);
      break;
    case '?':
      fprintf(stderr, "Unrecognized option\n");
      wrong_options();
      break;
  }
}
}