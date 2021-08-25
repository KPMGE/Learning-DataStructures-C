#ifndef TREE_H
#define TREE_H

typedef struct binaryTree BinaryTree;

BinaryTree *createBinaryTree();
void insertBinaryTree(BinaryTree *tree, int newValue);
void displayBinaryTree(BinaryTree *tree);
void freeBinaryTree(BinaryTree *tree);

#endif
