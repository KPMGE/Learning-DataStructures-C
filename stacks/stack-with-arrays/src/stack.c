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
    printf("\033[1;35m");
    printf("Insuficient memory!");
    printf("\033[0m");
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
    printf("\033[1;35m");
    printf("The stack is full!");
    printf("\033[0m");
    return;
  }

  stack->top++;
  stack->array[stack->top] = newItem;
}

void pop(Stack_t *stack) {
  if (isEmpty(stack)) {
    printf("\033[1;35m");
    printf("The stack is already empty!");
    printf("\033[0m");
    return;
  }

  stack->top--;
}

int peek(Stack_t *stack) {
  if (isEmpty(stack)) {
    printf("\033[1;35m");
    printf("There are no elements in the current stack, How about add one?");
    printf("\033[0m");
    return -1;
  }

  return stack->array[stack->top];
}

void displayStack(Stack_t *stack) {
  int size = stack->top+1;

  printf("\033[1;36m");
  for (int i = 0; i < size; i++) {
    printf("[ %d ]\n", stack->array[i]);
  }
  printf("\033[0m");
}

void freeStack(Stack_t *stack) {
  free(stack->array);
  free(stack);
}

