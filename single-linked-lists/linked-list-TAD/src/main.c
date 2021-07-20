// Simple implementation of a single linked list in C
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>
#include "../include/linked-list.h"

int main(void) {
  // create empty list
  LinkedList_t *myList = createEmptyList();

  // add some data into the list
  addAtTail(myList, 30);
  addAtTail(myList, 53);
  addAtTail(myList, 63);

  printf("Original linked list:  ");
  displayLinkedList(myList);

  // add at head another node
  printf("\nAfter add 42 at head: ");
  addAtHead(myList, 42);
  displayLinkedList(myList);

  // add at tail another node
  printf("\nAfter add 200 at tail: ");
  addAtTail(myList, 200);
  displayLinkedList(myList);

  // add 60 after 53
  printf("\nAfter add 60 in front of 53: ");
  addAfter(myList, 53, 60);
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
  printf("\nAfter delete node with value 60:  ");
  deleteSpecificNode(myList, 60);
  displayLinkedList(myList);

  // free linked list
  freeList(myList);

  return 0;
}
