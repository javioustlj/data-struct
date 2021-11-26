#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct StackNode {
    int *data;
    int top;
    int maxSize;
};
typedef struct StackNode *Stack;

Stack createStack(int n)
{
    Stack s = malloc(sizeof(struct StackNode));
    s->top = -1;
    s->maxSize = n;
    s->data = malloc(n * sizeof (int));
    return s;
}

bool isFull(Stack s)
{
    return s->top == s->maxSize - 1;
}
bool isEmpty(Stack s)
{
    return s->top == -1;
}

bool push(Stack s, int x)
{
    if (isFull(s)) {
        return false;
    }
    s->data[++s->top] = x;
    return true;
}

int pop(Stack s)
{
    return s->data[s->top--];
}

bool isValidSeq(int seq[], int N, int M)
{
    Stack s = createStack(M);
    int top = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = top + 1; j <= seq[i]; ++j) {
            if (!push(s, j))
                return false;
            top = seq[i];
        }
        if (isEmpty(s) || seq[i] != pop(s))
            return false;
    }
    return true;
}

int main(void)
{
    int M, N, K;
    scanf("%d %d %d", &M, &N, &K);
    int sequences[K][N];
    for (int i = 0; i < K; ++i)
        for (int j = 0; j < N; ++j)
            scanf("%d", &sequences[i][j]);
    for (int i = 0; i < K; ++i) {
        if (isValidSeq(sequences[i], N, M))
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
