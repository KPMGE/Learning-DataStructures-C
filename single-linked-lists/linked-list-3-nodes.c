// Simple implementation of a linked list with only three nodes

#include <stdio.h>
#include <stdlib.h>

// structure for a node
typedef struct _node {
  int data;
  struct _node *next;
} Node_t;

void displayList(Node_t *node);

int main(void) {
  // initialize nodes with NULL
  Node_t *head = NULL;
  Node_t *second = NULL;
  Node_t *tail = NULL;

  // allocating memory for nodes
  head = (Node_t *)malloc(sizeof(Node_t));
  second = (Node_t *)malloc(sizeof(Node_t));
  tail = (Node_t *)malloc(sizeof(Node_t));

  // assigning values to the data field of each node
  head->data = 1;
  second->data = 2;
  tail->data = 3;

  // linking list
  head->next = second;
  second->next = tail;
  tail->next = NULL;

  // displaying linked list
  displayList(head);

  // free allocated memory
  free(head);
  free(second);
  free(tail);

  return 0;
}

void displayList(Node_t *node) {
  // if node is NULL, then we're at the end of the list!
  while (node != NULL) {
    printf("%d -> ", node->data);
    node = node->next;
  }
  printf("NULL");
}
