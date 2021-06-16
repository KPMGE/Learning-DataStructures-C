#include "../include/stack.h"
#include <stdio.h>
#include <stdlib.h>

struct _stack {
  size_t top;
  size_t capacity;
  int *array;
};

void _checkAllocation(void *pointer) {
  if (pointer == NULL) {
    printf("Insuficient memory!");
    exit(1);
  }
}

Stack_t *createEmptyStack(size_t capacity) {
  Stack_t *stack = (Stack_t *)malloc(sizeof(Stack_t));
  _checkAllocation(stack);

  stack->capacity = capacity;
  stack->top = -1;
  stack->array = (int *)malloc(capacity * sizeof(int));
  _checkAllocation(stack->array);

  return stack;
}

bool isFull(Stack_t *stack) {
  return stack->top == (stack->capacity - 1);
}

bool isEmpty(Stack_t *stack) {
  return stack->top == -1;
}

void push(Stack_t *stack, int newItem) {
  if (isFull(stack)) {
    printf("The stack is full!");
    return;
  }

  stack->top++;
  stack->array[stack->top] = newItem;
}

void pop(Stack_t *stack) {
  if (isEmpty(stack)) {
    printf("The stack is already empty!");
    return;
  }

  stack->top--;
}

int peek(Stack_t *stack) {
  if (isEmpty(stack)) {
    printf("There are no elements in the current stack, How about add one?");
    return -1;
  }

  return stack->array[stack->top];
}

void displayStack(Stack_t *stack) {
  int size = stack->top+1;

  for (int i = 0; i < size; i++) {
    printf("[ %d ]\n", stack->array[i]);
  }
}

void freeStack(Stack_t *stack) {
  free(stack->array);
  free(stack);
}

