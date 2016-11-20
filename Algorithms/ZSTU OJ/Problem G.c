#include <stdio.h>
int num[1000] = {0};
void quicksort(int i, int j);
int main(void)
{
    int T, n, k, a, b;
    int count[2000] = {0};
    int max = 0;
    scanf("%d", &T);
    for (; T > 0; T--)
    {
        int count[2000] = {0};
        k = 0;
        scanf("%d", &n);
        for (a = 0; a < n; a++)
            scanf("%d", &num[a]);
        quicksort(0, n - 1);
        count[0] = num[0];
        for (a = 0; a < n; a++)
        {
            for (b = a; b < n; b++)
            {
                if (count[k] == num[b])
                {
                    count[k + 1] += 1;
                    num[b] = 0;
                    max = (max > count[k + 1]) ? max : count[k + 1];
                }
            }
            if (k < 998)
                k += 2;
            while (num[a] == 0 && a < n)
                a++;
            if (a < n && num[a] != 0)
            {
                count[k] = num[a];
                count[k + 1] += 1;
            }
        }
        for (k = 0; k < 2000; k += 2)
            if (count[k + 1] >= max)
                printf("%d ", count[k]);
        printf("\n");
    }
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