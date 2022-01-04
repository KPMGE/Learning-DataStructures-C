#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>

void check_allocation(void *ptr, char const *message) {
  if (!ptr) {
    fprintf(stderr, "%s", message);
    exit(1);
  }
}
