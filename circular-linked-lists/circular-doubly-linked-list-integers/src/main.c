#include <stdio.h>
#include "../include/doubly-circular-linked-list.h"

int main(void) {
  DoublyLinkedList_t *myList = createEmptyList();

  addAtHead(myList, 20);
  addAtHead(myList, 53);
  addAtHead(myList, 94);

  printf("\nOriginal List: ");
  displayLinkedList(myList);

  printf("\nIn reverse order: ");
  displayLinkedListReverse(myList);

  printf("\nAdd 200 at head: ");
  addAtHead(myList, 200);
  displayLinkedList(myList);

  printf("\nAdd 10 at tail: ");
  addAtTail(myList, 10);
  displayLinkedList(myList);

  printf("\nAdd 8 after 94: ");
  addAfter(myList, 94, 8);
  displayLinkedList(myList);

  printf("\nDelete head: ");
  deleteHead(myList);
  displayLinkedList(myList);

  printf("\nDelete tail: ");
  deleteTail(myList);
  displayLinkedList(myList);

  freeLinkedList(myList);

  return 0;
}

