#include "../include/generic-doubly-linked-list.h"
#include "../include/utils.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// private structure for a node
typedef struct node {
  void *data;
  struct node *previous;
  struct node *next;
} node;

// public structure, for linked list
struct linked_list {
  node *head;
  node *tail;
};

// private functions
static node *node_new(void *data) {
  node *new_node = malloc(sizeof(node));
  check_allocation(new_node, "Allocation error at 'node_new'");

  *new_node = (node){.data = data, .next = NULL, .previous = NULL};

  return new_node;
}

static node *node_find(linked_list *list, void *key, compare_fn compare) {
  node *current = list->head;

  while (current) {
    if (compare(current->data, key)) {
      return current;
    }

    current = current->next;
  }

  return NULL;
}

static node *node_get_position(linked_list *list, unsigned int position) {
  unsigned int i = 0;
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

void *list_get_head(linked_list *list) { return list->head->data; }

void *list_get_tail(linked_list *list) { return list->tail->data; }

void *list_get_at_position(linked_list *list, unsigned int position) {
  if (position == 0) {
    return list_get_head(list);
  }

  unsigned int count = 0;
  node *current = list->head;

  while (current) {
    if (count == position) {
      return current->data;
    }

    count++;
    current = current->next;
  }

  throw_error("Invalid position.");
  return NULL;
}

void list_add_head(linked_list *list, void *new_data) {
  node *new_node = node_new(new_data);

  if (list_is_empty(list)) {
    list->head = new_node;
    list->tail = new_node;
    return;
  }

  new_node->next = list->head;
  list->head->previous = new_node;
  list->head = new_node;
}

void list_add_tail(linked_list *list, void *new_data) {
  node *new_node = node_new(new_data);

  if (list_is_empty(list)) {
    list->head = new_node;
    list->tail = new_node;
    return;
  }

  new_node->previous = list->tail;
  list->tail->next = new_node;
  list->tail = new_node;
}

void list_add_after(linked_list *list, void *key, compare_fn compare,
                    void *new_data) {
  node *found_node = node_find(list, key, compare);

  if (!found_node) {
    throw_error(
        "There are no matches for provided key. Couldn't add new value");
    return;
  }

  if (!found_node->previous) {
    list_add_head(list, new_data);
    return;
  }

  if (!found_node->next) {
    list_add_tail(list, new_data);

    return;
  }

  node *new_node = node_new(new_data);

  new_node->next = found_node->next;
  new_node->previous = found_node;
  found_node->next->previous = new_node;
  found_node->next = new_node;
}

void list_add_before(linked_list *list, void *key, compare_fn compare,
                     void *new_data) {
  node *found_node = node_find(list, key, compare);

  if (!found_node) {
    throw_error(
        "There are no matches for provided key. Couldn't add new value");
    return;
  }

  if (!found_node->previous) {
    list_add_head(list, new_data);
    return;
  }

  if (!found_node->next) {
    list_add_tail(list, new_data);
    return;
  }

  node *new_node = node_new(new_data);
  found_node->previous->next = new_node;
  new_node->previous = found_node->previous;
  new_node->next = found_node;
  found_node->previous = new_node;
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

void list_delete_key(linked_list *list, void *key, compare_fn compare) {
  node *found_node = node_find(list, key, compare);

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

void list_delete_position(linked_list *list, unsigned int position) {
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

void list_display(linked_list *list, display_fn display) {
  node *current = list->head;

  while (current) {
    display(current->data);
    current = current->next;
  }
}

void list_display_reverse(linked_list *list, display_fn display) {
  node *current = list->tail;

  while (current) {
    display(current->data);
    current = current->previous;
  }
}

void list_free(linked_list *list, free_fn free_function) {
  node *current = list->head;

  while (current) {
    node *aux = current;
    current = current->next;
    free_function(aux);
  }
  free(list);
}
