#include <stdio.h>
#include <math.h>
#define LIMIT 5
#define PI 3.1415926
void transform(double sou[LIMIT], double tag[LIMIT], int, double (*pf)(double));

int main(void)
{
    int i;
    double a[LIMIT] = {60, 40, 30, 90, 120};
    double b[LIMIT] = {0};
    transform(a, b, LIMIT, sin);
    for (i = 0; i < LIMIT; i++)
    printf("%lf  ",b[i]);
    return 0;
}
void transform(double sou[LIMIT], double tag[LIMIT], int li, double (*pf)(double))
{
    int i;
    for (i = 0; i < LIMIT; i++)
    {
        tag[i] = (*pf)(sou[i] * PI / 180);
    }
}