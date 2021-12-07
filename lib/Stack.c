#include <stdlib.h>
#include "Stack.h"

struct StackNode
{
    int key;
    PtrToStackNode next;
};

struct StackHead
{
    PtrToStackNode top;
};

Stack createStack()
{
    Stack s = malloc(sizeof(struct StackHead));
    s->top = NULL;
    return s;
}

bool isStackEmpty(Stack s)
{
    return s->top == NULL;
}

void push(Stack s, int key)
{
    PtrToStackNode tmp = malloc(sizeof(struct StackNode));
    tmp->next = s->top;
    tmp->key = key;
    s->top = tmp;
}

int pop(Stack s)
{
    if (isStackEmpty(s))
        return ~0;
    PtrToStackNode tmp = s->top;
    int key = tmp->key;
    s->top = s->top->next;
    free(tmp);
    return key;
}
