#include <stdio.h>

long long A, B, sum, c, d;

int main(void)
{
    int T, t;
    scanf("%d", &T);
    for (t = 0; t < T; t++)
    {
        sum = 0;
        scanf("%lld%lld", &A, &B);
        printf("Case #%d\n", t + 1);
        for (c = A; c <= B; c++)
            for (d = A; d <= B; d++)
                if ((double)(A / B) + (double)(B / A) <= (double)(c / d) + (double)(d / c))
                    sum++;
        printf("%lld\n", sum);
        for (c = A; c <= B; c++)
            for (d = A; d <= B; d++)
                if ((double)(A / B) + (double)(B / A) <= (double)(c / d) + (double)(d / c))
                    printf("%lld %lld\n", c, d);
    }
    return 0;
}
