#include <stdlib.h>
#include <stdio.h>


typedef struct Node
{
  void* elem;
  struct Node* next;
} Node;

typedef struct Stack
{
  Node* head;
} Stack;

Stack* Stack_create()
{
  Stack* s = malloc(sizeof(Stack));
  s->head = NULL;
  return s;
}

void Stack_push(Stack* s, void* elem)
{
  Node* node = malloc(sizeof(Node));
  node->next = s->head;
  node->elem = elem;
  s->head = node;
}

void* Stack_pop(Stack* s)
{
  Node* node;
  if(s->head == NULL) return NULL;
  node = s->head;
  s->head = s->head->next;
  void* e = node->elem;
  free(node);
  return e;
}

char Stack_empty(Stack* s)
{
  return s->head == NULL;
}

/*int main(int argc, char const *argv[])
{
  int* int1 = malloc(sizeof(int));
  *int1 = 1;
  int* int2 = malloc(sizeof(int));
  *int2 = 2;
  int* int3 = malloc(sizeof(int));
  *int3 = 3;

  Stack* s = Stack_create();
  Stack_push(s, int1);
  Stack_push(s, int2);
  Stack_push(s, int3);

  printf("%d\n", *(int*) Stack_pop(s));
  printf("%d\n", *(int*) Stack_pop(s));
  printf("%d\n", *(int*) Stack_pop(s));

  free(int1);
  free(int2);
  free(int3);
  free(s);
  return 0;
}*/