#ifndef _TREE_H_
#define _TREE_H

typedef struct TreeNode *PtrToNode;

struct TreeNode
{
    ElementType element;
    PtrToNode firstChild;
    PtrToNode nextSibling;
};

#endif
