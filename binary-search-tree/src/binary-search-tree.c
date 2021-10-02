#include <stdio.h>
#include <stdlib.h>
#include "../include/binary-search-tree.h"

typedef struct _treeNode {
  int data;
  struct _treeNode *left;
  struct _treeNode *right;
} _TreeNode;

struct _binaryTree {
  _TreeNode *root;
};

// private functions
static void _display(_TreeNode *node) {
  if (node) {
    _display(node->left);
    _display(node->right);
    printf("%d\n", node->data);
  }
}

static _TreeNode *_createNode(int newData, _TreeNode *left, _TreeNode *right) {
  _TreeNode *newNode = (_TreeNode *) malloc(sizeof(_TreeNode));

  if (!newNode) {
    printf("Allocation failed!");
    exit(1);
  }

  newNode->data = newData;
  newNode->left = left;
  newNode->right = right;

  return newNode;
}

static _TreeNode *_search(_TreeNode *node, int value) {
  if (!node) {
    return NULL;
  } else if (node->data > value) {
    return _search(node->left, value);
  } else if (node->data < value) {
    return _search(node->right, value);
  } 

  return node;
}

static _TreeNode *_insert(_TreeNode *node, int value) {
  if (!node) {
    node = _createNode(value, NULL, NULL);
  } else if (value < node->data){
    node->left = _insert(node->left, value);
  } else {
    node->right = _insert(node->right, value);
  }

  return node;
}

static _TreeNode *_remove(_TreeNode *node, int value) {
  if (!node) {
    return NULL;
  } else if (node->data > value) {
    node->left = _remove(node->left, value);
  } else if (node->data < value) {
    node->right = _remove(node->right, value);
  } else {
    if (node->left && node->right) {
      free(node);
      node = NULL;
    } else if (node->left) {
      _TreeNode *aux = node;
      node = node->right;
      free(aux);
    } else if (node->right) {
      _TreeNode *aux = node;
      node = node->left;
      free(aux);
    } else {
      _TreeNode *aux = node->left;

      while (aux->right) {
        aux = aux->right;
      }

      node->data = aux->data;
      aux->data = value;
      node->left = _remove(node->left, value);
    }
  }

  return node;
}

static void _free(_TreeNode *node) {
  if (node) {
    _free(node->left);
    _free(node->right);
    free(node);
  }
} 

// public functions
BinaryTree *createEmptyBinaryTree(void) {
  BinaryTree *tree = (BinaryTree *) malloc(sizeof(BinaryTree));

  if (!tree) {
    printf("Allocation failed!");
    exit(1);
  }

  tree->root = NULL;

  return tree;
}

void displayBinaryTree(BinaryTree *tree) {
  _display(tree->root);
}

void insertBinaryTree(BinaryTree *tree, int value) {
  tree->root = _insert(tree->root, value);
}

void removeBinaryTree(BinaryTree *tree, int value) {
  tree->root = _remove(tree->root, value);
}

void freeBinaryTree(BinaryTree *tree) {
  _free(tree->root);
  free(tree);
}
