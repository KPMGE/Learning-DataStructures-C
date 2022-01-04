#include "../include/doubly-linked-list.h"
#include "../include/utils.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// private structure for a node
typedef struct node {
  int data;
  struct node *previous;
  struct node *next;
} node;

// public structure, for linked list
struct linked_list {
  node *head;
  node *tail;
};

// private functions

static node *node_new(int value) {
  node *new_node = malloc(sizeof(node));
  check_allocation(new_node, "Allocation error at 'node_new'");

  new_node->data = value;
  new_node->next = NULL;
  new_node->previous = NULL;

  return new_node;
}

static node *find_node(linked_list *list, int key) {
  node *current = list->head;

  while (current != NULL) {
    if (current->data == key) {
      return current;
    }

    current = current->next;
  }

  return NULL;
}

static node *get_node_at_position(linked_list *list, int position) {
  int i = 0;
  node *current = list->head;

  while (current != NULL) {
    if (i == position) {
      return current;
    }

    current = current->next;
    i++;
  }

  return NULL;
}

static bool list_is_empty(linked_list *list) {
  return (list->head == NULL) ? true : false;
}

// public functions
linked_list *list_new() {
  linked_list *new_list = malloc(sizeof(linked_list));

  check_allocation(new_list, "Allocation error at 'list_new'");

  new_list->head = NULL;
  new_list->tail = NULL;

  return new_list;
}

int list_get_head(linked_list *list) { return list->head->data; }

int list_get_tail(linked_list *list) { return list->tail->data; }

int list_get_at_position(linked_list *list, int position) {
  if (position == 0) {
    return list_get_head(list);
  }

  int count = 0;
  node *current = list->head;

  while (current != NULL) {
    if (count == position) {
      return current->data;
    }

    count++;
    current = current->next;
  }

  throw_error("Invalid position.");
  return (int)NAN;
}

int *list_to_array(linked_list *list) {
  if (list_is_empty(list)) {
    throw_error("The list is empty, couldn't create the array.");
    return NULL;
  }

  int *array = malloc(sizeof(int));
  check_allocation(array, "Allocation error at 'list_to_array'");

  int pos = 0;
  node *current = list->head;
  while (current != NULL) {
    array = realloc(array, (pos + 1) * sizeof(int));
    array[pos] = list_get_at_position(list, pos);
    pos++;

    current = current->next;
  }

  return array;
}

void list_add_head(linked_list *list, int newValue) {
  node *newnode = node_new(newValue);

  if (list_is_empty(list)) {
    list->head = newnode;
    list->tail = newnode;
    return;
  }

  newnode->next = list->head;
  list->head->previous = newnode;
  list->head = newnode;
}

void list_add_tail(linked_list *list, int newValue) {
  node *newnode = node_new(newValue);

  if (list_is_empty(list)) {
    list->head = newnode;
    list->tail = newnode;
    return;
  }

  newnode->previous = list->tail;
  list->tail->next = newnode;
  list->tail = newnode;
}

void list_add_after(linked_list *list, int key, int newValue) {
  node *foundnode = find_node(list, key);

  if (foundnode == NULL) {
    throw_error(
        "There are no matches for provided key. Couldn't add new value");
    return;
  }

  if (foundnode->previous == NULL) {
    list_add_head(list, newValue);
    return;
  }

  if (foundnode->next == NULL) {
    list_add_tail(list, newValue);
    return;
  }

  node *newnode = node_new(newValue);

  newnode->next = foundnode->next;
  newnode->previous = foundnode;
  foundnode->next->previous = newnode;
  foundnode->next = newnode;
}

void list_add_before(linked_list *list, int key, int newValue) {
  node *foundnode = find_node(list, key);

  if (foundnode == NULL) {
    throw_error(
        "There are no matches for provided key. Couldn't add new value");
    return;
  }

  if (foundnode->previous == NULL) {
    list_add_head(list, newValue);
    return;
  }

  if (foundnode->next == NULL) {
    list_add_tail(list, newValue);
    return;
  }

  node *newnode = node_new(newValue);
  foundnode->previous->next = newnode;
  newnode->previous = foundnode->previous;
  newnode->next = foundnode;
  foundnode->previous = newnode;
}

void list_delete_head(linked_list *list) {
  if (list_is_empty(list)) {
    throw_error("The list is empty.");
    return;
  }

  if (list->head->next == NULL) {
    free(list->head);
    list->head = NULL;
    list->tail = NULL;
    return;
  }

  node *aux = list->head;
  list->head->next->previous = NULL;
  list->head = list->head->next;
  free(aux);
}

void list_delete_tail(linked_list *list) {
  if (list_is_empty(list)) {
    throw_error("The list is empty.");
    return;
  }

  if (list->head->next == NULL) {
    free(list->head);
    list->head = NULL;
    list->tail = NULL;
    return;
  }

  node *aux = list->tail;
  list->tail->previous->next = NULL;
  list->tail = list->tail->previous;
  free(aux);
}

void list_delete_key(linked_list *list, int key) {
  node *foundnode = find_node(list, key);

  if (foundnode == NULL) {
    throw_error("There are no matches for provided key. Couldn't delete value");
    return;
  }

  if (foundnode->previous == NULL) {
    list_delete_head(list);
    return;
  }

  if (foundnode->next == NULL) {
    list_delete_tail(list);
    return;
  }

  foundnode->previous->next = foundnode->next;
  foundnode->next->previous = foundnode->previous;
  free(foundnode);
}

void list_delete_position(linked_list *list, int position) {
  node *foundnode = get_node_at_position(list, position);

  if (foundnode == NULL) {
    throw_error("There are no matches for provided key. Couldn't delete value");
    return;
  }

  if (foundnode->previous == NULL) {
    list_delete_head(list);
    return;
  }

  if (foundnode->next == NULL) {
    list_delete_tail(list);
    return;
  }

  foundnode->previous->next = foundnode->next;
  foundnode->next->previous = foundnode->previous;
  free(foundnode);
}

void list_display(linked_list *list) {
  node *current = list->head;

  printf("\033[1;36m");
  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("\033[0m");

  printf("\033[1;35m");
  printf("NULL");
  printf("\033[0m");
}

void list_display_reverse(linked_list *list) {
  node *current = list->tail;

  printf("\033[1;36m");
  while (current != NULL) {
    printf("%d -> ", current->data);
    current = current->previous;
  }
  printf("\033[0m");

  printf("\033[1;35m");
  printf("NULL");
  printf("\033[0m");
}

void list_free(linked_list *list) {
  node *current = list->head;

  while (current != NULL) {
    node *aux = current;
    current = current->next;
    free(aux);
  }
  free(list);
}
