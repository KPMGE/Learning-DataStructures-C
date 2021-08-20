// simple implementation of a single linked lists with recursion

#include <stdio.h>
#include <stdlib.h>
#include "../include/linked-list.h"

int main(void) {
  LinkedList_t *list = createEmptyList();

  // add some data into list
  list = addAtHead(list, 10);
  list = addAtHead(list, 30);
  list = addAtHead(list, 43);
  list = addAtHead(list, 43);

  // displays the data
  printf("Original list: \n");
  displayLinkedList(list);

  list = removeList(list, 30);
  list = removeList(list, 43);
  printf("30 and 43 removed: \n");
  displayLinkedList(list);

  // free linked lists
  freeLinkedList(list);

  return 0;
}
