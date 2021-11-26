#ifndef _BINTREE_H_
#define _BINTREE_H

typedef int ElementType;
typedef struct BinTreeNode *PtrToBinNode;
typedef PtrToBinNode BinTree;

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

#endif
