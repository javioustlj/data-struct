#include <stdio.h>
#include <stdlib.h>

#define MAXN 100004

struct Node {
    int data;
    int next;
};

typedef struct Node* List;

List readList(int N)
{
    List li = malloc(MAXN * sizeof(struct Node));
    int addr;
    for (int i = 0; i < N; ++i) {
        scanf("%d ", &addr);
        scanf("%d %d", &li[addr].data, &li[addr].next);
    }
    return li;
}

int main(void)
{
    int head, N, K, total = 0, cnt = 0;
    scanf("%d %d %d\n", &head, &N, &K);
    List li = readList(N);
    for (int addr = head; addr != -1; addr = li[addr].next)
        ++total;
    int addrs[K];
    int ans[total], ansk=0;
    for(int i = 0, addr = head; i < total; ++i) {
        addrs[cnt++] = addr;
        addr = li[addr].next;
        if (cnt == K) {
            for (int j = K; j != 0; --j) {
                ans[ansk++] = addrs[j - 1];
            }
            cnt = 0;
        }
    }
    for (int i = 0; i < cnt; ++i)
        ans[ansk++] = addrs[i];
    for (int i = 0; i < ansk - 1; ++i)
        printf("%05d %d %05d\n", ans[i], li[ans[i]].data, ans[i + 1]);
    printf("%05d %d -1\n", ans[ansk - 1], li[ans[ansk - 1]].data);

    return 0;
}
