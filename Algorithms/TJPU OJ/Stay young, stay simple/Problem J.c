#include <stdio.h>
int main(void)
{
    int n, k, i;
    int num[500];
    int max = 0;
    int sum = 0;
    scanf("%d%d", &n, &k);
    for (i = 0; i < n; i++)
        scanf("%d", &num[i]);
    for (i = 0; i < n - 1; i++)
    {
        if (num[i] + num[i + 1] < k)
        {
            sum = k - num[i];
            num[i + 1] += sum;
            max = (sum > max) ? sum : max;
        }
    }
    printf("%d\n", max);
    for (i = 0; i < n; i++)
        printf("%d", num[i]);
    return 0;
}