#include <stdio.h>
int main(void)
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if ((b < a && c > 0) || (b > a && c < 0))
        printf("NO");
    else if (c == 0)
        if (a == b)
            printf("YES");
        else
            printf("NO");
    else if ((b - a) % c == 0)
        printf("YES");
    else
        printf("NO");
    return 0;
}