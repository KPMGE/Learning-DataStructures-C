#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>

void check_allocation(void *ptr, char const *message) {
  if (!ptr) {
    printf("\033[1;35m");
    printf("%s", message);
    printf("\033[0m");
    exit(1);
  }
}

void throw_error(char const *message) {
  printf("\033[1;35m");
  printf("%s\n", message);
  printf("\033[0m");
}
