#include <stdio.h>

void sfp(int n, int k, int *num, int co);
int main(void)
{
    int N, K, a;
    int num[20];
    while (~scanf("%d%d", &N, &K))
    {
        for (a = 0; a < N; a++)
            scanf("%d", &num[a]);
        sfp(N, K, num, 0);
    }
    return 0;
}

void sfp(int n, int k, int *num, int co)
{
    int t;
    if (k > 0)
    {
        for (t = n; t > 0; t--)
        {
            n--;
            num++;
            sfp(n, k - 1, num, co + *num);
        }
    }
    else
        printf("%d\n", co);
}