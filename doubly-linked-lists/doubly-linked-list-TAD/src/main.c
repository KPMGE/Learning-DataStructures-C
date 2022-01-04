#include "../include/doubly-linked-list.h"
#include <stdio.h>
#include <stdlib.h>

void display_array(int *array, int size);

int main(void) {
  linked_list *myList = list_new();

  // add some data into list
  list_add_head(myList, 1);
  list_add_tail(myList, 5);
  list_add_tail(myList, 9);
  list_add_tail(myList, 23);

  // display original list
  printf("\nOriginal list: ");
  list_display(myList);

  printf("\nOriginal list in reverse order: ");
  list_display_reverse(myList);

  printf("\nAdd 200 after 5: ");
  list_add_after(myList, 5, 200);
  list_display(myList);

  printf("\nAdd 80 before 5: ");
  list_add_before(myList, 5, 80);
  list_display(myList);

  int *arr = list_to_array(myList);
  display_array(arr, 5);

  printf("\nDelete head: ");
  list_delete_head(myList);
  list_display(myList);

  printf("\nDelete tail: ");
  list_delete_tail(myList);
  list_display(myList);

  printf("\nDelete at position 1: ");
  list_delete_position(myList, 1);
  list_display(myList);

  printf("\nDelete node with value 200: ");
  list_delete_key(myList, 200);
  list_display(myList);

  printf("\nValue at position 1: %d\n", list_get_at_position(myList, 1));

  // free allocated list
  list_free(myList);
  free(arr);
}

void display_array(int *array, int size) {
  printf("\nArray: ");

  printf("\033[1;36m");
  printf("[");

  for (int i = 0; i < size; i++) {
    if (i == size - 1) {
      printf("%d", array[i]);
      continue;
    }
    printf("%d, ", array[i]);
  }

  printf("]");
  printf("\033[0m");
}
