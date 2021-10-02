#include <stdio.h>
#include "../include/binary-search-tree.h"

int main(void) {
  BinaryTree *tree = createEmptyBinaryTree();

  insertBinaryTree(tree, 10);
  insertBinaryTree(tree, 90);
  insertBinaryTree(tree, 43);
  insertBinaryTree(tree, 3);

  printf("original: \n");
  displayBinaryTree(tree);

  printf("\n90 removed: \n");
  removeBinaryTree(tree, 90);
  displayBinaryTree(tree);
  freeBinaryTree(tree);

  return 0;
}
