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

void execute_query(Graph* g, Query* q)
{
  Node* node1 = get(g, q->node1);
  Node* node2 = get(g, q->node2);
  char cont = 0;

  while(node1 != node2)
  {
    while(node1->level > node2->level || cont)
    {
      if(node1->parent_weight > q->weight)
        printf("YES\n");
      node1 = get(g, node1->parent_pos);
      if(cont)
        cont = 0;
    }

    while(node2->level > node1->level)
    {
      if(node2->parent_weight > q->weight)
        printf("YES\n");
      node2 = get(g, node2->parent_pos);
    }

    if(node1->level == node2->level)
      cont = 1;
  }
}


int main(int argc, char const **argv)
{
  Graph* g = create_load_graph();
  int queries_number = 0;
  Query* queries = create_load_queries(&queries_number);

  printf("loaded\n");

  /*for (int i = 0; i < queries_number; ++i)
  {
    execute_query(g, &(queries[i]));
  }*/
}