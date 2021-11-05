#include <stdio.h>

int main(void)
{
    int K;
    scanf("%d", &K);
    int a[K];
    for (int i = 0; i < K; ++i)
        scanf("%d", &a[i]);
    int subSum = 0, maxSum = 0;

    for (int i = 0; i < K; ++i) {
        subSum += a[i];
        if(subSum < 0)
            subSum = 0;
        if (subSum > maxSum)
            maxSum = subSum;
    }
    printf("%d\n", maxSum);
    return 0;
}
