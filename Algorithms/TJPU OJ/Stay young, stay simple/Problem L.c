#include <stdio.h>
int num[200000];
void quicksort(int i, int j);
int main(void)
{
    int n, a, b, snum, i, temp;
    int t, c, d, k, q;
    double sum = 0;
    double su = 0;
    scanf("%d%d%d", &n, &a, &b);
    snum = a + b;
    for (i = 0; i < snum; i++)
        scanf("%d", &num[i]);
    for (; i < n; i++)
    {
        scanf("%d", &temp);
        for (t = 0; t < snum; t++)
        {
            if (temp >num[t])
                {
                    num[t] = temp;
                    break;
                }
        }
    }
    quicksort(0, snum - 1);
    c = a;
    d = b;
    if (a > b)
    {
        c = b;
        d = a;
        k = a;
        a = b;
        b = k;
    }
    for (q = snum - 1; c > 0; q--, c--)
        sum += num[q];
    sum /= a;
    for (; d > 0; q--, d--)
        su += num[q];
    su /= b;
    printf("%lf", sum + su);
    return 0;
}

void quicksort(int i, int j)
{
    int a = i;
    int b = j - 1;
    int temp;
    if (a < b)
    {
        for (; a < b;)
        {
            while (num[a] <= num[j] && a < b)
                a++;
            while (num[b] > num[j] && a < b)
                b--;
            if (num[a] >= num[j] && num[b] <= num[j])
            {
                temp = num[a];
                num[a] = num[b];
                num[b] = temp;
            }
        }
        if (num[a] > num[j])
        {
            temp = num[a];
            num[a] = num[j];
            num[j] = temp;
        }
        quicksort(i, a);
        quicksort(b, j);
    }
    else if (a == b)
    {
        if (num[i] > num[j])
        {
            temp = num[i];
            num[i] = num[j];
            num[j] = temp;
        }
    }
}