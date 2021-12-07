#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_


struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

AvlTree insert(AvlTree T, int key);

#endif
