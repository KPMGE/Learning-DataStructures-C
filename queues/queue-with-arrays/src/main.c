#include <stdio.h>
#include "../include/queue-arrays.h"

int main(void) {
  Queue_t *myQueue = createQueue(10);

  enQueue(myQueue, 1);
  enQueue(myQueue, 2);
  enQueue(myQueue, 3);
  enQueue(myQueue, 4);

  printf("\nOriginal queue: ");
  displayQueue(myQueue);

  printf("\nafter add 5...");
  enQueue(myQueue, 5);
  displayQueue(myQueue);

  printf("\nafter deQueue ...");
  deQueue(myQueue);
  displayQueue(myQueue);

  printf("\nafter deQueue again...");
  deQueue(myQueue);
  displayQueue(myQueue);

  freeQueue(myQueue);

  return 0;
}
