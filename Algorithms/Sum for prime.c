#include <stdio.h>
int che;
void pn(int a);
void sfp(int n, int k, int *num, int co);
int main(void)
{
    int N, K, a;
    int num[21];
    while (~scanf("%d%d", &N, &K))
    {
        che = 0;
        for (a = 0; a < N; a++)
            scanf("%d", &num[a]);
        sfp(N, K, num, 0);
        printf("%d\n", che);
    }
    return 0;
}

void sfp(int n, int k, int *num, int co)
{
    int t;
    if (k > 0)
        for (t = n; t > 0; num++, t--)
        {
            n--;
            sfp(n, k - 1, num + 1, co + *num);
        }
    else
        pn(co);
}

void pn(int a)
{
    int n;
    if (a == 1)
        return;
    else if (a == 2 || a == 3 || a == 5 || a == 7)
        che++;
    else if (a % 2 == 0 || a % 3 == 0 || a % 5 == 0 || a % 7 == 0)
        return;
    else
    {
        for (n = 2; n * n < a; n++)
            if (a % n == 0)
                return;
        che++;
    }
}