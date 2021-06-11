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

  printf("\nAdd 200 after 5: ");
  addAfter(myList, 5, 200);
  displayLinkedList(myList);

  printf("\nAdd 80 before 5: ");
  addBefore(myList, 5, 80);
  displayLinkedList(myList);

  // free allocated list
  freeLinkedList(myList);

  return 0;
}
