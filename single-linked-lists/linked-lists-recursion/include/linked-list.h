#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct _linkedList LinkedList_t;

LinkedList_t *createEmptyList();
LinkedList_t *addAtHead(LinkedList_t *headRef, int newNum);
LinkedList_t *removeList(LinkedList_t *headRef, int num);
void displayLinkedList(LinkedList_t *headRef);
void freeLinkedList(LinkedList_t *headRef);

#endif
