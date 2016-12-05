#include <stdio.h>

long long A, B, sum;
void calc(long long c, long long d);

int main(void)
{
    int T, t;
    scanf("%d", &T);
    for (t = 0; t < T; t++)
    {
        sum = 0;
        scanf("%lld%lld", &A, &B);
        printf("Case #%d\n", t + 1);
        calc(A, A);
    }
    return 0;
}

void calc(long long c, long long d)
{
    if (c > B && d > B)
        printf("%lld\n", sum);
    else if (c > B || d > B)
        return;
    else
    {
        // printf("c = %lld, d =  %lld\n", c, d);
        if ((double)(A / B) + (double)(B / A) <= (double)(c / d) + (double)(d / c))
            sum++;
        if (d <= B)
            calc(c, d + 1);
        if (c <= B)
            calc(c + 1, d);
        if ((double)(A / B) + (double)(B / A) <= (double)(c / d) + (double)(d / c))
            printf("%lld %lld\n", c, d);
    }
}
