#ifndef QUEUE_H
#define QUEUE_H

typedef struct _linkedQueue LinkedQueue_t;

LinkedQueue_t *createEmptyQueue();
void enQueue(LinkedQueue_t *queue, int newValue);
void deQueue(LinkedQueue_t *queue);
void displayQueue(LinkedQueue_t *queue);
void freeQueue(LinkedQueue_t *queue);

#endif
