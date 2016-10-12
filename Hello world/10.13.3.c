#include <stdio.h>
int imax(int c[], int i);
int main(void)
{
    int num[5] = {1, 3, 23, 24, 14};
    printf("\n%d", imax(num, 5));
    return 0;
}

int imax(int c[], int i)
{
    int o = 0;
    int max = 0;
    for (; o < i; o++)
        max = (max > c[o]) ? max : c[o];
    return max;
}