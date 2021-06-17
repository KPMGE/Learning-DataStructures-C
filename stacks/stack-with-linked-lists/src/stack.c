#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/stack.h"

typedef struct _stackNode {
  int data;
  struct _stackNode *next;
} _StackNode_t;

struct _linkedStack {
  _StackNode_t *head;
};

// private functions
void _checkAllocation(void *pointer) {
  if (pointer == NULL) {
    printf("\033[1;35m");
    printf("Allocation failed!");
    printf("\033[0m");
    exit(1);
  }
}

_StackNode_t *createNode(int newData) {
  _StackNode_t *allocatedNode = (_StackNode_t*)malloc(sizeof(_StackNode_t));

  _checkAllocation(allocatedNode);

  allocatedNode->data = newData;
  return allocatedNode;
}

LinkedStack_t *createEmptyStack() {
  LinkedStack_t *allocatedStack = (LinkedStack_t*)malloc(sizeof(LinkedStack_t));

  _checkAllocation(allocatedStack);

  allocatedStack->head = NULL;
  return allocatedStack;
}

bool isEmpty(LinkedStack_t *stack) {
  return (stack->head == NULL) ? true : false;
}

void push(LinkedStack_t *stack, int newValue) {
  _StackNode_t *newNode = createNode(newValue);

  if (isEmpty(stack)) {
    newNode->next = NULL;
    stack->head = newNode;
    return;
  }

  newNode->next = stack->head;
  stack->head = newNode;
}

void pop(LinkedStack_t *stack) {
  if (isEmpty(stack)) {
    printf("\033[1;35m");
    printf("Your stack is empty!");
    printf("\033[0m");
    return;
  }

  _StackNode_t *aux = stack->head;
  stack->head = stack->head->next;
  free(aux);
}

void displayStack(LinkedStack_t *stack) {
  _StackNode_t *current = stack->head;

  printf("\033[1;36m");
  while (current != NULL) {
    printf("[ %d ]\n", current->data);
    current = current->next;
  }
  printf("\033[0m");
}

void freeStack(LinkedStack_t *stack) {
  _StackNode_t *current = stack->head;

  while (current != NULL) {
    _StackNode_t *aux = current;
    current = current->next;
    free(aux);
  }
  free(stack);
}
