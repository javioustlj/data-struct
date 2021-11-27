#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal( BinTree BT );  /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}

BinTree Insert( BinTree bst, ElementType x )
{
    BinTree p = bst;
    if(!bst) {
        bst = malloc(sizeof(struct TNode));
        bst->Data = x;
        bst->Left = bst->Right = NULL;
    }
    while(p) {
        if(x > p->Data) {
            if(p->Right)
                p = p->Right;
            else {
                BinTree tmp = malloc(sizeof(struct TNode));
                tmp->Data = x;
                tmp->Left = tmp->Right = NULL;
                p->Right = tmp;
                break;
            }
        }
        else if (x < p->Data) {
            if(p->Left)
                p = p->Left;
            else {
                BinTree tmp = malloc(sizeof(struct TNode));
                tmp->Data = x;
                tmp->Left = tmp->Right = NULL;
                p->Left = tmp;
                break;
            }
        }
        else
            break;
    }

    return bst;
}

BinTree Delete( BinTree bst, ElementType x )
{
    BinTree p = bst, parent = NULL, tmp = NULL, sub = NULL;
    int flag = 0, found = 0;
    while(p) {
        if(x > p->Data) {
            parent = p;
            flag = 1;
            p = p->Right;
        }
        else if (x < p->Data) {
            parent = p;
            flag = 0;
            p = p->Left;
        }
        else {
            found = 1;
            if (p->Left && p->Right) {
                tmp = p->Right;
                parent = p;
                while(tmp->Left) {
                    parent = tmp;
                    tmp = tmp->Left;
                }
                if (parent != p)
                    parent->Left = tmp->Right;
                else
                    p->Right = tmp->Right;
                p->Data = tmp->Data;
                free(tmp);
            }
            else {
                tmp = p;
                if (p->Left)
                    sub = p->Left;
                else if (p->Right)
                    sub = p->Right;
                if (parent) {
                    if (flag)
                        parent->Right = sub;
                    else
                        parent->Left = sub;
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

Position Find( BinTree bst, ElementType x )
{
    while(bst) {
        if(x > bst->Data)
            bst = bst->Right;
        else if (x < bst->Data)
            bst = bst->Left;
        else
            return bst;
    }
    return NULL;
}

Position FindMin( BinTree bst )
{
    if(bst)
        while(bst->Left)
            bst = bst->Left;
    return bst;
}

Position FindMax( BinTree bst )
{
    if (bst)
        while(bst->Right)
            bst = bst->Right;
    return bst;
}
