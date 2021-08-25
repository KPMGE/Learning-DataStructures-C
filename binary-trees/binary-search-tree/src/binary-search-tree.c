#include <stdio.h>
#include <stdlib.h>
#include "../include/binary-search-tree.h"
 
typedef struct treeNode{
  int data;
  struct treeNode *left;
  struct treeNode *right;
} TreeNode;

struct binaryTree {
  TreeNode *root;
};

// private functions
static TreeNode *createNode(int data, TreeNode *left, TreeNode *right) {
  TreeNode *newNode = (TreeNode *) malloc(sizeof(TreeNode));

  if (!newNode) {
    printf("Allocation failed!");
    exit(1);
  }

  newNode->data = data;
  newNode->left = left;
  newNode->right = right;

  return newNode;
}

static TreeNode *insert(TreeNode *node, int newValue) {
  if (!node) {
    return createNode(newValue, NULL, NULL);
  } 

  if (newValue < node->data) {
    node->left = insert(node->left, newValue);
  } 

  if (newValue > node->data) {
    node->right = insert(node->right, newValue);
  }

  return node;
}

static void display(TreeNode *node) {
  if (node) {
    display(node->left);
    printf("%d, ", node->data);
    display(node->right);
  }
}

static void freeTree(TreeNode *node) {
  if (node) {
    freeTree(node->left);
    freeTree(node->right);
    free(node);
  }
}


// public functions
BinaryTree *createBinaryTree() {
  BinaryTree *tree = (BinaryTree *) malloc(sizeof(BinaryTree));

  if (!tree) {
    printf("Allocation failed!");
    exit(1);
  }

  tree->root = NULL;

  return tree;
}

void insertBinaryTree(BinaryTree *tree, int newValue) {
  tree->root = insert(tree->root, newValue);
}

void displayBinaryTree(BinaryTree *tree) {
  display(tree->root);
}

void freeBinaryTree(BinaryTree *tree) {
  freeTree(tree->root);
  free(tree);
}
