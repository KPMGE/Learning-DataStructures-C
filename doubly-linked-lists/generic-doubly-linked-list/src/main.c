#include "../include/generic-doubly-linked-list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void display_int(void *val) {
  printf("\033[1;36m");
  printf("%d -> ", *(int *)val);
  printf("\033[0m");
}
bool compare_int(void *val1, void *val2) {
  return *(int *)val1 == *(int *)val2;
}

int main(void) {
  int n1 = 1, n2 = 2, n3 = 3, n4 = 4, n5 = 5, n6 = 6;
  linked_list *myList = list_new();

  // add some data into the list
  list_add_head(myList, &n1);
  list_add_tail(myList, &n2);
  list_add_tail(myList, &n3);
  list_add_tail(myList, &n4);

  printf("\nOriginal list: ");
  list_display(myList, display_int);
  printf("\033[1;35mNULL\033[0m");

  printf("\nOriginal list in reverse order: ");
  list_display_reverse(myList, display_int);
  printf("\033[1;35mNULL\033[0m");

  printf("\nAdd n5 after n2: ");
  list_add_after(myList, &n2, compare_int, &n5);
  list_display(myList, display_int);
  printf("\033[1;35mNULL\033[0m");

  printf("\nAdd n6 before n4: ");
  list_add_before(myList, &n4, compare_int, &n6);
  list_display(myList, display_int);
  printf("\033[1;35mNULL\033[0m");

  printf("\nDelete head: ");
  list_delete_head(myList);
  list_display(myList, display_int);
  printf("\033[1;35mNULL\033[0m");

  printf("\nDelete tail: ");
  list_delete_tail(myList);
  list_display(myList, display_int);
  printf("\033[1;35mNULL\033[0m");

  printf("\nDelete at position 1: ");
  list_delete_position(myList, 1);
  list_display(myList, display_int);
  printf("\033[1;35mNULL\033[0m");

  printf("\nDelete node with value n2: ");
  list_delete_key(myList, &n2, compare_int);
  list_display(myList, display_int);
  printf("\033[1;35mNULL\033[0m");

  printf("\nValue at position 1: \033[1;36m%d\033[0m\n",
         *(int *)list_get_at_position(myList, 1));

  // free allocated list
  list_free(myList, free);
}
