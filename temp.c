#include <stdio.h>

long long A, B, sum, d;
void dfs(long long d);
int mid(long long d);
_Bool jud = 0;
int main(void)
{
    int T, t;
    scanf("%d", &T);
    for (t = 0; t < T; t++)
    {
        jud = 0;
        sum = 0;
        scanf("%lld%lld", &A, &B);
        printf("Case #%d\n", t + 1);
        dfs(A);
    }
    return 0;
}

void dfs(long long d)
{
    long long c;
    if (d > B)
    {
        if (jud == 0)
            printf("%lld\n", sum);
        jud = 1;
        return;
    }
    else
    {
        if (mid(d) == 0)
            dfs(d + 1);
    }
}

int mid(long long d)
{
    int u = 0;
    long long c;
    if (jud == 0)
    {
        for (c = A; c <= B; c++)
            if ((double)(A / B) + (double)(B / A) <= (double)(c / d) + (double)(d / c))
            {
                sum++;
                dfs(d + 1);
                printf("%lld %lld\n", c, d);
                u = 1;
            }
    }
    return u;
}