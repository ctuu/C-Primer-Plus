#include <stdio.h>
double sub(double c[], int i);
int main(void)
{
    double num[5] = {1.3, 3.3, 27.7, 24.5, 14.8};
    printf("\n%.1lf", sub(num, 5));
    return 0;
}

double sub(double c[], int i)
{
    int o;
    double max = 0;
    double min = c[0];
    for (o = 0; o < i; o++)
        max = (max > c[o]) ? max : c[o];
    for (o = 0; o < i; o++)
        min = (min < c[o]) ? min : c[o];
    return max - min;
}