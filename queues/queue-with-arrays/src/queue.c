#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "../include/queue.h"

  struct _queue {
    int head;
    int tail;
    int size;
    int *array;
    size_t capacity;
  };

  // private functions
  void _checkAllocation(void *pointer) {
    if (pointer == NULL) {
      printf("Allocation failed!");
      exit(1);
    }
  } 

  bool _isEmpty(Queue_t *queue) {
    return (queue->capacity == 0) ? true : false;
  }

  bool _isFull(Queue_t *queue) {
    return (queue->size == queue->capacity) ? true : false;
  }


  // public functions
  Queue_t *createQueue(size_t capacity) {
    Queue_t *allocatedQueue = (Queue_t*)malloc(sizeof(Queue_t));
    _checkAllocation(allocatedQueue);

    allocatedQueue->array = (int*) malloc(capacity * sizeof(int));
    _checkAllocation(allocatedQueue->array);

    allocatedQueue->capacity = capacity;
    allocatedQueue->size = 0;
    allocatedQueue->head = 0;  
    allocatedQueue->tail = capacity - 1;

    return allocatedQueue;
  }

  int getHead(Queue_t *queue) {
    if (_isEmpty(queue)) {
      printf("The queue is empty!");
      return INT_MIN;
    }

    return queue->array[queue->head];
  }

  int getTail(Queue_t *queue) {
    if (_isEmpty(queue)) {
      printf("The queue is empty!");
      return INT_MIN;
    }

    return queue->array[queue->head];
  }

void enQueue(Queue_t *queue, int newValue) {
  if (_isFull(queue)) {
    printf("The queue is full already!");
    return;
  }

  int position = (queue->tail + 1) % queue->capacity;
  queue->tail = position;
  queue->array[position] = newValue;
  queue->size++;
}

int deQueue(Queue_t *queue) {
  if (_isEmpty(queue)) {
    printf("The queue is empty already!");
    return INT_MIN;
  }

  int removedValue = queue->array[queue->head];
  queue->head = (queue->head + 1) % queue->capacity;
  queue->size--;

  return removedValue;
}

void displayQueue(Queue_t *queue) {
  printf("[ ");
  for (int i = 0; i < queue->size; i++) {
    printf("%d, ", queue->array[i]);
  }
  printf(" ]");
}

void freeQueue(Queue_t *queue) {
  free(queue->array);
  free(queue);
}


