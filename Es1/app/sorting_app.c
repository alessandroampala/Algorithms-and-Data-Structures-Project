#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "array.h"
#include "sorting.h"

typedef struct {
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

    int size = 5000000;
    Record* records = malloc(sizeof(Record) * size);

    int lineno = 0;
    while(!feof(file)) {

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
        	records = realloc(records, size);
        }

        records[lineno].id = id;
        records[lineno].field1 = strndup(field1, MAX_BUF_LEN);
        records[lineno].field2 = field2;
        records[lineno].field3 = field3;
    }

    RecordArray ra;
    ra.array = records;
    ra.length = lineno;

    return ra;
}

int main(int argc, char const *argv[])
{
	RecordArray ra = load_data(argv[1]);
}