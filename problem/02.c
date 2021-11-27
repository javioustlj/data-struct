#include <stdio.h>

int main(void)
{
    int K;
    scanf("%d", &K);
    int a[K];
    for (int i = 0; i < K; ++i)
        scanf("%d", &a[i]);
    int subSum = 0, maxSum = 0;
    int first = 0, last = K - 1;
    int beg = 0;

    for (int i = 0; i < K; ++i) {
        subSum += a[i];
        if(subSum < 0) {
            subSum = 0;
            beg = i + 1;
        }
        else if (subSum == 0 && maxSum == 0) {
            first = last = i;
        }

        if (subSum > maxSum) {
            maxSum = subSum;
            first = beg;
            last = i;
        }
    }

    printf("%d %d %d\n", maxSum, a[first], a[last]);

    return 0;
}
