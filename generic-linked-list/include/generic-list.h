#ifndef GENERIC_LIST_H
#define GENERIC_LIST_H

typedef struct generic_list List;

List *create_empty_list(void);
void insert_head(List *list, void *data);
void insert_tail(List *list, void *data);
void remove_list(List *list, int (*cpr_func)(void*, void*), void *item);
int walk_through_list(List *list, int (*callback)(void*, void*), void *data);
void free_list(List *list);

#endif
