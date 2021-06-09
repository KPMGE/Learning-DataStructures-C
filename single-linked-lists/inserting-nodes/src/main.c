// Simple program to show how to insert nodes in a single linked list with 3
// different methods Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>
#include "../include/inserting-nodes.h"

int main(void) {
  // create empty list
  LinkedList_t *myList = createEmptyList();

  // add some data into the list
  addAtTail(myList, 30);
  addAtTail(myList, 532);
  addAtTail(myList, 53);

  printf("Original linked list: ");
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

  // free linked list
  freeList(myList);

  return 0;
}
