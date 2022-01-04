#ifndef DICTIONARY_H
#define DICTIONARY_H
#include "./keyval.h"

extern void *dictionary_not_found;

typedef struct dictionary dictionary;

dictionary *dictionary_new(void);
dictionary *dictionary_copy(dictionary *in);
int get_length(dictionary *in);
void dictionary_add(dictionary *in, char *key, void *value);
void *dictionary_find(dictionary const *in, char const *key);
void dictionary_free(dictionary *in);

#endif // !DICTIONARY_H
