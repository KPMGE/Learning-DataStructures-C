#include "../include/linked-list.h"
#include <stdio.h>
#include <stdlib.h>

// private struct for a linked list node
typedef struct _node {
  int data;
  struct _node *next;
} _Node_t;

// public structure(sentinel) of the list
struct _linkedList {
  _Node_t *head;
  _Node_t *tail;
};

// private functions
void _checkAllocation(void *pointer) {
  if (pointer == NULL) {
    printf("\033[1;35m");
    printf("Allocation failed!");
    exit(1);
    printf("\033[0m");
  }
}

_Node_t *_createNode(int number) {
  _Node_t *allocatedNode = (_Node_t *)malloc(sizeof(_Node_t));

  allocatedNode->data = number;

  return allocatedNode;
}

_Node_t *_getNode(LinkedList_t *list, int key) {
  _Node_t *current = list->head;

  while (current != NULL) {
    if (current->data == key) {
      return current;
    }
    current = current->next;
  }

  return NULL;
}

_Node_t *_getPreviousNode(LinkedList_t *list, int key) {
  _Node_t *current = list->head;
  _Node_t *previous;

  if (current == NULL) {
    return NULL;
  }

  // finding previous node
  while (current->next != NULL && current->data != key) {
    previous = current;
    current = current->next;
  }

  return previous;
}


// public functions for linked list

LinkedList_t *createEmptyList() {
  LinkedList_t *allocatedList = (LinkedList_t *)malloc(sizeof(LinkedList_t));

  // initialize pointers with NULL
  allocatedList->head = NULL;
  allocatedList->tail = NULL;

  return allocatedList;
}

void addAtHead(LinkedList_t *list, int number) {
  _Node_t *newNode = _createNode(number);

  // if the list is empty, then the head and tail are the same node
  if (list->head == NULL) {
    list->head = newNode;
    list->tail = newNode;
    return;
  }

  // newNode points to our head, and then, our head is in fact the new node
  newNode->next = list->head;
  list->head = newNode;
}

void addAfter(LinkedList_t *list, int searchNumber, int newNumber) {
  // getting the node for the provided searchNumber
  _Node_t *previous = _getNode(list, searchNumber);

  // if there are no matches
  if (previous == NULL) {
    printf("\033[1;35m");
    printf("There is no Node for the provided number");
    printf("\033[0m");

    exit(1);
  }

  // create a new node with newNumber
  _Node_t *newNode = _createNode(newNumber);

  // point the next pointer of created node to next pointer of our previous node
  newNode->next = previous->next;
  // now, we can point our next of previous to our just created node
  previous->next = newNode;
}

void addAtTail(LinkedList_t *list, int number) {
  // create a node and points it to NULL, because we'll add it at the tail of
  // list
  _Node_t *newNode = _createNode(number);
  newNode->next = NULL;

  // if our list is empty, so the head and tail are the same node
  if (list->tail == NULL) {
    list->head = newNode;
    list->tail = newNode;
    return;
  }

  list->tail->next = newNode;
  list->tail = newNode;
}

void deleteHeadNode(LinkedList_t *list) {
  if (list->head == NULL) {
    printf("\033[1;35m");
    printf("The list is empty.");
    printf("\033[0m");

    return;
  }

  _Node_t *aux = list->head;
  list->head = list->head->next;
  free(aux);
}

void deleteTailNode(LinkedList_t *list) {
  if (list->tail == NULL) {
    printf("\033[1;35m");
    printf("The list is empty.");
    printf("\033[0m");

    return;
  }

  // current and previous nodes
  _Node_t *current = list->head->next;
  _Node_t *previous = list->head;

  // getting the previous node
  while (current->next != NULL) {
    previous = previous->next;
    current = current->next;
  }

  // now, previous node points to previous node points to NULL,
  // therefore, it is actually our tail
  previous->next = NULL;
  list->tail = previous;

  // free last node
  free(current);
}

void deleteSpecificNode(LinkedList_t *list, int key) {
  _Node_t *current = _getNode(list, key);
  if (current == NULL) {
    printf("\033[1;35m");
    printf("There are no matches for provided key.");
    printf("\033[0m");

    return;
  }

  // if the current node is actually the head of the list
  if (current->data == list->head->data) {
    deleteHeadNode(list);
    return;
  }

  _Node_t *previous = _getPreviousNode(list, key);
  if (previous == NULL) {
    printf("\033[1;35m");
    printf("You can't delete a NULL node.");
    printf("\033[0m");

    return;
  }

  previous->next = current->next;
  free(current);
}

void deleteAtPosition(LinkedList_t *list, int position) {
  // it's actually the head of the list
  if (position == 0) {
    deleteHeadNode(list);
    return;
  }

  _Node_t *current = list->head;
  for (int i = 0; current != NULL && i < position - 1; i++) {
    current = current->next;
  }

  // if invalid position was provided
  if (current == NULL || current->next == NULL) {
    printf("\033[1;35m");
    printf("Invalid position.\n");
    printf("\033[0m");

    return;
  }

  _Node_t *previous = _getPreviousNode(list, current->data);
  previous->next = current->next;
  free(current);
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

void freeList(LinkedList_t *list) {
  _Node_t *current = list->head;

  while (current != NULL) {
    _Node_t *aux = current;
    current = current->next;
    free(aux);
  }

  free(list);
}
