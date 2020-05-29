#include "graph.h"
#include "stack.h"

Graph* create_graph(int size)
{
  Graph* g = malloc(sizeof(Graph));
  g->size = size;
  g->nodes = malloc(g->size * sizeof(Node));

  for(int i = 0; i < g->size; i++)
  {
    g->nodes[i].pos = i;
    g->nodes[i].is_visited = 0;
    g->nodes[i].adj = g->nodes[i].last = NULL;
    g->nodes[i].level = -1;
    g->nodes[i].parent_weight = -1;
    g->nodes[i].parent_pos = -1;
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

  for(int i = 1; i < element_number; i++)
  {
    scanf("%d %d %d", &node1, &node2, &weight);
    add_edge(g, node1-1, node2-1, weight);
  }

  return g;
}

void dfs(Graph* g)
{
  Stack* stack = Stack_create();
  Node* start = get(g, 0);
  start->level = 0;
  start->is_visited = 1;
  Stack_push(stack, start);

  while(!Stack_empty(stack))
  {
    Node* current = Stack_pop(stack);
    Edge* adj = current->adj; 
    while(adj != NULL)
    {
      Node* visit = get(g, adj->node); 
      if(visit->is_visited == 0)
      {
        visit->is_visited = 1;
        visit->level = current->level +1;
        visit->parent_weight = adj->weight;
        visit->parent_pos = current->pos;
        Stack_push(stack, visit);
      }
      adj = adj->next;
    }
 }
  
  free(stack);
}

void print_graph(Graph* g)
{
  for (int i = 0; i < g->size; ++i)
  {
    printf("pos %d\n", i);
    Edge* adj = g->nodes[i].adj;
    while(adj != NULL)
    {
      printf("%d,%d\n", adj->node, adj->weight);
      adj = adj->next;
    }
  }
}