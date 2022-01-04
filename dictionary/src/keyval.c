#include "../include/keyval.h"
#include "../include/utils.h"
#include <stdlib.h>
#include <strings.h>

struct keyval {
  char *key;
  void *value;
};

keyval *keyval_new(char *key, void *value) {
  keyval *out = malloc(sizeof(keyval));

  check_allocation(out, "Allocation error at 'keyval_new'");
  *out = (keyval){.key = key, .value = value};

  return out;
}

char *get_key(keyval *in) { return in->key; }

void *get_value(keyval *in) { return in->value; }

keyval *keyval_copy(keyval const *in) {
  keyval *out = malloc(sizeof(keyval));
  *out = *in;
  return out;
}

void keyval_free(keyval *in) { free(in); }

int keyval_matches(keyval const *in, char const *key) {
  return !strcasecmp(in->key, key);
}
