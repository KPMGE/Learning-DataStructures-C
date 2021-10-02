#include <stdio.h>
#include <stdlib.h>
#include "../include/generic-list.h"

typedef struct node {
  void *data;
  struct node *next;
} Node;

struct generic_list {
  Node *head;
  Node *tail;
};

List *create_empty_list(void) {
  List *list = (List *) malloc(sizeof(List));

  if (!list) {
    printf("Allocation error at create_empty_list!");
    exit(1);
  }

  list->head = NULL;

  return list;
}

void insert_head(List *list, void *data) {
  Node *new = (Node *) malloc(sizeof(Node));

  if (!new) {
    printf("Allocation error at insert!");
    exit(1);
  }

  new->next = NULL;
  new->data = data;

  if (!list->head) {
    list->head = list->tail = new;
    return;
  }

  new->next = list->head;
  list->head = new;
}

void insert_tail(List *list, void *data) {
  Node *new = (Node *) malloc(sizeof(Node));

  if (!new) {
    printf("Allocation error at insert!");
    exit(1);
  }

  new->next = NULL;
  new->data = data;

  if (!list->head) {
    list->head = list->tail = new;
    return;
  }

  list->tail->next = new;
}

void remove_list(List *list, int (*cpr_func)(void*, void*), void *item) {
  Node *prev = NULL;
  Node *aux = list->head;

  while (aux && cpr_func(aux->data, item)) {
    prev = aux;
    aux = aux->next;
  }

  if (!aux) {
    printf("Couldn't find cell");
    return;
  }

  // it's the first node
  if (!prev) {
    list->head = aux->next;
    free(aux);
    return;
  }

  prev->next = aux->next;
  free(aux);
}

int walk_through_list(List *list, int (*callback)(void*, void*), void *data) {
  Node *current = list->head;

  while (current) {
    if (!callback(current->data, data)) {
      return 0;
    }
    current = current->next;
  }

  return 1;
}

void free_list(List *list) {
  Node *current = list->head;

  while (current) {
    Node *aux = current;
    current = current->next;
    free(aux);
  }

  free(list);
}
