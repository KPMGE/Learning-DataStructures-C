#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "../include/queue-linked-list.h"

// private structure for a queue linked list node
typedef struct _queueNode {
  int data;
  struct _queueNode *next;
} _QueueNode_t;

// public linked queue structure
struct _linkedQueue {
  _QueueNode_t *head;
  _QueueNode_t *tail;
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

bool _isEmpty(LinkedQueue_t *queue) {
  return (queue->head == NULL) ? true : false;
}

_QueueNode_t *_createNode(int newValue) {
  _QueueNode_t *allocatedNode = (_QueueNode_t*) malloc(sizeof(_QueueNode_t));

  _checkAllocation(allocatedNode);
  allocatedNode->data = newValue;

  return allocatedNode;
}


// public functions
LinkedQueue_t *createEmptyQueue() {
  LinkedQueue_t *allocatedQueue = (LinkedQueue_t*) malloc(sizeof(LinkedQueue_t));
  _checkAllocation(allocatedQueue);

  allocatedQueue->head = NULL;
  allocatedQueue->tail = NULL;

  return allocatedQueue;
}

void enQueue(LinkedQueue_t *queue, int newValue) {
  _QueueNode_t *newNode = _createNode(newValue);

  if (_isEmpty(queue)) {
    newNode->next = NULL;
    queue->head = newNode;
    queue->tail = newNode;
    return;
  }

  newNode->next = queue->head;
  queue->head = newNode;
}

void deQueue(LinkedQueue_t *queue) {
  if (_isEmpty(queue)) {
    printf("\033[1;35m");
    printf("The queue is empty!");
    printf("\033[0m");
    return;
  }

  _QueueNode_t *previous = queue->head;
  _QueueNode_t *current = previous->next->next;

  while (current != NULL) {
    previous = previous->next;
    current = current->next;
  }

  previous->next = NULL;
  free(queue->tail);
  queue->tail = previous;
}

void displayQueue(LinkedQueue_t *queue) {
  _QueueNode_t *current = queue->head;

  printf("\033[1;36m");
  while (current != NULL) {
    printf("\n[ %d ]", current->data);
    current = current->next;
  }
  printf("\033[0m");
}

void freeQueue(LinkedQueue_t *queue) {
  _QueueNode_t *current = queue->head;

  while (current != NULL) {
    _QueueNode_t *aux = current;
    current = current->next;
    free(aux);
  }

  free(queue);
}
