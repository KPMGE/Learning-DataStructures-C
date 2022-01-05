#ifndef GENERIC_LIST_H
#define GENERIC_LIST_H

typedef struct list list;

list *list_new(void);
void list_add_head(list *in, void *data);
void list_add_tail(list *in, void *data);
void list_remove(list *in, int (*cpr_func)(void *, void *), void *item);
int list_walk_through(list *in, int (*callback)(void *, void *), void *data);
void list_display(list *list, void (*display_fn)(void *));
void list_free(list *in);

#endif
