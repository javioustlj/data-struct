#include <stdio.h>
#include <string.h>

#define N 10

struct TreeNode
{
    int left;
    int right;
};

int readTree(struct TreeNode *T)
{
    int n;
    char a, b;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; ++i) {
        scanf("%c %c", &a, &b);
        getchar();
        T[i].left = a == '-' ? -1 : a - '0';
        T[i].right = b == '-' ? -1 : b - '0';
    }
    int flag[n];
    for (int i = 0; i < n; ++i)
        flag[i] = 0;
    for (int i = 0; i < n; ++i) {
        if (T[i].left != -1)
            flag[T[i].left] = 1;
        if (T[i].right != -1)
            flag[T[i].right] = 1;
    }
    for (int i = 0; i < n; ++i)
        if (!flag[i])
            return i;
    return -1;
}

void levelOrderTranversal(struct TreeNode *T, int root)
{
    if (root == -1)
        return;
    int queue[N];
    memset(queue, 0, sizeof(queue));
    int rear = -1, tail = -1, key = 0, cnt = 0;
    int ans[N];
    queue[++rear] = root;
    while (tail != rear) {
        key = queue[++tail];
        if (T[key].left != -1)
            queue[++rear] = T[key].left;
        if (T[key].right != -1)
            queue[++rear] = T[key].right;
        if (T[key].left == -1 && T[key].right == -1)
            ans[cnt++] = key;
    }

    for (int i = 0; i < cnt; ++i)
        printf("%d%c", ans[i], i == cnt - 1 ? '\n' : ' ');
}

int main(void)
{
    struct TreeNode T[N];
    int root;
    root = readTree(T);
    levelOrderTranversal(T, root);

    return 0;
}
