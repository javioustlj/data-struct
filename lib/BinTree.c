#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"
#include "BinTree.h"

void inOrderTraversal(BinTree bt)
{
    BinTree tmp;
    Stack s = createStack();
    while (bt || !isStackEmpty(s)) {
        while(bt) {
            push(s, bt);
            bt = bt->left;
        }
        if (!isStackEmpty(s)) {
            bt = pop(s);
            print("%d\n", tmp->element);
            bt = bt->right;
        }
    }
}

void preOrderTraversal(BinTree bt)
{
    BinTree tmp;
    Stack s = createStack();
    while (bt || !isStackEmpty(s)) {
        while(bt) {
            push(s, bt);
            print("%d\n", tmp->element);
            bt = bt->left;
        }
        if (!isStackEmpty(s)) {
            bt = pop(s);
            bt = bt->right;
        }
    }
}

void postOrderTraversal(BinTree bt)
{
    BinTree tmp, preTree = NULL;
    Stack s = createStack();
    while (bt || !isStackEmpty(s)) {
        while(bt) {
            push(s, bt);
            bt = bt->left;
        }
        if (!isStackEmpty(s)) {
            bt = pop(s);
            if (preTree == bt->right || bt->right == NULL) {
                printf("%d\n", preTree->element);
                preTree = bt;
            }
            else {
                push(s, bt);
            }
            bt = bt->right;
        }
    }
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

Position find(ElementType x, BinTree bst)
{
    while(bst) {
        if(x > bst->element)
            bst = bst->right;
        else if (x < bst->element)
            bst = bst->left;
        else
            return bst;
    }
    return NULL;
}

Position findMin(BinTree bst)
{
    if(bst)
        while(bst->left)
            bst = bst->left;
    return bst;
}

Position findMax(BinTree bst)
{
    if (bst)
        while(bst->right)
            bst = bst->right;
    return bst;
}

BinTree insert(ElementType x, BinTree bst)
{
    BinTree p = bst;
    if(!bst) {
        bst = malloc(sizeof(struct BinTreeNode));
        bst->element = x;
        bst->left = bst->right = NULL;
    }
    while(p) {
        if(x > p->element) {
            if(p->right)
                p = p->right;
            else {
                BinTree tmp = malloc(sizeof(struct BinTreeNode));
                tmp->element = x;
                tmp->left = tmp->right = NULL;
                p->right = tmp;
                break;
            }
        }
        else if (x < p->element) {
            if(p->left)
                p = p->left;
            else {
                BinTree tmp = malloc(sizeof(struct BinTreeNode));
                tmp->element = x;
                tmp->left = tmp->right = NULL;
                p->left = tmp;
                break;
            }
        }
        else
            break;
    }

    return bst;
}

BinTree delete(ElementType x, BinTree bst)
{
    BinTree p = bst, parent = NULL, tmp = NULL, sub = NULL;
    int flag = 0, found = 0;
    while(p) {
        if(x > p->element) {
            parent = p;
            flag = 1;
            p = p->right;
        }
        else if (x < p->element) {
            parent = p;
            flag = 0;
            p = p->left;
        }
        else {
            found = 1;
            if (p->left && p->right) {
                tmp = p->right;
                parent = p;
                while(tmp->left) {
                    parent = tmp;
                    tmp = tmp->left;
                }
                if (parent != p)
                    parent->left = tmp->right;
                else
                    p->right = tmp->right;
                p->element = tmp->element;
                free(tmp);
            }
            else {
                tmp = p;
                if (p->left)
                    sub = p->left;
                else if (p->right)
                    sub = p->right;
                if (parent) {
                    if (flag)
                        parent->right = sub;
                    else
                        parent->left = sub;
                } else {
                    bst = sub;
                }

                free(tmp);
            }
        }
    }
    if (!found)
        printf("Not Found\n");
    return bst;
}

void inOrderTraversalByRecursion(BinTree bt)
{
    inOrderTraversal(bt->left);
    printf(bt->element);
    inOrderTraversal(bt->right);
}

void preOrderTraversalByRecursion(BinTree bt)
{
    printf(bt->element);
    inOrderTraversal(bt->left);
    inOrderTraversal(bt->right);
}

void postOrderTraversalByRecursion(BinTree bt)
{
    inOrderTraversal(bt->left);
    inOrderTraversal(bt->right);
    printf(bt->element);
}

Position findByRecursion(ElementType x, BinTree bst)
{
    if(!bst)
        return NULL;

    if(x > bst->element)
        return find(x, bst->right);
    else if(x < bst->element)
        return find(x, bst->left);
    else
        return bst;
}

Position findMinByRecursion(BinTree bst)
{
    if(!bst)
        return NULL;
    else if(!bst->left)
        return bst;
    else
        return findMinByRecursion(bst->left);
}

Position findMaxByRecursion(BinTree bst)
{
    if(!bst)
        return NULL;
    else if(!bst->right)
        return bst;
    else
        return findMaxByRecursion(bst->right);
}

BinTree insertByRecursion(ElementType x, BinTree bst)
{
    if(!bst) {
        bst = malloc(sizeof(struct BinTreeNode));
        bst->element = x;
        bst->left = bst->right = NULL;
    }
    else {
        if(x < bst->element)
            bst->left = insertByRecursion(x, bst->left);
        else if(x > bst->element)
            bst->right = insertByRecursion(x, bst->right);
    }
    return bst;
}

BinTree deleteByRecursion(ElementType x, BinTree bst)
{
    Position tmp;
    if (!bst)
        printf("Binary Tree is empty!\n");
    else if(x < bst->element)
        bst->left = delete(x, bst->left);
    else if(x > bst->element)
        bst->right = delete(x, bst->right);
    else {
        if(bst->left && bst->right) {
            tmp = findMin(bst->right);
            bst->element = tmp->element;
            bst->right = delete(bst->element, bst->right);
        }
        else {
            tmp = bst;
            if(!bst->left)
                bst = bst->right;
            else if(!bst->right)
                bst = bst->left;
            free(tmp);
        }
    }
    return bst;
}












