#include <stdio.h>
#include <stdlib.h>
#include "../include/linked-list.h"

struct _linkedList {
  int num;
  struct _linkedList *next;
};

LinkedList_t *createEmptyList() {
  return NULL;
}

LinkedList_t *addAtHead(LinkedList_t *headRef, int newNum) {
  LinkedList_t *newNode = (LinkedList_t *) malloc(sizeof(LinkedList_t));
  newNode->num = newNum;
  newNode->next = headRef;

  return newNode;
}

LinkedList_t *removeList(LinkedList_t *headRef, int num) {
  if (headRef != NULL) {
    if (headRef->num == num) {
      LinkedList_t *aux = headRef;
      headRef = headRef->next;
      free(aux);
    } else {
      headRef->next = removeList(headRef->next, num);
    }
  }

  return headRef;
}

void displayLinkedList(LinkedList_t *headRef) {
  if (headRef == NULL) {
    return;
  }

  printf("%d\n", headRef->num);
  displayLinkedList(headRef->next);
}

void freeLinkedList(LinkedList_t *headRef) {
  if (headRef != NULL) {
    freeLinkedList(headRef->next);
    free(headRef);
  }
}
