#include <stdio.h>
int main(void)
{
    const int **pp2;
    int *p1;
    const int n = 13;
    pp2 = &p1;
    *pp2 = &n;
    *p1 = 10;
    printf("%d", n);
    return 0;
}