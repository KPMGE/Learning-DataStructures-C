#ifndef TREE_H
#define TREE_H

#include <stdbool.h>

typedef struct tree Tree;

Tree *createEmptyTree(void);
Tree *createTree(char character, Tree *left, Tree *right);
void displayTree(Tree *tree);
bool hasElement(Tree *tree, char character);
int height(Tree *tree);
bool isEmpty(Tree *tree);
void freeTree(Tree *tree);

#endif
