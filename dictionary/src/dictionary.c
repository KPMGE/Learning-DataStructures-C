#include "../include/dictionary.h"
#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>

struct dictionary {
  keyval **pairs;
  int length;
};

void *dictionary_not_found;

dictionary *dictionary_new(void) {
  static int not_found;

  if (!dictionary_not_found) {
    dictionary_not_found = &not_found;
  }

  dictionary *out = malloc(sizeof(dictionary));
  check_allocation(out, "Allocation error at 'dictionary_new'");
  *out = (dictionary){.length = 0, .pairs = NULL};

  return out;
}

int get_length(dictionary *in) { return in->length; }

static void dictionary_add_keyval(dictionary *in, keyval *kv) {
  in->length++;
  in->pairs = realloc(in->pairs, sizeof(keyval *) * in->length);
  in->pairs[in->length - 1] = kv;
}

dictionary *dictionary_copy(dictionary *in) {
  dictionary *out = dictionary_new();

  for (int i = 0; i < in->length; i++) {
    dictionary_add_keyval(out, keyval_copy(in->pairs[i]));
  }

  return out;
}

void dictionary_add(dictionary *in, char *key, void *value) {
  if (!key) {
    fprintf(stderr, "NULL is not a valid key.\n");
    abort();
  }

  dictionary_add_keyval(in, keyval_new(key, value));
}

void *dictionary_find(dictionary const *in, char const *key) {
  for (int i = 0; i < in->length; i++) {
    if (keyval_matches(in->pairs[i], key)) {
      return get_value(in->pairs[i]);
    }
  }

  return dictionary_not_found;
}

void dictionary_free(dictionary *in) {
  for (int i = 0; i < in->length; i++) {
    keyval_free(in->pairs[i]);
  }

  free(in->pairs);
  free(in);
}
