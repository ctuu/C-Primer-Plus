#include <stdio.h>
#define HARMAVER(X, Y) (1 / ((1/X + 1/ Y)/ 2))

int main(void)
{
    double a, b;
    while (~scanf("%lf%lf",&a, &b))
        printf("%f\n", HARMAVER(a, b));

    return 0;
}