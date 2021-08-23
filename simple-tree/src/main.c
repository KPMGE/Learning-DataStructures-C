#include <stdio.h>
#include "../include/tree.h"

int main(void) {
  Tree *myTree = createEmptyTree();

  Tree *d = createTree('d', NULL, NULL);
  Tree *e = createTree('e', NULL, NULL);
  Tree *f = createTree('f', NULL, NULL);
  Tree *g = createTree('g', NULL, NULL);

  Tree *b = createTree('b', d, e);
  Tree *c = createTree('c', f, g);

  myTree = createTree('a', b, c);

  displayTree(myTree);

  freeTree(myTree);

  return 0;
}
