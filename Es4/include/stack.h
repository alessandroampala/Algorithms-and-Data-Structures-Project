#pragma once

typedef struct Stack Stack;

Stack* Stack_create();

void Stack_push(Stack* s, void* elem);

void* Stack_pop(Stack* s);

char Stack_empty(Stack* s);