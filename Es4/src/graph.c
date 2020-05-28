#include "graph.h"

Graph* create_graph(int size)
{
  Graph* g = malloc(sizeof(Graph));
  g->size = size;
  g->nodes = malloc(g->size * sizeof(Node));

  for(int i = 0; i < g->size; i++)
  {
    g->nodes[i].is_visited = 0;
    g->nodes[i].adj = g->nodes[i].last = NULL;
  }

  return g;
}

Node* get(Graph* g, int pos)
{
  return &(g->nodes[pos]);
}

void add_edge(Graph* g, int pos_node1, int pos_node2, int weight)
{
  Node* node1 = get(g, pos_node1);
  Node* node2 = get(g, pos_node2);

  Edge* e1 = malloc(sizeof(Edge));
  e1->node = pos_node2;
  e1->weight = weight;
  e1->next = NULL;
  if(node1->adj == NULL)
  {
    node1->adj = node1->last = e1;
  }
  else
  {
    node1->last->next = e1;
    node1->last = e1;
  }

  Edge* e2 = malloc(sizeof(Edge));
  e2->node = pos_node1;
  e2->weight = weight;
  e2->next = NULL;
  if(node2->adj == NULL)
  {
    node2->adj = node2->last = e2;
  }
  else
  {
    node2->last->next = e2;
    node2->last = e2;
  }
}

Graph* create_load_graph()
{
  int node1, node2, weight;
  int element_number;
  scanf("%d", &element_number);

  Graph* g = create_graph(element_number);

  for(int i = 0; i < element_number; i++)
  {
    scanf("%d %d %d", &node1, &node2, &weight);
    add_edge(g, node1, node2, weight);
  }

  return g;
}