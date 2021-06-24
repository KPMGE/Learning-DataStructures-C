#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/doubly-circular-linked-list.h"

// private structure _Node_t
typedef struct _node {
  int data;
  struct _node *next;
  struct _node *previous;
} _Node_t;

// public structure DoublyLinkedList_t
struct _doublyLinkedList {
  _Node_t *head;
};

// private functions
void _checkAllocation(void *pointer) {
  if (pointer == NULL) {
    printf("\033[1;35m");
    printf("Allocation failed!");
    printf("\033[0m");

    exit(1);
  }
}

_Node_t *_createNode(int value) {
  _Node_t *allocatedNode = (_Node_t *)malloc(sizeof(_Node_t));
  _checkAllocation(allocatedNode);

  allocatedNode->data = value;

  return allocatedNode;
}

bool _isEmpty(DoublyLinkedList_t *list) {
  return (list->head == NULL) ? true : false;
}

void _throwError(char *message) {
  printf("\033[1;35m");
  printf("%s", message);
  printf("\033[0m");
}

_Node_t *_getHeadNode(DoublyLinkedList_t *list) {
  return list->head;
}

_Node_t *_getTailNode(DoublyLinkedList_t *list) {
  return list->head->previous;
}

_Node_t *_searchNode(DoublyLinkedList_t *list, int key) {
  _Node_t *current = list->head;

  while (current != list->head->previous) {
    if (current->data == key) {
      return current;
    }

    current = current->next;
  }

  return NULL;
}


// public functions
DoublyLinkedList_t *createEmptyList() {
  DoublyLinkedList_t *allocatedList = (DoublyLinkedList_t *) malloc(sizeof(DoublyLinkedList_t));
  _checkAllocation(allocatedList);

  allocatedList->head = NULL;

  return allocatedList;
}

void addAtHead(DoublyLinkedList_t *list, int newValue) {
  if (_isEmpty(list)) {
    _Node_t *newNode = _createNode(newValue);
    newNode->next = newNode;
    newNode->previous = newNode;
    list->head = newNode;

    return;
  }

  _Node_t *newNode = _createNode(newValue);

  newNode->previous = _getTailNode(list);
  newNode->next = _getHeadNode(list);
  list->head->previous->next = newNode;
  list->head->previous = newNode;
  list->head = newNode;
}

void addAtTail(DoublyLinkedList_t *list, int newValue) {
 _Node_t *newNode = _createNode(newValue);

  if (_isEmpty(list)) {
    newNode->next = newNode;
    newNode->previous = newNode;
    list->head = newNode;

    return;
  }

  newNode->next = list->head;
  newNode->previous = list->head->previous;
  list->head->previous->next = newNode;
  list->head->previous = newNode;
}

void addAfter(DoublyLinkedList_t *list, int key, int newValue) {
  _Node_t *foundNode = _searchNode(list, key);

  if (foundNode == NULL) {
    printf("\033[1;35m");
    printf("There are no nodes for provided key");
    printf("\033[0m");

    return;
  }

  _Node_t *newNode = _createNode(newValue);
  newNode->next = foundNode->next;
  newNode->previous = foundNode;
  foundNode->next = newNode;
}

void deleteHead(DoublyLinkedList_t *list) {
  if (_isEmpty(list)) {
    _throwError("Your List is empty!");
    return;
  }

  _Node_t *aux = _getHeadNode(list);
  _Node_t *tail = _getTailNode(list);

  tail->next = list->head->next;
  list->head->next->previous = tail;
  list->head = list->head->next;

  free(aux);
}

void deleteTail(DoublyLinkedList_t *list) {
  if (_isEmpty(list)) {
    _throwError("Your list is empty!");
    return;
  }

  if (list->head == list->head->previous) {
    list->head = NULL;
    return;
  }
  
  _Node_t *tail = _getTailNode(list);
  _Node_t *aux = tail->previous;

  aux->next = list->head;
  list->head->previous = aux;

  free(tail);
}

void displayLinkedList(DoublyLinkedList_t *list) {
  _Node_t *current = _getHeadNode(list);

  printf("\033[1;36m");
  while (current != list->head->previous) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("%d -> ", current->data);

  printf("\033[1;35m");
  printf("HEAD");
  printf("\033[0m");
}

void displayLinkedListReverse(DoublyLinkedList_t *list) {
  _Node_t *current = _getTailNode(list);
  _Node_t *head = _getHeadNode(list);

  printf("\033[1;36m");
  while (current != head) {
    printf("%d -> ", current->data);
    current = current->previous;
  }
  printf("%d -> ", current->data);

  printf("\033[1;35m");
  printf("HEAD");
  printf("\033[0m");
}

void freeLinkedList(DoublyLinkedList_t *list) {
  _Node_t *current = list->head;

  while (current != list->head->previous) {
    _Node_t *aux = current;
    current = current->next;
    free(aux);
  }
  free(current);
  free(list);
}
