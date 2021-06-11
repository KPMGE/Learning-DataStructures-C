#include <stdio.h>
#include "../include/doubly-linked-list.h"

int main(void) {
  LinkedList_t *myList = createEmptyList();

  // add some data into list
  addAtHead(myList, 9);
  addAtTail(myList, 5);
  addAtTail(myList, 1);

  // display original list
  printf("\nOriginal list: ");
  displayLinkedList(myList);
  printf("\nOriginal list in reverse order: ");
  displayLinkedListReverse(myList);

  // free allocated list
  freeLinkedList(myList);

  return 0;
}
