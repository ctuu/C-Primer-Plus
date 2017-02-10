#include <stdio.h>

void apple(void);
void bag(void);
int main(void)
{
    int a;
    void (*pf)(void);
    while (~scanf("%d", &a))
    {
        if (a == 1)
            pf = apple;
        else if (a == 2)
            pf = bag;
        else
            {
                puts("Please enter 1 or 2");
                continue;
            }
        pf();
    }
    return 0;
}
void apple(void)
{
    printf("apple\n");
}

void bag(void)
{
    printf("bag\n");
}
