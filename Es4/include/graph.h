#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef struct Edge
{
  int node;
  int weight;
  struct Edge* next;
} Edge;

typedef struct Node
{
  Edge* adj; //list terminated by null
  Edge* last;
  int pos;
  char is_visited;
  int level;
  int parent_weight;
  int parent_pos;
} Node;

typedef struct Graph
{
  Node* nodes;
  int size;
} Graph;

Graph* create_graph(int size);
Node* get(Graph* g, int pos);
void add_edge(Graph* g, int pos_node1, int pos_node2, int weight);
Graph* create_load_graph();
void dfs(Graph* g);
void print_graph(Graph* g);