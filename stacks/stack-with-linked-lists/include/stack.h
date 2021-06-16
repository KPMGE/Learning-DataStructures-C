#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

typedef struct _linkedStack LinkedStack_t;

LinkedStack_t *createEmptyStack();
bool isEmpty(LinkedStack_t *stack);
void push(LinkedStack_t *stack, int newValue);
void pop(LinkedStack_t *stack);
void displayStack(LinkedStack_t *stack);
void freeStack(LinkedStack_t *stack);

#endif
