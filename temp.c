#include <stdio.h>
int main(void)
{
    int a, b, c, d;
    while (~scanf("%d", &a))
    {
        for (c = 0, d = 0; d < a; d++)
        {
            scanf("%d", &b);
            c += b;
        }
        printf("%d", c);
    }
    return 0;
}