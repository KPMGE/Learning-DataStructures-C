#include <stdio.h>
#include "../include/circular-list.h"

int main(void) {
  CircularList_t *myList = createEmptyList();

  addAtHead(myList, 10);
  addAtHead(myList, 334);
  addAtHead(myList, 53);

  printf("\nOriginal linked list: ");
  displayList(myList);

  printf("\nAfter add 200 head: ");
  addAtHead(myList, 200);
  displayList(myList);

  printf("\nAfter add 90 at tail: ");
  addAtTail(myList, 90);
  displayList(myList);

  printf("\nAfter delete head: ");
  deleteHead(myList);
  displayList(myList);

  printf("\nAfter delete tail: ");
  deleteTail(myList);
  displayList(myList);

  freeList(myList);

  return 0;
}
