#ifndef AVLTREES_H
#define AVLTREES_H

typedef struct avlTree{
    int value;
    int bal;
    struct avlTree *left, *right;
}AVLNode, *AVLTree;

void printTree(AVLTree t);
int makeTreeLine(AVLTree t, char *tree);
int makeTreeED(AVLTree t, char *tree, int n);
int alturaAVL(AVLTree t);
AVLTree rotateLeft(AVLTree a);
AVLTree rotateRight(AVLTree a);
AVLTree insertAVL(AVLTree t, int x);
AVLTree deleteAVL(AVLTree t, int x);
void clearAVL(AVLTree t);

#endif