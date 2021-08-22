#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct _binaryTree BinaryTree;

BinaryTree *createEmptyBinaryTree(void);
void displayBinaryTree(BinaryTree *tree);
void insertBinaryTree(BinaryTree *tree, int value);
void removeBinaryTree(BinaryTree *tree, int value);
void freeBinaryTree(BinaryTree *tree);

#endif
