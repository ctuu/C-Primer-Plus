#include <stdio.h>

int sum(int a[], int n);
int num[20];

int main(void)
{
    int n, k;
    int i;
    while (~scanf("%d%d", &n, &k))
    {
        for (i = 0; i < n; i++)
            scanf("%d", &num[i]);
        sum(num, k);
    }
    return 0;
}

int sum(int a[], int n)
{
    int i, q;
    if (n > 0)
    {
        for (i = 0; i < n; i++)
        {
            q += a[i];
            sum(a, n--);
        }
    }
    printf("%d", q);
}