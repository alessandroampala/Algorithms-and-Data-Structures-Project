#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

typedef struct Query
{
  int node1;
  int node2;
  int weight;
} Query;

Query* create_load_queries(int* element_number)
{
  scanf("%d", element_number);

  Query* queries = malloc(*element_number * sizeof(Query));

  for(int i = 0; i < *element_number; i++)
  {
    scanf("%d %d %d", &(queries[i].node1), &(queries[i].node2), &(queries[i].weight));
  }

  return queries;
}


int main(int argc, char const **argv)
{
  Graph* g = create_load_graph();
  int queries_number = 0;
  Query* queries = create_load_queries(&queries_number);

  
}