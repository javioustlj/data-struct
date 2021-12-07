#ifndef _BINTREE_H_
#define _BINTREE_H_

typedef int ElementType;
typedef struct BinTreeNode *PtrToBinNode;
typedef PtrToBinNode BinTree;
typedef PtrToBinNode Position;

struct BinTreeNode
{
    ElementType element;
    PtrToBinNode left;
    PtrToBinNode right;
};

void inOrderTraversal(BinTree bt);
void preOrderTraversal(BinTree bt);
void postOrderTraversal(BinTree bt);
void levelOrderTraversal(BinTree bt);

void inOrderTraversalByRecursion(BinTree bt);
void preOrderTraversalByRecursion(BinTree bt);
void postOrderTraversalByRecursion(BinTree bt);

// Binary Search Tree
Position find(ElementType x, BinTree bst);
Position findMin(BinTree bst);
Position findMax(BinTree bst);

BinTree insert(ElementType x, BinTree bst);
BinTree delete(ElementType x, BinTree bst);

Position findByRecursion(ElementType x, BinTree bst);
Position findMinByRecursion(BinTree bst);
Position findMaxByRecursion(BinTree bst);
BinTree insertByRecursion(ElementType x, BinTree bst);
BinTree deleteByRecursion(ElementType x, BinTree bst);

#endif
