#ifndef CIRCULAR_LIST_H 
#define CIRCULAR_LIST_H 

typedef struct _circularList CircularList_t;

CircularList_t *createEmptyList();
void addAtHead(CircularList_t *list, int newValue);
void addAtTail(CircularList_t *list, int newValue);
void deleteHead(CircularList_t *list);
void deleteTail(CircularList_t *list);
void displayList(CircularList_t *list);
void freeList(CircularList_t *list);

#endif
