#include <stdio.h>
#include <stdlib.h>
#include "../include/binary-search-tree.h"

int main(void) {
  BinaryTree *myTree = createBinaryTree();

  insertBinaryTree(myTree, 80);
  insertBinaryTree(myTree, 5);
  insertBinaryTree(myTree, 98);
  insertBinaryTree(myTree, 60);

  printf("Tree: \n");
  displayBinaryTree(myTree);
  freeBinaryTree(myTree);

  return 0;
}
