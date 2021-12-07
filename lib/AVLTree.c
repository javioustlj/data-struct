#include <stdlib.h>
#include "AvlTree.h"

struct AvlNode{
    int element; /* 结点数据 */
    AvlTree left;     /* 指向左子树 */
    AvlTree right;    /* 指向右子树 */
    int height;       /* 树高 */
};

int max ( int a, int b )
{
    return a > b ? a : b;
}

static int getHeight(AvlTree avlT)
{
    if (avlT == NULL)
        return -1;
    else
        return avlT->height;
}

/*
LL
         A                                      B
        / \                                   /   \
       B   T4      Right Rotate (z)          x      A
      / \          - - - - - - - - ->      /  \    /  \ 
     x   T3                               T1  T2  T3  T4
    / \
  T1   T2
*/

static AvlTree singleRotateWithLeft(AvlTree A)
{
    AvlTree B = A->left;
    A->left = B->right;
    B->right = A;
    A->height = max( getHeight(A->left), getHeight(A->right) ) + 1;
    B->height = max( getHeight(B->left), A->height ) + 1;

    return B;
}

/*
RR
           A                               B
         /  \                            /   \ 
        T1   B     Left Rotate(z)       A      x
            /  \   - - - - - - - ->    / \    / \
           T2   x                     T1  T2 T3  T4
               / \
             T3  T4
*/

static AvlTree singleRotateWithRight(AvlTree A)
{
    AvlTree B = A->right;
    A->right = B->left;
    B->left = A;
    A->height = max( getHeight(A->left), getHeight(A->right) ) + 1;
    B->height = max( getHeight(B->right), A->height ) + 1;

    return B;
}
/*
LR
            z                               z                           x
           / \                            /   \                        /  \ 
          y   T4  Left Rotate (y)        x    T4  Right Rotate(z)    y      z
         / \      - - - - - - - - ->    /  \      - - - - - - - ->  / \    / \
       T1   x                          y    T3                    T1  T2 T3  T4
           / \                        / \
         T2   T3                    T1   T2
*/

static AvlTree doubleRotateWithLeft (AvlTree A)
{
    A->left = singleRotateWithRight(A->left);

    return singleRotateWithLeft(A);
}

/*
RL
           z                            z                            x
          / \                          / \                          /  \ 
        T1   y   Right Rotate (y)    T1   x      Left Rotate(z)   z      y
            / \  - - - - - - - - ->     /  \   - - - - - - - ->  / \    / \
           x   T4                      T2   y                  T1  T2  T3  T4
          / \                              /  \
        T2   T3                           T3   T4
*/

static AvlTree doubleRotateWithRight(AvlTree A)
{
    A->right = singleRotateWithLeft(A->right);

    return singleRotateWithRight(A);
}

AvlTree insert(AvlTree T, int X)
{
    if(!T) {
        T = (AvlTree)malloc(sizeof(struct AvlNode));
        T->element = X;
        T->height = 0;
        T->left = T->right = NULL;
    }
    else if (X < T->element) {
        T->left = insert(T->left, X);
        if ( getHeight(T->left) - getHeight(T->right) == 2 )
            if (X < T->left->element)
               T = singleRotateWithLeft(T);
            else 
               T = doubleRotateWithLeft(T);
    }
    else if ( X > T->element ) {
        T->right = insert( T->right, X );
        if ( getHeight(T->right) - getHeight(T->left) == 2 )
            if ( X > T->right->element ) 
               T = singleRotateWithRight(T);
            else 
               T = doubleRotateWithRight(T); 
    }

    T->height = max( getHeight(T->left), getHeight(T->right) ) + 1;

    return T;
}
