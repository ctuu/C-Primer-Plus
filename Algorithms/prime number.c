#include <stdio.h>
void pn(int a);
int main(void)
{
    int n, i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        pn(i);
    return 0;
}

void pn(int a)
{
    int n;
    if (a == 1 || a == 2 || a == 3 || a == 5 || a == 7)
        printf("%d\n", a);
    else if (a % 2 == 0 || a % 3 == 0 || a % 5 == 0 || a % 7 == 0)
        return;
    for (n = 1; n * n < a; n++)
        if (a % n == 0)
            break;
    printf("%d\n", a);
}