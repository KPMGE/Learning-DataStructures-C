#include <stdio.h>
#include <stdlib.h>
#include "../include/doubly-linked-list.h"

// private structure for a node
typedef struct _node {
  int data;
  struct _node *previous;
  struct _node *next;
} _Node_t;

// public structure, for linked list
struct _linkedList{
  _Node_t *head;
  _Node_t *tail;
};

// private functions
void _checkAllocation(void *pointer) {
  if (pointer == NULL) {
    printf("\033[1;35m");
    printf("Allocation Failed!");
    printf("\033[0m");
    exit(1);
  }
}

void throwError(char *message) {
  printf("\033[1;35m");
  printf("%s", message);
  printf("\033[0m");
}

_Node_t *_createNode(int value) {
  _Node_t *allocatedNode = (_Node_t*) malloc(sizeof(_Node_t));

  _checkAllocation(allocatedNode);
  allocatedNode->data = value;

  return allocatedNode;
}

void _setValueToNode(_Node_t *node, int newValue) {
  node->data = newValue;
}

/*
_Node_t *searchForNode(LinkedList_t *list, int key) {
}
*/

// public functions
LinkedList_t *createEmptyList() {
  LinkedList_t *allocatedList = (LinkedList_t*) malloc(sizeof(LinkedList_t));

  _checkAllocation(allocatedList);

  allocatedList->head = NULL;
  allocatedList->tail = NULL;

  return allocatedList;
}

int getHeadValue(LinkedList_t *list) {
  return list->head->data;
}

int getTailValue(LinkedList_t *list) {
  return list->tail->data;
}

/*
int getValueAtPosition(LinkedList_t *list, int position) {

}
*/

/*
int* convertIntoArray(LinkedList_t *list) {

}
*/

void addAtHead(LinkedList_t *list, int newValue) {
  _Node_t *newNode = _createNode(newValue);
  newNode->previous = NULL;

  if (list->head == NULL) {
    list->head = newNode;
    list->tail = newNode;
    return;
  }

  newNode->next = list->head;
  list->head = newNode;
}

void addAtTail(LinkedList_t *list, int newValue) {
  _Node_t *newNode = _createNode(newValue);
  newNode->next = NULL;

  if (list->tail == NULL) {
    list->head = newNode;
    list->tail = newNode;
    return;
  }

  newNode->previous = list->tail;
  list->tail->next = newNode;
  list->tail = newNode;
}

void addAfter(LinkedList_t *list, int key, int newValue) {

}

void addBefore(LinkedList_t *list, int key, int newValue) {

}

void deleteHead(LinkedList_t *list) {

}

void deleteTail(LinkedList_t *list) {

}

void deleteSpecificNode(LinkedList_t *list, int key) {

}

void deleteAtPosition(LinkedList_t *list, int position) {

}

void displayLinkedList(LinkedList_t *list) {
  _Node_t *current = list->head;

  printf("\033[1;36m");
  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("\033[0m");

  printf("\033[1;35m");
  printf("NULL");
  printf("\033[0m");
}

void displayLinkedListReverse(LinkedList_t *list) {
  _Node_t *current = list->tail;

  printf("\033[1;36m");
  while (current->previous != NULL) {
    printf("%d -> ", current->data);
    current = current->previous;
  }
  printf("%d -> ", current->data);
  printf("\033[0m");

  printf("\033[1;35m");
  printf("NULL");
  printf("\033[0m");
}

void freeLinkedList(LinkedList_t *list) {
  _Node_t *current = list->head;

  while (current != NULL) {
    _Node_t *aux = current;
    current = current->next;
    free(aux);
  }
  free(list);
}

