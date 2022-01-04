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

  *new_node = (node){.data = value, .next = NULL, .previous = NULL};

  return new_node;
}

static node *node_find(linked_list *list, int key) {
  node *current = list->head;

  while (current) {
    if (current->data == key) {
      return current;
    }

    current = current->next;
  }

  return NULL;
}

static node *node_get_position(linked_list *list, int position) {
  int i = 0;
  node *current = list->head;

  while (current) {
    if (i == position) {
      return current;
    }

    current = current->next;
    i++;
  }

  return NULL;
}

static bool list_is_empty(linked_list *list) {
  return (!list->head) ? true : false;
}

// public functions
linked_list *list_new() {
  linked_list *new_list = malloc(sizeof(linked_list));

  check_allocation(new_list, "Allocation error at 'list_new'");
  *new_list = (linked_list){.head = NULL, .tail = NULL};

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

  while (current) {
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
  while (current) {
    array = realloc(array, (pos + 1) * sizeof(int));
    array[pos] = list_get_at_position(list, pos);
    pos++;

    current = current->next;
  }

  return array;
}

void list_add_head(linked_list *list, int new_value) {
  node *newnode = node_new(new_value);

  if (list_is_empty(list)) {
    list->head = newnode;
    list->tail = newnode;
    return;
  }

  newnode->next = list->head;
  list->head->previous = newnode;
  list->head = newnode;
}

void list_add_tail(linked_list *list, int new_value) {
  node *newnode = node_new(new_value);

  if (list_is_empty(list)) {
    list->head = newnode;
    list->tail = newnode;
    return;
  }

  newnode->previous = list->tail;
  list->tail->next = newnode;
  list->tail = newnode;
}

void list_add_after(linked_list *list, int key, int new_value) {
  node *found_node = node_find(list, key);

  if (!found_node) {
    throw_error(
        "There are no matches for provided key. Couldn't add new value");
    return;
  }

  if (!found_node->previous) {
    list_add_head(list, new_value);
    return;
  }

  if (!found_node->next) {
    list_add_tail(list, new_value);
    return;
  }

  node *newnode = node_new(new_value);

  newnode->next = found_node->next;
  newnode->previous = found_node;
  found_node->next->previous = newnode;
  found_node->next = newnode;
}

void list_add_before(linked_list *list, int key, int new_value) {
  node *found_node = node_find(list, key);

  if (!found_node) {
    throw_error(
        "There are no matches for provided key. Couldn't add new value");
    return;
  }

  if (!found_node->previous) {
    list_add_head(list, new_value);
    return;
  }

  if (!found_node->next) {
    list_add_tail(list, new_value);
    return;
  }

  node *newnode = node_new(new_value);
  found_node->previous->next = newnode;
  newnode->previous = found_node->previous;
  newnode->next = found_node;
  found_node->previous = newnode;
}

void list_delete_head(linked_list *list) {
  if (list_is_empty(list)) {
    throw_error("The list is empty.");
    return;
  }

  if (!list->head->next) {
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

  if (!list->head->next) {
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
  node *found_node = node_find(list, key);

  if (!found_node) {
    throw_error("There are no matches for provided key. Couldn't delete value");
    return;
  }

  if (!found_node->previous) {
    list_delete_head(list);
    return;
  }

  if (!found_node->next) {
    list_delete_tail(list);
    return;
  }

  found_node->previous->next = found_node->next;
  found_node->next->previous = found_node->previous;
  free(found_node);
}

void list_delete_position(linked_list *list, int position) {
  node *found_node = node_get_position(list, position);

  if (!found_node) {
    throw_error("There are no matches for provided key. Couldn't delete value");
    return;
  }

  if (!found_node->previous) {
    list_delete_head(list);
    return;
  }

  if (!found_node->next) {
    list_delete_tail(list);
    return;
  }

  found_node->previous->next = found_node->next;
  found_node->next->previous = found_node->previous;
  free(found_node);
}

void list_display(linked_list *list) {
  node *current = list->head;

  printf("\033[1;36m");
  while (current) {
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
  while (current) {
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

  while (current) {
    node *aux = current;
    current = current->next;
    free(aux);
  }
  free(list);
}
