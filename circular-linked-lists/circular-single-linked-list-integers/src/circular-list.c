#include "../include/circular-list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// private struct for node
typedef struct _node {
  int data;
  struct _node *next;
} _Node_t;

// public struct, for a linked list
struct _circularList {
  _Node_t *tail;
};

// private functions
void _checkAllocation(void *pointer) {
  if (pointer == NULL) {
    printf("\033[1;35m");
    printf("Allocation failed");
    printf("\033[0m");

    exit(1);
  }
}

void _throwError(char *message) {
  printf("\033[1;35m");
  printf("%s\n", message); 
  printf("\033[0m");
}

_Node_t *_createNode(int value) {
  _Node_t *node = (_Node_t *)malloc(sizeof(_Node_t));

  _checkAllocation(node);
  node->data = value;

  return node;
}

bool _isEmpty(CircularList_t *list) {
  return (list->tail == NULL) ? true : false;
}

// public functions
CircularList_t *createEmptyList() {
  CircularList_t *allocatedList = (CircularList_t *)malloc(sizeof(CircularList_t));

  _checkAllocation(allocatedList);

  allocatedList->tail = NULL;

  return allocatedList;
}

void addAtHead(CircularList_t *list, int newValue) {
  _Node_t *newNode = _createNode(newValue);

  if (_isEmpty(list)) {
    newNode->next = newNode;
    list->tail = newNode;
    return;
  }

  newNode->next = list->tail->next;
  list->tail->next = newNode;
}

void addAtTail(CircularList_t *list, int newValue) {
  _Node_t *newNode = _createNode(newValue);

  newNode->next = list->tail->next;
  list->tail->next = newNode;
  list->tail = list->tail->next;
}


void deleteHead(CircularList_t *list) {
  if (_isEmpty(list)) {
    _throwError("The list is empty");
    return;
  }

  _Node_t *head = list->tail->next;
  list->tail->next = head->next;
  free(head);
}

void deleteTail(CircularList_t *list) {
  if (_isEmpty(list)) {
    _throwError("The list is empty");
    return;
  }

  // finding previous node
  _Node_t *current = list->tail->next;
  _Node_t *previous = list->tail;

  while (current != list->tail) {
    current = current->next;
    previous = previous->next;
  }

  previous->next = list->tail->next;
  free(list->tail);
  list->tail = previous;
}

void displayList(CircularList_t *list) {
  _Node_t *current = list->tail->next;

  if (_isEmpty(list)) {
    _throwError("The list is empty.");
    return;
  }

  printf("\033[1;36m");
  do {
    printf("%d -> ", current->data);
    current = current->next;
  } while (current != list->tail->next);
  printf("\033[0m");

  printf("\033[1;35m");
  printf("NULL");
  printf("\033[0m");
}

void freeList(CircularList_t *list) {
  _Node_t *current = list->tail->next;

  while (current != list->tail) {
    _Node_t *aux = current;
    current = current->next;
    free(aux);
 }

  free(list->tail);
  free(list);
}
