#include "Queue.h"
#include "BinTree.h"

void inOrderTraversal(BinTree bt)
{
    inOrderTraversal(bt->left);
    printf(bt->element);
    inOrderTraversal(bt->right);
}

void preOrderTraversal(BinTree bt)
{
    printf(bt->element);
    inOrderTraversal(bt->left);
    inOrderTraversal(bt->right);
}

void postOrderTraversal(BinTree bt)
{
    inOrderTraversal(bt->left);
    inOrderTraversal(bt->right);
    printf(bt->element);
}

void levelOrderTraversal(BinTree bt)
{
    BinTree t;
    Queue q = createQueue();
    enQueue(q, bt);
    while ( !isQueueEmpty(q)) {
        t = deQueue(q);
        printf("%d\n", t->element);
        if (t->left)
            enQueue(q, t);
        if (t->right)
            enQueue(q, t);
    }
}
