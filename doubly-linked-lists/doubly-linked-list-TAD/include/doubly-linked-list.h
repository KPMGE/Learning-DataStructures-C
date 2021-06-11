#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct _linkedList LinkedList_t;

// functions for linked list
LinkedList_t *createEmptyList();
int getHeadValue(LinkedList_t *list);
int getTailValue(LinkedList_t *list);
int getValueAtPosition(LinkedList_t *list, int position);
int* convertIntoArray(LinkedList_t *list);
void addAtHead(LinkedList_t *list, int newValue);
void addAtTail(LinkedList_t *list, int newValue);
void addAfter(LinkedList_t *list, int key, int newValue);
void addBefore(LinkedList_t *list, int key, int newValue);
void deleteHead(LinkedList_t *list);
void deleteTail(LinkedList_t *list);
void deleteSpecificNode(LinkedList_t *list, int key);
void deleteAtPosition(LinkedList_t *list, int position);
void displayLinkedList(LinkedList_t *list);
void displayLinkedListReverse(LinkedList_t *list);
void freeLinkedList(LinkedList_t *list);

#endif
