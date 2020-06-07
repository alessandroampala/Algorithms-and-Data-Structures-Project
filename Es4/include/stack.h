#pragma once

/* 
 * Stack is a LIFO structure which is
 * implemented using a reference to the
 * head of a node's list.
 * When an element is pushed in stack, it 
 * becomes is the new first element of this list.  
 */
typedef struct Stack Stack;

/*
 * Create a new empty stack
 */
Stack* Stack_create();

/*
 * Insert an element in stack s
 */
void Stack_push(Stack* s, void* elem);

/*
 * Return and delete the element in stack's top
 */
void* Stack_pop(Stack* s);

/*
 * Return 1 if stack s is empty, 0 otherwise
 */
char Stack_empty(Stack* s);