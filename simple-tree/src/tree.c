#include <stdio.h>
#include <stdlib.h>
#include "../include/tree.h"

struct tree {
  char data;
  Tree *left;
  Tree *right;
};


Tree *createEmptyTree(void) {
  return NULL;
}

Tree *createTree(char character, Tree *left, Tree *right) {
  Tree *new = (Tree *) malloc(sizeof(Tree));

  if (!new) {
    printf("Allocation failed!");
    exit(1);
  }

  new->data = character;
  new->left = left;
  new->right = right;

  return new;
}

void displayTree(Tree *tree) {
  printf("<");
  if (!isEmpty(tree)) {
    printf("%c ", tree->data);
    displayTree(tree->left);
    displayTree(tree->right);
  }
  printf(">");
}

bool hasElement(Tree *tree, char character) {
  if (isEmpty(tree)) {
    return false;
  } else {
    return (tree->data == character) || 
      hasElement(tree->left, character) ||
      hasElement(tree->right, character);
  }
}

static int max(int a, int b) {
  return (a > b) ? a : b;
}

int height(Tree *tree) {
  if (!tree) {
    return -1;
  } 

  return 1 + max(height(tree->left), height(tree->right));
}

bool isEmpty(Tree *tree) {
  return tree == NULL;
}

void freeTree(Tree *tree) {
  if (!isEmpty(tree)) {
    freeTree(tree->left);
    freeTree(tree->right);
    free(tree);
  }
}
