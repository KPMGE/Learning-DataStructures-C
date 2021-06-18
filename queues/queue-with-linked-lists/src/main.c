#include <stdio.h>
#include "../include/queue-linked-list.h"

int main(void) {
  LinkedQueue_t *myQueue = createEmptyQueue();

  enQueue(myQueue, 1);
  enQueue(myQueue, 2);
  enQueue(myQueue, 3);
  enQueue(myQueue, 4);

  printf("\nOriginal queue: ");
  displayQueue(myQueue);

  printf("\n\nAfter add 5 to the queue: ");
  enQueue(myQueue, 5);
  displayQueue(myQueue);

  printf("\n\nAfter deQueue: ");
  deQueue(myQueue);
  displayQueue(myQueue);

  printf("\n\nAfter deQueue again: ");
  deQueue(myQueue);
  displayQueue(myQueue);

  freeQueue(myQueue);

  return 0;
}
