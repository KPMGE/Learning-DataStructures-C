#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct _doublyLinkedList DoublyLinkedList_t;

DoublyLinkedList_t *createEmptyList();
void addAtHead(DoublyLinkedList_t *list, int newValue);
void addAtTail(DoublyLinkedList_t *list, int newValue);
void addAfter(DoublyLinkedList_t *list, int key, int newValue);
void deleteHead(DoublyLinkedList_t *list);
void deleteTail(DoublyLinkedList_t *list);
void displayLinkedList(DoublyLinkedList_t *list);
void displayLinkedListReverse(DoublyLinkedList_t *list);
void freeLinkedList(DoublyLinkedList_t *list);

#endif
