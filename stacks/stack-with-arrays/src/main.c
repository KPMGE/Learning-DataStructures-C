// Simple Stack implementation in C with arrays
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include "../include/stack.h"

int main(void)  {
  Stack_t *myStack = createEmptyStack(10);

  // adding some data to stack
  push(myStack, 30);
  push(myStack, 43);
  push(myStack, 94);
  push(myStack, 53);

  // displaying stack
  printf("\nOriginal Stack:\n");
  displayStack(myStack);

  // adding arrayOfElements into myStack
  push(myStack, 5);
  printf("\nAfter adding value 5...");
  printf("\nStack:\n");
  displayStack(myStack);

  // displaying after popping 
  pop(myStack);
  printf("\nAfter popping...");
  printf("\nStack:\n");
  displayStack(myStack);

  // displaying after popping 
  pop(myStack);
  printf("\nAfter popping again...");
  printf("\nStack:\n");
  displayStack(myStack);

  // releasing stack
  freeStack(myStack);

  return 0;
}

