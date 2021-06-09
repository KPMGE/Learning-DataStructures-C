// Simple program to show how to delete nodes in a single linked list
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>
#include "../include/deleting-nodes.h"

int main(void) {
  // create empty list
  LinkedList_t *myList = createEmptyList();

  // add some data into the list
  addAtTail(myList, 30);
  addAtTail(myList, 532);
  addAtTail(myList, 53);
  addAtTail(myList, 63);
  addAtTail(myList, 85);
  addAtTail(myList, 70);

  printf("Original linked list:  ");
  displayLinkedList(myList);

  // deleting head node of the list
  printf("\nAfter delete head:  ");
  deleteHeadNode(myList);
  displayLinkedList(myList);

  // deleting tail node of the list
  printf("\nAfter delete tail:  ");
  deleteTailNode(myList);
  displayLinkedList(myList);

  // deleting node at position 2
  printf("\nAfter delete node at position 2:  ");
  deleteAtPosition(myList, 2);
  displayLinkedList(myList);

  // delete node with value 53
  printf("\nAfter delete node with value 63:  ");
  deleteSpecificNode(myList, 63);
  displayLinkedList(myList);

  // free linked list
  freeList(myList);

  return 0;
}
