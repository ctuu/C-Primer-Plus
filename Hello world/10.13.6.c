#include <stdio.h>
void sort(double *start, double *end);
int main(void)
{
    int c;
    double num[5] = {1.1, 2.3, 5.7, 23.9, 12.6};
    printf("Origin: ");
    for (c = 0; c < 5; c++)
        printf("%.1lf ", num[c]);
    printf("\nAfter: ");
    sort(num, num + 4);
    for (c = 0; c < 5; c++)
        printf("%.1lf ", num[c]);

    return 0;
}

void sort(double *start, double *end)
{
    double temp;
    for (; start <= end; start++, end--)
    {
        temp = *start;
        *start = *end;
        *end = temp;
    }
}