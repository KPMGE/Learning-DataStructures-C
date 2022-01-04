#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct linked_list linked_list;

// functions for linked list
linked_list *list_new();
int list_get_head(linked_list *list);
int list_get_tail(linked_list *list);
int list_get_at_position(linked_list *list, int position);
int *list_to_array(linked_list *list);
void list_add_head(linked_list *list, int newValue);
void list_add_tail(linked_list *list, int newValue);
void list_add_after(linked_list *list, int key, int newValue);
void list_add_before(linked_list *list, int key, int newValue);
void list_delete_head(linked_list *list);
void list_delete_tail(linked_list *list);
void list_delete_key(linked_list *list, int key);
void list_delete_position(linked_list *list, int position);
void list_display(linked_list *list);
void list_display_reverse(linked_list *list);
void list_free(linked_list *list);

#endif
