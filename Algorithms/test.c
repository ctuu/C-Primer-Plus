#include <stdio.h>
int main(void)
{
    int a, i, c, d;
    scanf("%d", &d);
    for (; d > 0; d--)
    {
        scanf("%d", &c);
        for (a = 0; c > 0; c--)
        {
            scanf("%d", &i);
            a += i;
        }
        printf("%d\n\n", a);
    }
    return 0;
}