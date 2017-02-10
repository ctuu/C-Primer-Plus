#include <stdio.h>
#include <time.h>

int main(void)
{
    double a, b;
    int ct = 100000000;
    a = clock();
    while (ct--)
        ;
    b = clock();
    printf("%f", (double) (b - a) / CLOCKS_PER_SEC);
    return 0;
}