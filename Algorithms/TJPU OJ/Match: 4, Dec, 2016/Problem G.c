#include <stdio.h>
long long ct;

long long A, B, sum, d;
void dfs(void);
int mid(long long y);
_Bool jud = 0;
int main(void)
{
    int T, t;
    scanf("%d", &T);
    for (t = 0; t < T; t++)
    {
        ct = 0;
        jud = 0;
        sum = 0;
        scanf("%lld%lld", &A, &B);
        printf("Case #%d\n", t + 1);
        d = A;
        if (A == B)
            printf("%d\n%lld %lld\n", 1, A, B);
        else
            dfs();
        printf("\nsum = %lld\n\n", ct);
    }
    return 0;
}

void dfs(void)
{
    if (d > B)
    {
        if (jud == 0)
            printf("%lld\n", sum);
        jud = 1;
        return;
    }
    else
    {
        ct++;
        if (mid(d) == 0)
        {
            d++;
            dfs();
        }
    }
}

int mid(long long y)
{
    long long c;

    int u = 0;
    if (jud == 0)
    {
        for (c = A; c <= B; c++)
        {
            ct++;
            if ((double)(A / B) + (double)(B / A) <= (double)(c / y) + (double)(y / c))
            {
                u = 1;
                sum++;
                d++;
                dfs();
                printf("%lld %lld\n", c, y);
            }
        }
    }
    return u;
}