#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// struct for a linked list, we have the reference for the head and tail of the
// linked list
typedef struct _linkedList LinkedList_t;

// functions to perform on linked list
LinkedList_t *createEmptyList();
void addAtHead(LinkedList_t *list, int number);
void addAtTail(LinkedList_t *list, int number);
void addAfter(LinkedList_t *list, int searchNumber, int newNumber);
void displayLinkedList(LinkedList_t *list);
void freeList(LinkedList_t *list);

#endif

