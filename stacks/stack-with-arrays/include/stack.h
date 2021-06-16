#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include <stddef.h>
#include <stdbool.h>

typedef struct _stack Stack_t;

Stack_t *createEmptyStack(size_t capacity);
int peek(Stack_t *stack);
void push(Stack_t* stack, int newItem);
void pop(Stack_t *stack);
void freeStack(Stack_t *stack);
void displayStack(Stack_t *stack);
bool isFull(Stack_t *stack);
bool isEmpty(Stack_t *stack);

#endif
