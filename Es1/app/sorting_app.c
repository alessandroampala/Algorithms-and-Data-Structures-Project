#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
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

int compare_field1(Record* obj1, Record* obj2)
{
  return strcmp(obj1->field1, obj2->field1);
}

int compare_field2(Record* obj1, Record* obj2)
{
  return obj1->field2 - obj2->field2;
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

void print_usage()
{
    printf("\nUSAGE:\n");
    printf("sorting_app < -i | -q > < -1 | -2 | -3 > <filename>\n");
    printf("    -i: sort using Insertion sort algorithm\n");
    printf("    -q: sort using Quicksort algorithm\n");
    printf("    -1: sort according to the first field ascending order\n");
    printf("    -2: sort according to the second field ascending order\n");
    printf("    -3: sort according to the third field ascending order\n");
}

void wrong_options()
{
  fprintf(stderr, "Unrecognized option\n");
  print_usage();
  exit(EXIT_FAILURE);
}

void get_options(int argc, char* const *argv, char* algorithm, int* field)
{
  switch(*algorithm = getopt(argc, argv, "qi"))
  {
    case 'q':
    case 'i':
      break;
    case '?':
    case -1:
      wrong_options();
      break;
  }

  switch(*field = getopt(argc, argv, "123"))
  {
    case '1':
    case '2':
    case '3':
      *field -= '0';
      break;
    case '?':
    case -1:
      wrong_options();
      break;
  }
}

RecordArray load_data(char const* filename)
{
  FILE* file = fopen(filename, "r");
  if(file == NULL)
  {
    fprintf(stderr, "Error while opening file, terminating\n");
    print_usage();
    exit(EXIT_FAILURE);
  }

  #define MAX_BUF_LEN 1024
  int id;
  char field1[MAX_BUF_LEN];
  int field2;
  float field3;
  int size = 100;
  int lineno = 0;
  Record* records = malloc(sizeof(Record) * size);

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

  fclose(file);

  RecordArray ra;
  ra.array = records;
  ra.length = lineno;
  return ra;
}

void free_elements(RecordArray* a)
{
  for(int i = 0; i < a->length; i++)
  {
    free(a->array[i].field1);
    free(&(a->array[i]));
  }
}

void update_time(time_t* rawtime, struct tm ** timeinfo)
{
  time(rawtime);
  *timeinfo = localtime(rawtime);
}

int main(int argc, char* const *argv)
{
  char algorithm;
  int field;
  RecordArray ra;
  compare_fun compare[] = {(compare_fun) compare_field1, (compare_fun) compare_field2, (compare_fun) compare_field3};

  get_options(argc, argv, &algorithm, &field);
  
  if(optind < argc)
  {
    printf("Loading file...\n");
    ra = load_data(argv[optind]); //LOAD FILE
  }
  else
    wrong_options();

  Array* a = Array_new(ra.array, ra.length, sizeof(Record));

  time_t rawtime;
  struct tm * timeinfo;
  
  update_time(&rawtime, &timeinfo);
  switch(algorithm)
  {
    case 'q':
      printf("Starting Quicksort on field%d\t%s", field, asctime(timeinfo));
      quick_sort(a, compare[field - 1]);
      break;
    case 'i':
      printf("Starting Insertion sort on field%d\t%s", field, asctime(timeinfo));
      insertion_sort(a, compare[field - 1]);
      break;
  }

  update_time(&rawtime, &timeinfo);
  printf("Successfully terminated\t\t%s", asctime(timeinfo));

  free_elements(&ra);
  Array_free(a);
}