#include <stdio.h>
#include <stdlib.h>
#include "../include/doubly-linked-list.h"

void displayArray(int *array, int size);

int main(void) {
  LinkedList_t *myList = createEmptyList();

  // add some data into list
  addAtHead(myList, 1);
  addAtTail(myList, 5);
  addAtTail(myList, 9);
  addAtTail(myList, 23);

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

  printf("\nValue at position 1: %d", getValueAtPosition(myList, 1));
  
  int *arr = convertIntoArray(myList);
  displayArray(arr, 5);

  printf("\nDelete head: ");
  deleteHead(myList);
  displayLinkedList(myList);

  printf("\nDelete tail: ");
  deleteTail(myList);
  displayLinkedList(myList);

  printf("\nDelete at position 0: ");
  deleteAtPosition(myList, 0);
  displayLinkedList(myList);

  printf("\nDelete node with value 5: ");
  deleteNodeWithKey(myList, 5);
  displayLinkedList(myList);

  // free allocated list
  freeLinkedList(myList);
  free(arr);

  return 0;
}

void displayArray(int *array, int size) {
  printf("\nArray: ");

  printf("\033[1;36m");
  printf("[");

  for (int i = 0; i < size; i++) {
    if (i == size - 1) {
      printf("%d", array[i]);
      continue;
    }
    printf("%d, ", array[i]);
  }

  printf("]");
  printf("\033[0m");
}
