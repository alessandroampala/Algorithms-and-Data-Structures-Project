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
  int max_weight;
} Graph;

/**
 * Get node with identified by pos
 * @param  g   Pointer to the Graph
 * @param  pos Identifyer of the node
 * @return     Pointer to the node
 */
Node* get(Graph* g, int pos);

/**
 * Adds an edge from between nodes identified by pos_node1 and pos_node2
 * @param g         Pointer to the Graph
 * @param weight    Weight of the edge
 */
void add_edge(Graph* g, int pos_node1, int pos_node2, int weight);

/**
 * Creates Graph object, load it with input from stdin
 * @return Pointer to the Graph
 */
Graph* create_load_graph();

/**
 * Executes a DFS on Graph g filling its nodes' fields
 */
void dfs(Graph* g);