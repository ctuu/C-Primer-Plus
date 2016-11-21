#include <stdio.h>
int main(void)
{
    int T, n, k;
    scanf("%d", &T);
    for (; T > 0; T--)
    {
        scanf("%d%d", &n, &k);
        if (n % 2 == 0)
        {
            if ((n / 2) >= k)
                printf("BH\n");
            else
                printf("LYF\n");
        }
        else
        {
            if ((n / 2) + 1 >= k)
                printf("BH\n");
            else
                printf("LYF\n");
        }
    }
    return 0;
}