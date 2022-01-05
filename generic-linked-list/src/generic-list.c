#include "../include/generic-list.h"
#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  void *data;
  struct node *next;
} node;

struct list {
  node *head;
  node *tail;
};

list *list_new(void) {
  list *new = malloc(sizeof(list));

  check_allocation(new, "allocation error at 'list_new'");
  new->head = NULL;

  return new;
}

void list_add_head(list *list, void *data) {
  node *new = malloc(sizeof(node));

  check_allocation(new, "allocation error at 'list_add_head'");
  new->next = NULL;
  new->data = data;

  if (!list->head) {
    list->head = list->tail = new;
    return;
  }

  new->next = list->head;
  list->head = new;
}

void list_add_tail(list *list, void *data) {
  node *new = malloc(sizeof(node));

  check_allocation(new, "allocation error at 'list_add_tail'");
  new->next = NULL;
  new->data = data;

  if (!list->head) {
    list->head = list->tail = new;
    return;
  }

  list->tail->next = new;
  list->tail = new;
}

void list_remove(list *list, int (*cpr_func)(void *, void *), void *item) {
  node *prev = NULL;
  node *aux = list->head;

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

int list_walk_through(list *list, int (*callback)(void *, void *), void *data) {
  node *current = list->head;

  while (current) {
    if (!callback(current->data, data)) {
      return 0;
    }
    current = current->next;
  }

  return 1;
}

void list_display(list *list, void (*display_fn)(void *)) {
  node *current = list->head;

  while (current) {
    display_fn(current->data);
    current = current->next;
  }
}

void list_free(list *list) {
  node *current = list->head;

  while (current) {
    node *aux = current;
    current = current->next;
    free(aux);
  }

  free(list);
}
