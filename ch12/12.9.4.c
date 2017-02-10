#include <stdio.h>
static int co;
void tri(void);
int main(void)
{
    int a, b;
    while (~scanf("%d", &a))
    {
        for (b = 0; b < a; b++)
            tri();
        printf("The function has called %d times.\n", co);
        co = 0;
    }
    return 0;
}

void tri(void)
{
    co++;
}
