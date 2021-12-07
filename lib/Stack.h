#ifndef _STACK_H_
#define _STACK_H

#include <stdbool.h>

typedef struct StackNode *PtrToStackNode;
typedef struct StackHead *Stack;
struct StackNode;
struct StackHead;

Stack createStack();
void deleteStack();
void push(Stack, int);
int pop(Stack);
bool isStackEmpty(Stack);

#endif
