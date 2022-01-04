#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdbool.h>

typedef void (*display_fn)(void *);
typedef bool (*compare_fn)(void *, void *);
typedef void (*free_fn)(void *);
typedef struct linked_list linked_list;

// functions for linked list
linked_list *list_new();

void *list_get_head(linked_list *list);
void *list_get_tail(linked_list *list);
void *list_get_at_position(linked_list *list, unsigned int position);

void list_add_head(linked_list *list, void *new_data);
void list_add_tail(linked_list *list, void *new_data);
void list_add_after(linked_list *list, void *key, compare_fn compare,
                    void *new_data);
void list_add_before(linked_list *list, void *key, compare_fn compare,
                     void *new_data);

void list_delete_head(linked_list *list);
void list_delete_tail(linked_list *list);
void list_delete_key(linked_list *list, void *key, compare_fn compare);
void list_delete_position(linked_list *list, unsigned int position);

void list_display(linked_list *list, display_fn display);
void list_display_reverse(linked_list *list, display_fn display);
void list_free(linked_list *list, free_fn free_function);

#endif
