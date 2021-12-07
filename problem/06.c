#include <stdio.h>
#include <stdbool.h>

#define N 10

struct TreeNode {
    char key;
    int left;
    int right;
};
struct TreeNode T1[N], T2[N];

int readTree(struct TreeNode *T)
{
    int n;
    scanf("%d", &n);getchar();

    char a, b, c;
    for (int i = 0; i < n; ++i) {
        scanf("%c %c %c", &a, &b, &c);
        getchar();
        T[i].key = a;
        T[i].left = b == '-' ? -1 : b - '0';
        T[i].right = c == '-' ? -1 : c - '0';
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

bool isomorphic(int t1, int t2)
{
    if (t1 == -1 && t2 == -1)
        return true;
    if ((t1 == -1 && t2 != -1) || (t1 != -1 && t2 == -1))
        return false;
    if (T1[t1].key != T2[t2].key)
        return false;
    return (isomorphic(T1[t1].left, T2[t2].left) && isomorphic(T1[t1].right, T2[t2].right)) ||
            (isomorphic(T1[t1].left, T2[t2].right) && isomorphic(T1[t1].right, T2[t2].left));
}

int main(void)
{
    int root1, root2;
    root1 = readTree(T1);
    root2 = readTree(T2);

//    for (int i = 0; i < N; ++i)
//        printf("%c %d %d \n", T1[i].key, T1[i].left, T2[i].left);
    bool ans = isomorphic(root1, root2);
    if (ans)
        puts("Yes");
    else
        puts("No");

    return 0;
}
