#include <stdio.h>
void pn(int a);
int main(void)
{
    int n, i;
    while(~scanf("%d", &n))
    {
    pn(n);
    printf("   %d\n",n);
    }
    return 0;
}

void pn(int a)
{
    int n;
        for (n = 2; n * n < a; n++)
            if (a % n == 0)
                {
                    printf("NO, %d", n);
                    return;
                }
        printf("%d\n", a);
}