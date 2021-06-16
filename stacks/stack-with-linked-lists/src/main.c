#include <stdio.h>
#include <stdlib.h>
#include "../include/stack.h"

int main(void) {
  LinkedStack_t *myStack = createEmptyStack();

  // adding some data into stack
  push(myStack, 10);
  push(myStack, 53);
  push(myStack, 84);
  push(myStack, 64);

  // displaying it
  printf("\nOrignal stack:\n");
  displayStack(myStack);

  // adding node
  printf("\nAfter adding number 5...\n");
  push(myStack, 5);
  displayStack(myStack);

  // removing node 
  printf("\nAfter popping:\n");
  pop(myStack);
  displayStack(myStack);

  // removing node 
  printf("\nAfter popping again:\n");
  pop(myStack);
  displayStack(myStack);

  // releasing allocated memory
  freeStack(myStack);

  return 0;
}
