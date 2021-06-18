#ifndef QUEUE_H
#define QUEUE_H
#include <stddef.h>

typedef struct _queue Queue_t;

Queue_t *createQueue(size_t capacity);
int getHead(Queue_t *queue);
int getTail(Queue_t *queue);
void enQueue(Queue_t *queue, int newValue);
int deQueue(Queue_t *queue);
void displayQueue(Queue_t *queue);
void freeQueue(Queue_t *queue);

#endif
