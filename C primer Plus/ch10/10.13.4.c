#include <stdio.h>
int imax(double c[], int i);
int main(void)
{
    double num[5] = {1.1, 3.3, 27.7, 24.5, 14.8};
    printf("\n%d", imax(num, 5));
    return 0;
}

int imax(double c[], int i)
{
    int in;
    int o = 0;
    double max = 0;
    for (; o < i; o++)
        if (c[o] > max)
            {
                max = c[o];
                in = o;
            }
    return in;
}