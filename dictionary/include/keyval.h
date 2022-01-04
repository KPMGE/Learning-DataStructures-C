#ifndef KEYVAL_H
#define KEYVAL_H

typedef struct keyval keyval;

keyval *keyval_new(char *key, void *value);
char *get_key(keyval *in);
void *get_value(keyval *in);
keyval *keyval_copy(keyval const *in);
void keyval_free(keyval *in);
int keyval_matches(keyval const *in, char const *key);

#endif // !KEYVAL_H
