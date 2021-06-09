// Simple program to show how to delete nodes in a single linked list
// Author: Kevin Carvalho de Jesus

#include <stdio.h>
#include <stdlib.h>

// struct for a linked list node
typedef struct _node {
  int data;
  struct _node *next;
} Node_t;

// struct for a linked list, we have the reference for the head and tail of the
// linked list
typedef struct _linkedList {
  Node_t *head;
  Node_t *tail;
} LinkedList_t;

// function that allocates a node and sets it with the value provided
Node_t *createNode(int number);
Node_t *getNode(LinkedList_t *list, int number);

// functions to perform on linked list
LinkedList_t *createList();
Node_t* getPreviousNode(LinkedList_t *list, int key);
void addAtHead(LinkedList_t *list, int number);
void addAtTail(LinkedList_t *list, int number);
void addAfter(LinkedList_t *list, int searchNumber, int newNumber);
void deleteHeadNode(LinkedList_t *list);
void deleteTailNode(LinkedList_t *list);
void deleteSpecificNode(LinkedList_t *list, int key);
void displayLinkedList(LinkedList_t *list);
void freeList(LinkedList_t *list);

int main(void) {
  // create empty list
  LinkedList_t *myList = createList();

  // add some data into the list
  addAtTail(myList, 30);
  addAtTail(myList, 532);
  addAtTail(myList, 53);
  addAtTail(myList, 63);
  addAtTail(myList, 85);

  printf("Original linked list:  ");
  displayLinkedList(myList);

  printf("\nAfter delete head:  ");
  deleteHeadNode(myList);
  displayLinkedList(myList);

  printf("\nAfter delete tail:  ");
  deleteTailNode(myList);
  displayLinkedList(myList);

  printf("\nAfter delete node with value 53:  ");
  deleteSpecificNode(myList, 53);
  displayLinkedList(myList);

  // free linked list
  freeList(myList);

  return 0;
}

Node_t *createNode(int number) {
  Node_t *allocatedNode = (Node_t *)malloc(sizeof(Node_t));

  allocatedNode->data = number;

  return allocatedNode;
}

LinkedList_t *createList() {
  LinkedList_t *allocatedList = (LinkedList_t *)malloc(sizeof(LinkedList_t));

  // initialize pointers with NULL
  allocatedList->head = NULL;
  allocatedList->tail = NULL;

  return allocatedList;
}

Node_t *getNode(LinkedList_t *list, int number) {
  Node_t *current = list->head;

  while (current != NULL) {
    if (current->data == number) {
      return current;
    }
    current = current->next;
  }

  return NULL;
}


Node_t* getPreviousNode(LinkedList_t *list, int key) {
  Node_t *current = list->head;
  Node_t *previous;

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

void addAtHead(LinkedList_t *list, int number) {
  Node_t *newNode = createNode(number);

  // if the list is empty, so the head and tail are the same node
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
  Node_t *previous = getNode(list, searchNumber);

  // if there are no matches
  if (previous == NULL) {
    printf("There is no Node for the provided number");
    exit(1);
  }

  // create a new node with newNumber
  Node_t *newNode = createNode(newNumber);

  // point the next pointer of created node to next pointer of our previous node
  newNode->next = previous->next;
  // now, we can point our next of previous to our just created node
  previous->next = newNode;
}

void addAtTail(LinkedList_t *list, int number) {
  // create a node and points it to NULL, because we'll add it at the tail of
  // list
  Node_t *newNode = createNode(number);
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
    printf("The list is empty.");
    return;
  }

  Node_t *aux = list->head;
  list->head = list->head->next;
  free(aux);
}

void deleteTailNode(LinkedList_t *list) {
  if (list->tail == NULL) {
    printf("The list is empty.");
    return;
  }

  // current and previous nodes
  Node_t *current = list->head->next;
  Node_t *previous = list->head;

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
  Node_t *current = getNode(list, key);
  if (current == NULL) {
    printf("There are no matches for provided key.");
    return;
  }
  
  // if the current node is actually the head of the list
  if (current->data == list->head->data) {
    deleteHeadNode(list);
    return;
  }

  Node_t *previous = getPreviousNode(list, key);
  if (previous == NULL) {
    printf("You can't delete a NULL node.");
    return;
  }

  //printf("current = %d\n", current->data);
  //printf("previous = %d\n", previous->data);

  previous->next = current->next;
  free(current);
}

void displayLinkedList(LinkedList_t *list) {
  Node_t *current = list->head;

  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL");
}

void freeList(LinkedList_t *list) {
  Node_t *current = list->head;

  while (current != NULL) {
    Node_t *aux = current;
    current = current->next;
    free(aux);
  }

  free(list);
}
