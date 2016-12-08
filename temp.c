#include <stdio.h>
int main(void)
{
    int a = 2;
    int c = 3;
    int * p[2] = {&a, &c};
    int * t;
    int b = 0;
    for (t = p[0];t && b < 2; b++)
    {
        printf("%d\n", *t);
        t = p[1];
    }
    return 0;
}