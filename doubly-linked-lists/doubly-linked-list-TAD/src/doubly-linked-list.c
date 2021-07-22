#include "../include/doubly-linked-list.h"
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

// private structure for a node
typedef struct _node {
  int data;
  struct _node *previous;
  struct _node *next;
} _Node_t;

// public structure, for linked list
struct _linkedList {
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

void _throwError(char *message) {
  printf("\033[1;35m");
  printf("%s\n", message);
  printf("\033[0m");
}

_Node_t *_createNode(int value) {
  _Node_t *allocatedNode = (_Node_t*) malloc(sizeof(_Node_t));
  _checkAllocation(allocatedNode);

  allocatedNode->data = value;
  allocatedNode->next = NULL;
  allocatedNode->previous = NULL;

  return allocatedNode;
}

_Node_t *_searchForNode(LinkedList_t *list, int key) {
  _Node_t *current = list->head;

  while (current != NULL) {
    if (current->data == key) {
      return current;
    }

    current = current->next;
  }

  return NULL;
}

_Node_t *_getNodeAtPosition(LinkedList_t *list, int position) {
  int i = 0;
  _Node_t *current = list->head;

  while (current != NULL) {
    if (i == position) {
      return current;
    }

    current = current->next;
    i++;
  }

  return NULL;
}

bool _isEmpty(LinkedList_t *list) {
  return (list->head == NULL) ? true : false;
}


// public functions
LinkedList_t *createEmptyList() {
  LinkedList_t *allocatedList = (LinkedList_t *) malloc(sizeof(LinkedList_t));

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

int getValueAtPosition(LinkedList_t *list, int position) {
  if (position == 0) {
    return getHeadValue(list);
  }

  int count = 0;
  _Node_t *current = list->head;

  while (current != NULL) {
    if (count == position) {
      return current->data;
    }

    count++;
    current = current->next;
  }

  _throwError("Invalid position.");
  return (int)NAN;
}

int* convertIntoArray(LinkedList_t *list) {
  if (_isEmpty(list)) {
    _throwError("The list is empty, couldn't create the array.");
    return NULL;
  }

  int *array = (int*) malloc(sizeof(int));
  _checkAllocation(array);

  int pos = 0;
  _Node_t *current = list->head;
  while (current != NULL) {
    array = realloc(array, (pos + 1) * sizeof(int));
    array[pos] = getValueAtPosition(list, pos);
    pos++;

    current = current->next;
  }

  return array;
}

void addAtHead(LinkedList_t *list, int newValue) {
  _Node_t *newNode = _createNode(newValue);

  if (_isEmpty(list)) {
    list->head = newNode;
    list->tail = newNode;
    return;
  }

  newNode->next = list->head;
  list->head->previous = newNode;
  list->head = newNode;
}

void addAtTail(LinkedList_t *list, int newValue) {
  _Node_t *newNode = _createNode(newValue);

  if (_isEmpty(list)) {
    list->head = newNode;
    list->tail = newNode;
    return;
  }

  newNode->previous = list->tail;
  list->tail->next = newNode;
  list->tail = newNode;
}

void addAfter(LinkedList_t *list, int key, int newValue) {
  _Node_t *foundNode = _searchForNode(list, key);

  if (foundNode == NULL) {
    _throwError("There are no matches for provided key. Couldn't add new value");
    return;
  }

  if (foundNode->previous == NULL) {
    addAtHead(list, newValue);
    return;
  }

  if (foundNode->next == NULL) {
    addAtTail(list, newValue);
    return;
  }

  _Node_t *newNode = _createNode(newValue);

  newNode->next = foundNode->next;
  newNode->previous = foundNode;
  foundNode->next->previous = newNode;
  foundNode->next = newNode;
}

void addBefore(LinkedList_t *list, int key, int newValue) {
  _Node_t *foundNode = _searchForNode(list, key);

  if (foundNode == NULL) {
    _throwError("There are no matches for provided key. Couldn't add new value");
    return;
  }

  if (foundNode->previous == NULL) {
    addAtHead(list, newValue);
    return;
  }

  if (foundNode->next == NULL) {
    addAtTail(list, newValue);
    return;
  }

  _Node_t *newNode = _createNode(newValue);
  foundNode->previous->next = newNode;
  newNode->previous = foundNode->previous;
  newNode->next = foundNode;
  foundNode->previous = newNode;
}

void deleteHead(LinkedList_t *list) {
  if (_isEmpty(list)) {
    _throwError("The list is empty.");
    return;
  }

  if (list->head->next == NULL)  {
    free(list->head);
    list->head = NULL;
    list->tail = NULL;
    return;
  }

  _Node_t *aux = list->head;
  list->head->next->previous = NULL;
  list->head = list->head->next;
  free(aux);
}

void deleteTail(LinkedList_t *list) {
  if (_isEmpty(list)) {
    _throwError("The list is empty.");
    return;
  }

  if (list->head->next == NULL) {
    free(list->head);
    list->head = NULL;
    list->tail = NULL;
    return;
  }

  _Node_t *aux = list->tail;
  list->tail->previous->next = NULL;
  list->tail = list->tail->previous;
  free(aux);
}

void deleteNodeWithKey(LinkedList_t *list, int key) {
  _Node_t *foundNode = _searchForNode(list, key);

  if (foundNode == NULL) {
    _throwError("There are no matches for provided key. Couldn't delete value");
    return;
  }

  if (foundNode->previous == NULL) {
    deleteHead(list);
    return;
  }

  if (foundNode->next == NULL) {
    deleteTail(list);
    return;
  }

  foundNode->previous->next = foundNode->next;
  foundNode->next->previous = foundNode->previous;
  free(foundNode);
}

void deleteAtPosition(LinkedList_t *list, int position) {
  _Node_t *foundNode = _getNodeAtPosition(list, position);

  if (foundNode == NULL) {
    _throwError("There are no matches for provided key. Couldn't delete value");
    return;
  }

  if (foundNode->previous == NULL) {
    deleteHead(list);
    return;
  }

  if (foundNode->next == NULL) {
    deleteTail(list);
    return;
  }

  foundNode->previous->next = foundNode->next;
  foundNode->next->previous = foundNode->previous;
  free(foundNode);
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
  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->previous;
  }
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
